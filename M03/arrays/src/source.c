#include <stdio.h>
#include "source.h"


/* Array Sum
 * Calculate the sum of integers in array starting at address <array>.
 * There will be <count> elements in array. Return the sum as return value.
 */
int array_sum(int* array, int count) {
    int sum = 0;
    for(int i=0; i<count; i++) {
        sum += array[i];
    }

    return sum;
}

/* Array Reader */
/* Parameters:
 * vals: array to be filled
 * n: maximum size of array
 * returns: number of values read */
unsigned int array_reader(int* vals, int n) {
    int i = 0;

    for( ; i<n; i++) {
        int ret = scanf("%d", &vals[i]);
        if(ret != 1) {
            break;
        }
    }

    return i;
}