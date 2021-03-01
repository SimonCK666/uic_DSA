#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y);
void swap(int x, int y);

int main(int argc, char const *argv[])
{
    int x, y;
    int res;
    printf("Input x:\n");
    scanf("%d", &x);
    printf("Input y:\n");
    scanf("%d", &y);

    if (x < y)
    {
        /* let the first value bigger than the second value */
        swap(x, y);
    }
    
    // call the function
    res = GCD(x, y);
    printf("Result: %d\n", res);

    system("pause");

    return 0;
}

int GCD(int x, int y) {
    if (y > 0)
    {
        if (x % y == 0)
        {
            return y;
        } else
        {
            // get the greatest common divisor
            return GCD(y, x % y);
        }
    } else if (y == 0)
    {
        return x;
    }
}

void swap(int x, int y) {
    // swap the x y
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}
