#include "stringsplit.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Split string by another string, return split parts + NULL in array.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */

char** split_string(const char* str, const char* split) {
    // Create an array
    char** array = malloc(sizeof(char*));
    array[0] = NULL;

    int c = 0;

    // Loop through the str
    while(1) {
        // Find the split
        char* ptr = strstr(str, split);

        if(!ptr)
            break;

        // Allocate more memory
        array = realloc(array, (c+2) * sizeof(char*));
        array[c+1] = NULL;

        int len = ptr-str;

        // Reserve memory part
        array[c] = calloc(len+1, sizeof(char));

        // Copy the part of the string
        strncpy(array[c], str, len);

        str = ptr + strlen(split);
        c++;
    }

    int l = strlen(str);
    array = realloc(array, (c+2) * sizeof(char*));
    array[c] = calloc(l+1, sizeof(char));
    strncpy(array[c], str, l);
    array[c+1] = NULL;

    // Return the array
    return array;
}

void print_split_string(char** split_string) {
    for(int i=0; split_string[i]!=NULL; i++) {
        printf("%s\n", split_string[i]);
    }
}

void free_split_string(char** split_string) {
    for(int i=0; split_string[i]!=NULL; i++) {
        free(split_string[i]);
    }

    free(split_string);
}



