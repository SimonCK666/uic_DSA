#include "Stack.h"
#define STACK_INIT_SIZE 100
// addition space
#define STACKINCREMENT 10


// int StackLen(Stack stack)
// {
//     int len;
//     len = stack.top - stack.base;
//     return len;
// }

bool CreateStack(Stack* stack, int size)
{
    // allocation space for stack
    stack->base = (double *)malloc(sizeof(double) * size);
    if (!stack->base)
    {
        /* test whether stack space is success */
        exit(0);
    }

    // stack top and base has the same position
    stack->top = stack->base;
    stack->stacksize = size;

    return true;
    
}

bool IsEmpty(Stack* stack)
{
    if (stack->top == stack->base)
    {
        /* stack is empty */
        return true;
    } else
    {
        return false;
    }
    
    
}

bool IsFull(Stack* stack)
{
    if ((stack->top - stack->base) == stack->stacksize)
    {
        /* stack is full */
        return true;
    } else
    {
        return false;
    }
    
    
}

bool Top(Stack* Stack, double* x)
{
    Stack->top = x;
    return true;

}

bool Push(Stack* stack, double x)
{
    if ((stack->top - stack->base) >= stack->stacksize)
    {
        /* stack is full */
        stack->base = (double *)realloc(stack->base, (stack->stacksize + STACKINCREMENT) * sizeof(double));
        if (!stack->base)
        {
            /* memory does not allocate successfully */
            exit(0);
        }
        
        stack->stacksize += STACKINCREMENT; 
        stack->top = stack->base + stack->stacksize;
        
    }

    // push x at top
    *(stack->top) = x;
    stack->top++;
    
}

bool Pop(Stack* stack, double* x)
{
    if (stack->top == stack->base)
    {
        /* overflow on the bottom */
        return false;
    }

    *x == *--(stack->top);
    return true;
}

void DisplayStack(Stack* stack)
{
    int len, i;
    // get the length of stack
    len = stack->top - stack->base;

    printf("top  -->  ");

    for ( i = len - 1; i >= 0; i--)
    {
        /* code */
        if (i == len - 1)
        {
            /* code */
            printf("|\t%f\t|\n", stack[i]);

        } else
        {
            /* code */
            if (stack+1 >= 0)
            {
                /* code */
                printf("\t  |\t %f\t|\n", stack[i]);
                
            } else
            {
                /* code */
                printf("\t  |\t%f\t|\n", stack[i]);

            }
        }
        
        // printf("|\t%f\t|\n", a[i]);
    }
    printf("\t  +---------------------+\n");
    printf("\n");
    

}

void DestroyStack(Stack* stack)
{
    // free base
    free(stack->base);

    stack->base = NULL;
    stack->top = NULL;
    
    // size equal to 0
    stack->stacksize = 0;
}






int main(void) {
    Stack stack;
    double val;
    CreateStack(&stack, 5);
    Push(&stack, 5.0);
    Push(&stack, 6.5);
    Push(&stack, -3.0);
    Push(&stack, -8.0);
    DisplayStack(&stack);
    if(Top(&stack, &val))
        printf("Top: %f\n", val);
    Pop(&stack, &val);
    if(Top(&stack, &val))
        printf("Top: %f\n", val);
    while(!IsEmpty(&stack))
        Pop(&stack, &val);
    DisplayStack(&stack);
    DestroyStack(&stack);
    return 0;
}