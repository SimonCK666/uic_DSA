#include "Stack.h"
#define STACK_INIT_SIZE 100
// addition space
#define STACKINCREMENT 10


bool CreateStack(Stack* stack, int size)
{
    // allocation space for stack
    if (size <= 0)
    {
        
        return false;
    }

    stack->values = (double*)malloc(sizeof(double) * size);
    stack->top = -1;    // the stack is null
    stack->maxTop = size - 1;

    return true;
    
    
}

bool IsEmpty(Stack* stack)
{
    if (stack->top == -1)
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
    if (stack->top > stack->maxTop)
    {
        /* stack is full */
        return true;
    } else
    {
        return false;
    }
    
    
}

bool Top(Stack* stack, double* x)
{
    if (IsEmpty(stack))
    {
        /* stack is empty */
        // printf("The stack is empty.\n");
        return false;
    }

    *x = stack->values[stack->top];

    return true;
    

}

bool Push(Stack* stack, double x)
{
    if (IsFull(stack))
    {
        /* stack is full */
        return false;
    }

    if (stack->top == stack->maxTop)
    {
        /* realloc memory */
        stack->maxTop *= 2;
        stack->values = (double*)realloc(stack->values, stack->maxTop);
    }
    

    stack->values[++stack->top] = x;

    return true;
    
    
}

bool Pop(Stack* stack, double* x)
{
    if (IsEmpty(stack))
    {
        /* the stack is empty */
        printf("Stack is Empty!!\n");
        return false;
    } else
    {
        /* code */
        // stack->top = *x;
        stack->top--;
    }

    Top(stack, x);

    return true;
    
    
}

void DisplayStack(Stack* stack)
{
    int i, len;
    len = stack->top;

    printf("top  -->  ");

    for ( i = len; i > -1; i--)
    {
        /* test */
        // printf("\t%f\n", stack->values[i]);
        if (i == len)
        {
            /* code */
            printf("|\t%f\t|\n", stack->values[i]);

        } else
        {
            /* code */
            if (stack->values[i] >= 0)
            {
                /* code */
                printf("\t  |\t %f\t|\n", stack->values[i]);
                
            } else
            {
                /* code */
                printf("\t  |\t%f\t|\n", stack->values[i]);

            }
        }
    }

    printf("\t  +---------------------+\n");
    printf("\n");

    
    

}

void DestroyStack(Stack* stack)
{
    // free base
    free(stack->values);
    stack->values = NULL;
    stack->top = -1;
    stack->maxTop = 0;
}


char *Uncompress(char *str)
{
    int len = (int)strlen(str);
    Stack *stack;
    
    // Create a stack
    CreateStack(stack, len);

    for (int i = 0; i < len; i++)
    {
        /* code */
        if (str[i] != '(')
        {
            /* code */
            if (stack->top == stack->maxTop)
            {
                /* get more memory */
                stack = realloc(stack, sizeof(char) * ())
            }
            
        }
        
    }
    


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