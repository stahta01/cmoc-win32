/* cas2wav - convert Dragon/CoCo .cas file to WAV.
   Ciaran Anscomb, 2013.  Public Domain.

   v0.5a: converted to C, fixed Perl ancestry typo
   v0.6: support different sample rates, 8- or 16-bit sample sizes, 1 or 2
         channels, sine or approximated square wave.

   C99 required - you might need -std=c99 when compiling with gcc.
   Maths functions used: link with -lm.

   Set sample rate with -r, sample size with -b, channel count with -c.

   If sample rate is less than 11025Hz, exactly 1200Hz and 2400Hz cycles are
   output, otherwise cycles are closer to what a Dragon would actually write.

   Pure sine waves are the default, so -s is a no-op.

   -q doesn't generate pure square wave data, but instead adds harmonics to the
   fundamental up to nyquist (sample rate / 2).  This seems to make it more
   resilient during subsequent sample rate conversions.

   The harmonic limit can be modified with -t.  Simulate your naff old tapes
   with -t 12000!  Just need a noise option now...
*/

#define _POSIX_C_SOURCE 200112L

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Bits of this will be filled in before writing. */

static uint8_t wav_header[44] = {
	'R', 'I', 'F', 'F', 0x00, 0x00, 0x00, 0x00,
	'W', 'A', 'V', 'E', 'f', 'm', 't', ' ',
	0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x08, 0x00, 'd', 'a', 't', 'a',
	0x00, 0x00, 0x00, 0x00
};

static unsigned sample_rate = 9600;
static unsigned tape_rate = 0;
static unsigned bits_per_sample = 8;
static unsigned num_channels = 1;
static unsigned bytes_per_sample;
static _Bool square_wave = 0;

static uint8_t *wave_data[2];
static unsigned wave_len[2];

static double compute_sample(unsigned cycle_freq, unsigned sample) {
	double m_pi2 = 2 * acos(-1.0);
	unsigned num_samples = sample_rate / cycle_freq;
	double i = (double)((sample * 2) + 1) / (double)(num_samples * 2);
	double v = sin(i * m_pi2);
	if (square_wave) {
		// add harmonics up to the "tape rate"
		unsigned k = 3;
		unsigned r = cycle_freq * k;
		while (r <= tape_rate) {
			double h = i * (double)k;
			v += sin(h * m_pi2) / (double)k;
			k += 2;
			r = cycle_freq * k;
		}
	}
	return v * 0.7855;
}

static void generate_wavetable(unsigned cycle_freq, int bit) {
	unsigned num_samples = sample_rate / cycle_freq;
	unsigned len = num_samples * num_channels * bytes_per_sample;
	uint8_t *wave = malloc(len);
	wave_len[bit] = len;
	wave_data[bit] = wave;
	for (unsigned i = 0; i < num_samples; i++) {
		double v = compute_sample(cycle_freq, i);
		for (unsigned j = 0; j < num_channels; j++) {
			if (bits_per_sample == 16) {
				unsigned di = ((i * num_channels) + j) * 2;
				uint16_t dv = v * 32767.;
				wave[di] = dv & 0xff;
				wave[di+1] = (dv >> 8) & 0xff;
			} else {
				uint8_t dv = (v * 127.) + 128.;
				wave[(i * num_channels) + j] = dv;
			}
		}
	}
}

static void usage(const char *argv0) {
	printf("Usage: %s [OPTION]... INFILE OUTFILE\n", argv0);
	puts(
"Convert a Dragon/Tandy CoCo CAS file to WAV.\n\n"
"   -r RATE       set sample rate of OUTFILE (4800 - 192000) [9600]\n"
"   -t RATE       max harmonic of RATE in square wave [sample rate / 2]\n"
"   -b BITS       bits per sample, 8 or 16 [8]\n"
"   -c CHANNELS   number of channels, 1 or 2 [1]\n"
"   -s            generate sine wave [default]\n"
"   -q            generate square wave\n"
	);
}

int main(int argc, char **argv) {
	FILE *in, *out;

	int opt;
	while ((opt = getopt(argc, argv, "r:t:b:c:sqh")) != -1) {
		switch (opt) {
		case 'r':
			sample_rate = atoi(optarg);
			break;
		case 't':
			tape_rate = atoi(optarg);
			break;
		case 'b':
			bits_per_sample = atoi(optarg);
			break;
		case 'c':
			num_channels = atoi(optarg);
			break;
		case 's':
			square_wave = 0;
			break;
		case 'q':
			square_wave = 1;
			break;
		case 'h':
			usage(argv[0]);
			exit(EXIT_SUCCESS);
		default:
			exit(EXIT_FAILURE);
		}
	}

	if (sample_rate < 4800 || sample_rate > 192000) {
		fprintf(stderr, "unsupported sample rate: use 4800-192000\n");
		exit(EXIT_FAILURE);
	}

	if (bits_per_sample != 8 && bits_per_sample != 16) {
		fprintf(stderr, "unsupported bits per sample: use 8 or 16\n");
		exit(EXIT_FAILURE);
	}

	if (num_channels < 1 || num_channels > 2) {
		fprintf(stderr, "unsupported number of channels: use 1 or 2\n");
		exit(EXIT_FAILURE);
	}

	if (tape_rate == 0)
		tape_rate = sample_rate / 2;

	if (tape_rate < 2400 || tape_rate > 96000) {
		fprintf(stderr, "unsupported tape rate: use 2400-96000\n");
		exit(EXIT_FAILURE);
	}

	if ((optind + 1) >= argc) {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	bytes_per_sample = bits_per_sample >> 3;

	if ((in = fopen(argv[optind], "rb")) == NULL) {
		perror("Failed to open input file");
		exit(EXIT_FAILURE);
	}

	if ((out = fopen(argv[optind+1], "wb")) == NULL) {
		perror("Failed to open output file");
		exit(EXIT_FAILURE);
	}

	// generate wavetables
	if (sample_rate < 11025) {
		generate_wavetable(1200, 0);
		generate_wavetable(2400, 1);
	} else {
		generate_wavetable(1101, 0);
		generate_wavetable(2057, 1);
	}

	// NumChannels
	wav_header[22] = num_channels;
	wav_header[23] = 0;
	// SampleRate
	wav_header[24] = sample_rate & 0xff;
	wav_header[25] = (sample_rate >> 8) & 0xff;
	wav_header[26] = (sample_rate >> 16) & 0xff;
	wav_header[27] = (sample_rate >> 24) & 0xff;
	// ByteRate
	unsigned byte_rate = sample_rate * num_channels * bytes_per_sample;
	wav_header[28] = byte_rate & 0xff;
	wav_header[29] = (byte_rate >> 8) & 0xff;
	wav_header[30] = (byte_rate >> 16) & 0xff;
	wav_header[31] = (byte_rate >> 24) & 0xff;
	// BlockAlign
	unsigned block_align = (num_channels * bits_per_sample) / 8;
	wav_header[32] = block_align & 0xff;
	wav_header[33] = (block_align >> 8) & 0xff;
	// BitsPerSample
	wav_header[34] = bits_per_sample;
	wav_header[35] = 0;

	if (fwrite(wav_header, 1, sizeof(wav_header), out) < 44) {
		perror("Failed to write WAV header");
		exit(EXIT_FAILURE);
	}

	// Data
	unsigned count = 0;
	int c;
	while ((c = fgetc(in)) != EOF) {
		int i;
		for (i = 0; i < 8; i++) {
			int bit = c & 1;
			unsigned length = wave_len[bit];
			if (fwrite(wave_data[bit], 1, length, out) < length) {
				perror("Short write on output file");
				exit(EXIT_FAILURE);
			}
			count += length;
			c >>= 1;
		}
	}

	// rewrite Subchunk2Size
	fseek(out, 40L, SEEK_SET);
	fputc(count & 0xff, out);
	fputc((count >> 8) & 0xff, out);
	fputc((count >> 16) & 0xff, out);
	fputc((count >> 24) & 0xff, out);
	// rewrite ChunkSize
	count += 36;
	fseek(out, 4L, SEEK_SET);
	fputc(count & 0xff, out);
	fputc((count >> 8) & 0xff, out);
	fputc((count >> 16) & 0xff, out);
	fputc((count >> 24) & 0xff, out);

	fclose(out);
	fclose(in);
	return EXIT_SUCCESS;
}
