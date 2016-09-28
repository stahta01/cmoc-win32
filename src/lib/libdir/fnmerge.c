
#include "_dir.h"

void fnmerge(char* path, char* drive, char* dir, char* name, char* ext)
{
    if (drive) {
        path = _stpcpy(path, drive);
        if (path[-1] != ':') {
            *path++ = ':';
        }
    }
    if (dir) {
        path = _stpcpy(path, dir);
        if (path[-1] != '/') {
            *path++ = '/';
        }
    }
    if (name) {
        path = _stpcpy(path, name);
    }
    if (ext) {
        if (ext[0] != '.') {
            *path++ = '.';
        }
        path = _stpcpy(path, ext);
    }
    *path = 0;
}

