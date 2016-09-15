
#include <stdio.h>
#include <dskcon.h>
#include <string.h>
#include <stdlib.h>
#include <equates.h>

typedef struct {
    int drv, trk, sec, pos, mod;
    char buf[256];
    void* next;
} sector_t;

int sector_seek(sector_t* sect, int drv, int trk, int sec)
{
    sect->drv = drv;
    sect->trk = trk;
    sect->sec = sec;
    sect->pos = sect->mod = 0;
    return dskcon(DCOPC_READ, drv, trk, sec, sect->buf);
}

int sector_next(sector_t* sect)
{
    return sector_seek(sect, sect->drv, sect->trk, sect->sec + 1);
}

sector_t* sector_open(int drv, int trk, int sec, void* next)
{
    sector_t* sect = (sector_t*)calloc(sizeof(sector_t), 1);
    sect->next = next ? next : sector_next;
    sector_seek(sect, drv, trk, sec);
    return sect;
}

void sector_read(sector_t* sect, void* buf, size_t size)
{
    if (buf && size) {
        do {
            if (sect->pos >= 256) {
                sect->next(sect);
            }
            size_t n = 256 - sect->pos;
            if (size < n) {
                n = size;
            }
            memcpy(buf, sect->buf + sect->pos, n);
            sect->pos += n;
            size -= n;
            buf += n;
        } while (size > 0);
    }
}

void sector_close(sector_t* sect)
{
    free(sect);
}

typedef struct {
    char name[8];
    char ext[3];
    unsigned char type, flag, granule, lastsize;
    char reserved[17];
} dskcon_filename_t;

struct dirent {
    char d_name[9];
    char d_type;
};

typedef struct {
    struct dirent dirent;
    sector_t* sector;
} DIR;

DIR* opendir(char* name)
{
    DIR* dir = (DIR*)calloc(sizeof(DIR), 1);
    dir->sector = sector_open(0, 17, 3, 0);
    return dir;
}

int closedir(DIR* dir)
{
    sector_close(dir->sector);
    free(dir);
    return 0;
}

struct dirent* readdir(DIR* dir)
{
    if (dir->sector) {
        dskcon_filename_t fn;
        do {
            sector_read(dir->sector, &fn, sizeof(fn));
        } while (fn.name[0] == 0);
        if (fn.name[0] == 255) {
            sector_close(dir->sector);
            dir->sector = nullptr;
        } else {
            dir->dirent.d_name[8] = 0;
            *(char*)memccpy(dir->dirent.d_name, fn.name, ' ', 8) = 0;
            return &dir->dirent;
        }
    }
    return nullptr;
}

void showdir(int drive)
{
    sector_t* sect = sector_open(0, 17, 3, 0);
    if (sect) {
        dskcon_filename_t ent;
        do {
            sector_read(sect, &ent, sizeof(ent));
            if (ent.name[0] > 0) {
                fwrite(ent.name, 7, 1, stdout);
                fwrite(ent.ext, 3, 1, stdout);
                fputc('\n', stdout);
            }
        } while (ent.name[0] != -1);
        sector_close(sect);
    }
}

int main(void)
{
    puts("DSKCON EXAMPLE");

    DIR* dir = opendir("*,0");
    if (dir) {
        struct dirent* dirent;
        while (dirent = readdir(dir)) {
            puts(dirent->d_name);
        }
        closedir(dir);
    }
    showdir(0);
    return 0;
}

