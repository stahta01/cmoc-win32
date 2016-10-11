
// NOTE: This is work in progress. It wont be ready for weeks.

// The aim is to write a Tiny Assembler Code (TAC) compiler, which
// will take C strings and compile to 6809 code.

// The code must be untra small, fast and usable for large projects.

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAC_TYP_VAL     1
#define TAC_TYP_REG     2

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
    for (; tac.sym && strncmp(tac.sym->name, name, size); tac.sym = tac.sym->next);
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

void tac_eatval(void)
{
    tac.sym->value = strtoi(tac.src, &tac.src, 0);
    tac.chr = *tac.src;
}

void tac_eatsym(void)
{
    char mod = tac.chr;
    if (mod == TAC_MOD_PTR || mod == TAC_MOD_VAL) {
        EATCHR;
    }
    if ((tac.chr & 192) == 64) {
        for (tac.tok = tac.src; (tac.chr & 192) == 64; EATCHR);
        tac_addsym(tac.tok, tac.src - tac.tok, TAC_TYP_VAL);
    } else {
        tac.sym = tac.numb;
        tac_eatval();
    }
    tac.sym->mod = mod;
}

void tac_compile(void)
{
    tac.chr = *tac.src;
    while (tac.chr) {
        tac_eatspc();
        sym_t* lft = tac.sym;
        switch (tac.chr) {
        case ':':
            EATCHR;
            tac.sym->value = tac.dst;
            break;
        case '=':
            EATCHR;
            tac_eatsym();
            if (lft->type == TAC_TYP_VAL) {
                if (tac.sym->type == TAC_TYP_VAL) {
                    lft->value = tac.sym->value;
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
    tac_addsym("N", 1, TAC_TYP_VAL);
    tac.numb = tac.sym;
    return;
    tac_addsym("A", 1, TAC_TYP_REG);
    tac.rega = tac.sym;
    tac_addsym("B", 1, TAC_TYP_REG);
    tac.regb = tac.sym;
    tac_addsym("D", 1, TAC_TYP_REG);
    tac.regd = tac.sym;
    tac_addsym("X", 1, TAC_TYP_REG);
    tac.regx = tac.sym;
    tac_addsym("Y", 1, TAC_TYP_REG);
    tac.regy = tac.sym;
}

int main(void)
{
    tac_init();
    tac.dst = 0x6000;
    tac.src = "PEAR=0xFF APPLE=PEAR *1024=A";
    tac_compile();
    for (sym_t* sym = tac.top; sym; sym = sym->next) {
        cprintf("$%06i %s\n", sym->value, sym->name);
    }
    return 0;
}

