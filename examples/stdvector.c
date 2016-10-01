
// Simple example of using C++ style vectors with CMOC.
// The qsort function is now from kreiderlib.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <std/vector.h>

// Note: There are still some issues with CMOC's optimizations. If you
// see something unexpected, try to switch off optimizations using:

//#pragma options --optimize=2

typedef struct {
    char name[20];
    int year;
} game_t;

typedef std_vector(game_t) games_t;

game_t* game_init(game_t* dst, char* name, int year)
{
    strcpy(dst->name, name);
    dst->year = year;
    return dst;
}

void games_add(games_t* games, char* name, int year)
{
    game_t game;
    std_vector_add(games, game_init(&game, name, year));
}

int order = 1;

int game_compare_year(game_t* a, game_t* b)
{
    return (a->year - b->year) * order;
}

int game_compare_name(game_t* a, game_t* b)
{
    return strcmp(a->name, b->name) * order;
}

int main(void)
{
    games_t games = {0, 0};

    games_add(&games,  "SPACE INVADERS", 1980);
    games_add(&games,  "STAR RAIDERS", 1982);
    games_add(&games,  "FROGGER", 1982);
    games_add(&games,  "ASTEROIDS", 1981);
    games_add(&games,  "SURROUND", 1977);
    games_add(&games,  "TRACK & FIELD", 1983);
    games_add(&games,  "VIDEO CHESS", 1979);
    games_add(&games,  "XENOPHOBE", 1990);
    games_add(&games,  "AIR RAID", 1982);
    games_add(&games,  "BURGERTIME", 1982);

    for (;;) {
        clrscr();
        puts("LIST OF POPULAR 2600 GAMES\n");
        for (int i = 0; i < games.size; i++) {
            printf("%2d: %4d %s\n", i + 1, games.data[i].year, games.data[i].name);
        }
        puts("\nSORT BY [Y]EAR/[N]AME OR E[X]IT");
        switch (getch()) {
        case 'Y':
            qsort(games.data, games.size, sizeof(*games.data), game_compare_year);
            break;
        case 'N':
            qsort(games.data, games.size, sizeof(*games.data), game_compare_name);
            break;
        case 'X':
            goto done;
        }
        order = -order;
    }
done:
    puts("BACK TO BASIC");
    return 0;
}

