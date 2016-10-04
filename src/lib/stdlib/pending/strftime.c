/*---------------------------------------------------------------------------*/
/* strftime() - convert the time structure to a formatted string             */
/*---------------------------------------------------------------------------*/
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

size_t strftime(char *string, size_t smax, const char *fmt,
                const struct tm *tp)
{
  int fail = 0;
  int mcase = 0;
  int dcase = 0;
  int dtfmt = 0;
  int apfmt = 0;
  int cdtfmt = 0;
  size_t elen;
  size_t slen = 0;
  size_t dlen = 3;
  char tmsep = ':';
  char *fmtptr = (char *)fmt;

  char *ampm[] =  { "am", "pm" };

  if(smax > 0)
  {
    if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C)) {
      apfmt = 1;
    } else if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_FRANCE)) {
      dtfmt = 2;
      cdtfmt = 2;
      tmsep = '.';
    } else if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_GERMANY)) {
      dlen = 2;
      dtfmt = 3;
      cdtfmt = 3;
    } else if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_ITALY)) {
      mcase = 1;
      dcase = 1;
      dtfmt = 1;
      cdtfmt = 4;
    } else if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_SPAIN)) {
      mcase = 1;
      dcase = 1;
      dtfmt = 1;
      cdtfmt = 5;
    } else if(!strcmp(_crt_base->_crt_locale[LC_TIME], LC_C_UK)) {
      dtfmt = 1;
      cdtfmt = 1;
    } else {
      apfmt = 2;
    }
    while(*fmtptr && !fail)
    {
      if(*fmtptr == '%')
      {
        fmtptr++;
        switch(*fmtptr)
        {
          case 'a':
            if((slen + dlen) < smax)
            {
              strncpy(string, _crt_base->_crt_localday[tp->tm_wday], dlen);
              if(dcase) strupr(string);
              string += dlen;
              slen += dlen;
            } else {
              fail = 1;
            }
            break;

          case 'A':
            elen = strlen(_crt_base->_crt_localday[tp->tm_wday]);
            if((slen + elen) < smax)
            {
              strcpy(string, _crt_base->_crt_localday[tp->tm_wday]);
              string +=elen;
              slen += elen;
            } else {
              fail = 1;
            }
            break;

          case 'b':
            if((slen + 3) < smax)
            {
              strncpy(string, _crt_base->_crt_localmon[tp->tm_mon], 3);
              if(mcase) strupr(string);
              string += 3;
              slen += 3;
            } else {
              fail = 1;
            }
            break;

          case 'B':
            elen = strlen(_crt_base->_crt_localmon[tp->tm_mon]);
            if((slen + elen) < smax)
            {
              strcpy(string, _crt_base->_crt_localmon[tp->tm_mon]);
              string +=elen;
              slen += elen;
            } else {
              fail = 1;
            }
            break;

          case 'c':
            switch(cdtfmt)
            {
              case 1:
                if((slen + 17) < smax)
                {
                  sprintf(string,
                          "%.2d/%.2d/%.2d ",
                          tp->tm_mday,
                          tp->tm_mon + 1,
                          (tp->tm_year % 100));

                  string += 9;
                  slen += 9;
                } else {
                  fail = 1;
                }
                break;

              case 2:
                if((slen + 17) < smax)
                {
                  sprintf(string,
                          "%.2d-%.2d-%.2d ",
                          tp->tm_mday,
                          tp->tm_mon + 1,
                          (tp->tm_year % 100));

                  string += 9;
                  slen += 9;
                } else {
                  fail = 1;
                }
                break;

              case 3:
                if((slen + 19) < smax)
                {
                  sprintf(string,
                          "%.4d-%.2d-%.2d ",
                          tp->tm_year + 1900,
                          tp->tm_mon + 1,
                          tp->tm_mday);

                  string += 11;
                  slen += 11;
                } else {
                  fail = 1;
                }
                break;

              case 4:
                if((slen + 19) < smax)
                {
                  sprintf(string,
                          "%.2d/%.2d/%.4d ",
                          tp->tm_mday,
                          tp->tm_mon + 1,
                          tp->tm_year + 1900);

                  string += 11;
                  slen += 11;
                } else {
                  fail = 1;
                }
                break;

              case 5:
                if((slen + strlen(_crt_base->_crt_localmon[tp->tm_mon])+ 17)
                    < smax)
                {
                  sprintf(string,
                          "%.2d %s %.4d ",
                          tp->tm_mday,
                          _crt_base->_crt_localmon[tp->tm_mon],
                          tp->tm_year + 1900);

                  string += strlen(_crt_base->_crt_localmon[tp->tm_mon]) + 9;
                  slen += strlen(_crt_base->_crt_localmon[tp->tm_mon]) + 9;
                } else {
                  fail = 1;
                }
                break;

              default:
                if((slen + 17) < smax)
                {
                  sprintf(string,
                          "%.2d/%.2d/%.2d ",
                          (tp->tm_year % 100),
                          tp->tm_mon + 1,
                          tp->tm_mday);

                  string += 9;
                  slen += 9;
                } else {
                  fail = 1;
                }
                break;
            }

            if(apfmt)
            {
              sprintf(string,
                      "%.2d%c%.2d%c%.2d",
                      (tp->tm_hour % 12),
                      tmsep,
                      tp->tm_min,
                      tmsep,
                      tp->tm_sec);
            } else {
              sprintf(string,
                      "%.2d%c%.2d%c%.2d",
                      tp->tm_hour,
                      tmsep,
                      tp->tm_min,
                      tmsep,
                      tp->tm_sec);
            }
            string += 8;
            slen += 8;
            break;

          case 'd':

            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", tp->tm_mday);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'H':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", tp->tm_hour);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'I':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", (tp->tm_hour % 12));
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'j':
            if((slen + 3) < smax)
            {
              sprintf(string, "%.3d", tp->tm_yday + 1);
              string += 3;
              slen += 3;
            } else {
              fail = 1;
            }
            break;

          case 'm':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", tp->tm_mon + 1);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'M':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", tp->tm_min);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'p':
            if(apfmt)
            {
              if((slen + 2) < smax)
              {
                if(tp->tm_hour < 12)
                {
                  strcpy(string, ampm[0]);
                } else {
                  strcpy(string, ampm[1]);
                }
                if(apfmt == 2) strupr(string);
                string += 2;
                slen += 2;
              } else {
                fail = 1;
              }
            }
            break;

          case 'S':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", tp->tm_sec);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'U':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", ((tp->tm_yday + 1) / 7) + 1);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'w':
            if((slen + 1) < smax)
            {
              sprintf(string, "%.1d", tp->tm_wday);
              string += 1;
              slen += 1;
            } else {
              fail = 1;
            }
            break;

          case 'W':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", (tp->tm_yday / 7) + 1);
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'x':
            if(dtfmt != 3)
            {
              if((slen + 8) < smax)
              {
                switch(dtfmt)
                {
                  case 1:
                    sprintf(string,
                            "%.2d/%.2d/%.2d",
                            tp->tm_mday,
                            tp->tm_mon + 1,
                            tp->tm_year);
                    break;

                  case 2:
                    sprintf(string,
                            "%.2d.%.2d.%.2d",
                            tp->tm_mday,
                            tp->tm_mon + 1,
                            tp->tm_year);
                    break;


                  default:
                    sprintf(string,
                            "%.2d/%.2d/%.2d",
                            tp->tm_mon + 1,
                            tp->tm_mday,
                            tp->tm_year);
                    break;
                }
                string += 8;
                slen += 8;
              } else {
                fail = 1;
              }
            } else {

              if((slen + 10) < smax)
              {
                sprintf(string,
                        "%.2d.%.2d.%.4d",
                        tp->tm_mday,
                        tp->tm_mon + 1,
                        tp->tm_year + 1900);

                string += 10;
                slen += 10;
              } else {
                fail = 1;
              }
            }
            break;

          case 'X':
            if((slen + 8) < smax)
            {
              if(apfmt)
              {
                sprintf(string,
                        "%.2d%c%.2d%c%.2d",
                        (tp->tm_hour % 12),
                        tmsep,
                        tp->tm_min,
                        tmsep,
                        tp->tm_sec);
              } else {
                sprintf(string,
                        "%.2d%c%.2d%c%.2d",
                        tp->tm_hour,
                        tmsep,
                        tp->tm_min,
                        tmsep,
                        tp->tm_sec);
              }
              string += 8;
              slen += 8;
            } else {
              fail = 1;
            }
            break;

          case 'y':
            if((slen + 2) < smax)
            {
              sprintf(string, "%.2d", (tp->tm_year % 100));
              string += 2;
              slen += 2;
            } else {
              fail = 1;
            }
            break;

          case 'Y':
            if((slen + 4) < smax)
            {
              sprintf(string, "%4d", tp->tm_year + 1900);
              string += 4;
              slen += 4;
            } else {
              fail = 1;
            }
            break;

          case 'Z':
            if(strlen(_crt_base->_crt_tzname[0]) >= 3)
            {
              strncpy(string, _crt_base->_crt_tzname[0], 3);
              string += 3;
              slen += 3;
            }
            break;

          default:
            if(slen < smax)
            {
              *string++ = *fmtptr;
              slen++;
            } else {
              fail = 1;
            }
        }
        fmtptr++;

      } else {
        if(slen < smax)
        {
          *string++ = *fmtptr++;
          slen++;
        } else {
          fail = 1;
        }
      }
    }
    *string = '\0';
    if(fail) slen = 0;
  }
  return(slen);
}
