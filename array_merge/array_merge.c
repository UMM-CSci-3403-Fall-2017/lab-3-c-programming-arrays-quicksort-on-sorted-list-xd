#include <stdlib.h>

#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){

	if(num_arrays == 0){
		int* empty_result = (int*) calloc(2, sizeof(int));
		empty_result[0] = 0;
		return empty_result;
	}

	int counter = 0;
	for (int i = 0; i < num_arrays; i++){
		counter = counter + sizes[i];
	}

	int* temp_array = (int*) calloc(counter + 1, sizeof(int));

	counter = 0;
	for (int i = 0; i < num_arrays; i++){
		for(int j = 0; j < sizes[i]; j++){
			temp_array[counter] = values[i][j];
			counter++;
		}
	}

	mergesort(counter, temp_array);

	int count_uniq = 1;
	for(int i = 1; i < counter; i++){
		if(temp_array[i] != temp_array[i-1]){
			count_uniq++;
		}	
	}

	int* result_array = (int*) calloc(count_uniq + 2, sizeof(int));

	result_array[0] = count_uniq;
	result_array[1] = temp_array[0];

	int final_counter = 2;
	for(int i = 1; i < counter; i++){
		if(temp_array[i] != temp_array[i-1]){
                        result_array[final_counter] = temp_array[i];
			final_counter++;
                }
	}

	free(temp_array);
	return result_array;
}
