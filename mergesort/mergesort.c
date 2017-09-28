#include <stdlib.h>

#include "mergesort.h"

void mergesort(int size, int values[]) {
	if (size <= 1) {
		return;
	}

	int mid = size / 2;
	int* part_one = (int*) calloc((size/2) + 1, sizeof(int));
	int* part_two = (int*) calloc((size/2) + 1, sizeof(int));

	int i = 0;
	while (i < mid) {
		part_one[i] = values[i];
		i++;
	}
	int k = 0;
	int j = i;
	while (j < size) {
		part_two[k] = values[j];
		j++;
		k++;
	}

	mergesort(i, part_one);
	mergesort(k, part_two);

	int offset_one = 0;
	int offset_two = 0;
	int a;
	int b;
	while (offset_one < i && offset_two < k) {
		a = part_one[offset_one];
		b = part_two[offset_two];

		if (a <= b) {
			values[offset_one + offset_two] = a;
			offset_one++;
		} else { 
			values[offset_one + offset_two] = b;
			offset_two++;
		}
	}

	while (offset_one < i) {
		values[offset_one + offset_two] = part_one[offset_one];
		offset_one++;
	}

	while (offset_two < k) {
                values[offset_one + offset_two] = part_two[offset_two];
                offset_two++;
        }
	
	free(part_one);
	free(part_two);
}
