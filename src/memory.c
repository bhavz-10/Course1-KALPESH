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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Bhavik Kalpesh
 * @date June 1 2020
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int loop;
  for(loop = 0; loop < size; loop++) {
    set_value(ptr, loop, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

//Area may overlap
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	uint8_t* temp = malloc(length);
	//Copy bytes into the temp storage.
        for(int loop = 0; loop < length; loop++)
	{
		*(temp+loop) = *(src + loop);
	}
	//Copy bytes from the temp storage to the destination Pointer.
	for(int loop = 0; loop < length; loop++)
	{
		*(dst + loop) = *(temp+loop);
	}
	return dst;	
}

//Areas may not overlap
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
	//Copy bytes from Source to Sestination.
        for(int loop = 0; loop < length; loop++)
	{
		*(dst + loop) = *(src + loop);
	}
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	for(int loop = 0; loop < length; loop++)
	{
		*(src + loop) = value;
	}
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	for(int loop = 0; loop < length; loop++)
	{
		*(src + loop) = 0;
	}
	return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	uint8_t temp;
	for(int loop = 0; loop < length/2; loop++)
	{
		temp = *(src + loop);
		*(src + loop) = *(src + (length - 1) -loop); 
		*(src + (length - 1) -loop) = temp;
	}
	return src;
}

int32_t * reserve_words(size_t length)
{
	int32_t* words = malloc(length*2);
	return words;
}

void free_words(uint32_t * src){
	free(src);
}
