// Sum of Natural Numbers Using Recursion

#include <stdio.h>

int sum(int n);

int main(int argc, char const *argv[])
{
    int n = 100;
    int res;

    res = sum(100);

    printf("sum: %d\n", res);
    
    return 0;
}

int sum(int n) {
    if (n != 0)
    {
        /* code */
        return n + sum(n - 1);
    } else {
        return n;
    }
    
}
