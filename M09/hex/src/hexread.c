#include "hexread.h"
#include <stdio.h>

/* Prints the given file as hexdump, at most 16 numbers per line.
 * <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int file_to_hex(const char* filename) {
    FILE* f = fopen(filename, "r");

    if(!f)
        return -1;

    int c = fgetc(f);
    int i = 0;

    while(c != EOF) {
        printf("%02x ", c);

        i++;

        if(i % 16 == 0) 
            printf("\n");

        c = fgetc(f);
    }

    fclose(f);

    return i;
}
