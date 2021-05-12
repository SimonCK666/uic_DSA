#include <stdio.h>

void insertSort(int r[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        /* code */
        r[0] = r[i];
        int j = i - 1;

        while (r[0] < r[j])
        {
            /* code */
            r[j + 1] = r[j];
            j--;
        }

        r[j + 1] = r[0];
        
    }
    
}


int main(int argc, char const *argv[])
{
    int r[] = {7, 3, 5 ,2 ,1};
    int n = 6;

    insertSort(r, n);

    for (int i = 1; i <= n; i++)
    {
        /* code */
        printf("%d\t", r[i]);
    }

    printf("\n");
    
    return 0;
}
