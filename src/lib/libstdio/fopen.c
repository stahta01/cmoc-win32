
#include "_stdio.h"

FILE* fopen(char* name, char* m)
{
    FILE* fp = NULL;
    if (m[0] == 'r' || m[0] == 'w') {
        char devnum;
        if (name[0] == 'C' && name[1] == 'O' && name[2] == 'N' && name[3] == ':') {
            devnum = 0;
            name += 4;
        }  else if (name[0] == 'C' && name[1] == 'A' && name[2] == 'S' && name[3] == ':') {
            devnum = -1;
            name += 4;
        }  else if (name[0] == 'P' && name[1] == 'R' && name[2] == 'T' && name[3] == ':') {
            devnum = -2;
            name += 4;
        } else {
            for (devnum = _fcbact; devnum > 0; devnum--) {
                unsigned char* fcb = (unsigned char*)((unsigned*)_FCBV1)[devnum - 1];
                if (!fcb[_FCBTYP]) {
                    break;
                }
            }
        }
        if (devnum) {
            systemf("OPEN\"%c\",#%d,\"%s\"", m[0] == 'r' ? 'I' : 'O', devnum, name);
            fp = (FILE*)calloc(sizeof(FILE), 1);
            fp->devnum = devnum;
            if (m[0] == 'r') {
                fgetc(fp);
            }
        }
    }
    return fp;
}

