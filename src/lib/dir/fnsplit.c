
#include "_dir.h"

int fnsplit(char* path, char* drive, char* dir, char* name, char* ext)
{
    int result = FILENAME;
    char* s = strchr(path, ':') + 1;
    if (s > 1) {
        result |= DRIVE;
        if (drive) {
            memcpy(drive, path, s - path);
            drive[s - path] = 0;
        }
        path = s;
    } else {
        if (drive) {
            *drive = 0;
        }
    }
    s = strrchr(path, '/') + 1;
    if (s > 1) {
        result |= DIRECTORY;
        if (dir) {
            memcpy(dir, path, s - path);
            dir[s - path] = 0;
        }
        path = s;
    } else {
        if (dir) {
            *dir = 0;
        }
    }
    s = strrchr(path, '.');
    if (s) {
        result |= EXTENSION;
        if (ext) {
            strcpy(ext, s);
        }
        if (name) {
            memcpy(name, path, s - path);
            name[s - path] = 0;
        }
    } else {
        if (ext) {
            *ext = 0;
        }
        if (name) {
            strcpy(name, path);
        }
    }
    return result;
}

