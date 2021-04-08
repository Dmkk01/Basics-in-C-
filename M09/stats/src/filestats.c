#include "filestats.h"
#include <stdio.h>
#include <ctype.h>

/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char* filename) {
    FILE* f = fopen(filename, "r");
    if(!f)
        return -1;

    int c = fgetc(f);
    int n = 0, chars = 0;

    while(c != EOF) {
        if(c == '\n') {
            chars = 0;
            n++;
        } else {
            chars++;
        }

        c = fgetc(f);
    }

    if(chars > 0)
        n++;

    fclose(f);
    return n;
}

/* Count the number of words in the file. Word has to include at least one
 * alphabetic character, and words are separated by whitespace.
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * number of words in the file */
int word_count(const char* filename) {
    FILE* f = fopen(filename, "r");
    if(!f)
        return -1;

    int c = fgetc(f), n = 0, word = 0;

    while(c != EOF) {
        if(isalpha(c))
            word = 1;
        
        if(isspace(c) && word == 1) {
            n++;
            word = 0;
        }

        c = fgetc(f);
    }

    if(word)
        n++;

    fclose(f);
    return n;
}
