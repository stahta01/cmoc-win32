/*---------------------------------------------------------------------------*/
/* write() - write data to a file                                            */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <io.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int write(int handle, void *buffer, unsigned int count)
{
  int rc = 0;
  USIZE bytes;
  USIZE wbytes = 0;
  int crlf = _CRLF_;
  int ccount = count;
  int lbytes = count;
  long fpos;
  char *p = (char *)buffer;
  if(handle < _crt_base->_crt_openmax)
  {
    handle = *(_crt_base->_htab_base + handle) - 1;
    if(handle != -1)
    {
      if((*(_crt_base->_crt_llioflg + handle)) & O_APPEND)
      {
        fpos = lseek(handle, 0L, SEEK_END);
        if(fpos == -1L)
        {
          rc = _crt_base->_crt_doserrno;
        }
      }
      if(!((*(_crt_base->_crt_llioflg + handle)) & O_BINARY))
      {
        while((!rc) && ccount)
        {
          if(*p == '\n')
          {
            #ifdef _WIN32
              rc = WriteFile(handle, buffer, wbytes, &bytes, NULL);
              if(rc)
              {
                rc = 0;
              } else {
                rc = (int)GetLastError();
              }
            #else
              rc = DosWrite(handle, buffer, wbytes, &bytes);
            #endif

            if(!rc)
            {
              #ifdef _WIN32
                rc = WriteFile(handle, &crlf, 2, &bytes, NULL);
                if(rc)
                {
                  rc = 0;
                } else {
                  rc = (int)GetLastError();
                }
              #else
                rc = DosWrite(handle, &crlf, 2, &bytes);
              #endif

              lbytes = ccount - 1;
              buffer = p + 1;
              wbytes = 0;
            } else {
              break;
            }
          } else if(*p == _EOF_) {
             #ifdef _WIN32
               rc = WriteFile(handle, buffer, wbytes + 1, &bytes, NULL);
               if(rc)
               {
                 rc = 0;
               } else {
                 rc = (int)GetLastError();
               }
             #else
               rc = DosWrite(handle, buffer, wbytes + 1, &bytes);
             #endif

             lbytes = 0;
             break;
          } else {
            wbytes++;
          }
          ccount--;
          p++;
        }
      }
    } else {
      rc = ERROR_INVALID_HANDLE;
    }
  } else {
    rc = ERROR_INVALID_HANDLE;
  }
  if ((!rc) && lbytes)
  {
    #ifdef _WIN32
      rc = WriteFile(handle, buffer, lbytes, &bytes, NULL);
      if(rc)
      {
        rc = 0;
      } else {
        rc = (int)GetLastError();
      }
    #else
      rc = DosWrite(handle, buffer, lbytes, &bytes);
    #endif
  }
  if(rc)
  {
    count = (unsigned int)-1;
    _crt_base->_crt_doserrno = rc;
    if(rc == ERROR_DISK_FULL)
    {
      _crt_base->_crt_errno = ENOSPC;
    } else {
      _crt_base->_crt_errno = EBADF;
    }
  }
  return(count);
}
