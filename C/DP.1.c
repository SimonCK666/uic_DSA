#include <stdio.h>
int main(int argc, char const *argv[])
{
    int *pc;
    int c;

    c = 22;

    printf("Address of c: %u\n", &c);
    printf("Value of c: %d\n\n", c);

    pc = &c;
    printf("Value of pc: %u\n", pc);
    printf("Value of *pc: %d\n\n", *pc);

    *pc = 2;
    // c = 2;
    printf("Address of c: %u\n", &c);
    printf("Value of c: %d\n\n", c);

    return 0;
}
