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

void printArray(struct dynamicArray *dynArrPtr) {
    printf("(%d/%d): [", dynArrPtr->size, dynArrPtr->capacity);

    if (dynArrPtr->size == 0) {
        printf("]\n");
        return;
    }

    for (int index = 0; index < dynArrPtr->size; index++) {
        if (index < dynArrPtr->size - 1) {
            printf("%d, ", *(dynArrPtr->array + index));
        } else {
            printf("%d]\n", *(dynArrPtr->array + index));
        }
    }
}

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

/**
 * @brief Transfers elements of the provided array into a new array with
 * double the capacity
 * 
 * @param arrPtr The address of the dynamic array struct
 */
void upSizeArray(struct dynamicArray *arrPtr) {
    // allocate memory on the heap for the new array with 2x capacity
    int *newArray = (int*) malloc(2 * arrPtr->capacity * sizeof(int));

    // transfer elements from old array to the new array
    for (int index = 0; index < arrPtr->size; index++) {
        newArray[index] = *(arrPtr->array + index);
    }

    // free existing array from memory and update pointer in dynamic array 
    // struct to point to the new array
    free(arrPtr->array);
    arrPtr->array = newArray;

    // double array capacity
    arrPtr->capacity = 2 * arrPtr->capacity;
}

/**
 * @brief Pushes a new value to the top of the stack
 * 
 * @param value The value to push
 * @param stackPtr The address of the dynamic array struct being used to
 * represent a stack
 */
void push(int value, struct dynamicArray *stackPtr) {
    // check if the underlying static array needs to be up sized
    if ((float) (stackPtr->size + 1) / (float) (stackPtr->capacity) >= TABLE_RATIO) {
        upSizeArray(stackPtr);
    }

    *(stackPtr->array + stackPtr->size) = value;  // push value to the end of the stack
    stackPtr->size++;  // increment array size
}

/**
 * @brief Returns the top value on the stack without removing it
 * from the stack
 * 
 * @param stackPtr The address of the dynamic array struct being used to
 * represent a stack
 * @return int The top value on the stack
 */
int peek(struct dynamicArray *stackPtr) {
    return *(stackPtr->array + (stackPtr->size - 1));
}

int main(void) {
    struct dynamicArray stack = newDynamicArray();
    struct dynamicArray queue = newDynamicArray();

    push(10, &stack);
    printArray(&stack);

    push(5, &stack);
    printArray(&stack);

    push(15, &stack);
    printArray(&stack);

    push(2, &stack);
    printArray(&stack);

    return 0;
}
