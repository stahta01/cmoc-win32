
#include "_stdio.h"

FILE* fopen(char* name, char* m)
{
    FILE* fp = NULL;
    if (m[0] == 'r' || m[0] == 'w') {
        char devnum;
        if (m[1] == 'c') {
            devnum = -1;
        } else if (m[1] == 'p') {
            devnum = -2;
        } else {
            for (devnum = _fcbact; devnum > 0; devnum--) {
                unsigned char* fcb = (unsigned char*)((unsigned*)_FCBV1)[devnum - 1];
                if (!fcb[_FCBTYP]) {
                    break;
                }
            }
        }
        if (devnum) {
            systemf("OPEN \"%c\",#%d,\"%s\"", m[0] == 'r' ? 'I' : 'O', devnum, name);
            fp = (FILE*)calloc(sizeof(FILE), 1);
            fp->devnum = devnum;
            if (m[0] == 'r') {
                fgetc(fp);
            }
        }
    }
    return fp;
}

