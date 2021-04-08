#include "filebasics.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Print give file <filename> to the standard output stream.
 * Return number of characters printed, -1 if file opening fails.
 */
int print_file_and_count(const char* filename) {
    FILE* f = fopen(filename, "r");

    if(!f)
        return -1;

    int c = fgetc(f);
    int i = 0;

    while(c != EOF) {
        printf("%c", c);
        i++;
        c = fgetc(f);
    }

    fclose(f);

    return i;
}

/* Compare two files. The function should return the first lines that differ
 * in the two files, concatenated together, separated by four dashes, on
 * different lines. If the files are equal, NULL is returned. 
 * Function stops immediately, if either one of the files end and returns NULL.
 * You can assume that lines are not longer than 1000 characters.
 */
char *difference(const char* file1, const char* file2) {
    FILE* f1 = fopen(file1, "r");
    if(!f1)
        return NULL;

    FILE* f2 = fopen(file2, "r");
    if(!f2) {
        fclose(f1);
        return NULL;
    }

    char line1[1000];
    char line2[1000];

    char* combined = NULL;

    while(fgets(line1, 1000, f1) && fgets(line2, 1000, f2)) {
        if(strcmp(line1, line2)) {
            combined = malloc(strlen(line1)+strlen(line2)+strlen("----\n")+1);
            strcpy(combined, line1);
            strcat(combined, "----\n");
            strcat(combined, line2);
            break;
        }
    }

    fclose(f1);
    fclose(f2);

    return combined;
}


