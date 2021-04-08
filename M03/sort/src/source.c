
#include "source.h"

/* Selection sort */
/* Parameters:
 * start: start of an array
 * size: length of an array
 */
void sort(int* start, int size) {
    for(int i=0; i<size; i++) {
        int smallest_idx = i;

        for(int j=i; j<size; j++) {
            if(start[j] < start[smallest_idx])
                smallest_idx = j;
        }

        int temp = start[i];
        start[i] = start[smallest_idx];
        start[smallest_idx] = temp;
    }
}
