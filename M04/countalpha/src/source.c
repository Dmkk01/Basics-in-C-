#include "source.h"
#include <ctype.h>

/* Count Alpha
 * Count number of alphabetic characters in the given string <str>,
 * and return the count
 */
int count_isalpha(const char* str) {
    int n=0;
    for(int i=0; str[i]; i++)
        if(isalpha(str[i]))
            n++;

    return n;
}