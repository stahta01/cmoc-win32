
#include <vectrex.h>

// Set the text width and height. Negative values are needed for the y coordinate.
// Otherwise text will be upside down.

void vectrex_set_text_size(int8_t height, int8_t width)
{
    asm {
        LDA     :width
        STA     Vec_Text_Width
        LDA     :height
        STA     Vec_Text_Height
    }
}

