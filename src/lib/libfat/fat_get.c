
#include "_fat.h"

fat_t* fat_get(int drive)
{
    return drive >= DRIVE_MIN && drive <= DRIVE_MAX ? &((fat_t*)_FATBL0)[drive] : (fat_t*)nullptr;
}

