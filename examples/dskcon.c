
#include <stdio.h>
#include <dskcon.h>
#include <string.h>
#include <stdlib.h>
#include <equates.h>

typedef struct {
    char name[8];
    char ext[3];
    unsigned char type, flag, granule, lastsize;
    char reserved[17];
} dskent_t;

struct dirent {
    char d_name[9];
    char d_type;
};

typedef struct {
    char drive, sector;
    struct dirent dirent;
    dskent_t names[8];
    char name;
} DIR;

DIR* opendir(char* name)
{
    DIR* dir = (DIR*)calloc(sizeof(DIR), 1);
    dir->drive = 0;
    dir->sector = 3;
    dskcon(DCOPC_READ, dir->drive, 17, dir->sector, dir->names);
    return dir;
}

int closedir(DIR* dir)
{
    free(dir);
    return 0;
}

typedef struct {
    int drv, trk, sec, pos;
    char buf[256];
} SECT;

SECT* sopen(int drv, int trk, int sec)
{
    SECT* sect = (SECT*)calloc(sizeof(SECT), 1);
    dskcon(DCOPC_READ, sect->drv = drv, sect->trk = trk, sect->sec = sec, sect->buf);
    return sect;
}

void sread(SECT* sect, void* buf, size_t size)
{
    do {
        if (sect->pos >= 256) {
            sect->pos = 0;
            sect->sec++;
            dskcon(DCOPC_READ, sect->drv, sect->trk, sect->sec, sect->buf);
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

void sclose(SECT* sect)
{
    free(sect);
}

struct dirent* readdir(DIR* dir)
{
    while (dir->names[dir->name].name[0] == 0) {
        dir->name++;
        if (dir->name == 8) {
            dir->name = 0;
            dir->sector++;
            dskcon(DCOPC_READ, dir->drive, 17, dir->sector, dir->names);
        }
    }
    if (dir->names[dir->name].name[0] == -1) {
        return 0;
    }
    struct dirent* dirent = &dir->dirent;
    *(char*)memccpy(dirent->d_name, dir->names[dir->name].name, ' ', 8) = 0;
    //*(char*)memccpy(dirent->d_name,dir->names[0].name, ' ', 8) = 0;
    return dirent;
}

void showdir(int drive)
{
    SECT* sect = sopen(0, 17, 3);
    if (sect) {
        dskent_t ent;
        do {
            sread(sect, &ent, sizeof(ent));
            if (ent.name[0] > 0) {
                fwrite(ent.name, 7, 1, stdout);
                fwrite(ent.ext, 3, 1, stdout);
                fputc('\n', stdout);
            }
        } while (ent.name[0] != -1);
        sclose(sect);
    }
}

int main(void)
{
    puts("DSKCON EXAMPLE");
    /*
    DIR* dir = opendir("*,0");
    if (dir) {
        struct dirent* dirent;
        while (dirent = readdir(dir)) {
            puts(dirent->d_name);
        }
        closedir(dir);
    }
    */
    showdir(0);
    return 0;
}

