
#include <stdio.h>
#include <dskcon.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <dir.h>
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

void dskcon_dirent_get(dskcon_dirent_t* dirent, char* fn)
{
    char* pos = fn, *end;
    end = (char*)memccpy(pos, dirent->name, ' ', 8);
    end = end ? end - 1 : pos + 8;
    *end++ = '.';
    pos = end;
    end = (char*)memccpy(pos, dirent->ext, ' ', 3);
    end = end ? end - 1 : pos + 3;
    *end = 0;
}

typedef struct {
    struct dirent dirent;
    sector_t* sector;
} DIR;

DIR* opendir(char* fn)
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
        dskcon_dirent_t dskcon_dirent;
        do {
            sector_read(dir->sector, &dskcon_dirent, sizeof(dskcon_dirent));
        } while (dskcon_dirent.name[0] == 0);
        if (dskcon_dirent.name[0] == 255) {
            sector_close(dir->sector);
            dir->sector = nullptr;
        } else {
            dskcon_dirent_get(&dskcon_dirent, dir->dirent.d_name);
            return &dir->dirent;
        }
    }
    return nullptr;
}

int main(void)
{
    puts("DSKCON EXAMPLE");

    DIR* dir = opendir("*,0");
    if (dir) {
        struct dirent* dirent;
        while (dirent = readdir(dir)) {
            printf("%-16s", dirent->d_name);
        }
        closedir(dir);
    }
    return 0;
}

