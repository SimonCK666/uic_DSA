#include <stdio.h>


int main(int argc, char const *argv[])
{
    double a[] = {5, 6.5, -3, -8};
    int len, i;

    len = sizeof(a) / sizeof(double);

    printf("\n\n%f\n\n", *(a+0));

    printf("\nLength: %d\n\n", len);

    printf("top  -->  ");

    for ( i = len - 1; i >= 0; i--)
    {
        /* code */
        if (i == len - 1)
        {
            /* code */
            printf("|\t%f\t|\n", a[i]);

        } else
        {
            /* code */
            if (a[i] >= 0)
            {
                /* code */
                printf("\t  |\t %f\t|\n", a[i]);
                
            } else
            {
                /* code */
                printf("\t  |\t%f\t|\n", a[i]);

            }
        }
        
        // printf("|\t%f\t|\n", a[i]);
    }
    printf("\t  +---------------------+\n");
    printf("\n");
    printf("\nDone!!\n");

    

    return 0;
}
