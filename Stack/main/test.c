#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct StackD
{
    DataType* _array;
    int _capacity;
    int _top;
}StackD;


// 检测栈是否为空 
int StackDEmpty(StackD* s)
{
    assert(s);

    if (0 == s->_top)
    return 1;
else
    return 0;
}

// 栈的初始化 
void StackDInit(StackD* s, int capacity)
{
    assert(s);                         //参数检测

s->_array = (DataType*)malloc(sizeof(DataType)* capacity);           // 申请空间
if (NULL == s->_array)                                           //判空
{
    assert(0);
    return;
}

s->_capacity = capacity;                                    //重置容量
s->_top = 0;                                                //无元素，top为零
}


// 入栈 
void StackDPush(StackD* s, DataType data)
{
    assert(s);                                         //参数检测

if (s->_top < s->_capacity)                         //栈未满，直接入栈
{
    s->_array[s->_top] = data;
    s->_top++;                               
}
else                                                //栈已满，扩容后再入栈
{
    int capacity = 2 * s->_capacity;
    s->_array = (DataType*)realloc(s->_array, sizeof(DataType)*capacity);          //扩容
    s->_capacity = capacity;                                                   //重置容量
    s->_array[s->_top] = data;                                            //入栈
    s->_top++;
}
}

// 出栈
void StackDPop(StackD* s)
{
    assert(s);                                    //参数检测

    if (StackDEmpty(s))
    {
        printf("栈已空，无法出栈！！\n");
        return;
    }
    else                           //栈顶减一即出栈
        s->_top--;
}


// 获取栈顶元素 
DataType StackDTop(StackD* s)
{
    assert(s);                            //参数检测

    if (StackDEmpty(s))
    {
        printf("栈已空，无栈顶元素！！ \n");
        return 0;
    }

    return s->_array[s->_top - 1];
    }

    // 获取栈中元素个数 
    int StackDSize(StackD* s)
    {
        assert(s);

    return s->_top;
}



void DisplayStack(StackD* stack)
{
    int i;
    for ( i = stack->_top; i > -1; i--)
    {
        /* code */
        printf("\t%f\n", stack->_array[i - 1]);
    }
    
    

}

void DestroyStack(StackD* stack)
{
    // free base
    free(stack->_array);
    stack->_array = NULL;
    stack->_capacity = 0;
    stack->_top = 0;
}


int main(void) {
    StackD stack;
    double val;
    StackDInit(&stack, 5);
    StackDPush(&stack, 5.0);
    StackDPush(&stack, 6.5);
    StackDPush(&stack, -3.0);
    StackDPush(&stack, -8.0);
    DisplayStack(&stack);
    if(StackDTop(&stack))
        printf("Top: %f\n", val);
    StackDPop(&stack);
    if(StackDTop(&stack))
        printf("Top: %f\n", val);
    while(!StackDEmpty(&stack))
        StackDPop(&stack);
    DisplayStack(&stack);
    DestroyStack(&stack);
    return 0;
}