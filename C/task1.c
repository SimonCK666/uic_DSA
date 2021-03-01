#include <stdio.h>
#include <stdlib.h>

long int factR(int n);

int main(int argc, char const *argv[])
{
    int n, res;
    printf("Input: ");
    scanf("%d", &n);

    // get the result
    res = factR(n);
    printf("res: %d\n", res);

	system("pause");
    return 0;
}


long int factR(int n) {
    if (n == 1)
    {
        return 1;
    } else if(n > 1) {
        // find the factorial
        return n * factR(n - 1);
    }
    
}