#include "source.h"
#include <string.h>

/* Count Substring
 * Count number of occurances of substring <sub> in string <str>,
 * and return the count.
 */
int num_substr(const char* str, const char* sub) {
    int c = 0;
    while((str = strstr(str, sub)) != NULL) {
        c++;
        str++;
    }

    return c;

}
