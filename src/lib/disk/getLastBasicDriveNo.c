
#include "_disk.h"

byte _getLastBasicDriveNo()
{
#ifdef _COCO_BASIC_
    return * (byte*) 0xEB;
#else
    return 0;
#endif
}


