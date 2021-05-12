/**
* queue.c
* @author Simon
* @description 
* @created 2021-03-17T10:10:56.639Z+08:00
* @copyright None 
* None
* @last-modified 2021-03-18T10:53:02.045Z+08:00
*/

#include "queue.h"
#define MAXSIZE 100

bool CreateQueue(Queue *queue, int size)
{
    if (size < 1)
    {
        /* code */
        printf("Error: size shoule be positive. \n");
        return false;
    }

    queue->values = (double*)malloc(sizeof(double) * size);
    if (!queue->values)
    {
        /* code */
        exit(1);
    }
    
    queue->front = 0;
    queue->rear = -1;
    queue->counter = 0;
    queue->maxSize = size;

    return true;
    
}

bool IsEmpty(Queue *queue)
{
    // if (queue->front == queue->rear)
    // {
    //     /* the size of the queue is 0 */
    //     return true;
    // }
    
    if (queue->counter == 0)
    {
        /* code */
        return true;
    } else
    {
        /* code */
        return false;
        
    }
    
    

}

bool IsFull(Queue *queue)
{
    // if ((queue->rear + 1) % queue->maxSize == queue->front)
    // {
    //     /* the counter queue equal to maxsize, the quque is full */
    //     return true;
    // }

    if (queue->counter == queue->maxSize)
    {
        /* code */
        return true;
    } else
    {
        /* code */
        return false;
    }
    
    
    
}

bool Enqueue(Queue *queue, double x)
{
    if (IsFull(queue))
    {
        /* the queue is full */
        printf("Error: the queue is full.\n");
        return false;
    }

    // Insert data
    queue->rear = (queue->rear + 1) % queue->maxSize;
    queue->values[queue->rear] = x;
    queue->counter++;

    return true;
    
}


bool Dequeue(Queue *queue, double *x)
{
    if (IsEmpty(queue))
    {
        /* code */
        printf("Error: the queue is Empty.\n");
        return false;
    }

    *x = queue->values[queue->front];
    queue->front = (queue->front + 1) % queue->maxSize;
    queue->counter--;

    return true;
    
    
}


void DisplayQueue(Queue *queue)
{
    int i = 1;
    // printf("front--> ");
    // printf("\t%f\n\n", queue->values[(queue->front) % queue->maxSize]);
    // printf("\n\n");
    // printf("\t%f\n\n", queue->values[(queue->front + queue->counter - 1) % queue->maxSize]);
    
    
    for ( i; i <= queue->counter; i++)
    {
        /* code */
        if (i == 1)
        {
            /* code */
            printf("front-->");
            printf("%f\n", queue->values[(queue->front + i - 1) % queue->maxSize]);
            
        } else if (i == queue->counter)
        {
            printf("\t%f", queue->values[(queue->front + i - 1) % queue->maxSize]);
            printf(" <-- rear\n");
            
        } else
        {
            /* code */
            printf("\t%f\n", queue->values[(queue->front + i - 1) % queue->maxSize]);
            
        }
        
        
    }

    // printf(" <-- rear\n");



    
}

void DestroyQueue(Queue *queue)
{
    free(queue->values);
    queue->values = NULL;
    queue->front = 0;
    queue->rear = 0;
    queue->counter = 0;
    queue->maxSize = 0;

}

