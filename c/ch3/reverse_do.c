#include <stdio.h>

#define NELEMS(a) (sizeof(a)/sizeof(a[0]))

/* Demonstrate do-while loop */
int main (void)
{
    int values[] = { 123, 73, 0, 3982 };
    int i = 0;

    while (i < NELEMS(values)) {
        int val = values[i];
        printf("val = %d \t rval = ", val);

        /* Print integer in reverse order */
        do
        {
            printf("%d", val % 10);
            val /= 10;
        } while (val != 0);

        printf("\n");
        ++i;
    }
}
