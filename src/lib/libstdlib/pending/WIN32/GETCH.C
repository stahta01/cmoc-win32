/*---------------------------------------------------------------------------*/
/* getch() - get a character from the console without echo                   */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <win32.h>
#include <stdio.h>

#define VIRT_KEY_ALT       18
#define VIRT_KEY_ARROW_UP  72
#define VIRT_KEY_ARROW_DN  80
#define VIRT_KEY_ARROW_RT  77
#define VIRT_KEY_ARROW_LF  75
#define VIRT_KEY_CAPS      20
#define VIRT_KEY_CTRL      17
#define VIRT_KEY_DELETE    83
#define VIRT_KEY_END       79
#define VIRT_KEY_F1        59
#define VIRT_KEY_F10       68
#define VIRT_KEY_F11       87
#define VIRT_KEY_F12       88
#define VIRT_KEY_HOME      71
#define VIRT_KEY_INSERT    82
#define VIRT_KEY_NUMLOCK  144
#define VIRT_KEY_PGUP      73
#define VIRT_KEY_PGDN      81
#define VIRT_KEY_SCRLOCK  145
#define VIRT_KEY_SHIFT     16

#define EXTENDED_KEY      0xffffffe0

#define F11_NORMAL        0xffffff85
#define F11_SHIFT         0xffffff87
#define F11_CTRL          0xffffff89
#define F11_ALT           0xffffff8b

#define F12_NORMAL        0xffffff86
#define F12_SHIFT         0xffffff88
#define F12_CTRL          0xffffff8a
#define F12_ALT           0xffffff8c

#define FKEY_ALT_BIAS     45
#define FKEY_CTRL_BIAS    35
#define FKEY_SHIFT_BIAS   25

#define INS_EXT_ALT       0xffffffa2
#define INS_EXT_CTRL      0xffffff92

#define HOME_EXT_ALT      0xffffff97
#define HOME_EXT_CTRL     0x77

#define PGUP_EXT_ALT      0xffffff99
#define PGUP_EXT_CTRL     0xffffff86
#define PGUP_CTRL         0xffffff84

#define DELETE_EXT_ALT    0xffffffa3
#define DELETE_EXT_CTRL   0xffffff93

#define END_EXT_ALT       0xffffff9f
#define END_EXT_CTRL      0x75

#define PGDN_EXT_ALT      0xffffffa1
#define PGDN_EXT_CTRL     0x76

#define ARROW_UP_EXT_ALT  0xffffff98
#define ARROW_UP_EXT_CTRL 0xffffff8d

#define ARROW_DN_EXT_ALT  0xffffffa0
#define ARROW_DN_EXT_CTRL 0xffffff91

#define ARROW_RT_EXT_ALT  0xffffff9d
#define ARROW_RT_EXT_CTRL 0x74

#define ARROW_LF_EXT_ALT  0xffffff9b
#define ARROW_LF_EXT_CTRL 0x73

int getch(void)
{
  int c;
  int AltState;
  int CtrlState;
  int ShiftState;

  HANDLE hStdin;
  INPUT_RECORD irInBuf[1];
  DWORD cNumRead = 0;

  hStdin = GetStdHandle(STD_INPUT_HANDLE);

  if(_crt_base->_crt_getchbuf)
  {
    c = _crt_base->_crt_getchbuf;
    _crt_base->_crt_getchbuf = 0;
  } else {
    for(;;)
    {
      WaitForSingleObject(hStdin, INFINITE);

      ReadConsoleInputA(hStdin,
                        irInBuf,
                        1,
                        &cNumRead);

      if(cNumRead &&
        (irInBuf[0].EventType == KEY_EVENT) &&
        (irInBuf[0].Event.KeyEvent.wVirtualKeyCode != VIRT_KEY_SHIFT) &&
        (irInBuf[0].Event.KeyEvent.wVirtualKeyCode != VIRT_KEY_CTRL) &&
        (irInBuf[0].Event.KeyEvent.wVirtualKeyCode != VIRT_KEY_ALT) &&
        (irInBuf[0].Event.KeyEvent.wVirtualKeyCode != VIRT_KEY_CAPS) &&
        (irInBuf[0].Event.KeyEvent.wVirtualKeyCode != VIRT_KEY_NUMLOCK) &&
        (irInBuf[0].Event.KeyEvent.wVirtualKeyCode != VIRT_KEY_SCRLOCK))
      {
        if(irInBuf[0].Event.KeyEvent.bKeyDown)
        {
          c = irInBuf[0].Event.KeyEvent.AsciiChar;
          if(c == 0)
          {
            _crt_base->_crt_getchbuf =
                irInBuf[0].Event.KeyEvent.wVirtualScanCode;

            AltState = (irInBuf[0].Event.KeyEvent.dwControlKeyState &
                          RIGHT_ALT_PRESSED) |
                       (irInBuf[0].Event.KeyEvent.dwControlKeyState &
                          LEFT_ALT_PRESSED);

            CtrlState = (irInBuf[0].Event.KeyEvent.dwControlKeyState &
                           RIGHT_CTRL_PRESSED) |
                        (irInBuf[0].Event.KeyEvent.dwControlKeyState &
                           LEFT_CTRL_PRESSED);

            ShiftState = irInBuf[0].Event.KeyEvent.dwControlKeyState &
                           SHIFT_PRESSED;

            if(_crt_base->_crt_getchbuf >= VIRT_KEY_F1 &&
               _crt_base->_crt_getchbuf <= VIRT_KEY_F10)
            {
              if(AltState)
              {
                 _crt_base->_crt_getchbuf += FKEY_ALT_BIAS;
              } else if(CtrlState) {
                 _crt_base->_crt_getchbuf += FKEY_CTRL_BIAS;
              } else if(ShiftState) {
                 _crt_base->_crt_getchbuf += FKEY_SHIFT_BIAS;
              }

            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_F11) {
              c = EXTENDED_KEY;
              if(AltState)
              {
                 _crt_base->_crt_getchbuf = F11_ALT;
              } else if(CtrlState) {
                 _crt_base->_crt_getchbuf = F11_CTRL;
              } else if(ShiftState) {
                 _crt_base->_crt_getchbuf = F11_SHIFT;
              } else {
                 _crt_base->_crt_getchbuf = F11_NORMAL;
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_F12) {
              c = EXTENDED_KEY;
              if(AltState)
              {
                 _crt_base->_crt_getchbuf = F12_ALT;
              } else if(CtrlState) {
                 _crt_base->_crt_getchbuf = F12_CTRL;
              } else if(ShiftState) {
                 _crt_base->_crt_getchbuf = F12_SHIFT;
              } else {
                 _crt_base->_crt_getchbuf = F12_NORMAL;
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_INSERT) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = INS_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = INS_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = INS_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_HOME) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = HOME_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = HOME_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = HOME_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_PGUP) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = PGUP_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = PGUP_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = PGUP_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_DELETE) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = DELETE_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = DELETE_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = DELETE_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_END) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = END_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = END_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = END_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_PGDN) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = PGDN_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = PGDN_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = PGDN_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_ARROW_UP) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = ARROW_UP_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = ARROW_UP_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = ARROW_UP_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_ARROW_DN) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = ARROW_DN_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = ARROW_DN_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = ARROW_DN_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_ARROW_RT) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = ARROW_RT_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = ARROW_RT_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = ARROW_RT_EXT_CTRL;
                }
              }
            } else if(_crt_base->_crt_getchbuf == VIRT_KEY_ARROW_LF) {
              if(irInBuf[0].Event.KeyEvent.dwControlKeyState & ENHANCED_KEY)
              {
                c = EXTENDED_KEY;
                if(AltState)
                {
                   c = 0;
                   _crt_base->_crt_getchbuf = ARROW_LF_EXT_ALT;
                } else if(CtrlState) {
                   _crt_base->_crt_getchbuf = ARROW_LF_EXT_CTRL;
                }
              } else {
                if(CtrlState)
                {
                   _crt_base->_crt_getchbuf = ARROW_LF_EXT_CTRL;
                }
              }
            }
          }
          break;
        }
      }
    }
  }
  return(c);
}
