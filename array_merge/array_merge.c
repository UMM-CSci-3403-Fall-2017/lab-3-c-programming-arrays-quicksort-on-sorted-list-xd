#include <stdlib.h>

#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	
	//Checks if zero arrays are being passed in
	//In which it would be reasonable to output and empty array
	if(num_arrays == 0){
		int* empty_result = (int*) calloc(2, sizeof(int));
		empty_result[0] = 0;
		return empty_result;
	}

	//Counts the total number of values in all the arrays
	int counter = 0;
	for (int i = 0; i < num_arrays; i++){
		counter = counter + sizes[i];
	}

	//Temp array used to store values that are going to be sorted
	int* temp_array = (int*) calloc(counter + 1, sizeof(int));

	//Counter is now used to keep track of temp_array's index
	counter = 0;
	//Entering values into our temp_array so that we can sort it later
	for (int i = 0; i < num_arrays; i++){
		for(int j = 0; j < sizes[i]; j++){
			temp_array[counter] = values[i][j];
			counter++;
		}
	}

	mergesort(counter, temp_array);

	//Starts at 1 because first value is always unique
	int count_uniq = 1;
	//Counts unique values in our temp_array
	for(int i = 1; i < counter; i++){
		if(temp_array[i] != temp_array[i-1]){
			count_uniq++;
		}	
	}

	int* result_array = (int*) calloc(count_uniq + 2, sizeof(int));

	//Populates the result_array with just the unique values
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
