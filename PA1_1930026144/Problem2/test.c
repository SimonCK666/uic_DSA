#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKSIZE 50
#define SIZE 50

//declear
struct stack
{
    char *sta;
    int top;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 0;
    else
        return 1;
}

// full
int isFull(struct stack *s)
{
    if (s->top == STACKSIZE - 1)
        return 1;
    else
        return 0;
}


void CreateStack(struct stack *s)
{
    s->top = -1;
    s->sta = (char*)malloc(sizeof(char) * STACKSIZE);

}


int Push(struct stack *s, char data)
{
    if (isFull(s))
    {
        printf("stack is full. \n");
        exit(1);
    }
    (s->top)++;
    s->sta[s->top] = data;
}


char Pop(struct stack *s)
{
    if (isEmpty(s) == 0)
    {
        printf("stack is empty. \n");
        exit(1);
    }
    char tmp = s->sta[s->top];
    (s->top)--;

    return tmp;
}


char TOP(struct stack *s)
{
    if (isEmpty(s) == 0)
    {
        return -1;
    }
    char tmp = s->sta[s->top];

    return tmp;
}


int ValidBrackets(struct stack *sta, char *string)
{
    char *ps = string;
    while (*ps != '\0')
    {
        switch (*ps)
        {
        case '(':
        case '{':
        case '[':
        case '<':
            Push(sta, *ps);
            break;
        case ')':
            if ('(' == (TOP(sta)))
            {
                Pop(sta);
                break;
            }
            else
                goto err;
        case '}':
            if ('{' == (TOP(sta)))
            {
                Pop(sta);
                break;
            }
            else
                goto err;
        case ']':
            if ('[' == (TOP(sta)))
            {
                Pop(sta);
                break;
            }
            else
                goto err;
        case '>':
            if ('<' == (TOP(sta)))
            {
                Pop(sta);
                break;
            }
            else
                goto err;
        default:
            break;
        }
        ps++;
    }
    if (isEmpty(sta) == 0)
    ok:
        return 0;
    else
    err:
        return 1;
}


int main(int argc, char *argv[])
{
    struct stack sta;

    CreateStack(&sta);

    char buf[SIZE] = {0};

    //	char* buf = "he({ljfs})jfkdjs";
    printf("Please input a string：\n");
    fgets(buf, SIZE, stdin);

    int ret = ValidBrackets(&sta, buf);
    if (ret == 0)
        printf("Compare... \n");
    else
        printf("NOT Compare!!! \n");

    return 0;
}