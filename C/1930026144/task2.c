#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseR(char *str, int length);

int main(int argc, char const *argv[])
{
    char str[50];
    int len, num = 0;

    printf("Input:\n");
    scanf("%s", str);

    do
    {
        /* get the length */
        num++;
    } while (str[num] != '\0');
    
    // using the recursion
    reverseR(str, num);
    printf("%s\n", str);
    printf("\n");
    // getchar();

    system("pause");

    return 0;
}

void reverseR(char *str, int length) {
    char temp;
    if (length != 1 && length != 0)
    {
        /* let temp equal to the first value */
        temp = *str;
        // the first value equal to the last value
        *str = *(str + length -1);
        // let the last value equal to the first value
        *(str + length -1) = temp;
        // call itself
        reverseR(str + 1, length -2);
    } else
    {
        return ;
    }
    
    
}