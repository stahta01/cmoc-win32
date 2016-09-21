
// This is work in progress.
// Im making a virtual disk drive for the upper 32k (under ROM)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <basic.h>

#define SECTOR_USED     1
#define SECTOR_DIRTY    2

#define SECT_MAX 254
#define SECT_SIZE 254
#define SECT_LINK 255

typedef struct {
    byte flag[256];
    byte link[256];
    byte size[256];
    byte sect[10][256];
} vdos_t;

vdos_t* dos;

typedef struct {
    char name[32];
    word size;
    byte flags;
    byte sid;
} vname_t;

typedef struct {
    byte top, sid, pos;
    word tell;
} vfile_t;

void vformat(void)
{
    memset(dos->flag, 0, 256);
    memset(dos->link, 0, 256);
    memset(dos->size, 0, 256);
    dos->flag[0] |= SECTOR_USED;
}

byte vsectalloc(void)
{
    for (byte sid = 0; sid <= 255; sid++) {
        if (!(dos->flag[sid] & SECTOR_USED)) {
            dos->flag[sid] |= SECTOR_USED;
            dos->sect[sid][SECT_SIZE] = dos->sect[sid][SECT_LINK] = 0;
            return sid;
        }
    }
    return 0;
}

void vsectfree(byte sid)
{
    while (sid) {
        dos->flag[sid] &= SECTOR_USED ^ -1;
        sid = dos->sect[sid][SECT_LINK];
    }
}

void vopen(vfile_t* file, byte sid)
{
    file->top = sid;
    file->sid = sid;
    file->tell = file->pos = 0;
}

void vrewind(vfile_t* file)
{
    file->sid = file->top;
    file->tell = file->pos = 0;
}

word vtell(vfile_t* file)
{
    return file->tell;
}

byte vnextsect(vfile_t* file)
{
    byte sid = dos->sect[file->sid][SECT_LINK];
    if (sid) {
        file->sid = sid;
        file->pos = 0;
    }
    return sid;
}

byte vnextsize(vfile_t* file, word len)
{
    byte size = dos->sect[file->sid][SECT_SIZE] - file->pos;
    if (!size && vnextsect(file)) {
        size = dos->sect[file->sid][SECT_SIZE] - file->pos;
    }
    if (size > len) {
        size = (byte)len;
    }
    return size;
}

void vwrite(vfile_t* file, void* data, word len)
{
    while (len > 0) {
        if (file->pos >= SECT_MAX) {
            if (!dos->sect[file->sid][SECT_LINK]) {
                dos->sect[file->sid][SECT_LINK] = vsectalloc();
            }
            vnextsect(file);
        }
        byte size = SECT_MAX - file->pos;
        if (size > len) {
            size = (byte)len;
        }
        memcpy(&dos->sect[file->sid][file->pos], data, size);
        file->pos += size;
        file->tell += size;
        if (file->pos > dos->sect[file->sid][SECT_SIZE]) {
            dos->sect[file->sid][SECT_SIZE] = file->pos;
        }
        data += size;
        len -= size;
    }
}

byte vseekpos(vfile_t* file, word pos)
{
    vrewind(file);
    for (byte size = vnextsize(file, pos); size; size = vnextsize(file, pos)) {
        file->pos += size;
        file->tell += size;
        pos -= size;
    }
    return pos ? 0 : 1;
}

void vseekend(vfile_t* file)
{
    for (byte size = vnextsize(file, 0xFFFF); size; size = vnextsize(file, 0xFFFF)) {
        file->pos += size;
        file->tell += size;
    }
}

word vread(vfile_t* file, void* data, word len)
{
    void* start = data;
    for (byte size = vnextsize(file, len); size; size = vnextsize(file, len)) {
        memcpy(data, &dos->sect[file->sid][file->pos], size);
        file->pos += size;
        file->tell += size;
        data += size;
        len -= size;
    }
    return data - start;
}

int vfind(char* name, vname_t* ent)
{
    vfile_t file;
    vopen(&file, 0);
    while (vread(&file, ent, sizeof(vname_t))) {
        if (!strcmp(name, ent->name)) {
            return 1;
        }
    }
    return 0;
}

void vdirectory(void)
{
    vname_t ent;
    vfile_t file;
    vopen(&file, 0);
    while (vread(&file, &ent, sizeof(vname_t))) {
        printf("%s ", ent.name);
    }
}

void WriteSomeNames(void)
{
    vfile_t file;
    vname_t ent;
    vopen(&file, 0);
    printf("NAME SIZE\n");
    for (int i = 0; i < 20; i++) {
        sprintf(ent.name, "NAME%d", i);
        ent.size = i * 10;
        vwrite(&file, &ent, sizeof(ent));
    }
    vrewind(&file);
    for (int i = 0; i < 2; i++) {
        vread(&file, &ent, sizeof(ent));
        sprintf(ent.name, "NEW%d", i);
        ent.size = i * 10;
        vwrite(&file, &ent, sizeof(ent));
    }
}

vdos_t mydos;

int main(void)
{
    char s[10];
    vfile_t file;

    dos = &mydos;

    vformat();
    WriteSomeNames();
    vdirectory();

    DIR(0);

    puts("DONE");

    return 0;
}

