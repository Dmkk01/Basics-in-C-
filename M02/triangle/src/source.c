#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size) {
    for(unsigned int y = 1; y <= size; y++) {
        for(unsigned int x = 1; x <= size; x++) {
            if(y <= size-x)
                printf(".");
            else
                printf("#");
        }
        
        printf("\n");
    }
}
