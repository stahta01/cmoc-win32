
#include "_dir.h"

void fnmerge(char* path, char* drive, char* dir, char* name, char* ext)
{
    if (drive) {
        path = stpcpy(path, drive);
        if (path[-1] != ':') {
            *path++ = ':';
        }
    }
    if (dir) {
        path = stpcpy(path, dir);
        if (path[-1] != '/') {
            *path++ = '/';
        }
    }
    if (name) {
        path = stpcpy(path, name);
    }
    if (ext) {
        if (ext[0] != '.') {
            *path++ = '.';
        }
        path = stpcpy(path, ext);
    }
    *path = 0;
}

