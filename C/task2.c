#include <stdio.h>
#include <string.h>
void reverseR(char *str, int length);

int main(int argc, char const *argv[])
{
    char str[50];
    char *s;
    int len;
    printf("Input: ");
    
    scanf("%s", str);

    // test
    printf("Test: \n");

    for (int i = 40; i >= 0; i--)
    {
        /* code */
        if (str[i] >= 'a' || str[i] <= 'z' || str[i] >= 'A' || str[i] <= 'Z')
        {
            /* code */
            printf("%c", str[i]);
        }
        
    }
    
    

    printf("\n\n");


    return 0;
}

void reverseR(char *str, int length) {
    
}