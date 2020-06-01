 
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
 * @file course1.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Bhavik Kalpesh
 * @date June 1 2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/**
* @brief function to convert data from a standard integer type into an ASCII string.
*
* All operations need to be performed using pointer arithmetic, not array indexing
* The number you wish to convert is passed in as a signed 32-bit integer.
* You should be able to support bases 2 to 16 by specifying the integer value of the base you wish to convert to (base).
* Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
* The signed 32-bit number will have a maximum string size (Hint: Think base 2).
* You must place a null terminator at the end of the converted c-string
* Function should return the length of the converted data (including a negative sign). Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
* This function needs to handle signed data.
* You may not use any string functions or libraries
*
* @return the length of the converted data (including a negative sign)
*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
* @brief function to convert data back from an ASCII represented string into an integer type.
*
* All operations need to be performed using pointer arithmetic, not array indexing
* The character string to convert is passed in as a uint8_t * pointer (ptr).
* The number of digits in your character set is passed in as a uint8_t integer (digits).
* You should be able to support bases 2 to 16.
* This function needs to handle signed data.
* You may not use any string functions or libraries
*
* @return the converted 32-bit signed integer
*/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);



/**
* @brief function to perform binary addition of two numbers.
*
*
*
* @return result of binary addition of two integers
*/
int32_t binaryAddition(int32_t addend1,int32_t addend2);
#endif /* __DATA_H__ */

