#include <stdio.h>
#include <stdlib.h> /* for rand() function */

#define SIZE    50

/* Demonstrate "break" operation */
int main(void)
{
    double array[SIZE];
    double smallest, tmp; 
    int i;

    /* Fill array with random numbers */
    for (i = 0; i < SIZE; ++i) { 
        array[i] = rand() / (double)rand();
        printf("%3.4f\t", array[i]);
    }

    /* Fast algorithm for finding the smallest element in array */
    tmp = smallest = array[0]; /* save original first element in tmp */
    while (1) {
        while (array[--i] > smallest) /* search for smaller than current smallest */
            ;
        if (i == 0) 
            break;
        array[0] = smallest = array[i]; /* store new smallest at beginning */
    }
    array[0] = tmp; /* restore first element */

    printf("\n\nSmallest value: %3.4f\n", smallest);
    return 0;
} 
