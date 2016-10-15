
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
#include <charset.h>
#include <exception.h>


void print_help(void)
{
    clrscr();
    cputs(
        "Stack Operations\n"
        "================\n"
        "(D)rop (C)lear s(W)ap du(P)\n\n"
        "Single Value Operations\n"
        "=======================\n"
        "(N)eg (R)eciprocal (S)quare Root"
        "s(I)n c(O)s (T)an (A)tn (L)og\n"
        "(E)exp #-rad @-deg ([)pi\n"
        "(&)log10 \n\n"
        "Two Value Operations\n"
        "====================\n"
        "(+)add (-)sub (*)mul (/)div\n"
        "(%)pct (^)pwr ($)n-root\n"
        "(])log base\n\n"
        "<<press any key to continue>>\n");
    getch();
}

#define SAVEFILE "RPNCALC.DAT"

#define HASH '#'

typedef union {
    float_t floatval;
    byte bytearr[5];
} floatarr_t ;

/*
void _fhex(float_t* src)
{
    floatarr_t* temp;
    temp = (floatarr_t*)src;

    for (int i=0; i < 5; i++) {
        cprintf("[%02X]", temp->bytearr[i]);
    }
    cprintf("\n");
}
*/

typedef struct {
    node_t node;
    float_t floatval;
} stackelem_t;

typedef char floatstr_t[30];

char* trimwhitespace(char* str)
{
    char* end;
    /* Trim leading space */
    while (isspace(*str)) {
        str++;
    }
    if (*str == 0) { /* All spaces? */
        return str;
    }
    /* Trim trailing space */
    end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) {
        end--;
    }
    /* Write new null terminator */
    *(end+1) = 0;
    return str;
}

list_t* stack = list_create();
char message[80];
int stacksz = 0;

void dropelem(void)
{
    if (stacksz > 0) {
        free(list_pull_head(stack));
        stacksz--;
    }
}

void clearstack(void)
{
    for (stackelem_t* elem; elem = (stackelem_t*)list_pull_head(stack);) {
        free(elem);
    }
    stacksz = 0;
}

void pushdst(float_t* value)
{
    stackelem_t* elem = new(stackelem_t);
    elem->floatval = *value;
    list_push_head(stack, &elem->node);
    stacksz++;
}

void savestack()
{
    FILE* fp = fopen(SAVEFILE, "wb");
    if (fp) {
        cputs("<<SAVING STACK TO DISK>>\n");
        int pos = stacksz;
        stackelem_t* elem = (stackelem_t*)list_tail(stack);
        while (pos) {
            fwrite(&elem->floatval, sizeof(float_t), 1, fp);
            elem = (stackelem_t*)(elem->node.prev);
            pos--;
        }
        fclose(fp);
    }
}

void loadstack()
{
    FILE* fp = fopen(SAVEFILE, "rb");
    if (fp) {
        cputs("<<LOADING STACK FROM DISK>>\n");
        while (!feof(fp)) {
            float_t dst;
            fread(&dst, sizeof(float_t), 1, fp);
            if (!feof(fp)) {
                pushdst(&dst);
            }
        }
        fclose(fp);
    }
}

void msg_fun(char* name, float_t* f1, float_t* f2)
{
    floatstr_t ts1, ts2;
    swritef(message, "<<%s(%s) = %s>>", name, _ftoa(f1, ts1), _ftoa(f2, ts2));
}

void msg_opr(char* op, float_t* f1, float_t* f2, float_t* f3)
{
    floatstr_t ts1, ts2, ts3;
    swritef(message, "%s %s %s = %s", _ftoa(f1, ts1), op, _ftoa(f2, ts2), _ftoa(f3, ts3));
}

int main(void)
{
    system("WIDTH40");
    malloc_uses_gmalloc = true;

    *(byte*)0xff22 |= 16;                       // Lowercase mode.

    if (stack) {
        message[0] = 0;
        /* Don't allow an Overflow to terminate the program to basic */
        POKE(0xBA92, 0x39);
        loadstack();
        for (;;) {
            clrscr();
            cputs("CMOC RPN Calculator-Brian Holmane(X)it (H)elp\n\n");
            if (message[0]) {
                cputs(message);
                cputc('\n');
            }

            /* Display Stack */
            int pos = stacksz;
            stackelem_t* elem = (stackelem_t*)list_tail(stack);
            while (pos) {
                floatstr_t tmp;
                cwritef("%d: %s\n", pos, _ftoa(&elem->floatval, tmp));
                // _fhex(&elem->floatval);
                elem = (stackelem_t*)(elem->node.prev);
                pos--;
            }

            /* Prompt for input and trim whitespace */
            char line[33];
            line[0] = 31;
            cputc(']');
            cgets(line);
            cputc('\n');
            char* strval = trimwhitespace(line+2);
            char cmd = strval[0];

            /* Check if valid command or value */
            if (cmd && !strval[1] && !isdigit(cmd)) {
                if (cmd == 'H') {
                    print_help();
                }
                /* Free memory and exit program */
                else if (cmd == 'X') {
                    savestack();
                    clrscr();
                    cputs("<<BACK TO BASIC>>\n");
                    clearstack();
                    free(stack);
                    return 0;
                }
                /* Clear Stack */
                else if (cmd == 'C') {
                    clearstack();
                    strcpy(message, "<<CLEAR STACK>>");
                }
                /* Drop last element off stack */
                else if (cmd == 'D') {
                    dropelem();
                    strcpy(message, "<<DROP LAST VALUE>>");
                }
                /* Push PI */
                else if (cmd == '[') {
                    pushdst((float_t*)FP_PI);
                } else if (stacksz > 0) {
                    elem = (stackelem_t*)list_head(stack);
                    float_t res, fp1 = elem->floatval;

                    /* Negative of last element */
                    if (cmd == 'N') {
                        msg_fun("NEG", &fp1, _fmul(&elem->floatval, &fp1, (float_t*)FP_MINUSONE));
                    }
                    /* Reciprocal of last element */
                    else if (cmd == 'R') {
                        msg_fun("INV", &fp1, _fdiv(&elem->floatval, (float_t*)FP_ONE, &fp1));
                    }
                    /* Square root of last element */
                    else if (cmd == 'S') {
                        msg_fun("SQRT", &fp1, _fsqrt(&elem->floatval, &fp1));
                    }
                    /* Sin of last element */
                    else if (cmd == 'I') {
                        msg_fun("SIN", &fp1, _fsin(&elem->floatval, &fp1));
                    }
                    /* Cos of last element */
                    else if (cmd == 'O') {
                        msg_fun("COS", &fp1, _fcos(&elem->floatval, &fp1));
                    }
                    /* Tan of last element */
                    else if (cmd == 'T') {
                        msg_fun("TAN", &fp1, _ftan(&elem->floatval, &fp1));
                    }
                    /* Atn of last element */
                    else if (cmd == 'A') {
                        msg_fun("ATN", &fp1, _fatan(&elem->floatval, &fp1));
                    }
                    /* Log of last element */
                    else if (cmd == 'L') {
                        if (_fsign(&fp1) > 0) {
                            msg_fun("LOG", &fp1, _flog(&elem->floatval, &fp1));
                        }
                    }
                    /* Log 10 of last element */
                    else if (cmd == '&') {
                        if (_fsign(&fp1) > 0) {
                            msg_fun("LOG10", &fp1, _flog10(&elem->floatval, &fp1));
                        }
                    }
                    /* Exponent */
                    else if (cmd == 'E') {
                        _fsub(&res, &fp1, (float_t*)FP_MAXEXP);
                        if (_fsign(&res) <= 0) {
                            msg_fun("EXP", &fp1, _fexp(&elem->floatval, &fp1));
                        } else {
                            strcpy(message, "<<OVERFLOW ON EXP>>");
                        }
                    } else if (cmd == '@') {
                        msg_fun("DEG", &fp1, _fdeg(&elem->floatval, &fp1));
                    } else if (cmd == HASH) {
                        msg_fun("RAD", &fp1, _frad(&elem->floatval, &fp1));
                    } else if (cmd == 'P') {
                        pushdst(&fp1);
                        strcpy(message, "<<DUPLICATE LAST VALUE>>");
                    }
                    /* Ensure at least two values are on the stack */
                    else if (stacksz >= 2) {
                        stackelem_t* temp = (stackelem_t*)list_head(stack)->next;
                        float_t fp2 = temp->floatval;
                        /* Swap the last two elements on the stack */
                        if (cmd == 'W') {
                            elem->floatval = fp2;
                            temp->floatval = fp1;
                            strcpy(message,"<<SWAP LAST TWO VALUES>>");
                        } else {
                            bool success = true;
                            switch (cmd) {
                            case '+' :
                                _fadd(&res, &fp1, &fp2);
                                break;
                            case '-' :
                                _fsub(&res, &fp1, &fp2);
                                break;
                            case '*' :
                                _fmul(&res, &fp1, &fp2);
                                break;
                            case '%' :
                                _fdiv10(&res, &fp2);
                                fp2 = res;
                                _fdiv10(&res, &fp2);
                                fp2 = res;
                            case '/' :
                                if (!fp2.exp && !fp2.msb && !fp2.lsb) {
                                    success = false;
                                    strcpy(message, "<<CAN'T DIVIDE BY ZERO>>");
                                } else {
                                    _fdiv(&res, &fp1, &fp2);
                                }
                                break;
                            case '^' :
                                if (!_fpow(&res, &fp1, &fp2)) {
                                    success = false;
                                    strcpy(message, "<<OVERFLOW ON POW>>");
                                }
                                break;
                            case '$' :
                                if (!_froot(&res, &fp1, &fp2)) {
                                    success = false;
                                    strcpy(message, "<<OVERFLOW ON ROOT>>");
                                }
                                break;
                            case ']' :
                                _flogbase(&res, &fp1, &fp2);
                                break;
                            default :
                                success = false;
                                strcpy(message, "<<UNKNOWN COMMAND>>");
                                break;

                            }
                            /* If successful push result on stack */
                            if (success) {
                                msg_opr(strval, &fp1, &fp2, &res);
                                dropelem();
                                dropelem();
                                pushdst(&res);
                            }
                        }
                    }
                }
            } else {
                /* Push float value to the stack */
                float_t value;
                _atof(strval, &value);
                pushdst(&value);
                strcpy(message, "");
            }
        }
    }
    return -1;
}

