#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_INIT_SIZE 100
// addition space
#define STACKINCREMENT 10

typedef struct 
{
    /* data */
    char *values;
    int top;
    int maxSize;
} Stack;


char* Uncompress(char* str)
{
    int len = (int)strlen(str);

    Stack* s;
    Stack* t;
    
    int stackSize = s->maxSize = 50;
    char* stack = s->values = malloc(sizeof(char) * stackSize);
    int top = s->top = -1;

    for (int i=0; i<len; i++) {
        if (str[i] != ']') {
            //不够扩容
            if (top == stackSize-1) {
                stack = realloc(stack, sizeof(char) * (stackSize+=50));
            }
            stack[++top] = str[i];
        }else{
            //新建temp栈
            int tempSize = t->maxSize = 20;
            char * temp = t->values = malloc(sizeof(char) * tempSize);
            int tempTop = t->top = -1;
            
            while (stack[top] != '[') {
                //不够扩容
                if (tempTop == tempSize-1) {
                    temp = realloc(temp, sizeof(char) * (tempSize+=20));
                }
                //temp入栈,stack栈出栈
                temp[++tempTop] = stack[top--];
            }
            //记录数字的上限位置
            int rightIndex = top;
            //把 [ 出栈
            top--;
            //继续出栈直到栈顶不是0-9或者top=-1
            //这里注意要先判断top>-1 否则 stack[top]会越界
            while (top > -1 && stack[top] >= '0' && stack[top] <= '9') {
                top--;
            }
            char strOfInt[11];
            //遍历取出(下限-上限)之间的数字字符存进数组
            for (int j = top+1; j<rightIndex; j++) {
                strOfInt[j-(top+1)] = stack[j];
            }
            //尾部添加\0转成字符串
            strOfInt[rightIndex - (top+1)] = '\0';
            //转成数字
            int repCount = atoi(strOfInt);
            
            int tempTopIndex;
            //遍历N遍，取出temp栈中的字符存进stack栈中
            for (int j=0; j<repCount; j++) {
                //这里因为要进行多次循环，所以不能改变原先的temptop
                tempTopIndex = tempTop;
                while (tempTopIndex != -1) {
                    //不够扩容
                    if (top == stackSize-1) {
                        stack = realloc(stack, sizeof(char) * (stackSize+=50));
                    }
                    stack[++top] = temp[tempTopIndex--];
                }
            }
            //这里记得释放temp
            free(temp);
            temp = NULL;
        }
    }
    
    //动态调整内存
    char* result = realloc(stack, (top + 2) * sizeof(char));
    result[++top] = '\0';
    return result;
    
}

int main(int argc, char const *argv[])
{
    char str[STACK_INIT_SIZE];
    char *result;
    printf("Please input a string: \n");

    scanf("%s", str);

    result = Uncompress(str);

    printf("Result: \n");
    printf("%s\n", result);

    return 0;
}
