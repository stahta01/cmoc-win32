/*---------------------------------------------------------------------------*/
/* _printfs() - print formatted data to a file or a string                   */
/*---------------------------------------------------------------------------*/
#ifdef _WIN32
  #include <win32.h>
#else
  #include <os2.h>
#endif

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#define _SPRINTF_BUFSIZ     384

#define POS_INFINITY  "infinity"
#define NEG_INFINITY "-infinity"

#define _FLOAT_ROUND_ADJUST (double)5e-15

int _floatp10(double *fnum, int *fsign, int prec);

int _printfs(FILE *fp, char *string, const char *format, va_list ap)
{
  int *n;
  int c = 0;
  char schar;
  char *buffer;
  char *p, *s, *b;
  char *fplnz;
  int wid, uwid, prec, uprec;
  int just, sign, pfx1, pfx2;
  int flag, zpad, h_mod, l_mod;
  int ssize, dsize, maxlen;
  int fpower, fsign, fdigit, fprec, fzfill;
  int padlen, zpadlen, gfmt;
  double fnum, sfnum;

  if(_crt_base->_printf_buffer == NULL)
  {
     _crt_base->_printf_buffer = malloc(_SPRINTF_BUFSIZ);
     if(_crt_base->_printf_buffer == NULL)
     {
        _crt_base->_crt_errno = ENOMEM;
        _crt_base->_crt_doserrno = ERROR_NOT_ENOUGH_MEMORY;
        return(EOF);
     }
  }
  buffer = _crt_base->_printf_buffer;

  for(p = (char *)format; (*p && c != EOF); p++)
  {
    if(*p != '%')
    {
      if(fp != NULL)
      {
        if(fputc(*p, fp) != EOF)
        {
          c++;
        } else {
          c = EOF;
        }
      } else {
        *string++ = *p;
        c++;
      }
    } else {
      wid = 0;
      uwid = 0;
      flag = 1;
      just = 0;
      sign = 0;
      pfx1 = 0;
      pfx2 = 0;
      zpad = 0;
      prec = 0;
      gfmt = 0;
      uprec = 0;
      fprec = 0;
      schar = 0;
      h_mod = 0;
      l_mod = 0;
      padlen = 0;
      zpadlen = 0;
      maxlen = -1;
      while(*++p && flag)
      {
        switch(*p)
        {
          case '-':
            just = 1;
            break;
          case '+':
            sign = 1;
            break;
          case '0':
            zpad = 1;
            break;
          case ' ':
            pfx1 = 1;
            break;
          case '#':
            pfx2 = 1;
            break;
          default:
            p--;
            flag = 0;
            break;
        }
      }
      if(*p == '*')
      {
        wid = va_arg(ap, int);
        uwid++;
        p++;
      } else {
        while(isdigit(*p))
        {
          wid = (wid * 10) + (int)(*p - '0');
          uwid++;
          p++;
        }
      }
      if(*p == '.')
      {
        p++;
        if(*p == '*')
        {
          prec = va_arg(ap, int);
          uprec++;
          p++;
        } else {
          uprec++;
          while(isdigit(*p))
          {
            prec = (prec * 10) + (int)(*p - '0');
            uprec++;
            p++;
          }
        }
      }
      if(*p == 'h')
      {
        h_mod = 1;
        p++;
      } else if(*p == 'l') {
        l_mod = 1;
        p++;
      }
      switch(*p)
      {
        case 'c':
          s = buffer;
          *s = (unsigned char)va_arg(ap, int);
          *(s + 1) = '\0';
          sign = 0;
          zpad = 0;
          pfx1 = 0;
          pfx2 = 0;
          uprec = 0;
          break;

        case 'd':
        case 'i':
          if(l_mod) {
             s = ltoa(va_arg(ap, long), buffer, 10);
          } else if(h_mod) {
             s = itoa(va_arg(ap, short), buffer, 10);
          } else {
             s = itoa(va_arg(ap, int), buffer, 10);
          }
          pfx2 = 0;
          break;

        case 'g':
        case 'G':
          gfmt = 1;
          fnum = va_arg(ap, double);
          sfnum = fnum;
          fpower = _floatp10(&sfnum, &fsign, -999);
          sfnum = fnum;
          if((!uprec) && prec == 0) prec = 6;
          fpower = _floatp10(&sfnum, &fsign, prec - fpower);
          if((fnum != (double)0) && ((fpower < -4) || (fpower >= prec)))
          {
            if(*p == 'g')
            {
              *p = 'e';
            } else {
              *p = 'E';
            }
          } else {
            *p = 'f';
            prec -= (fpower + 1);
            if(prec <= 0) prec = 1;
          }

        case 'e':
        case 'E':
          if(*p != 'f')
          {
            s = buffer;
            if(!gfmt) fnum = va_arg(ap, double);
            if(fnum == HUGE_VAL)
            {
              strcpy(buffer, POS_INFINITY);
              zpad = 0;
              uprec = 0;
              break;
            } else if(fnum == -HUGE_VAL) {
              strcpy(buffer, NEG_INFINITY);
              zpad = 0;
              uprec = 0;
              break;
            }
            sfnum = fnum;
            if((!uprec) && prec == 0) prec = 6;
            fpower = _floatp10(&sfnum, &fsign, -999);
            fpower = _floatp10(&fnum, &fsign, prec - fpower);
            if(fsign < 0) *s++ = '-';
            fdigit = (int)fnum;
            *s++ = (char)((char)fdigit + (char)48);
            fnum -= (double)fdigit;
            fnum *= (double)10;
            fnum += _FLOAT_ROUND_ADJUST;
            if(gfmt) fplnz = s;
            if(prec)
            {
              uprec = 0;
              *s++ = '.';
              while(prec)
              {
                if(fprec < 16)
                {
                  fdigit = (int)fnum;
                  *s++ = (unsigned char)((unsigned char)fdigit +
                                         (unsigned char)48);
                  if(gfmt && fdigit > 0) fplnz = s;
                  fnum -= (double)fdigit;
                  fnum *= (double)10;
                  fnum += _FLOAT_ROUND_ADJUST;
                  fprec++;
                } else {
                  *s++ = '0';
                }
                prec--;
              }
            }
            if(gfmt) s = fplnz;
            *s++ = *p;
            if(fpower >= 0)
            {
              *s++ = '+';
            } else {
              *s++ = '-';
              fpower = -fpower;
            }
            if(fpower < 10) *s++ = '0';
            s = itoa(fpower, s, 10);
            s = buffer;
            break;
          }

        case 'f':
          s = buffer;
          if(!gfmt) fnum = va_arg(ap, double);
          if(fnum == HUGE_VAL)
          {
            strcpy(buffer, POS_INFINITY);
            zpad = 0;
            uprec = 0;
            break;
          } else if(fnum == -HUGE_VAL) {
            strcpy(buffer, NEG_INFINITY);
            zpad = 0;
            uprec = 0;
            break;
          }
          if((!uprec) && prec == 0) prec = 6;
          fpower = _floatp10(&fnum, &fsign, prec);
          if(fsign < 0) *s++ = '-';
          if(fpower < 0)
          {
            *s++ = '0';
            fpower++;
            fzfill++;
          } else {
            while(fpower >= 0)
            {
              if(fprec < 16)
              {
                fdigit = (int)fnum;
                *s++ = (char)((char)fdigit + (char)48);
                fnum -= (double)fdigit;
                fnum *= (double)10;
                fnum += _FLOAT_ROUND_ADJUST;
                fprec++;
              } else {
                *s++ = '0';
              }
              fpower--;
            }
            fpower = 0;
          }
          if(gfmt) fplnz = s;
          if(prec)
          {
            uprec = 0;
            *s++ = '.';
            while(prec)
            {
              if(fzfill && fpower < 0)
              {
                *s++ = '0';
                fpower++;
              } else {
                if(fprec < 16)
                {
                  fdigit = (int)fnum;
                  *s++ = (unsigned char)((unsigned char)fdigit +
                                         (unsigned char)48);

                  if(gfmt && fdigit > 0) fplnz = s;

                  fnum -= (double)fdigit;
                  fnum *= (double)10;
                  fnum += _FLOAT_ROUND_ADJUST;
                  fprec++;
                } else {
                  *s++ = '0';
                }
              }
              prec--;
            }
          }
          if(gfmt)
          {
            *fplnz = '\0';
          } else {
            *s = '\0';
          }
          s = buffer;
          break;

        case 'n':
          s = NULL;
          n = va_arg(ap, int *);
          *n = c;
          break;

        case 'o':
          if(l_mod) {
             s = ultoa(va_arg(ap, unsigned long), buffer, 8);
          } else if(h_mod) {
             s = ultoa((unsigned long)(va_arg(ap, unsigned short)),
                       buffer, 8);
          } else {
             s = ultoa((unsigned long)(va_arg(ap, unsigned int)),
                       buffer, 8);
          }
          break;

        case 'p':
          s = strupr(ultoa((unsigned long)va_arg(ap, void *), buffer, 16));
          #if(!defined(API32) && !defined(_WIN32))
            dsize = (8 - strlen(s));
            memset(buffer + 32, '0', dsize);
            strcpy(buffer + 32 + dsize, s);
            strncpy(s, buffer + 32, 4);
            strncpy(s + 4, ":", 1);
            strncpy(s + 5, buffer + 36, 4);
            memset(s + 9, 0, 1);
          #endif
          pfx2 = 0;
          break;

        case 's':
          s = va_arg(ap, char *);
          if(uprec)
          {
            uprec = 0;
            maxlen = prec;
          }
          sign = 0;
          zpad = 0;
          pfx1 = 0;
          pfx2 = 0;
          break;

        case 'u':
          if(l_mod) {
             s = ultoa(va_arg(ap, unsigned long), buffer, 10);
          } else if(h_mod) {
             s = ultoa((unsigned long)(va_arg(ap, unsigned short)),
                       buffer, 10);
          } else {
             s = ultoa((unsigned long)(va_arg(ap, unsigned int)),
                       buffer, 10);
          }
          pfx2 = 0;
          break;

        case 'x':
        case 'X':
          if(l_mod) {
             s = ultoa(va_arg(ap, unsigned long), buffer, 16);
          } else if(h_mod) {
             s = ultoa((unsigned long)(va_arg(ap, unsigned short)),
                       buffer, 16);
          } else {
             s = ultoa((unsigned long)(va_arg(ap, unsigned int)),
                       buffer, 16);
          }
          if(*p == 'X') strupr(s);
          break;

        default:
          s = p;
          sign = 0;
          just = 0;
          zpad = 0;
          pfx1 = 0;
          pfx2 = 0;
          maxlen = 1;
      }
      if(s != NULL)
      {
        ssize = strlen(s);
        dsize = ssize;
        if(just && zpad) zpad = 0;
        if((*p != 'c') && (*p != 's'))
        {
          if(ssize == 1 && *s == '0')
          {
            if(uprec && prec == 0)
            {
              *s = '\0';
              ssize = 0;
              dsize = 0;
            }
          }
		  else if(pfx2)
		  {
            if(*p == 'o' && prec < ssize)
            {
              pfx2 = 0;
              uprec = 1;
              prec = ssize + 1;
            }
			else if(*p == 'x' || *p == 'X')
			{
              ssize += 2;
              *(buffer + 32) = '0';
              *(buffer + 33) = *p;
              *(buffer + 34) = '\0';
            }
          }
          if(*s == '-') {
            s++;
            schar = '-';
            dsize--;
          }
		  else if(sign)
		  {
            schar = '+';
            ssize++;
          }
		  else if(pfx1)
		  {
            schar = ' ';
            ssize++;
          }
        }
        if(wid > ssize)
        {
          if(uprec && (prec > dsize))
          {
            padlen = wid - (ssize + (prec - dsize));
          }
		  else
		  {
            padlen = wid - ssize;
          }
        }
        if(uprec && (prec > dsize))
        {
          zpadlen = prec - dsize;
        } else if(zpad) {
          zpadlen = padlen;
          padlen = 0;
        }
        while(!just && (padlen > 0) && c != EOF)
        {
          if(fp != NULL)
          {
            if(fputc(' ', fp) != EOF)
            {
              c++;
            } else {
              c = EOF;
            }
          } else {
            *string++ = ' ';
            c++;
          }
          padlen--;
        }
        if(pfx2)
        {
          b = buffer + 32;
          while(*b && (c != EOF))
          {
            if(fp != NULL)
            {
              if(fputc(*b, fp) != EOF)
              {
                c++;
              } else {
                c = EOF;
              }
          } else {
            *string++ = *b;
            c++;
          }
            b++;
          }
        } else if(schar) {
          if(fp != NULL)
          {
            if(fputc(schar, fp) != EOF)
            {
              c++;
            } else {
              c = EOF;
            }
          } else {
            *string++ = schar;
            c++;
          }
        }
        while((zpadlen > 0) && c != EOF)
        {
          if(fp != NULL)
          {
            if(fputc('0', fp) != EOF)
            {
              c++;
              zpadlen--;
            } else {
              c = EOF;
            }
          } else {
            *string++ = '0';
            c++;
            zpadlen--;
          }
        }
        while(*s && (c != EOF))
        {
          if(maxlen != -1)
          {
           if(!(maxlen--)) break;
          }
          if(fp != NULL)
          {
            if(fputc(*s, fp) != EOF)
            {
              c++;
            } else {
              c = EOF;
            }
          } else {
            *string++ = *s;
            c++;
          }
          s++;
        }

		/* * *
		 * fix: When a string was left justified using '-' in the format string,
		 *      instead of being padded with the difference between field width
		 *      and string width the entire field width was used resulting in an
		 *      incorrect field width.
		 *      Changing the variable wid to padlen fixed the problem.
		 *      fixed by: Roger Scudder - 08/11/1999
		 * * */
		while(just && (padlen > 0) && c != EOF)
        {
          if(fp != NULL)
          {
            if(fputc(' ', fp) != EOF)
            {
              c++;
            } else {
              c = EOF;
            }
          } else {
            *string++ = ' ';
            c++;
          }
          padlen--;
        }
      }
    }
  }
  if(fp == NULL) *string = '\0';
  return(c);
}
