#include <stdio.h>

unsigned int arraylen(const char* array) {
    unsigned int n = 0;
    for( ; array[n]; n++);
    return n;
}

void countchars(const char* array, unsigned int* counts) {
    for(unsigned int i=0; i<arraylen(array); i++) {
        // The solution below does the exact same thing 
        // as this commented code:
        /*
        char character = array[i];
        int index = (int)character;
        counts[index]++;
        */
        
        counts[(int)array[i]]++;
    }
}
