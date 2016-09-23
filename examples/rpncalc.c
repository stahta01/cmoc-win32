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
#pragma options -machine=coco --optimize=2

#include <sac.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <stdarg.h>
#include <equates.h>
#include <ctype.h>

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

int main(void)
{
    if (stack)
    {
        char line[33];
        int pos;
        bool success;

        for (;;)
        {
            clrscr();
            cputs("cmoc rpn calc-BRIAN HOLMAN\n");
            cputs("E(X)IT (D)ROP (C)LEAR (N)NEG\n");
            cputs("(+)ADD (-)SUB (*)MUL (/)DIV\n");
            cputs("(%)PCT (S)SWAP (R)ECIPROCAL\n");
            cputs("===========================\n");

            /* Display Stack */
            pos = stacksz;
            elem = (stackelem_t*)list_tail(stack);
            while (pos)
            {
                cprintf("%02d: %f\n", pos, &elem->floatval);
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
                    dropelem();
                /* Negative of last element */
                else if (strval[0] == 'N' && stacksz > 0)
                {
                    elem = (stackelem_t*)list_head(stack);
                    _atof(&fp2,"-1");
                    fp1 = elem->floatval;
                    _fmul(&elem->floatval, &fp1, &fp2);
                }
                /* Reciprocal of last element */
                else if (strval[0] == 'R' && stacksz > 0)
                {
                    elem = (stackelem_t*)list_head(stack);
                    _atof(&fp1,"1");
                    fp2 = elem->floatval;
                    _fdiv(&elem->floatval, &fp1, &fp2);
                }
                /* Free memory and exit program */
                else if (strval[0] == 'X')
                {
                    clrscr();
                    cputs("<<BACK TO BASIC>>\n");
                    clearstack();
                    free(stack);
                    return 0;
                }
                /* Clear Stack */
                else if (strval[0] == 'C')
                    clearstack();
                /* Swap the last two elements on the stack */
                else if (strval[0] == 'S' && stacksz >= 2)
                {
                        elem = (stackelem_t*)list_head(stack);
                        fp1 = elem->floatval;
                        temp = (stackelem_t*)list_head(stack)->next;
                        fp2 = temp->floatval;
                        elem->floatval = fp2;
                        temp->floatval = fp1;

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
                        cprintf("%f %f\n", &fp1, &fp2);
                        success = true;
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
                                    success = false;
                                else
                                    _fdiv(&dst, &fp1, &fp2);
                                break;
                            default :
                                success = false;
                                break;

                        }
                        /* If successful push result on stack */
                        if (success)
                        {
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
                _atof(&dst, strval);
                pushdst();
            }
        }
    }
    return -1;
}


