/******************************************************************************
 * Copyright (C) 2023 Abdel Halim Mansour
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 ******************************************************************************
 *
 * @file data.h
 * @brief File contains description of functions that perform ASCII-to-INT and INT-to-ASCII
 *
 * @author Abdel Halim Mansour
 * @date 2/11/2023
 *
 *****************************************************************************/

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>
#include <math.h>



/**
 * @brief Integer-to-ASCII function.
 * 
 * Converts an data from a standard integer type into an ASCII string, supports
 * a variety of numbers and bases.
 * 
 * @param data The 32-bit, signed number to be converted to ASCII
 * @param ptr The pointer to the output string
 * @param base The base of the number passed in, support base between 2 to 16
 * @return uint8_t Returns the length of the converted data (including negative sign & null terminator)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief ASCII-to-Integer function.
 * 
 * Converts a ASCII string to a number with a specified base
 * 
 * @param ptr Points to the beggining of the character string to convert
 * @param digits Number of digits in the string
 * @param base The base of the number, bases between 2 to 16 are supported
 * @return int32_t Converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif