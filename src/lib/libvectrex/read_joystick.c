
#include <vectrex.h>

// Read the joystick positions. This is an expensive call, as the Vectrex makes use of measring time over
// an RC network to do AD conversion for the joystick positions. For the moment, only digital positions are
// measured with this routine.
// You can use this routine as follows:
// uint8_t joystick = read_joystick(1);
// if ( joystick & JOY_UP_MASK) {
//   do joystick up stuff
//   ...
// }
uint8_t read_joystick(uint8_t joystick)
{
    uint8_t result;
    asm {
        PSHS    X, DP
        JSR     DP_to_D0
        LDA     :joystick                       // Which joystick?
        CMPA    #$02
        BEQ     read_joystick_2

        read_joystick_1:
        LDA     #1                              // Joystick 1 set up
        STA     Vec_Joy_Mux_1_X
        LDA     #3
        STA     Vec_Joy_Mux_1_Y
        LDA     #0                              // No Joystick 2 - saves a lot of cycles
        STA     Vec_Joy_Mux_2_X
        STA     Vec_Joy_Mux_2_Y

        JSR     Joy_Digital                     // Read joystick

        LDB     #$00                            // Clear direction mask

        LDA     Vec_Joy_1_X                     // Check X direction
        BSR     read_joystick_check_x
        LDA     Vec_Joy_1_Y                     // Check Y direction
        BSR     read_joystick_check_y

        BRA     read_joystick_end

        read_joystick_2:
        LDA     #0                              // No Joystick 1 - saves a lot of cycles
        STA     Vec_Joy_Mux_1_X
        STA     Vec_Joy_Mux_1_Y
        LDA     #5                              // Joystick 2 set up
        STA     Vec_Joy_Mux_2_X
        LDA     #7
        STA     Vec_Joy_Mux_2_Y

        JSR     Joy_Digital                     // Read joystick

        LDB     #$00                            // Clear direction mask

        LDA     Vec_Joy_2_X                     // Check X direction
        BSR     read_joystick_check_x
        LDA     Vec_Joy_2_Y                     // Check Y direction
        BSR     read_joystick_check_y

        BRA     read_joystick_end

        read_joystick_check_x:
        CMPA    #0
        BEQ     read_joystick_x_done
        BMI     read_joystick_left
        ORB     #JOY_RIGHT_MASK_ASM
        BRA     read_joystick_x_done
        read_joystick_left:
        ORB     #JOY_LEFT_MASK_ASM
        read_joystick_x_done:
        RTS

        read_joystick_check_y:
        CMPA    #0
        BEQ     read_joystick_y_done
        BMI     read_joystick_down
        ORB     #JOY_UP_MASK_ASM
        BRA     read_joystick_y_done
        read_joystick_down:
        ORB     #JOY_DOWN_MASK_ASM
        read_joystick_y_done:
        RTS

        read_joystick_end:
        STB     result
        PULS    X, DP
    }
    return result;
}

