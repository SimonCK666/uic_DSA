#include <stdio.h>
double add(int x, int y);

int main(int argc, char const *argv[])
{
    int x = 7;
    
    double d1 = add(1, 2);
    double d2 = add(2, 3);

    printf("%lf\n", d1);
    printf("%lf\n", d2);
    
    return 0;
}

double add(int x, int y) {
    double dl = x + y;

    return dl;
}