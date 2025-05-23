/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */

#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)


unsigned char find_minimum(unsigned char* array, int array_length){
	unsigned char minimum_nummer_found = -1;
	for(int i = 0; i < array_length; i++){
		if(array[i] <= minimum_nummer_found){
			minimum_nummer_found = array[i];
		}
	}
	return minimum_nummer_found;
};

unsigned char find_maximum(unsigned char* array, int array_length){
	unsigned char maximum_nummer_found = 0;
	for(int i = 0; i < array_length; i++){
		if(array[i] >= maximum_nummer_found){
			maximum_nummer_found = array[i];
		}
	}
	return maximum_nummer_found;
};

float find_mean(unsigned char* array, int array_length){
	unsigned int sum = 0;
	for(int i = 0; i < array_length; i++){
		sum += array[i];
	}
	return (float)sum/array_length;
};
 


void print_array(unsigned char* array, int array_length){
	PRINTF("{");
	for(int i = 0; i < array_length; i++){
		PRINTF(" %u,", array[i]);
	}
	PRINTF("}\n");
	return;

};

void sort_array(unsigned char* array, int array_length){
	int idx = 0;
	unsigned char temp;
	for (int i = 0; i < array_length; ++i)
	{
		unsigned char maximum_nummer_found = 0;
		for(int j = 0 + i; j < array_length; j++){
			if(array[j] >= maximum_nummer_found){
				maximum_nummer_found = array[j];
				idx = j;
			}
		}
		temp = array[i];
		array[i] = array[idx];
		array[idx] = temp;		
	}
	return;
};

float find_median(unsigned char* array, int array_length){
	sort_array(array,array_length);
	if(array_length %2 == 0){
		return (float)array[array_length/2];
	}else{
		return (float)((array[array_length/2]+array[(array_length/2) + 1])/2.0);
	}
};

void print_statistics(unsigned char* array, int array_length){
	#ifdef VERBOSE
	    uint8_t  min = find_minimum (array, array_length);
	    uint8_t  max = find_maximum (array, array_length);
	    float    mean= find_mean    (array, array_length);
	    float    med = find_median  (array, array_length);

	    PRINTF("Stats — min:%u max:%u mean:%.2f median:%.2f\n",
	           min, max, mean, med);
	#else
	    /* Nada en modo no verboso */
	#endif
};

/*void main() {

	  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
	                              114, 88,   45,  76, 123,  87,  25,  23,
	                              200, 122, 150, 90,   92,  87, 177, 244,
	                              201,   6,  12,  60,   8,   2,   5,  67,
	                                7,  87, 250, 230,  99,   3, 100,  90};

 
  print_array(test, SIZE);
  unsigned char minimum = find_minimum(test, SIZE);
  printf("minimum: %u\n", minimum);
  unsigned char maximum = find_maximum(test, SIZE);
  printf("maximum: %u\n", maximum);
  float mean = find_mean(test, SIZE);
  printf("mean: %.2f\n", mean);
  float median = find_median(test, SIZE);
  printf("median: %.2f\n", median);
  print_statistics(test,SIZE);
} */

/* Add other Implementation File Code Here */
 /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
