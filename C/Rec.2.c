#include <stdio.h>

int recurse(int i) {
    if (i == 0)
    {
        /* code */
        return 0;
    }
    
    return recurse(i - 1);
}

int main() {
    int i;
    scanf("%d", &i);
    
    printf("%d\n",recurse(i));

    return 0;
}