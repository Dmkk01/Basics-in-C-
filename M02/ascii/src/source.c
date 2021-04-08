#include "source.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ascii_chart(char min, char max) {
    for(int i=1; min <= max; min++, i++) {
        if(isprint(min))
            printf("%3d 0x%02x %c", min, min, min);
        else
            printf("%3d 0x%02x ?", min, min);

        if(i % 4 == 0)
            printf("\n");
        else
            printf("\t");
    }
}
