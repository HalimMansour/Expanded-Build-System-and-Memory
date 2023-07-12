/******************************************************************************
 * Copyright (C) 2023 Abdel Halim Mansour
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 ******************************************************************************
 *
 * @file data.c
 * @brief File contains functions that perform ASCII-to-INT and INT-to-ASCII
 *
 * @author Abdel Halim Mansour
 * @date 2/11/2023
 *
 *****************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include "data.h"


uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base) {
    uint8_t *p = ptr;
    uint8_t negative = 0;
    uint32_t tmp;

    if (data < 0 && base == 10) {
        negative = 1;
        *p++ = '-';
        data = -data;
    }

    tmp = data;
    do {
        ++p;
        tmp /= base;
    } while (tmp);

    *p = '\0';

    do {
        *--p = "0123456789ABCDEF"[data % base];
        data /= base;
    } while (data);

    return p - ptr + negative + 1;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base) {
    int32_t result = 0;
    uint8_t negative = 0;
    uint8_t *p = ptr;

    if (*p == '-') {
        negative = 1;
        ++p;
    }

    while (digits--) {
        uint8_t c = *p++;
        int32_t value;

        if (c >= '0' && c <= '9') {
            value = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            value = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            value = c - 'a' + 10;
        } else {
            break;
        }

        result = result * base + value;
    }

    return negative ? -result : result;
}