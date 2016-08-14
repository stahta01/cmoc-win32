
#include <coco.h>

byte isCoCo3 = FALSE;
byte textScreenWidth  = 32;
byte textScreenHeight = 16;

byte curDriveNo = 0;
byte* fatBuffer = 0;  // will point to an array of MAX_NUM_GRANULES entries
byte fatUpToDate = FALSE;  // when TRUE, fatBuffer[] does not need to be reloaded


