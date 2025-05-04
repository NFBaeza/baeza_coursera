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
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 


/**
 * @brief find minimum values of an array
 *
 * @param array array.
 * @param array_length size of array.
 *
 * @return minimum values in unsigned char.
 */
unsigned char find_minimum(unsigned char* array, int array_length);


/**
 * @brief find maximum values of an array
 *
 * @param array array.
 * @param array_length size of array.
 *
 * @return maximum values in unsigned char.
 */
unsigned char find_maximum(unsigned char* array, int array_length);

/**
 * @brief find average of values of an array
 *
 * @param array array.
 * @param array_length size of array.
 *
 * @return mean of array (float).
 */
float find_mean(unsigned char* array, int array_length);


/**
 * @brief find median values of an array
 *
 * @param array array.
 * @param array_length size of array.
 *
 * @return median of array (float).
 */
float find_median(unsigned char* array, int array_length);


/**
 * @brief sort an array from highest to smallest values
 *
 * @param array array.
 * @param array_length size of array.
 */
void sort_array(unsigned char* array, int array_length);

/**
 * @brief print summary of statistics (min, max, mean and median)
 *
 * @param array array.
 * @param array_length size of array.
 */
void print_statistics(unsigned char* array, int array_length);

/**
 * @brief print an array
 *
 * @param array array.
 * @param array_length size of array.
 */
void print_array(unsigned char* array, int array_length);

#endif /* __STATS_H__ */

