
#include "_fat.h"

fat_t* fat_get(int drv)
{
    return drv >= DRIVE_MIN && drv <= DRIVE_MAX ? &((fat_t*)_FATBL0)[drv] : (fat_t*)nullptr;
}

