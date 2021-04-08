#include "source.h"
#include <ctype.h>

char* my_toupper(char* dest, const char* src) {
    int j=0;
	for(int i=0; src[i]; i++, j++) {
        if(src[i] == '?') 
            dest[j] = '!';
        else if(src[i] == '.') {
            // store the !!! 

            // strcat looks for the '\0' at the end of the string,
            // so that needs to be added to the position we
            // want the !!! to go to:
            dest[j] = 0;
            strcat(dest, "!!!");
            j+=2;
            
            // you could do this also like
            /*
            dest[j++] = '!';
            dest[j++] = '!';
            dest[j] = '!';
            */
        } else {
            dest[j] = toupper(src[i]);
        }
    }

    dest[j] = 0;

    return dest;
}