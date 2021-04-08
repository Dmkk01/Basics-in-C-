#include <stdlib.h>
#include <string.h>
#include "source.h"

int* join_arrays(unsigned int n1, const int* a1,
		 unsigned int n2, const int* a2,
		 unsigned int n3, const int* a3) {
	int* array = malloc((n1+n2+n3)*sizeof(int));

	memcpy(array, a1, n1*sizeof(int));
	memcpy(array+n1, a2, n2*sizeof(int));
	memcpy(array+n1+n2, a3, n3*sizeof(int));

	return array;
}
