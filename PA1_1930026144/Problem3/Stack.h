#ifndef CBBA0499_D901_42AE_9832_3DBACA009A68
#define CBBA0499_D901_42AE_9832_3DBACA009A68


#endif /* CBBA0499_D901_42AE_9832_3DBACA009A68 */
#ifndef B298A5E4_48BA_4068_823C_15ED13ED6A12
#define B298A5E4_48BA_4068_823C_15ED13ED6A12

#pragma once
 
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
 
// typedef double ElemType;
 
typedef struct Stack
{
    /* data */
    double *values;
    int top;
    int maxTop;
} Stack;

// int StackLen(Stack satck);
bool CreateStack(Stack* stack, int size);
bool IsEmpty(Stack* stack);
bool IsFull(Stack* stack);
bool Top(Stack* stack, double* x);
bool Push(Stack* stack, double x);
bool Pop(Stack* stack, double* x);
void DisplayStack(Stack* stack);
void DestroyStack(Stack* stack);

#endif /* B298A5E4_48BA_4068_823C_15ED13ED6A12 */
