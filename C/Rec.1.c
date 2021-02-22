#include <stdio.h>

int recurse(int i) {
    return recurse(i - 1);
}

int main() {
    int i;
    scanf("%d", &i);
    
    printf("%d\n",recurse(i));

    return 0;
}