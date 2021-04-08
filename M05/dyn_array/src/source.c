
#include "source.h"
#include <stdlib.h>
#include <stdio.h>

/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int* create_dyn_array(unsigned int n) {
    int* array = malloc(n * sizeof(int));

    for(int i=0; n > 0; i++) {
        int ret = scanf("%d", &array[i]);
        
        if(ret != 1) {
            printf("Reading failed!\n");
            return array;
        }
        n--;
    }

    return array;
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int* add_dyn_array(int* arr, unsigned int num, int newval) {
    arr = realloc(arr, (num + 1) * sizeof(int));
    arr[num] = newval;
    return arr;
}
