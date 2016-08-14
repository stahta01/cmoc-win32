/*---------------------------------------------------------------------------*/
/* ctime() - convert the calendar time to local time                         */
/*---------------------------------------------------------------------------*/
#include <time.h>

char *ctime(const time_t *tp)
{
  return(asctime(localtime(tp)));
}
