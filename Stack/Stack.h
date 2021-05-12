#ifndef B298A5E4_48BA_4068_823C_15ED13ED6A12
#define B298A5E4_48BA_4068_823C_15ED13ED6A12

#pragma once
 
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
 
// typedef double ElemType;
 
typedef struct Stack
{
    /* data */
    double *top;  // Stack top
    double *base;
    int stacksize;  // size of Stack
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
