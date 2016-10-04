/*

CMOC RPN FLOATING POINT CALCULATOR
==================================
-Written by Brian K. Holman (me@brianholman.com) for the TRS-80 Coco
-Requires WinCMOC 0.5 or greater to compile

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*/

#undef NO_OLDNAMES

#include <sac.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdarg.h>
#include <equates.h>
#include <ctype.h>
#include <peekpoke.h>

#include "dirent.h"


#define SAVEFILE "RPNCALC.DAT"

typedef union
{
    float_t floatval;
    byte bytearr[5];
} floatarr_t ;

void _fhex(float_t *src)
{
    floatarr_t *temp;
    temp = (floatarr_t *)src;

    for (int i=0; i < 5; i++)
        cprintf("[%02X]", temp->bytearr[i]);
    cprintf("\n");
}

typedef struct {
    node_t node;
    float_t floatval;
} stackelem_t;

char *trimwhitespace(char *str)
{
  char *end;

  /* Trim leading space */
  while(isspace(*str)) str++;

  if(*str == 0)  /* All spaces? */
    return str;

  /* Trim trailing space */
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  /* Write new null terminator */
  *(end+1) = 0;

  return str;
}

list_t* stack = list_create();
int stacksz = 0;
stackelem_t *elem, *temp;
float_t dst, fp1, fp2;

void dropelem()
{
    if (stacksz > 0)
    {
        elem = (stackelem_t*)list_pull_head(stack);
        free(elem);
        stacksz--;
    }
}

void clearstack()
{
    for (; elem = (stackelem_t*)list_pull_head(stack);)
    {
        free(elem);
    }
    stacksz = 0;
}

void pushdst()
{
    elem = new(stackelem_t);
    elem->floatval = dst;
    list_push_head(stack, &elem->node);
    stacksz++;
}

void savestack()
{
        FILE* fp = fopen(SAVEFILE, "wb");
        if (fp)
        {
            cputs("<<SAVING STACK TO DISK>>\n");
            int pos = stacksz;
            elem = (stackelem_t*)list_tail(stack);
            while (pos)
            {
                fwrite(&elem->floatval, sizeof(float_t), 1, fp);
                elem = (stackelem_t*)(elem->node.prev);
                pos--;
            }
            fclose(fp);
        }
}

void loadstack()
{
    DIR* dir = opendir("*,0");
    if (dir)
    {
        struct dirent* dirent;
        while (dirent = readdir(dir))
        {
            if (strcmp(dirent->d_name, SAVEFILE) == 0)
            {
                FILE *fp = fopen(SAVEFILE, "rb");
                if (fp)
                {
                    cputs("<<LOADING STACK FROM DISK>>\n");
                    while (!feof(fp))
                    {
                        fread(&dst, sizeof(float_t), 1, fp);
                        if (!feof(fp)) pushdst();
                    }
                    fclose(fp);
                }

            }
        }
        closedir(dir);
    }
}

int main(void)
{
    if (stack)
    {
        char line[33];
        char message[254];
        char operation[128];
        int pos;
        bool success;
        message[0] = '\0';
        conio_uses_graph();
        textmode(MODE_H0_32X24);
        /* Don't allow an Overflow to terminate the program to basic */
        POKE(0xBA92, 0x39);
        loadstack();
        for (;;)
        {
            clrscr();

            cputs("CMOC RPN CALCULATOR-Brian Holman");
            cputs("e(X)it (H)elp\n");
            cputs("===========================\n");
            if (strlen(message) > 0)
            {
                cputs(message);
                cputc('\n');
            }

            /* Display Stack */
            pos = stacksz;
            elem = (stackelem_t*)list_tail(stack);
            while (pos)
            {
                cprintf("%02d: %f\n", pos, &elem->floatval);
                // _fhex(&elem->floatval);
                elem = (stackelem_t*)(elem->node.prev);
                pos--;
            }

            /* Prompt for input and trim whitespace */
            line[0] = 31;
            cgets(line);
            cputc('\n');
            char *strval = trimwhitespace(line+2);

            /* Check if valid command or value */
            if (strlen(strval) == 1 && !isdigit(strval[0]))
            {
                /* Drop last element off stack */
                if (strval[0] == 'D')
                {
                    dropelem();
                    sprintf(message,"<<DROP LAST VALUE>>");
                }
                /* Negative of last element */
                else if (strval[0] == 'N' && stacksz > 0)
                {
                    elem = (stackelem_t*)list_head(stack);
                    fp1 = elem->floatval;
                    _fmul(&elem->floatval, &fp1, (float_t *)FP_MINUSONE);
                    sprintf(message, "<<NEG(%f) = %f>>", &fp1, &elem->floatval);
                }
                /* Reciprocal of last element */
                else if (strval[0] == 'R' && stacksz > 0)
                {
                    elem = (stackelem_t*)list_head(stack);
                    fp2 = elem->floatval;
                    _fdiv(&elem->floatval, (float_t *)FP_ONE, &fp2);
                    sprintf(message, "<< 1 / %f  = %f>>", &fp2, &elem->floatval);
                }
                /* Square root of last element */
                else if (strval[0] == 'S' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                    _fsqrt(&elem->floatval, &fp1);
                    sprintf(message, "<<SQRT(%f) = %f>>", &fp1, &elem->floatval);
                }
                /* Sin of last element */
                else if (strval[0] == 'I' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                    _fsin(&elem->floatval, &fp1);
                    sprintf(message, "<<SIN(%f) = %f>>", &fp1, &elem->floatval);
                }
                /* Cos of last element */
                else if (strval[0] == 'O' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                    _fcos(&elem->floatval, &fp1);
                    sprintf(message, "<<COS(%f) = %f>>", &fp1, &elem->floatval);
                }
                /* Tan of last element */
                else if (strval[0] == 'T' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                    _ftan(&elem->floatval, &fp1);
                    sprintf(message, "<<TAN(%f) = %f>>", &fp1, &elem->floatval);
                }
                /* Atn of last element */
                else if (strval[0] == 'A' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                    _fatan(&elem->floatval, &fp1);
                    sprintf(message, "<<ATN(%f) = %f>>", &fp1, &elem->floatval);
                }
                /* Log of last element */
                else if (strval[0] == 'L' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                     if (_fsign(&fp1) > 0)
                     {
                        _flog(&elem->floatval, &fp1);
                        sprintf(message, "<<LOG(%f) = %f>>", &fp1, &elem->floatval);
                     }
                }
                else if (strval[0] == '&' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                     if (_fsign(&fp1) > 0)
                     {
                        _flog10(&elem->floatval, &fp1);
                        sprintf(message, "<<LOG10(%f) = %f>>", &fp1, &elem->floatval);
                     }
                }
                /* Exponent */
                else if (strval[0] == 'E' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                     _fsub(&dst, &fp1, (float_t*)FP_MAXEXP);
                     if (_fsign(&dst) <= 0)
                     {
                        _fexp(&elem->floatval, &fp1);
                        sprintf(message, "<<EXP(%f) = %f>>", &fp1, &elem->floatval);
                     }
                     else
                     {
                        sprintf(message, "<<OVERFLOW ON EXP>>");
                     }
                }
                else if (strval[0] == '@' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                     _fdeg(&elem->floatval, &fp1);
                     sprintf(message, "<<DEG(%f) = %f>>", &fp1, &elem->floatval);
                }
                 else if (strval[0] == '#' && stacksz > 0)
                {
                     elem = (stackelem_t*)list_head(stack);
                     fp1 = elem->floatval;
                     _frad(&elem->floatval, &fp1);
                     sprintf(message, "<<RAD(%f) = %f>>", &fp1, &elem->floatval);
                }
                else if (strval[0] == '[')
                {
                    memcpy(&dst, FP_PI, sizeof(float_t));
                    pushdst();
                }
                else if (strval[0] == 'P' && stacksz > 0)
                {
                    elem = (stackelem_t*)list_head(stack);
                    dst =  elem->floatval;
                    pushdst();
                    sprintf(message, "<<DUPLICATE LAST VALUE>>");
                }
                /* Free memory and exit program */
                else if (strval[0] == 'X')
                {
                    savestack();
                    clrscr();
                    cputs("<<BACK TO BASIC>>\n");
                    clearstack();
                    free(stack);
                    return 0;
                }
                /* Clear Stack */
                else if (strval[0] == 'C')
                {
                    clearstack();
                    sprintf(message, "<<CLEAR STACK>>");
                }
                /* Swap the last two elements on the stack */
                else if (strval[0] == 'W' && stacksz >= 2)
                {
                        elem = (stackelem_t*)list_head(stack);
                        fp1 = elem->floatval;
                        temp = (stackelem_t*)list_head(stack)->next;
                        fp2 = temp->floatval;
                        elem->floatval = fp2;
                        temp->floatval = fp1;
                        sprintf(message,"<<SWAP LAST TWO VALUES>>");
                }
                else if (strval[0] == 'H')
                {
                    clrscr();
                    cputs("Stack Operations\n");
                    cputs("================\n");
                    cputs("(D)rop (C)lear s(W)ap du(P)\n\n");
                    cputs("Single Value Operations\n");
                    cputs("=======================\n");
                    cputs("(N)eg (R)eciprocal (S)quare Root");
                    cputs("s(I)n c(O)s (T)an (A)tn (L)og\n");
                    cputs("(E)exp #-rad @-deg ([)pi\n");
                    cputs("(&)log10 \n\n");
                    cputs("Two Value Operations\n");
                    cputs("====================\n");
                    cputs("(+)add (-)sub (*)mul (/)div\n");
                    cputs("(%)pct (^)pwr ($)n-root\n");
                    cputs("(])log base\n\n");
                    cputs("<<press any key to continue>>\n");
                    while(!kbhit());
                }
                else
                {
                    /* Ensure at least two values are on the stack */
                    if (stacksz >= 2)
                    {
                        elem = (stackelem_t*)list_head(stack);
                        fp1 = elem->floatval;
                        elem = (stackelem_t*)list_head(stack)->next;
                        fp2 = elem->floatval;
                        success = true;
                        sprintf(operation, "%f %c %f",&fp1, strval[0], &fp2);
                        switch (strval[0])
                        {
                            case '+' :
                                _fadd(&dst, &fp1, &fp2);
                                break;
                            case '-' :
                                _fsub(&dst, &fp1, &fp2);
                                break;
                            case '*' :
                                _fmul(&dst, &fp1, &fp2);
                                break;
                            case '%' :
                                _fdiv10(&dst, &fp2);
                                fp2 = dst;
                                _fdiv10(&dst, &fp2);
                                fp2 = dst;
                            case '/' :
                                if (!fp2.exp && !fp2.msb && !fp2.lsb)
                                {
                                    success = false;
                                    sprintf(message, "<<CAN'T DIVIDE BY ZERO>>");
                                }
                                else
                                    _fdiv(&dst, &fp1, &fp2);
                                break;
                            case '^' :
                                if(!_fpow(&dst, &fp1, &fp2))
                                {
                                    success = false;
                                    sprintf(message, "<<OVERFLOW ON POW>>");
                                }
                                break;
                            case '$' :
                                if(!_froot(&dst, &fp1, &fp2))
                                {
                                    success = false;
                                    sprintf(message, "<<OVERFLOW ON ROOT>>");
                                }
                                break;
                            case ']' :
                                _flogbase(&dst, &fp1, &fp2);
                                break;
                           default :
                                success = false;
                                sprintf(message, "<<UNKNOWN COMMAND>>");
                                break;

                        }
                        /* If successful push result on stack */
                        if (success)
                        {
                            sprintf(message, "<<%s = %f>>", operation, &dst);
                            dropelem();
                            dropelem();
                            pushdst();
                        }
                    }
                }
            }
            else
            {
                /* Push float value to the stack */
                _atof(strval, &dst);
                pushdst();
                sprintf(message, "");
            }
        }
    }
    return -1;
}


