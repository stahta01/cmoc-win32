
#include <conio.h>
#include <string.h>
#include <equates.h>

#define isvidram() (_curpos < 0x600 && _curpos >= 0x400)
#define isgrpram() (_curpos < _endgrp && _curpos >= _beggrp)

