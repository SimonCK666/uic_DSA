#include <stdio.h>

int doubleIt(int x, int *p) {
    *p = 2 * x;

    return *p;
}

int main() {
    int a = 16;

    printf("res: %d\n", doubleIt(9, &a));

    return 0;
}