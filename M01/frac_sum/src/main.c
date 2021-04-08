#include <stdio.h>

double fracsum(int n1, int d1, int n2, int d2) {
    return (double)n1/d1 + (double)n2/d2;
}

int main(void) {
    printf("%.3f %.3f %.3f\n",
	   fracsum(1,2,2,4),
	   fracsum(1,4,1,8),
	   fracsum(4,3,5,6));

    return 0;
}