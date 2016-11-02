
#include <eddie.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <sac.h>
#include <ctype.h>
#include <ascii.h>

typedef struct {
    dnode_t node;
    char* line;
} fused_line_t;

typedef struct {
    dlist_t list;
    fused_line_t* top, *cur;
    int x, y;
} fused_t;

void fused_init(fused_t* fused)
{
    dlist_init(&fused->list);
}

void fused_add_line(fused_t* fused, char* s)
{
    fused_line_t* line = new(fused_line_t);
    line->line = strdup(s);
    dlist_push_tail(&fused->list, &line->node);
}

void fused_print(fused_t* fused)
{
    clrscr();
    fused_line_t* line = fused->top;
    if (line) {
        for (int count = 14; line->node.next && count--; line = (fused_line_t*)line->node.next) {
            cputs(line->line);
            cputc('\n');
        }
    }
}

void fused_down(fused_t* fused)
{
    if (fused->cur->node.next->next) {
        fused->y++;
        fused->cur = (fused_line_t*)fused->cur->node.next;
    }
}

void fused_run(fused_t* fused)
{
    char s[100];
    for (;;) {
        gotoy(fused->y);
        strcpy(s, fused->cur->line);
        int chr = eddie_line_at(s, 32, fused->y * 32, fused->x, "\r", false);
        fused_down(fused);
    }
}

fused_t fused;

int main(void)
{
    fused_init(&fused);
    for (int i = 0; i < 8; i++) {
        fused_add_line(&fused, "HELLO THERE");
    }
    fused.top = fused.cur = (fused_line_t*)fused.list.head.next;
    fused_print(&fused);

    fused_run(&fused);

    //fused_line(s, 32, "\r", false);

    return 0;
}

