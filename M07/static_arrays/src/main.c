#include <stdio.h>

int main(void) {
    int taulu[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            taulu[j][i] = i*j;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%2d ", taulu[j][i]);
        }
        printf("\n");
    }
    return 0;
}