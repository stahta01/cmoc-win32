
#pragma target coco

#include <basic.h>
#include <unistd.h>
#include <math.h>

void ClearBoard(void)
{
    CLS(0);

    LLINE(1, 0, 1, 32, 5);
    LLINE(62, 0, 62, 32, 5);
    LLINE(1, 0, 62, 0, 5);

    for (int y = 2; y < 14; y += 2) {
        LLINE_B(2, y, 62, y + 2, (byte)(y >> 1) + 1);
    }
}

void PlayGame(void)
{
    int ball_x = _i2f(31), ball_xx = 150;
    int ball_y = _i2f(16), ball_yy = 150;
    byte ball_sx = (byte)_f2i(ball_x);
    byte ball_sy = (byte)_f2i(ball_y);

    byte paddle_x = 2, paddle_sx = 2;

    for (;;) {
        ball_x += ball_xx;
        ball_y += ball_yy;
        if (_f2i(ball_x) < 2 || _f2i(ball_x) > 61) {
            ball_x += ball_xx = -ball_xx;
            SOUND(100, 0);
        }
        if (_f2i(ball_y) < 14 || _f2i(ball_y) > 30) {
            ball_y += ball_yy = -ball_yy;
            SOUND(200, 0);
        }
        if (_f2i(ball_x) != ball_sx || _f2i(ball_y) != ball_sy) {
            SET(ball_sx, ball_sy, 0);
            ball_sx = (byte)_f2i(ball_x);
            ball_sy = (byte)_f2i(ball_y);
            SET(ball_sx, ball_sy, 5);
        }
        paddle_x = (byte)(((unsigned)JOYSTK(0) * 205) >> 8) + 2;
        LLINE(paddle_sx, 31, paddle_sx + 10, 31, paddle_x !=  paddle_sx ? 0 : 5);
        paddle_sx = (byte)paddle_x;
        LLINE(paddle_sx, 31, paddle_sx + 10, 31, 5);
    }
}

int main(void)
{
    ClearBoard();
    PlayGame();
    return 0;
}

