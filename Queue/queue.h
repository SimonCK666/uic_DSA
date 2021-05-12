#ifndef EC82B90C_2B3F_45D7_9DBC_3B089F725E95
#define EC82B90C_2B3F_45D7_9DBC_3B089F725E95

#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    /* data */
    double *values;     // demonstraction
    int front;          // index of the front
    int rear;           // index of the rear
    int counter;        // number of elem in the queue
    int maxSize;        // maximum size of the queue
} Queue;


bool CreateQueue(Queue *queue, int size);
bool IsEmpty(Queue *queue);
bool IsFull(Queue *queue);
bool Enqueue(Queue *queue, double x);
bool Dequeue(Queue *queue, double *x);
void DisplayQueue(Queue *queue);
void DestroyQueue(Queue *queue);

#endif /* EC82B90C_2B3F_45D7_9DBC_3B089F725E95 */
