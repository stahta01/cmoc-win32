
#include "_stdio.h"

FILE* fopen(char* name, char* m)
{
    FILE* file = NULL;
    if (m[0] == 'r' || m[0] == 'w') {
        char devnum;
        for (devnum = _fcbact; devnum > 0; devnum--) {
            unsigned char* fcb = (unsigned char*)((unsigned*)_FCBV1)[devnum - 1];
            if (!fcb[_FCBTYP]) {
                break;
            }
        }
        if (devnum) {
            systemf("OPEN \"%c\",#%d,\"%s\"", m[0] == 'r' ? 'I' : 'O', devnum, name);
            file = (FILE*)calloc(sizeof(FILE), 1);
            file->devnum = devnum;
        }
    }
    return file;
}

