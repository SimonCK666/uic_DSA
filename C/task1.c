#include <stdio.h>

long int factR(int n);

int main(int argc, char const *argv[])
{
    int n, res;
    printf("Input: ");
    scanf("%d", &n);

    res = factR(n);
    printf("res: %d\n", res);

    return 0;
}


long int factR(int n) {
    if (n == 1)
    {
        /* code */
        return 1;
    } else if(n > 1) {
        return n * factR(n - 1);
    }
    
}