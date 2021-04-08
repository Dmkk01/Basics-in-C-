#include "gameoflife.h"
#include <stdlib.h>
#include <stdio.h>

/* Exercise a: Allocates needed memory for the GameArea structure and
 * the actual game area. 'x_size' and 'y_size' indicate the horizontal and
 * vertical dimensions of the GameArea.
 * 
 * Returns: pointer to the GameArea structure allocated by this function.
 */
GameArea* createGameArea(unsigned int x_size, unsigned int y_size) {
    GameArea* a = malloc(sizeof(GameArea));
    a->x_size = x_size;
    a->y_size = y_size;

    a->cells = malloc(y_size * sizeof(CellStatus*));
    for(unsigned int y=0; y<y_size; y++) {
        a->cells[y] = malloc(x_size * sizeof(CellStatus));
        for(unsigned int x=0; x<x_size; x++) {
            a->cells[y][x] = DEAD;
        }
    }

    return a;
}

/* Free memory allocated for GameArea <a>.
 */
void releaseGameArea(GameArea* a) {
    for(unsigned int y=0; y<a->y_size; y++) {
        free(a->cells[y]);
    }

    free(a->cells);
    free(a);
}

/* Exercise b: Initialize game GameArea by setting exactly <n> cells into
 * ALIVE CellStatus in the game GameArea <a>.
 */
void initGameArea(GameArea* a, unsigned int n) {
    for( ; n>0; n--) {
        int x = rand() % a->x_size;
        int y = rand() % a->y_size;

        while(a->cells[y][x] == ALIVE) {
            x = rand() % a->x_size;
            y = rand() % a->y_size;
        }
        
        a->cells[y][x] = ALIVE;
    }
}

/* Exercise c: Output the current CellStatus of GameArea <a>.
 */
void printGameArea(const GameArea* a) {
    for(unsigned int y=0; y<a->y_size; y++) {
        for(unsigned int x=0; x<a->x_size; x++) {
            printf("%c", a->cells[y][x] ? '*' : '.');

            // The above with the ternary operator ? : is the same as
            /*
            if(a->cells[y][x] == ALIVE)
                printf("%c", '*');
            */
        }
        printf("\n");
    }
}

/* Calculates number of live neighbours around position (x,y),
 * and returns the count.
 */
unsigned int live_neighbours(const GameArea* a, unsigned int x, unsigned int y) {
    unsigned int n=0;

    for(int i = -1; i<=1; i++) {
        for(int j = -1; j<=1; j++) {
            if((int)x+j < 0 || x+j >= a->x_size || (int)y+i < 0 || y+i >= a->y_size)
                continue;

            if(i==0 && j==0)
                continue;

            if(a->cells[y+i][x+j] == ALIVE) {
                n++;
            }
        }
    }

    return n;
}

/* Exercise d: Advance GameArea <a> by one generation.
 */
void gameTick(GameArea* a) {
    CellStatus** c = malloc(a->y_size * sizeof(CellStatus*));
    for(unsigned int y = 0; y<a->y_size; y++) {
        c[y] = malloc(a->x_size * sizeof(CellStatus));
    }
    
    for(unsigned int y=0; y<a->y_size; y++) {
        for(unsigned int x=0; x<a->x_size; x++) {
            int n = live_neighbours(a, x, y);

            c[y][x] = a->cells[y][x];

            if(a->cells[y][x] == ALIVE) {
                if(n==2 || n==3) 
                    c[y][x] = ALIVE;
                else
                    c[y][x] = DEAD;
            } else {
                if(n==3) {
                    c[y][x] = ALIVE;
                }
            }
        }
    }

    for(unsigned int y = 0; y<a->y_size; y++) {
        free(a->cells[y]);
    }
    free(a->cells);

    a->cells = c;
}
