
#include "_exception.h"

try_block_t* current_try_block;

void _static_error_driver(void)
{
    errno_t error;
    asm {
        clra
        std     :error
    }
    current_try_block->exception.errno = error;
    current_try_block->exception.line = _curlin;
    longjmp(&current_try_block->jump, true);
}

void try_block_done(try_block_t* try_block)
{
    _current_exception = try_block->exception;
    _rvecs[17] = try_block->rvec;
    current_try_block = try_block->prev;
}

bool try_block_init(try_block_t* try_block, int jmp_return)
{
    if (jmp_return) {
        try_block_done(try_block);
    } else {
        try_block->prev = current_try_block;
        try_block->rvec = _rvecs[17];
        try_block->exception.errno = ERRNO_NONE;
        try_block->exception.line = 0;
        current_try_block = try_block;
        _rvecs[17].inst = 0x7e;
        _rvecs[17].addr = _static_error_driver;
    }
    return !jmp_return;
}

