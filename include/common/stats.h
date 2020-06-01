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
 * @file stats.h 
 * @brief This file contains all the functions for 
 * stats.c
 *
 * There are eight fucntions that are implemented in stats.c. This 
 * file contains all the declarations of the functions so that
 * they can be used in stats.c
 *
 * @author Bhavik Kalpesh
 * @date May 5, 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

void print_statistics(unsigned char mean,unsigned char median,unsigned char minimum,unsigned char maximum);
/**
 * @brief Prints the statistics data
 *
 * This function takes an input of 4 variables which are minimum,
 * maximum,mean and median. It then prints all the data.
 *
 * @param mean,median,minimum,maximum
 *
 * @return It does not need to return any value.
 */

void print_array(unsigned char *array,int size);
/**
 * @brief Prints the data of the array
 *
 * This function takes input the address of the array.
 * It stores it into the pointer and then uses it to
 * print the data of the array that is passed to this function.
 *
 * @param *array The array that is supposed to be printed
 * @param size The size of the array
 * @return It does not need to return any value
 */

unsigned char find_median(unsigned char *array,int size);
/**
 * @brief Finds the median of the elements in the array.
 *
 * This function takes input the address of the array.
 * It stores it into the pointer and then uses it to
 * calculate the median of the array that is passed on to this function.
 * 
 * NOTE: The median that is calculated is in unsigned char so it will
 * 	 be the floor value.
 *
 * @param *array The array whose median is supposed to be calculated
 * @param size The size of the array
 * @return It returns the median after calculation.
 */

void sort_array(unsigned char *array,int size);
/**
 * @brief Sorts the elements in the array.
 *
 * This function takes input the address of the array.
 * It stores it into the pointer and then uses it to
 * sort the elements in the array in descending order.
 *
 * @param *array The array whose elements are supposed to be sorted
 * @param size The size of the array
 * @return It does not return any value
 */

unsigned char find_mean(unsigned char *array,int size);
/**
 * @brief It calculates the mean of the elements in the array.
 *
 * This function takes input the address of the array.
 * It stores it into the pointer and then uses it to
 * calculate the mean of the elements
 *
 * NOTE: It returns the mean in unsigned char so it is 
 * 	 the floor value.
 *
 * @param *array The array whose elements are supposed to be sorted
 * @param size The size of the array
 * @return it returns the mean of the elements.
 */

unsigned char find_minimum(unsigned char *array,int size);
/**
 * @brief It calculates the minimum of the elements in the array.
 *
 * This function takes input the address of the array.
 * It stores it into the pointer and then uses it to
 * calculate the minimum value of the elements
 *
 *
 * @param *array The array whose elements are supposed to be sorted
 * @param size The size of the array
 * @return it returns the minimum of the elements.
 */

unsigned char find_maximum(unsigned char *array,int size);
/**
 * @brief It calculates the maximum of the elements in the array.
 *
 * This function takes input the address of the array.
 * It stores it into the pointer and then uses it to
 * calculate the maximum value of the elements
 *
 *
 * @param *array The array whose elements are supposed to be sorted
 * @param size The size of the array
 * @return it returns the maximum of the elements.
 */



#endif /* __STATS_H__ */
