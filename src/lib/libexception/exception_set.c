
#include "_exception.h"

// We hook into RVEC 17, but this may change. I need
// todo more research.

#define RVEC_INDEX 17

exception_t* _exception;

void _static_error_driver(void)
{
    word code;
    asm {
        clra
        std     code
    }
    _exception->code = code;
    longjmp(&_exception->jmp, -1);
}

int exception_set(exception_t* exception)
{
    int result = setjmp(&exception->jmp);
    if (result) {
        _rvecs[17] = exception->rvec;
        _exception = exception->prev;
    } else {
        exception->prev = _exception;
        exception->rvec = _rvecs[RVEC_INDEX];
        exception->code = 0;
        exception->what = nullptr;
        _exception = exception;
        _rvecs[RVEC_INDEX].inst = 0x7e;
        _rvecs[RVEC_INDEX].addr = _static_error_driver;
    }
    return result;
}

