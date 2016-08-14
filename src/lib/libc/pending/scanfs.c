/*---------------------------------------------------------------------------*/
/* _scanfs() - scan formatted data from a file or a string                   */
/*---------------------------------------------------------------------------*/

#include <float.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <llmath.h>

char *_getfs(FILE *fp, char *s, int *tc, int *c);
char *_ungetfs(FILE *fp, char *s, int *tc, int c);

int _scanfs(FILE *fp, const char *string, const char *format, va_list ap)
{
  int c, ct;
  int tc = 0;
  int num = 0;
  int scan = 1;
  int count, wid, uwid, assigned;
  int store, fstart, h_mod, l_mod, l_not;
  int fval, fdec, fexp, fprec, expon, esign;
  long lsign;
  unsigned long pval, ulval, ulcval;
  char fmt;
  char *p, *p1, *p2, *arg;
  char *s = (char *)string;
  double fnum, fsign, frac, fpower, fxpower;
  if(fp != NULL)
  {
    c = (char)fgetc(fp);
    if(c != EOF) ungetc(c, fp);
  } else {
    c = *string;
    if(c == '\0') c = EOF;
  }
  if(c == EOF)
  {
    num = EOF;
  } else {
    for(p = (char *)format; *p; p++)
    {
      assigned = 0;
      if(*p != '%')
      {
        if(scan)
        {
          s = _getfs(fp, s, &tc, &c);
          if(isspace(*p))
          {
            while(isspace(c))
            {
              s = _getfs(fp, s, &tc, &c);
            }
            s = _ungetfs(fp, s, &tc, c);
          } else if(c != *p) {
            s = _ungetfs(fp, s, &tc, c);
            scan = 0;
          }
        }
      } else {
        p++;
        wid = 0;
        uwid = 0;
        count = 0;
        fstart = 0;
        store = 1;
        lsign = 1;
        h_mod = 0;
        l_mod = 0;
        ulval = 0;
        fval = 0;
        fdec = 0;
        fexp = 0;
        frac = 0;
        fnum = 0;
        fsign = 1;
        fprec = 0;
        esign = 0;
        expon = 0;
        fpower = 1;
        fxpower = 1;
        if(*p == '*')
        {
          store = 0;
          p++;
        }
        while(isdigit(*p))
        {
          wid = (wid * 10) + (int)(*p - '0');
          uwid++;
          p++;
        }
        if(*p == 'h')
        {
          h_mod = 1;
          p++;
        } else if(*p == 'l') {
          l_mod = 1;
          p++;
        }
        fmt = *p;
        if(fmt == 'i')
        {
          fmt ='d';
          if(scan)
          {
            s = _getfs(fp, s, &tc, &c);
            while(isspace(c))
            {
              s = _getfs(fp, s, &tc, &c);
            }
            if(c == '0')
            {
              s = _getfs(fp, s, &tc, &c);
              if(c == 'x' || c == 'X')
              {
                fmt = 'x';
              } else {
                fmt ='o';
                if(c != EOF) s = _ungetfs(fp, s, &tc, c);
              }
            } else {
              if(c != EOF) s = _ungetfs(fp, s, &tc, c);
            }
          }
        }
        #ifdef API32
          if(fmt == 'p') fmt = 'x';
        #endif
        switch(fmt)
        {
          case 'c':
            if(store) arg = va_arg(ap, char *);
            if(scan)
            {
              if(!uwid) wid = 1;
              while(wid && c != EOF)
              {
                wid--;
                s = _getfs(fp, s, &tc, &c);
                if(store && c != EOF)
                {
                  *arg++ = (char)c;
                  assigned = 3;
                }
              }
            }
            break;

          case 'd':
          case 'u':
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  if(!isdigit(c))
                  {
                    if(isspace(c))
                    {
                      if(fstart)
                      {
                        s = _ungetfs(fp, s, &tc, c);
                        if(!assigned)
                        {
                          assigned = 2;
                          scan = 0;
                          break;
                        }
                        break;
                      } else {
                        wid--;
                      }
                    } else {
                      if(fstart)
                      {
                        s = _ungetfs(fp, s, &tc, c);
                        break;
                      } else {
                        if(c == '+')
                        {
                          wid--;
                          lsign = 1;
                          fstart = 1;
                        } else if(c == '-') {
                          wid--;
                          lsign = -1;
                          fstart = 1;
                        } else {
                          s = _ungetfs(fp, s, &tc, c);
                          assigned = 2;
                          scan = 0;
                          break;
                        }
                      }
                    }
                  } else {
                    if(store)
                    {
                      ulval = _mul32(ulval, 10L) + (unsigned long)(c - '0');
                      assigned = 1;
                    }
                    wid--;
                    fstart = 1;
                  }
                }
              }
            } else {
              assigned = 2;
            }
            break;

          case 'e':
          case 'f':
          case 'g':
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  if(!isdigit(c))
                  {
                    if(isspace(c))
                    {
                      if(fstart)
                      {
                        s = _ungetfs(fp, s, &tc, c);
                        if(!assigned)
                        {
                          assigned = 2;
                          scan = 0;
                          break;
                        }
                        break;
                      } else {
                        wid--;
                      }
                    } else {
                      if((c == '.') && !fdec)
                      {
                        wid--;
                        fdec = 1;
                        fstart = 1;
                      } else if(fstart) {
                        if((c == 'e' || c == 'E') && !fexp)
                        {
                          wid--;
                          fexp = 1;
                          while((!uwid || wid) && c != EOF)
                          {
                            s = _getfs(fp, s, &tc, &c);
                            if(c != EOF)
                            {
                              if(isdigit(c))
                              {
                                if(!esign) esign = 1;
                                if(expon < DBL_MAX_EXP)
                                  expon = (expon * 10) + (int)(c - '0');
                                wid--;
                              } else {
                                if((c == '-') && !esign)
                                {
                                  wid--;
                                  esign = -1;
                                } else if((c == '+') && !esign) {
                                  wid--;
                                  esign = 1;
                                } else {
                                  s = _ungetfs(fp, s, &tc, c);
                                  break;
                                }
                              }
                            }
                          }
                          while(expon > 100)
                          {
                            fxpower *= (double)1e100;
                            expon -= 100;
                          }
                          while(expon > 10)
                          {
                            fxpower *= (double)1e10;
                            expon -= 10;
                          }
                          while(expon)
                          {
                            fxpower *= (double)10;
                            expon --;
                          }
                          break;
                        } else {
                          s = _ungetfs(fp, s, &tc, c);
                          break;
                        }
                      } else {
                        if(c == '+')
                        {
                          wid--;
                          fsign = 1;
                          fstart = 1;
                        } else if(c == '-') {
                          wid--;
                          fsign = -1;
                          fstart = 1;
                        } else {
                          s = _ungetfs(fp, s, &tc, c);
                          assigned = 2;
                          scan = 0;
                          break;
                        }
                      }
                    }
                  } else {
                    if(store)
                    {
                      if(!fdec)
                      {
                        fnum = fnum * (double)10 + (double)(c - '0');
                        if(fnum > 0) fprec++;
                      } else {
                        if(fprec < 16)
                        {
                          fpower *= 10;
                          frac += ((double)(c - '0') / fpower);
                          fprec++;
                        }
                      }
                      fval = 1;
                      assigned = 1;
                    }
                    wid--;
                    fstart = 1;
                  }
                }
              }
            } else {
              assigned = 2;
            }
            break;

          case 'n':
            *va_arg(ap, int *) = tc;
            break;

          case 'o':
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  if(isdigit(c) && (c != '8') && (c != '9'))
                  {
                    if(store)
                    {
                      ulval = _mul32(ulval, 8L) + (unsigned long)(c - '0');
                      assigned = 1;
                    }
                    wid--;
                    fstart = 1;
                  } else if(isspace(c)) {
                    if(fstart)
                    {
                      s = _ungetfs(fp, s, &tc, c);
                      break;
                    } else {
                      wid--;
                    }
                  } else {
                    s = _ungetfs(fp, s, &tc, c);
                    if(!fstart)
                    {
                      scan = 0;
                      assigned = 2;
                    }
                    break;
                  }
                }
              }
            } else {
              assigned = 2;
            }
            break;

          case 'p':
            if(!h_mod) l_mod = 1;
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  if(isxdigit(c))
                  {
                    if(store)
                    {
                      if(isdigit(c)) {
                        ulcval = (c - '0');
                      } else if(isxlower(c)) {
                        ulcval = (c - 'a') + 10;
                      } else {
                        ulcval = (c - 'A') + 10;
                      }
                      ulval = _mul32(ulval, 16L) + ulcval;
                      assigned = 1;
                    }
                    wid--;
                    fstart = 1;
                  } else if(c == ':' && !count ) {
                    pval = _mul32(ulval, 65536L);
                    ulval = 0;
                    count++;
                  } else if(isspace(c)) {
                    if(fstart)
                    {
                      s = _ungetfs(fp, s, &tc, c);
                      break;
                    } else {
                      wid--;
                    }
                  } else {
                    s = _ungetfs(fp, s, &tc, c);
                    if(!fstart)
                    {
                      scan = 0;
                      assigned = 2;
                    }
                    break;
                  }
                }
              }
              if(assigned == 1 && count) ulval += pval;
            } else {
              assigned = 2;
            }
            break;

          case 's':
            if(store) arg = va_arg(ap, char *);
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  if(isspace(c))
                  {
                    if(fstart)
                    {
                      s = _ungetfs(fp, s, &tc, c);
                      break;
                    } else {
                      wid--;
                    }
                  } else {
                    if(store)
                    {
                      *arg++ = (char)c;
                      assigned = 3;
                    }
                    fstart = 1;
                    wid--;
                  }
                }
              }
              if(store && assigned) *arg = '\0';
            }
            break;

          case 'x':
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  if(count == 0 && c == '0')
                  {
                    wid--;
                    count++;
                  } else if(count == 1 && (c == 'x' || c == 'X')) {
                    wid--;
                    count++;
                  } else if(isxdigit(c)) {
                    count++;
                    if(store)
                    {
                      if(isdigit(c)) {
                        ulcval = (c - '0');
                      } else if(isxlower(c)) {
                        ulcval = (c - 'a') + 10;
                      } else {
                        ulcval = (c - 'A') + 10;
                      }
                      ulval = _mul32(ulval, 16L) + ulcval;
                      assigned = 1;
                    }
                    wid--;
                    count++;
                    fstart = 1;
                  } else if(isspace(c)) {
                    if(fstart)
                    {
                      s = _ungetfs(fp, s, &tc, c);
                      break;
                    } else {
                      wid--;
                    }
                  } else {
                    s = _ungetfs(fp, s, &tc, c);
                    if(!fstart)
                    {
                      scan = 0;
                      assigned = 2;
                    }
                    break;
                  }
                }
              }
            } else {
              assigned = 2;
            }
            break;

          case '[':
            p++;
            p1 = p;
            l_not = 0;
            if(store) arg = va_arg(ap, char *);
            while(*p != ']')
            {
              if(*p)
              {
                p++;
                count++;
              } else {
                p--;
                scan = 0;
                count = 0;
                break;
              }
            }
            if(scan)
            {
              if(count)
              {
                if(*p1 == '^')
                {
                  l_not = 1;
                  count--;
                  p1++;
                }
              }
              if(!count)
              {
                p++;
                while(*p != ']')
                {
                  if(*p)
                  {
                    p++;
                    count++;
                  } else {
                    p--;
                    scan = 0;
                    count = 0;
                    break;
                  }
                }
              }
            }
            if(scan)
            {
              while((!uwid || wid) && c != EOF)
              {
                s = _getfs(fp, s, &tc, &c);
                if(c != EOF)
                {
                  ct = 0;
                  scan = 0;
                  for(p2 = p1; ct < count; p2++)
                  {
                    if(c == *p2)
                    {
                      if(store && !l_not)
                      {
                        *arg++ = (char)c;
                        assigned = 3;
                      }
                      scan = 1;
                      break;
                    }
                    ct++;
                  }
                  if(l_not)
                  {
                    if(scan)
                    {
                      scan = 0;
                      s = _ungetfs(fp, s, &tc, c);
                      break;
                    } else {
                      if(store)
                      {
                        *arg++ = (char)c;
                        assigned = 3;
                      }
                    }
                  } else {
                    if(!scan)
                    {
                      s = _ungetfs(fp, s, &tc, c);
                      break;
                    }
                  }
                  wid--;
                }
              }
              if(store && assigned) *arg = '\0';
            }
            break;

          default:
            if(scan)
            {
              s = _getfs(fp, s, &tc, &c);
              if(c != EOF)
              {
                if(c != fmt)
                {
                  s = _ungetfs(fp, s, &tc, c);
                  scan = 0;
                }
              }
            }
            break;
        }
      }
      if(assigned)
      {
        if(fval)
        {
          if(assigned == 1)
          {
            fnum += frac;
            if(esign == -1)
            {
              fnum /= fxpower;
             } else {
              fnum *= fxpower;
            }
            if(l_mod) {
              *va_arg(ap, double *) = fsign * fnum;
            } else {
              *va_arg(ap, float *) = (float)(fsign * fnum);
            }
            num++;
          } else {
          }
        } else {
          if(assigned == 1)
          {
            if(l_mod) {
              *va_arg(ap, unsigned long *) = _mul32(ulval, lsign);
            } else if(h_mod) {
              *va_arg(ap, unsigned short *) = (short)_mul32(ulval, lsign);
            } else {
              *va_arg(ap, unsigned int *) = (int)_mul32(ulval, lsign);
            }
            num++;
          } else if(store && assigned == 2) {
            arg = va_arg(ap, void *);
          } else {
            num++;
          }
        }
      }
    }
  }
  return(num);
}

/*---------------------------------------------------------------------------*/
/* _getfs() - get next character from a file or a string                     */
/*---------------------------------------------------------------------------*/
char *_getfs(FILE *fp, char *s, int *tc, int *c)
{
  if(fp != NULL)
  {
    *c = (char)fgetc(fp);
  } else {
    if(*s != '\0')
    {
      *c = *s;
      s++;
    } else {
      *c = EOF;
    }
  }
  if(*c != EOF) (*tc)++;
  return(s);
}

/*---------------------------------------------------------------------------*/
/* _ungetfs() - unget a character from a file or a string                    */
/*---------------------------------------------------------------------------*/
char *_ungetfs(FILE *fp, char *s, int *tc, int c)
{
  if(fp != NULL)
  {
    ungetc(c, fp);
  } else {
      s--;
  }
  (*tc)--;
  return(s);
}
