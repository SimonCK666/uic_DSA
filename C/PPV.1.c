#include <stdio.h>

int doubleIt(int x, int p) {
    p = 2 * x;

    return p;
}

int main() {
    int a = 16;
    int res = doubleIt(8, a);

    printf("res: %d\n", res);

    return 0;
}