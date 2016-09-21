
#include <stdio.h>
#include <stdlib.h>
#include <iff.h>

bool iff_chunk_is_type(iff_chunk_t* chunk, char* type)
{
    return
        (chunk->type[0] == type[0]) && (chunk->type[1] == type[1]) &&
        (chunk->type[2] == type[2]) && (chunk->type[3] == type[3]);
}

bool iff_chunk_read(iff_chunk_t* chunk, FILE* fp)
{
    return fread(chunk, sizeof(iff_chunk_t), 1, fp) == 1;
}

/*
    iff_form_t form;
    iff_chunk_t chunk;
    char buffer[3000];
    FILE* fp = fopen("Image1.iff", "rb");
    if (fp)
    {
        fread(&form, sizeof(form), 1, fp);

        for (;;) {
            iff_chunk_read(&chunk, fp);
            fread(buffer, chunk.size.lo, 1, fp);

            if (iff_chunk_is_type(&chunk, "BODY"))
            {
                ShowMessage(chunk.type);
                break;
            }
        }

        fclose(fp);
    }
    */

void test(FILE* fp)
{
    char buf[2000];
    iff_chunk_t chunk;
    iff_chunk_read(&chunk, fp);
    printf("%s %u\n", chunk.type, chunk.size.lo);
    printf("%d\n", fread(buf, 1, chunk.size.lo, fp));

}
int main(void)
{
    system("DRIVE1");

    char buf[4000];
    FILE* fp = fopen("IMAGE.IFF", "r");

    if (fp) {
        iff_chunk_t chunk;

        if (iff_chunk_read(&chunk, fp) && iff_chunk_is_type(&chunk, "FORM")) {
            fread(buf, 4, 1, fp);
            test(fp);
            test(fp);
            test(fp);
            //fread(buf, chunk.size.lo, 1, fp);
            //iff_chunk_read(&chunk, fp);
            //fputc(fgetc(fp), stdout);

            //fread(buf, chunk.size.lo, 1, fp);

            return 0;
            while (iff_chunk_read(&chunk, fp)) {
                printf("%s %u\n", chunk.type, chunk.size.lo);
                fread(buf, chunk.size.lo, 1, fp);
                if (iff_chunk_is_type(&chunk, "BODY")) {
                    puts("BODY FOUND");
                }
            }
        }
        fclose(fp);
    }
    return 0;
}

