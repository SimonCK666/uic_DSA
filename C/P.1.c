#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n = 7;
    int *y = &n;
    int x = 0;

    printf("n: %d\n", n);
    printf("n: %p\n", n);

    printf("\n");

    printf("y: %d\n", y);
    printf("y: %p\n", y);

    printf("\n");

    printf("*y: %d\n", *y);
    printf("*y: %p\n", *y);

    
    return 0;
}
