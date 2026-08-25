#include <stdio.h>
#include <stdlib.h> /* for rand() function */

#define SIZE    50

/* Demonstrate "continue" operation */
int main(void)
{
    double array[SIZE];
    int i;

    /* Fill array with random numbers */
    for (i = 0; i < SIZE; ++i) { 
        array[i] = rand() / (double)rand() - 0.5;
        printf("%3.4f\t", array[i]);
    }
    printf("\n\n");

    /* Process array */
    for (i = 0; i<SIZE ; ++i) {
        /* Skip -ve elements */
        if (array[i] < 0) 
            continue;

        /* Process +ve elements */
        printf("%3.4f\t", array[i]);
    }
    printf("\n\n");
} 
