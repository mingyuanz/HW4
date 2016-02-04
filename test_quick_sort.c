#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sort.h"

__attribute__ ((weak))
int compare(int a, int b) {
	    return a - b;
}

__attribute__ ((weak))
int my_compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}


void quick_sort(int *numbers, unsigned count) {
	qsort(numbers, count, sizeof(int), my_compare);
}


void print_numbers(const int* numbers, unsigned count) {
	assert(count);

	unsigned i;
	printf("@ ");
	for (i=0; i < (count-1); i++) {
		printf("%d, ", numbers[i]);
	}
	printf("%d\n", numbers[i]);
}

int main() {

	//printf("%d\n", compare(2,3));

	//int x = 3, y = 2;

	//printf("%d\n", compar((void *)x,(void *)y));

	const int a[] = {1,115,-10,52,-6,2,4,264,23,-14,1,15,13,42,72,43,-143,53};
	const unsigned count = sizeof(a)/sizeof(int);

	printf("count is: %d\n", count);
	//qsort(a, count, sizeof(int), my_compare);
	quick_sort(a, count);

	print_numbers(a, count);



	return 0;
}

//int ptr can be used as array



