#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrcat(char* dest, const char* src) {
    // Reallocate memory
    dest = realloc(dest, strlen(dest)+strlen(src)+1);

    char* origdest = dest;    
    while(*dest) {
        dest++;    
    }
    
    while (*src) {
        *dest++ = *src++;  // Copies character and increases/moves pointer    
    }    
    
    *dest = 0;    
    return origdest;
}

int main(void) {
    char* str = malloc(7);
    strcpy(str, "Aatami");

    str = mystrcat(str, "Beetami");
    printf("%s\n", str);
    free(str);

    return 0;
}