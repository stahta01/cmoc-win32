
// This is a version of the DDS-BASIC interpreter by Diomidis Spinellis 1990
// annotated by Michael Somos 1997

// The original "obfuscated" version can be found here:
// http://www.nicholson.com/rhn/files/dds_basic.c

// I found this version at:
// http://mit.edu/~ecprice/mulinux/sources/ddsbasic.c

// I cleaned up the code a little, changed some code which CMOC doesn't handle,
// reduced the size of the arrays and added breaking. There is a "bug" in WinCMOC 0.6
// which caused DDS-BASIC to only accept 2 digit numbers. I fixed the issue, but it
// shouldn't effect any normal C code. DDS-BASIC does some strange things.

// You can reduce the size of the bin, but removing the printf's, and using system()
// to save the BASIC source. There are lots of things that can be done. I could play with
// this code for hours, but, i'll leave it like it is.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define strtol strtoi

#define SMAX 100                                    // 999
#define CMAX 256
#define BMAX 80                                     // 999
#define LMAX 100                                    // 9999

typedef char* STRPTR;

int E[SMAX];                                        // subroutine line number stack
int L[CMAX];                                        // FOR loop beginning line number
int M[CMAX];                                        // FOR loop maximum index value
int P[CMAX];                                        // program variable value
int l, i, j;
int* C;                                             // subroutine stack pointer
char B[BMAX];                                       // command input buffer
char F[2];                                          // temporary search string
STRPTR m[1 + LMAX];                                 // pointers to lines of program
STRPTR p, q, x, y, z, s, d;
FILE* f;                                            // file pointer for input and output

void G(void);
int S(void);
int J(void);
int K(void);
int V(void);
int W(void);
int Y(void);

STRPTR strstr(STRPTR s, STRPTR o)
{
    STRPTR x , y , z ;
    for ( x = s ; * x ; x ++ ) {
        for ( y = x , z = o ; * z && * y == * z ; y ++ ) {
            z ++ ;
        }
        if ( z > o && ! * z ) {
            return x ;
        }
    }
    return 0 ;
} /* end strstr */

int main(void)
{
    system("WIDTH40");
    clrscr();
    puts("DDS-BASIC INTERPRETER\nBY DIOMIDIS SPINELLIS 1990\n");

    m[LMAX] = "E";                                  // "END"
    for (;;) {
        puts("OK");
        gets(B);
        switch (*B) {
        case 'R':                                   // "RUN" command
            C = E;
            l = 1;
            // initialize variables
            for (i = 0; i < CMAX; P[i++] = 0);

            while (l) {
                // Added breaking. Press END key when running Vcc.
                if (kbhit() && getch() == 3) {
                    break;
                }
                while (!(s = m[l])) {
                    l++;
                }
                if (!strstr(s , "\"")) {
                    while ((p = strstr(s, "<>"))) {
                        *p++= '#';
                        *p = ' ';
                    }
                    while ((p = strstr(s , "<="))) {
                        *p++ = '$';
                        *p = ' ';
                    }
                    while ((p = strstr(s , ">="))) {
                        *p++ = '!';
                        *p = ' ';
                    }
                }
                d = B;
                while ((*F = *s)) {
                    if (*s == '"') {
                        j++;
                    }
                    if (j & 1 || !strstr(" \t", F)) {
                        *d++ = *s;
                    }
                    s++;
                }
                *d-- = (char)(j = 0);
                if (B[1] != '=') switch (*B) {
                    case 'E':                       // "END"
                        l = -1;
                        break;
                    case 'R':                       // "REM"
                        if (B[2] != 'M') {
                            l = *--C;               // "RETURN"
                        }
                        break;
                    case 'I':
                        if (B[1] == 'N') {          // "INPUT"
                            gets(p = B);
                            P[*d] = S();

                        } else {                    // "IF"
                            *(q = strstr(B, "TH")) = 0; // "THEN"
                            p = B + 2;
                            if (S()) {
                                p = q + 4;
                                l = S() - 1;
                            }
                        }
                        break;
                    case 'P':                       // "PRINT"
                        if (B[5] == '"') {
                            *d = 0;
                            puts(B + 6);
                        } else {
                            p = B + 5;
                            printf("%d\n", S());
                        }
                        break;
                    case 'G':                       // "GOTO"
                        p = B + 4;
                        if (B[2] == 'S') {          // "GOSUB"
                            *C++ = l;
                            p++;
                        }
                        l = S() - 1;
                        break;
                    case 'F':                       // "FOR"
                        *(q = strstr(B , "TO")) = 0; // "TO"
                        p = B + 5;
                        P[i = B[3]] = S();
                        p = q + 2;
                        M[i] = S();
                        L[i] = l;
                        break;
                    case 'N':                       // "NEXT"
                        if (++P[*d] <= M[*d]) {
                            l = L [*d];
                        }
                    }
                else {
                    p = B + 2;
                    P [*B] = S();
                }
                l++;
            }
            break;
        case 'L':                                   // "LIST" command
            for (i = 0; i < LMAX; i++)  {
                if (m[i]) {
                    printf("%d %s\n", i , m[i]);
                }
            }
            break;
        case 'N':                                   // "NEW" command
            for (i = 0; i < LMAX; i++) {
                if (m[i]) {
                    free(m[i]);
                    m[i] = 0;
                }
            }
            break;
        case 'B':                                   // "BYE" command
            return 0;
            break;
        case 'S':                                   // "SAVE" command
            f = fopen(B + 5, "w") ;
            for (i = 0; i < LMAX; i++)  {
                if (m[i]) {
                    fprintf(f, "%d %s\n", i , m[i]);
                }
            }
            fclose(f);
            break;
        case 'O':                                   // "OLD" command
            f = fopen(B + 4, "r");
            while (fgets(B, BMAX, f)) {
                *strstr(B, "\n") = 0;
                G();
            }
            fclose(f);
            break;
        case 0:
        default:
            G();
        }
    }
    return 0;
}

// get program line from buffer

void G(void)
{
    l = atoi(B);
    if (m[l]) {
        free(m[l]);
    }
    if ((p = strstr(B, " "))) {
        strcpy(m[l] = (char*)malloc(strlen(p)), p + 1);
    } else {
        m[l] = 0;
    }
}

// recursive descent parser for arithmetic/logical expressions

int S(void)
{
    int o = J();
    switch (*p++) {
    case '=':
        return o == S();
        break;
    case '#':
        return o != S();
    default:
        p--;
        return o;
    }
}

int J(void)
{
    int o = K();
    switch (*p++) {
    case '<':
        return o < J();
        break ;
    case '>':
        return o > J();
    default:
        p--;
        return o;
    }
}

int K(void)
{
    int o = V();
    switch (*p++) {
    case '$':
        return o <= K();
        break;
    case '!':
        return o >= K();
    default:
        p--;
        return o;
    }
}

int V(void)
{
    int o = W();
    switch (*p++) {
    case '+':
        return o + V();
        break;
    case '-':
        return o - V();
    default:
        p--;
        return o;
    }
}

int W(void)
{
    int o = Y();
    switch (*p++) {
    case '*':
        return o * W();
        break;
    case '/':
        return o / W();
    default:
        p--;
        return o;
    }
}

int Y(void)
{
    int o;
    if (*p == '-') {
        p++;
        return -Y();
    }
    if (*p >= '0' && *p <= '9') {
        return strtol(p, &p, 0);
    }
    if (*p == '(') {
        p++;
        o = S();
        p++;
        return o;
    }
    return P[*p++];
}

