/*---------------------------------------------------------------------------*/
/* _cinit() - initialize the C runtime environment                           */
/*---------------------------------------------------------------------------*/

#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <io.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <float.h>
#include <stdlib.h>
#include <locale.h>

int _cinit(void)
{
  FILE *fp;
  int rc = 0;
  struct DATETIME timebuf;
  unsigned long julian_days[12] = {  0,  31,  59,  90, 120, 151,
                                   181, 212, 243, 273, 304, 334 };

  _crt_base = calloc(sizeof(struct _crt_), 1);
  if(_crt_base != NULL)
  {
    _fpreset();

    #ifdef _WIN32
      GetLocalTime(&timebuf);
      timebuf.hundredths /= 10;
    #else
      DosGetDateTime(&timebuf);
    #endif

    _crt_base->_base_time = (timebuf.hours * 360000L) +
                            (timebuf.minutes * 6000L) +
                            (timebuf.seconds * 100L) +
                            timebuf.hundredths;

    _crt_base->_base_date = ((timebuf.year - 1970) * 365L) +
                            ((timebuf.year - 1970) / 4) +
                            julian_days[timebuf.month - 1] +
                            timebuf.day - 1;

    setlocale(LC_ALL, "C");

    _crt_base->_exit_list = 0;
    _crt_base->_rand_next = 1;
    _crt_base->_crt_nerr = _CRT_SYSERR_;
    _crt_errno = &(_crt_base->_crt_errno);

    _crt_base->_crt_syserrlist[EZERO]      = _CRT_EZERO_;
    _crt_base->_crt_syserrlist[EDOM]       = _CRT_EDOM_;
    _crt_base->_crt_syserrlist[ERANGE]     = _CRT_ERANGE_;
    _crt_base->_crt_syserrlist[EPERM]      = _CRT_EPERM_;
    _crt_base->_crt_syserrlist[ENOENT]     = _CRT_ENOENT_;
    _crt_base->_crt_syserrlist[ESRCH]      = _CRT_ESRCH_;
    _crt_base->_crt_syserrlist[EINTR]      = _CRT_EINTR_;
    _crt_base->_crt_syserrlist[EIO]        = _CRT_EIO_;
    _crt_base->_crt_syserrlist[ENXIO]      = _CRT_ENXIO_;
    _crt_base->_crt_syserrlist[E2BIG]      = _CRT_E2BIG_;
    _crt_base->_crt_syserrlist[ENOEXEC]    = _CRT_ENOEXEC_;
    _crt_base->_crt_syserrlist[EBADF]      = _CRT_EBADF_;
    _crt_base->_crt_syserrlist[ECHILD]     = _CRT_ECHILD_;
    _crt_base->_crt_syserrlist[EAGAIN]     = _CRT_EAGAIN_;
    _crt_base->_crt_syserrlist[ENOMEM]     = _CRT_ENOMEM_;
    _crt_base->_crt_syserrlist[EACCES]     = _CRT_EACCES_;
    _crt_base->_crt_syserrlist[EFAULT]     = _CRT_EFAULT_;
    _crt_base->_crt_syserrlist[ENOTBLK]    = _CRT_ENOTBLK_;
    _crt_base->_crt_syserrlist[EBUSY]      = _CRT_EBUSY_;
    _crt_base->_crt_syserrlist[EEXIST]     = _CRT_EEXIST_;
    _crt_base->_crt_syserrlist[EXDEV]      = _CRT_EXDEV_;
    _crt_base->_crt_syserrlist[ENODEV]     = _CRT_ENODEV_;
    _crt_base->_crt_syserrlist[ENOTDIR]    = _CRT_ENOTDIR_;
    _crt_base->_crt_syserrlist[EISDIR]     = _CRT_EISDIR_;
    _crt_base->_crt_syserrlist[EINVAL]     = _CRT_EINVAL_;
    _crt_base->_crt_syserrlist[ENFILE]     = _CRT_ENFILE_;
    _crt_base->_crt_syserrlist[EMFILE]     = _CRT_EMFILE_;
    _crt_base->_crt_syserrlist[ENOTTY]     = _CRT_ENOTTY_;
    _crt_base->_crt_syserrlist[ETXTBSY]    = _CRT_ETXTBSY_;
    _crt_base->_crt_syserrlist[EFBIG]      = _CRT_EFBIG_;
    _crt_base->_crt_syserrlist[ENOSPC]     = _CRT_ENOSPC_;
    _crt_base->_crt_syserrlist[ESPIPE]     = _CRT_ESPIPE_;
    _crt_base->_crt_syserrlist[EUCLEAN]    = _CRT_EUCLEAN_;
    _crt_base->_crt_syserrlist[EDEADLOCK]  = _CRT_EDEADLOCK_;
    _crt_base->_crt_syserrlist[ENOTEXIST]  = _CRT_ENOTEXIST_;
    _crt_base->_crt_syserrlist[EUNKNOWN]   = _CRT_EUNKNOWN_;

    _crt_base->_excp_base = calloc(sizeof(void *), _MAX_SIG_);
    _crt_base->_exit_base = calloc(sizeof(void *), _MAX_EXIT_);
    _crt_base->_htab_base = calloc(sizeof(int), _BASE_FILES_);
    _crt_base->_crt_llioflg = calloc(sizeof(int), _BASE_FILES_);
    _crt_base->_tmpnam_base = calloc(sizeof(char *), _BASE_FILES_);
    _crt_base->_asctim_ptr = calloc(_ASCTIME_BUFSZ_, 1);
    _crt_base->_tm_base = calloc(sizeof(struct tm), 1);

    if((_crt_base->_excp_base != NULL) &&
       (_crt_base->_exit_base != NULL) &&
       (_crt_base->_htab_base != NULL) &&
       (_crt_base->_crt_llioflg != NULL) &&
       (_crt_base->_tmpnam_base != NULL) &&
       (_crt_base->_asctim_ptr != NULL) &&
       (_crt_base->_tm_base != NULL))
    {
      _crt_base->_crt_openmax = _BASE_FILES_;
      _crt_base->_crt_bufsize = _BASE_BUFSZ_;
      _crt_base->_crt_fmode = O_TEXT;
      _crt_base->_io_base = calloc(_BASE_FILES_, sizeof(struct _iobuf));
      if(_crt_base->_io_base != NULL)
      {
        fp = stdin;
        fp->fd = _STDIN;
        fp->flag = _READ;
        *(_crt_base->_crt_llioflg + _STDIN)  = (_FOPN_ | O_TEXT);
        fp = stdout;
        fp->fd = _STDOUT;
        fp->flag = _WRITE | _UNBUF;
        *(_crt_base->_crt_llioflg + _STDOUT) = (_FOPN_ | O_TEXT);
        fp = stderr;
        fp->fd = _STDERR;
        fp->flag = _WRITE | _UNBUF;
        *(_crt_base->_crt_llioflg + _STDERR) = (_FOPN_ | O_TEXT);
        #ifdef _WIN32
          FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
          *(_crt_base->_htab_base + _STDIN) =
             GetStdHandle(STD_INPUT_HANDLE) + 1;
          *(_crt_base->_htab_base + _STDOUT) =
             GetStdHandle(STD_OUTPUT_HANDLE) + 1;
          *(_crt_base->_htab_base + _STDERR) =
            GetStdHandle(STD_ERROR_HANDLE) + 1;
        #else
          *(_crt_base->_htab_base + _STDIN) = _STDIN + 1;
          *(_crt_base->_htab_base + _STDOUT) = _STDOUT + 1;
          *(_crt_base->_htab_base + _STDERR) = _STDERR + 1;
          close(_STDAUX);
          close(_STDPRN);
        #endif
        _crt_base->_crt_errno = 0;
      } else {
        rc = ERROR_NOT_ENOUGH_MEMORY;
      }
    } else {
      rc = ERROR_NOT_ENOUGH_MEMORY;
    }
  } else {
    rc = ERROR_NOT_ENOUGH_MEMORY;
  }
  return(rc);
}
