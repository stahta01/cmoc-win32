/*---------------------------------------------------------------------------*/
/* setlocale - set locale specific information                               */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <string.h>
#include <limits.h>
#include <locale.h>

char *_setlocale(int category, const char *locale);

char *setlocale(int category, const char *locale)
{
  char *lptr;
  if(locale == NULL)
  {
    if(category >= LC_ALL && category <= LC_TIME)
    {
      lptr = _crt_base->_crt_locale[category];
    } else {
      lptr = NULL;
    }
  } else {
    if(category == LC_ALL)
    {
      lptr = _setlocale(LC_COLLATE, locale);
      if(lptr != NULL)
      {
         _setlocale(LC_CTYPE, locale);
         _setlocale(LC_MONETARY, locale);
         _setlocale(LC_NUMERIC, locale);
         _setlocale(LC_TIME, locale);
         _crt_base->_crt_locale[LC_ALL] = lptr;
      }
    } else {
      lptr = _setlocale(category, locale);
    }
  }
  return(lptr);
}

char *_setlocale(int category, const char *locale)
{
  char *lptr = NULL;

  if(!strcmp(locale, LC_C) ||
     !strcmp(locale, LC_C_USA) ||
     !strcmp(locale, LC_C_UK)) {

       switch(category)
       {
         case LC_COLLATE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_COLLATE] = lptr;
           break;

         case LC_CTYPE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_CTYPE] = lptr;
           break;

         case LC_MONETARY:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_MONETARY] = lptr;
           if(!strcmp(locale, LC_C))
           {
             _crt_base->_crt_lcbuffer.int_curr_symbol = "";
             _crt_base->_crt_lcbuffer.currency_symbol = "";
             _crt_base->_crt_lcbuffer.mon_decimal_point = "";
             _crt_base->_crt_lcbuffer.mon_thousands_sep = "";
             _crt_base->_crt_lcbuffer.mon_grouping = "";
             _crt_base->_crt_lcbuffer.positive_sign = "";
             _crt_base->_crt_lcbuffer.negative_sign = "";
             _crt_base->_crt_lcbuffer.frac_digits = CHAR_MAX;
             _crt_base->_crt_lcbuffer.int_frac_digits = CHAR_MAX;
             _crt_base->_crt_lcbuffer.p_cs_precedes = CHAR_MAX;
             _crt_base->_crt_lcbuffer.p_sep_by_space = CHAR_MAX;
             _crt_base->_crt_lcbuffer.n_cs_precedes = CHAR_MAX;
             _crt_base->_crt_lcbuffer.n_sep_by_space = CHAR_MAX;
             _crt_base->_crt_lcbuffer.p_sign_posn = CHAR_MAX;
             _crt_base->_crt_lcbuffer.n_sign_posn = CHAR_MAX;

           } else {
             if(!strcmp(locale, LC_C_USA))
             {
               _crt_base->_crt_lcbuffer.int_curr_symbol = "AMD";
             } else {
               _crt_base->_crt_lcbuffer.int_curr_symbol = "GBP";
             }
             _crt_base->_crt_lcbuffer.currency_symbol = "$";
             _crt_base->_crt_lcbuffer.mon_decimal_point = ".";
             _crt_base->_crt_lcbuffer.mon_thousands_sep = ",";
             _crt_base->_crt_lcbuffer.mon_grouping = "\3";
             _crt_base->_crt_lcbuffer.positive_sign = "";
             _crt_base->_crt_lcbuffer.negative_sign = "-";
             _crt_base->_crt_lcbuffer.frac_digits = 2;
             _crt_base->_crt_lcbuffer.int_frac_digits = 2;
             _crt_base->_crt_lcbuffer.p_cs_precedes = 1;
             _crt_base->_crt_lcbuffer.p_sep_by_space = 0;
             _crt_base->_crt_lcbuffer.n_cs_precedes = 1;
             _crt_base->_crt_lcbuffer.n_sep_by_space = 0;
             _crt_base->_crt_lcbuffer.p_sign_posn = 1;
             _crt_base->_crt_lcbuffer.n_sign_posn = 1;
           }
           break;

         case LC_NUMERIC:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_NUMERIC] = lptr;
           _crt_base->_crt_lcbuffer.decimal_point = ".";
           if(!strcmp(locale, LC_C))
           {
             _crt_base->_crt_lcbuffer.thousands_sep = "";
             _crt_base->_crt_lcbuffer.grouping = "";
           } else {
             _crt_base->_crt_lcbuffer.thousands_sep = ",";
             _crt_base->_crt_lcbuffer.grouping = "\3";
           }
           break;

         case LC_TIME:

           _crt_base->_crt_localday[0] = "Sunday";
           _crt_base->_crt_localday[1] = "Monday";
           _crt_base->_crt_localday[2] = "Tuesday";
           _crt_base->_crt_localday[3] = "Wednesday";
           _crt_base->_crt_localday[4] = "Thursday";
           _crt_base->_crt_localday[5] = "Friday";
           _crt_base->_crt_localday[6] = "Saturday";

           _crt_base->_crt_localmon[0] = "January";
           _crt_base->_crt_localmon[1] = "February";
           _crt_base->_crt_localmon[2] = "March";
           _crt_base->_crt_localmon[3] = "April";
           _crt_base->_crt_localmon[4] = "May";
           _crt_base->_crt_localmon[5] = "June";
           _crt_base->_crt_localmon[6] = "July";
           _crt_base->_crt_localmon[7] = "August";
           _crt_base->_crt_localmon[8] = "September";
           _crt_base->_crt_localmon[9] = "October";
           _crt_base->_crt_localmon[10] = "November";
           _crt_base->_crt_localmon[11] = "December";

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_TIME] = lptr;

           if(!strcmp(locale, LC_C_UK))
           {
             _crt_base->_crt_daylight = 0;
             _crt_base->_crt_timezone = 0;
             _crt_base->_crt_tzname[0] = "\0";
             _crt_base->_crt_tzname[1] = "\0";
           } else {
             _crt_base->_crt_daylight = 1;
             _crt_base->_crt_timezone = 18000L;
             _crt_base->_crt_tzname[0] = "EST";
             _crt_base->_crt_tzname[1] = "EDT";
           }
           break;

         default:
           break;
       }

  } else if(!strcmp(locale, LC_C_FRANCE)) {

       switch(category)
       {
         case LC_COLLATE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_COLLATE] = lptr;
           break;

         case LC_CTYPE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_CTYPE] = lptr;
           break;

         case LC_MONETARY:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_MONETARY] = lptr;
           _crt_base->_crt_lcbuffer.int_curr_symbol = "FRF";
           _crt_base->_crt_lcbuffer.currency_symbol = "F";
           _crt_base->_crt_lcbuffer.mon_decimal_point = ",";
           _crt_base->_crt_lcbuffer.mon_thousands_sep = ".";
           _crt_base->_crt_lcbuffer.mon_grouping = "\3";
           _crt_base->_crt_lcbuffer.positive_sign = "";
           _crt_base->_crt_lcbuffer.negative_sign = "-";
           _crt_base->_crt_lcbuffer.frac_digits = 2;
           _crt_base->_crt_lcbuffer.int_frac_digits = 2;
           _crt_base->_crt_lcbuffer.p_cs_precedes = 0;
           _crt_base->_crt_lcbuffer.p_sep_by_space = 1;
           _crt_base->_crt_lcbuffer.n_cs_precedes = 0;
           _crt_base->_crt_lcbuffer.n_sep_by_space = 1;
           _crt_base->_crt_lcbuffer.p_sign_posn = 1;
           _crt_base->_crt_lcbuffer.n_sign_posn = 1;
           break;

         case LC_NUMERIC:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_NUMERIC] = lptr;
           _crt_base->_crt_lcbuffer.decimal_point = ",";
           _crt_base->_crt_lcbuffer.thousands_sep = "";
           _crt_base->_crt_lcbuffer.grouping = "\3";
           break;

         case LC_TIME:

           _crt_base->_crt_localday[0] = "Dimanche";
           _crt_base->_crt_localday[1] = "Lundi";
           _crt_base->_crt_localday[2] = "Mardi";
           _crt_base->_crt_localday[3] = "Mercredi";
           _crt_base->_crt_localday[4] = "Juedi";
           _crt_base->_crt_localday[5] = "Vendredi";
           _crt_base->_crt_localday[6] = "Samedi";

           _crt_base->_crt_localmon[0] = "janvier";
           _crt_base->_crt_localmon[1] = "fevrier";
           _crt_base->_crt_localmon[2] = "mars";
           _crt_base->_crt_localmon[3] = "avril";
           _crt_base->_crt_localmon[4] = "mai";
           _crt_base->_crt_localmon[5] = "juin";
           _crt_base->_crt_localmon[6] = "juillet";
           _crt_base->_crt_localmon[7] = "aout";
           _crt_base->_crt_localmon[8] = "septembre";
           _crt_base->_crt_localmon[9] = "octobre";
           _crt_base->_crt_localmon[10] = "novembre";
           _crt_base->_crt_localmon[11] = "decembre";

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_TIME] = lptr;

           _crt_base->_crt_daylight = 0;
           _crt_base->_crt_timezone = 0;
           _crt_base->_crt_tzname[0] = "\0";
           _crt_base->_crt_tzname[1] = "\0";
           break;

         default:
           break;
       }

  } else if(!strcmp(locale, LC_C_GERMANY)) {

       switch(category)
       {
         case LC_COLLATE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_COLLATE] = lptr;
           break;

         case LC_CTYPE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_CTYPE] = lptr;
           break;

         case LC_MONETARY:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_MONETARY] = lptr;
           _crt_base->_crt_lcbuffer.int_curr_symbol = "DEM";
           _crt_base->_crt_lcbuffer.currency_symbol = "DM";
           _crt_base->_crt_lcbuffer.mon_decimal_point = ",";
           _crt_base->_crt_lcbuffer.mon_thousands_sep = ".";
           _crt_base->_crt_lcbuffer.mon_grouping = "\3";
           _crt_base->_crt_lcbuffer.positive_sign = "";
           _crt_base->_crt_lcbuffer.negative_sign = "-";
           _crt_base->_crt_lcbuffer.frac_digits = 2;
           _crt_base->_crt_lcbuffer.int_frac_digits = 2;
           _crt_base->_crt_lcbuffer.p_cs_precedes = 1;
           _crt_base->_crt_lcbuffer.p_sep_by_space = 0;
           _crt_base->_crt_lcbuffer.n_cs_precedes = 1;
           _crt_base->_crt_lcbuffer.n_sep_by_space = 0;
           _crt_base->_crt_lcbuffer.p_sign_posn = 1;
           _crt_base->_crt_lcbuffer.n_sign_posn = 1;
           break;

         case LC_NUMERIC:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_NUMERIC] = lptr;
           _crt_base->_crt_lcbuffer.decimal_point = ",";
           _crt_base->_crt_lcbuffer.thousands_sep = ".";
           _crt_base->_crt_lcbuffer.grouping = "\3";
           break;

         case LC_TIME:

           _crt_base->_crt_localday[0] = "Sonntag";
           _crt_base->_crt_localday[1] = "Montag";
           _crt_base->_crt_localday[2] = "Dienstag";
           _crt_base->_crt_localday[3] = "Mittwoch";
           _crt_base->_crt_localday[4] = "Donnerstag";
           _crt_base->_crt_localday[5] = "Freitag";
           _crt_base->_crt_localday[6] = "Samstag";

           _crt_base->_crt_localmon[0] = "Januar";
           _crt_base->_crt_localmon[1] = "Februar";
           _crt_base->_crt_localmon[2] = "Maerz";
           _crt_base->_crt_localmon[3] = "April";
           _crt_base->_crt_localmon[4] = "Mai";
           _crt_base->_crt_localmon[5] = "Juni";
           _crt_base->_crt_localmon[6] = "Juli";
           _crt_base->_crt_localmon[7] = "August";
           _crt_base->_crt_localmon[8] = "September";
           _crt_base->_crt_localmon[9] = "Oktober";
           _crt_base->_crt_localmon[10] = "November";
           _crt_base->_crt_localmon[11] = "Dezember";

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_TIME] = lptr;

           _crt_base->_crt_daylight = 0;
           _crt_base->_crt_timezone = 0;
           _crt_base->_crt_tzname[0] = "\0";
           _crt_base->_crt_tzname[1] = "\0";
           break;

         default:
           break;
       }

  } else if(!strcmp(locale, LC_C_ITALY)) {

       switch(category)
       {
         case LC_COLLATE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_COLLATE] = lptr;
           break;

         case LC_CTYPE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_CTYPE] = lptr;
           break;

         case LC_MONETARY:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_MONETARY] = lptr;
           _crt_base->_crt_lcbuffer.int_curr_symbol = "ITL";
           _crt_base->_crt_lcbuffer.currency_symbol = "L.";
           _crt_base->_crt_lcbuffer.mon_decimal_point = "";
           _crt_base->_crt_lcbuffer.mon_thousands_sep = ".";
           _crt_base->_crt_lcbuffer.mon_grouping = "\3";
           _crt_base->_crt_lcbuffer.positive_sign = "";
           _crt_base->_crt_lcbuffer.negative_sign = "-";
           _crt_base->_crt_lcbuffer.frac_digits = 0;
           _crt_base->_crt_lcbuffer.int_frac_digits = 0;
           _crt_base->_crt_lcbuffer.p_cs_precedes = 1;
           _crt_base->_crt_lcbuffer.p_sep_by_space = 1;
           _crt_base->_crt_lcbuffer.n_cs_precedes = 1;
           _crt_base->_crt_lcbuffer.n_sep_by_space = 1;
           _crt_base->_crt_lcbuffer.p_sign_posn = 1;
           _crt_base->_crt_lcbuffer.n_sign_posn = 1;
           break;

         case LC_NUMERIC:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_NUMERIC] = lptr;
           _crt_base->_crt_lcbuffer.decimal_point = ",";
           _crt_base->_crt_lcbuffer.thousands_sep = ".";
           _crt_base->_crt_lcbuffer.grouping = "\3";
           break;

         case LC_TIME:

           _crt_base->_crt_localday[0] = "domenica";
           _crt_base->_crt_localday[1] = "lunedi";
           _crt_base->_crt_localday[2] = "martedi";
           _crt_base->_crt_localday[3] = "marcoledi";
           _crt_base->_crt_localday[4] = "giovedi";
           _crt_base->_crt_localday[5] = "venerdi";
           _crt_base->_crt_localday[6] = "sabato";

           _crt_base->_crt_localmon[0] = "gennaio";
           _crt_base->_crt_localmon[1] = "febbraio";
           _crt_base->_crt_localmon[2] = "marzo";
           _crt_base->_crt_localmon[3] = "aprile";
           _crt_base->_crt_localmon[4] = "maggio";
           _crt_base->_crt_localmon[5] = "giugno";
           _crt_base->_crt_localmon[6] = "lugio";
           _crt_base->_crt_localmon[7] = "agosto";
           _crt_base->_crt_localmon[8] = "settembre";
           _crt_base->_crt_localmon[9] = "ottobre";
           _crt_base->_crt_localmon[10] = "novembre";
           _crt_base->_crt_localmon[11] = "dicembre";

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_TIME] = lptr;

           _crt_base->_crt_daylight = 0;
           _crt_base->_crt_timezone = 0;
           _crt_base->_crt_tzname[0] = "\0";
           _crt_base->_crt_tzname[1] = "\0";
           break;

         default:
           break;
       }

  } else if(!strcmp(locale, LC_C_SPAIN)) {

       switch(category)
       {
         case LC_COLLATE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_COLLATE] = lptr;
           break;

         case LC_CTYPE:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_CTYPE] = lptr;
           break;

         case LC_MONETARY:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_MONETARY] = lptr;
           _crt_base->_crt_lcbuffer.int_curr_symbol = "ESP";
           _crt_base->_crt_lcbuffer.currency_symbol = "Pts";
           _crt_base->_crt_lcbuffer.mon_decimal_point = "";
           _crt_base->_crt_lcbuffer.mon_thousands_sep = ".";
           _crt_base->_crt_lcbuffer.mon_grouping = "\3";
           _crt_base->_crt_lcbuffer.positive_sign = "";
           _crt_base->_crt_lcbuffer.negative_sign = "-";
           _crt_base->_crt_lcbuffer.frac_digits = 0;
           _crt_base->_crt_lcbuffer.int_frac_digits = 0;
           _crt_base->_crt_lcbuffer.p_cs_precedes = 1;
           _crt_base->_crt_lcbuffer.p_sep_by_space = 1;
           _crt_base->_crt_lcbuffer.n_cs_precedes = 1;
           _crt_base->_crt_lcbuffer.n_sep_by_space = 1;
           _crt_base->_crt_lcbuffer.p_sign_posn = 1;
           _crt_base->_crt_lcbuffer.n_sign_posn = 1;
           break;

         case LC_NUMERIC:

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_NUMERIC] = lptr;
           _crt_base->_crt_lcbuffer.decimal_point = ",";
           _crt_base->_crt_lcbuffer.thousands_sep = ".";
           _crt_base->_crt_lcbuffer.grouping = "\3";
           break;

         case LC_TIME:

           _crt_base->_crt_localday[0] = "Domingo";
           _crt_base->_crt_localday[1] = "Lunes";
           _crt_base->_crt_localday[2] = "Martes";
           _crt_base->_crt_localday[3] = "Miercoles";
           _crt_base->_crt_localday[4] = "Jueves";
           _crt_base->_crt_localday[5] = "Viernes";
           _crt_base->_crt_localday[6] = "Sabado";

           _crt_base->_crt_localmon[0] = "Enero";
           _crt_base->_crt_localmon[1] = "Febrero";
           _crt_base->_crt_localmon[2] = "Marzo";
           _crt_base->_crt_localmon[3] = "Abril";
           _crt_base->_crt_localmon[4] = "Mayo";
           _crt_base->_crt_localmon[5] = "Junio";
           _crt_base->_crt_localmon[6] = "Julio";
           _crt_base->_crt_localmon[7] = "Agosto";
           _crt_base->_crt_localmon[8] = "Septiembre";
           _crt_base->_crt_localmon[9] = "Octubre";
           _crt_base->_crt_localmon[10] = "Noviembre";
           _crt_base->_crt_localmon[11] = "Diciembre";

           lptr = (char *)locale;
           _crt_base->_crt_locale[LC_TIME] = lptr;

           _crt_base->_crt_daylight = 0;
           _crt_base->_crt_timezone = 0;
           _crt_base->_crt_tzname[0] = "SST";
           _crt_base->_crt_tzname[1] = "\0";

           break;

         default:
           break;
       }
  }
  return(lptr);
}
