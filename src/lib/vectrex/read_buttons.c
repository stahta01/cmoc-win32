
#include <vectrex.h>

// Read the joystick buttons.
// uint8_t buttons = read_buttons();
// if (buttons & JOY1_BTN1_MASK) {
//   do stuff when joystick one button one is pressed
//   ...
// }
uint8_t vectrex_read_buttons()
{
    uint8_t buttons;
    asm {
        JSR DP_to_D0
        JSR Read_Btns
        STA buttons
    }
    return buttons;
}

