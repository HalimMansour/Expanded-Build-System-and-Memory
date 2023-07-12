/******************************************************************************
 * Copyright (C) 2023 by Abdel Halim Mansour
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
 * @author Abdel Halim Mansour
 * @date February 11 2023 
 *
 */
#include "memory.h"
#include <stdlib.h>
#include <stdint.h>

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
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/***********************************************************
                     New Functions 
***********************************************************/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {

    if (src == dst) return dst;
    if (src < dst && dst < src + length) {
        src = src + length - 1;
        dst = dst + length - 1;
        while (length--) {
            *dst-- = *src--;
        }
    } else {
        while (length--) {
            *dst++ = *src++;
        }
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    while (length--) {
        *dst++ = *src++;
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    uint8_t * temp = src;
    while (length--) {
        *temp++ = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    uint8_t * temp = src;
    while (length--) {
        *temp++ = 0;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    uint8_t * left = src;
    uint8_t * right = src + length - 1;
    while (left < right) {
        uint8_t temp = *left;
        *left++ = *right;
        *right-- = temp;
    }
    return src;
}

int32_t * reserve_words(size_t length) {
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));
    if (ptr == NULL) {
        // malloc failed to allocate memory
        return NULL;
    }
    return ptr;
}

void free_words(uint32_t * src){
    return free(src);
}

