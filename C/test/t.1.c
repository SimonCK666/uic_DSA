#include <stdio.h>
int main() {
    int i = 0, c;
    
    while ((c = getchar()) != EOF)
    {
        /* code */
        if (c != 10)
        {
            /* code */
            ++i;
        } else
        {
            /* code */
            break;
        }
        
    }

    printf("%d\n", i);

    return 0;
    
}