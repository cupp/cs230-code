#include <stdio.h>  /* for printf() */
#include <stdlib.h> /* for rand() */
#include <string.h> /* for memset() */

#define SIZE    1000
enum { VAL1='a', VAL2='b', VAL3='Z' };

int main(void)
/* Demonstrate a legitimate use of goto (adapted from K&R page 66). 
 * This example is contrived, but the idea is to find a common
 * element in two arrays. In the process, we demonstrate a couple
 * of useful standard library functions. */
{
    char a[SIZE], b[SIZE];
    int i, j;

    /* Initialise arrays so they are different from each other */
    memset(a, VAL1, SIZE); 
    memset(b, VAL2, SIZE); 

    /* Set a random element in each array to VALUE */
    a[rand()%SIZE] = VAL3;
    b[rand()%SIZE] = VAL3;

    /* Search for location of common elements */
    for (i=0; i<SIZE; ++i)
        for (j=0; j<SIZE; ++j)
            if (a[i] == b[j])
                goto found;
    
    /* Error: match not found */
    printf("Did not find any common elements!!\n");
    return 0;

found: /* Results on success */
    printf("a[%d] = %c and b[%d] = %c\n", i, a[i], j, b[j]);
}
