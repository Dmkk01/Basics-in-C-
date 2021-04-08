#include <stdio.h>

void show_table(long* a, size_t n) {
    for (int i = 0; i < n; i++) {
        printf("%ld ", a[i]);
    }
    printf("\n");
}

int main(void) {
    long table[30];
    table[0] = 3;
    for(int i=1; i < 30; i++)
        table[i] = table[i-1]*2;
    
    printf("size: %lu\n", sizeof(table)); /* print array size for fun */

    /* below is one way to get the number of elements */
    // Note that this only works here as table is defined as long table[30]
    // and this would not work inside the show_table function for example,
    // where a is a pointer.
    show_table(table, sizeof(table)/sizeof(long));

    return 0;
}