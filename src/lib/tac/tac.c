
// NOTE: This is work in progress. It wont be ready for weeks.

// The aim is to write a Tiny Assembler Compiler (TAC), which
// will take C strings and compile to 6809 code.

// The code must be untra small, fast and usable for large projects.

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAC_TYP_N       0
#define TAC_TYP_A       1
#define TAC_TYP_B       2
#define TAC_TYP_D       3
#define TAC_TYP_X       4
#define TAC_TYP_Y       5
#define TAC_TYP_U       6
#define TAC_TYP_S       7

#define TAC_MOD_VAL     '#'
#define TAC_MOD_PTR     '*'

typedef struct sym_t {
    struct sym_t* next;
    byte type, mod;
    char* name;
    word value;
} sym_t;

typedef struct {
    byte* dst;
    char chr, *tok, *src;
    sym_t* sym;
    sym_t* top;
    sym_t* numb;
    sym_t* rega;
    sym_t* regb;
    sym_t* regd;
    sym_t* regx;
    sym_t* regy;
} TAC_t;

TAC_t tac;

void tac_locsym(char* name, size_t size)
{
    tac.sym = tac.top;
    for (; tac.sym && strmcmp(tac.sym->name, name, size); tac.sym = tac.sym->next);
}

void tac_newsym(char* name, size_t size, byte type)
{
    tac.sym = (sym_t*)malloc(sizeof(sym_t));
    if (tac.sym) {
        tac.sym->next = tac.top;
        tac.top = tac.sym;
        tac.sym->type = type;
        tac.sym->value = tac.sym->mod = 0;
        tac.sym->name = (char*)malloc(size + 1);
        if (tac.sym->name) {
            ((char*)memcpy(tac.sym->name, name, size))[size] = 0;
        }
    }
}

void tac_addsym(char* name, size_t size, byte type)
{
    tac_locsym(name, size);
    if (!tac.sym) {
        tac_newsym(name, size, type);
    }
}

#define EATCHR (tac.chr = *++tac.src)

void tac_eatspc(void)
{
    for (; tac.chr && tac.chr <= 32; EATCHR);
}

void tac_eatnum(void)
{
    tac.sym = tac.numb;
    tac.sym->value = strtoi(tac.src, &tac.src, 0);
    tac.chr = *tac.src;
}

void tac_eatsym(void)
{
    char mod = tac.chr;
    if (mod == TAC_MOD_PTR || mod == TAC_MOD_VAL) {
        EATCHR;
    }
    if (isalpha(tac.chr)) {
        for (tac.tok = tac.src; isalnum(tac.chr); EATCHR);
        tac_addsym(tac.tok, tac.src - tac.tok, TAC_TYP_N);
    } else {
        tac_eatnum();
    }
    tac.sym->mod = mod;
}

void tac_compile(void)
{
    tac.chr = *tac.src;
    while (tac.chr) {
        tac_eatspc();
        sym_t* lft = tac.sym, *rgt;
        switch (tac.chr) {
        case ':':
            EATCHR;
            tac.sym->value = tac.dst;
            break;
        case '=':
            EATCHR;
            tac_eatsym();
            rgt = tac.sym;

            //
            if (lft->type) {
            } else {
                if (rgt->type) {
                   cprintf("%s %d ? %s %d\n", lft->name, lft->type, rgt->name, rgt->type);
                }
            }
            if (lft->type == TAC_TYP_N) {
                if (rgt->type == TAC_TYP_N) {
                    lft->value = rgt->value;
                }
            }
            break;
        case '+':
        case '-':
        case '&':
        case '|':
            EATCHR;
            tac_eatsym();
            lft->value = tac.sym->value;
            break;
        default:
            tac_eatsym();
        }
    }
}

void tac_init(void)
{
    tac_addsym("N", 1, TAC_TYP_N);
    tac.numb = tac.sym;
    tac_addsym("A", 1, TAC_TYP_A);
    tac.rega = tac.sym;
    return;
    tac_addsym("B", 1, TAC_TYP_B);
    tac.regb = tac.sym;
    tac_addsym("D", 1, TAC_TYP_D);
    tac.regd = tac.sym;
    tac_addsym("X", 1, TAC_TYP_X);
    tac.regx = tac.sym;
    tac_addsym("Y", 1, TAC_TYP_Y);
    tac.regy = tac.sym;
}

asm void code(void)
{
    // sty  16
    // sta  183
    // stx  191
    // stb  247
    // std  253
    // stu  255

    asm {
        stu     1024
    }
}

int main(void)
{
    int p = (int)code;

    //cprintf("%d %u\n", *(byte*)p, *(word*)(p + 1));

    tac_init();
    tac.dst = 0x6000;
    tac.src = "PEAR=0xFF APPLE=PEAR *1024=A";
    tac.src = "PEAR=0xFF APPLE=1024  APPLE2=A";
    tac_compile();
    for (sym_t* sym = tac.top; sym; sym = sym->next) {
        cprintf("$%06i %s\n", sym->value, sym->name);
    }
    return 0;
}

