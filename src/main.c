/******************************************************************************
 * Copyright (C) 2023 by Abdel Halim Mansour
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 ****************************************************************************
 **                                  Description
 *                        
 * @file main.c 
 * @brief This file is the main file for the final assessment of course1.
 *
 * @author Abdel Halim Mansour
 * @date February 11th 2023
 *
 */

/*******************************************************************************/
                                      /*Include*/

#include "stats.h"
#include "data.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*******************************************************************************/
                                      /*main*/

int main(){
    #ifdef COURSE1
    
        printf("compile time switch to course1()\n");
        course1();  
        return 0;

    #endif

    return 0;
}
