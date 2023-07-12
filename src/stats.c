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


#include <stdio.h>
#include <stdint.h>
#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)





void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
 

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

   print_statistics(test,SIZE);

}

/* Add other Implementation File Code Here */

void print_array(unsigned char array[],unsigned int length)
{
    #ifdef VERBOSE
    for(int i = 0 ; i < SIZE ;i++)
    {
        printf("%d ",array[i]);
    }
    #endif
    
}


void sort_array(unsigned char array[],unsigned int length)
{
  int i,j,temp;

  for(i=0; i < SIZE-1 ; ++i)
	{
	   for (j = 0; j < SIZE- i -1; ++j)
	   {
	       if (array[j] < array[j+1]) 
                {
 
                    temp =  array[j+1];
                    array[j+1] = array[j];
                    array[j] = temp;
                }
	   }
	}

}


unsigned char find_minimum(unsigned char array[],unsigned int length)
{
    unsigned char min = array[0];
    for(int i = 0 ; i < SIZE ;i++)
    {
        if (array[i]<min)
        {
            min = array[i];
        }
    }
    return min;
}


unsigned char find_maximum(unsigned char array[],unsigned int length)
{
    unsigned char max = array[0];
    for(int i = 0 ; i < SIZE ;i++)
    {
        if (array[i]>max)
        {
            max = array[i];
        }
    }
    return max;
}


unsigned char find_median(unsigned char array[],unsigned int length)
{
    unsigned char median;
    sort_array(array,SIZE);
    median = array[SIZE/2];
    return median;
}


unsigned char find_mean(unsigned char array[],unsigned int length)
{
    unsigned char mean;
    int temp = 0;
    for(int i = 0 ; i < SIZE ;i++)
    {
        temp=temp+array[i];
    }
    mean= temp / SIZE;
    return mean;
}


void print_statistics(unsigned char array[],unsigned int length )
{
    unsigned char max,min,median,mean;
    printf("Array:\n");
    print_array(array,SIZE);

    printf("\n\nSorted Array:\n");
    sort_array(array,SIZE);
    print_array(array,SIZE);
    
    printf("\n\nThe Maximum value in the array:");
    max=find_maximum(array,SIZE);
    printf("%d ",max);
    
    printf("\n\nThe Minimum value in the array:");
    min=find_minimum(array,SIZE);
    printf("%d ",min);
    
    printf("\n\nMean :");
    mean=find_mean(array,SIZE);
    printf("%d ",mean);

    printf("\n\nMedian :");
    median=find_median(array,SIZE);
    printf("%d ",median);
    printf("\n\n"); 
}

