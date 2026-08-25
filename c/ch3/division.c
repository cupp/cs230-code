#include <stdio.h>

/* if-else statement */
int main (void)
{
    int num[] = {43, 564, 7243, 3, 21};    
    int size = sizeof(num)/sizeof(num[0]); /* see text: section 8.1 */
    int k, denom;

    /* Reader should change these two values to get different outcomes */
    k = 4;
    denom = 7;

    if (k < 0 || k > size)
        printf("Error: Invalid number of elements (out-of-bounds).\n");
    else if (denom == 0)
        printf("Error: Denominator is zero.\n");
    else {
        int i;
        printf("Result of division by %d: ", denom);
        for (i = 0; i < k; ++i)
            printf("%d ", num[i]/denom);
        printf("\n");
    }
}
