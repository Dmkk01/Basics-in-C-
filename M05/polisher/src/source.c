#include <string.h>
#include <stdlib.h>
#include "source.h"

/* Remove C comments from the program stored in memory block <input>.
 * Returns pointer to code after removal of comments.
 * Calling code is responsible of freeing only the memory block returned by
 * the function.
 */
char* delete_comments(char* input) {
    char* output = malloc(strlen(input)+1);
    int j = 0;
    for(unsigned int i=0; i<strlen(input); i++) {
        if(input[i] == '/' && input[i+1] == '/') {
            while(input[i] != '\n')
                i++;
        } else if(input[i] == '/' && input[i+1] == '*') {
            while(input[i] != '*' || input[i+1] != '/') 
                i++;
            i++;
        } else {
            output[j] = input[i];
            j++;
        }
    }

    output[j] = 0;

    free(input);

    return output;
}
