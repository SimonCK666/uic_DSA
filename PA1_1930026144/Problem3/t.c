#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    /* data */
    char *values;
    int top;
    int maxSize;
} Stack;

char * Uncompress(char * str){
    int len = (int)strlen(str);
    int maxSize = 50;
    char *stack = malloc(sizeof(char) * maxSize);
    int top = -1;
    
    for (int i=0; i<len; i++) {
        if (str[i] != ')') {
            //get more memory
            if (top == maxSize-1) {
                stack = realloc(stack, sizeof(char) * (maxSize+=50));
            }
            stack[++top] = str[i];
        }else{
            //create a new stack
            int tempSize = 20;
            char * temp = malloc(sizeof(char) * tempSize);
            int tempTop = -1;
            
            while (stack[top] != '(') {
                //get more memory
                if (tempTop == tempSize-1) {
                    temp = realloc(temp, sizeof(char) * (tempSize+=20));
                }
                
                temp[++tempTop] = stack[top--];
            }
            //get the top
            int rightIndex = top;
            
            top--;
            
            while (top > -1 && stack[top] >= '0' && stack[top] <= '9') {
                top--;
            }
            char strOfInt[11];
            // store in the array
            for (int j = top+1; j<rightIndex; j++) {
                strOfInt[j-(top+1)] = stack[j];
            }
            //change to the string
            strOfInt[rightIndex - (top+1)] = '\0';
            //change to number
            int repCount = atoi(strOfInt);
            
            int tempTopIndex;
            
            for (int j=0; j<repCount; j++) {
                
                tempTopIndex = tempTop;
                while (tempTopIndex != -1) {
                    //get more memory
                    if (top == maxSize-1) {
                        stack = realloc(stack, sizeof(char) * (maxSize+=50));
                    }
                    stack[++top] = temp[tempTopIndex--];
                }
            }
            //free temp
            free(temp);
            temp = NULL;
        }
    }
    
    // get the result
    char* result = realloc(stack, (top + 2) * sizeof(char));
    result[++top] = '\0';
    return result;
}


int main(int argc, char const *argv[])
{
    char str[50];
    char *result;
    printf("Please input a string: \n");

    // read str
    scanf("%s", str);

    result = Uncompress(str);

    printf("Result: \n");
    printf("%s\n", result);

    return 0;
}