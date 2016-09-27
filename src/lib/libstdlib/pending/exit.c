/*---------------------------------------------------------------------------*/
/* exit() - exit to the operating system                                     */
/*---------------------------------------------------------------------------*/
#include <crtdef.h>
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

typedef void (*PFV) (void);

void exit(int status)
{
	/* * *
	 *  fix: functions registered with atexit failed to execute when
	 *       program was terminated with a call to exit().  Moving the
	 *       code to unwind the function list from cstart to exit (below)
	 *       fixed the problem.  Note: closeall() also was moved to make
	 *       sure it was called last before ExitProcess().  - RCS
	 * * */
	unsigned long *exitptr;
	int index;

	if(_crt_base->_exit_list)
	{
		exitptr = (unsigned long *)(_crt_base->_exit_base);
		exitptr += (--_crt_base->_exit_list);
		for(index = _crt_base->_exit_list; index >= 0; index--)
		{
			((PFV)*exitptr)();
			exitptr--;
		}
	}
	fcloseall();
#ifdef _WIN32
    ExitProcess(status);
#else
    DosExit(1, status);
#endif
}
