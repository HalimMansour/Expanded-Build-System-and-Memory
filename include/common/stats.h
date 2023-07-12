/******************************************************************************
 * Copyright (C) 2023 by @author
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Abdel Halim Mansour is not liable for any misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Function prototypes for providing statics on an array of numbers, 
 *   and general practice in the "C" language
 *
 *
 * @author Abdel Halim Mansour
 * @date 2023-02-07   
 *
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief < funtion to print unsigned char array >
 *
 * @param array unsigned char array that we will print 
 * @param length unsigned int length of the array (size)
 *
 * @return void()
 */
void print_array(unsigned char array[],unsigned int length);


/**
 * @brief < funtion to sort unsigned char array >
 *
 * @param array unsigned char array that we will sort 
 * @param length unsigned int length of the array (size)
 *
 * @return void()
 */
void sort_array(unsigned char array[],unsigned int length);


/**
 * @brief < funtion to get minimum value form unsigned char array >
 *
 * @param array unsigned char array which we want to get the smallest (minimum) value from
 * @param length unsigned int length of the array (size)
 *
 * @return unsigned char minimum 
 */
unsigned char find_minimum(unsigned char array[],unsigned int length);


/**
 * @brief < funtion to get minimum value form unsigned char array >
 *
 *
 * @param array unsigned char array which we want to get the largest (maximum) value from
 * @param length unsigned int length of the array (size)
 *
 * @return unsigned char maximum 
 */
unsigned char find_maximum(unsigned char array[],unsigned int length);


/**
 * @brief < funtion to get median of the unsigned char array >
 *
 *
 * @param array unsigned char array which we want to get the median from
 * @param length unsigned int length of the array (size)
 *
 * @return unsigned char median 
 */
unsigned char find_median(unsigned char array[],unsigned int length);


/**
 * @brief < funtion to get mean (average) of the unsigned char array >
 *
 * @param array unsigned char array which we want to get the median from
 * @param length unsigned int length of the array (size)
 *
 * @return unsigned char mean 
 */
unsigned char find_mean(unsigned char array[],unsigned int length);

/**
 * @brief < function that prints the statistics of an unsigned char array including minimum, maximum, mean, and median >
 *                         
 * @param array unsigned char array which we want to get the median from
 * @param length unsigned int length of the array (size)
 *
 * @return void()
 */
void print_statistics(unsigned char array[],unsigned int length );

#endif /* __STATS_H__ */
