/**
 * @file main.c
 * @author Colin Francis
 * @brief An implementation of a stack and a queue in C
 * @version 0.1
 * @date 2021-12-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_RATIO 0.75

struct dynamicArray {
    int size;  // current number of elements in the array
    int capacity;  // current allowable number of element in the array
    int *array;  // a pointer to the array
};

/**
 * @brief Create a new dynamic array data structure
 * 
 * @return struct dynamicArray A struct representing a dynamic array
 */
struct dynamicArray newDynamicArray() {
    // declare and initialize a dynamic array struct
    struct dynamicArray dynArr = {.size=0, .capacity=5, .array=NULL};
    // allocate memory on the heap for underlying static array
    int *statArr = (int*) malloc(dynArr.capacity * sizeof(int));

    // set array member to statArr address
    dynArr.array = statArr;

    return dynArr;
}

int main(void) {
    struct dynamicArray stack = newDynamicArray();
    struct dynamicArray queue = newDynamicArray();

    return 0;
}
