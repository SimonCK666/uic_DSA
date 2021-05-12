// 运用 Stack 将二进制转换为十进制数

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE 100
//加大的空间
#define STACKINCREMENT 10

typedef int ElemType;
typedef struct 
{
    /* data */
    ElemType *base;
    ElemType *top;
    int stackSize;
} sqStack;

/*
    对于需要修改的栈，就要传入 *s
    对于只要测试，传入 s
*/


// 初始化
void initStack(sqStack *s) 
{
    // 分配空间
    s->base = (ElemType*)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
    // 测试是否分配成功
    if (!s->base)
    {
        /* 分配失败 */
        exit(0);
    }

    // 初始化栈顶和栈底在同一个位置
    s->top = s->base;

    s->stackSize = STACK_INIT_SIZE;
    
}

// 入栈
void Push(sqStack *s, ElemType e)
{
    if ((s->top - s->base) >= s->stackSize)
    {
        /* 栈满了 */
        s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
        {
            /* 如果分配失败 */
            exit(0);
        }
        
    }
    

    // 栈顶指针所对应的地址等于要押入的值
    *(s->top) = e;
    s->top++;
}

// 出栈
void Pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
    {
        /* 下溢出: 栈到底了 */
        return;
    }

    *e = *--(s->top);
    
}

// 求栈当前容量
int StackLen(sqStack s)
{
    // 指针相减不是地址的相减
    return (s.top - s.base);
}

void DisplayStack(sqStack* stack)
{
    int len, i;
    // get the length of stack
    len = stack->top - stack->base;

    printf("%d\n", stack[2]);


    // printf("top  -->  ");

    // for ( i = len - 1; i >= 0; i--)
    // {
    //     /* code */
    //     if (i == len - 1)
    //     {
    //         /* code */
    //         printf("|\t%f\t|\n", stack[i]);

    //     } else
    //     {
    //         /* code */
    //         if (stack+1 >= 0)
    //         {
    //             /* code */
    //             printf("\t  |\t %f\t|\n", stack[i]);
                
    //         } else
    //         {
    //             /* code */
    //             printf("\t  |\t%f\t|\n", stack[i]);

    //         }
    //     }
        
    //     // printf("|\t%f\t|\n", a[i]);
    // }
    // printf("\t  +---------------------+\n");
    // printf("\n");
    

}

int main(int argc, char const *argv[])
{
    /* code */
    ElemType c;
    sqStack s;
    int len, i, sum = 0;

    initStack(&s);

    // Push(&s, 1);
    // Push(&s, 0);
    // Push(&s, 1);
    // Push(&s, 1);


    printf("Please input Binary Number(End with #): \n");
    scanf("%c", &c);
    while (c != '#')
    {
        /* code */
        Push(&s, c);
        scanf("%c", &c);
    }

    getchar();      // 拿走回车的值
    DisplayStack(&s);

    len = StackLen(s);
    printf("Now Length: %d\n", len);
    
    for ( i = 0; i < len; i++)
    {
        /* code */
        Pop(&s, &c);
        // c 返回的是 ASCII 码
        sum = sum + (c - 48) * pow(2, i);       // 转换成十进制
    }

    printf("Decimalism: %d\n", sum);
    

    return 0;
}
