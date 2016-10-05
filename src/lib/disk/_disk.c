
#include "_disk.h"

byte curDriveNo = 0;
byte* fatBuffer = 0;  // will point to an array of MAX_NUM_GRANULES entries
byte fatUpToDate = FALSE;  // when TRUE, fatBuffer[] does not need to be reloaded

