
#include "_disk.h"

byte setDefaultDriveNo(byte no)
{
    if (no > 3) {
        return FALSE;
    }
    curDriveNo = no;
    return TRUE;
}


