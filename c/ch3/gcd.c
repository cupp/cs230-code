#include <stdio.h>

/* Demonstrate while loop */
int main (void)
{
    int m = 5424, n = 2436;

    printf("m = %d, n = %d, ", m, n);

    /* Compute greatest common divisor of m and n. That is, the largest
        integer that can divide both numbers without leaving a remainder. */
    while (n) {
        int tmp = n;
        n = m % n;
        m = tmp;
    }

    printf("GCD = %d\n", m); 
}
