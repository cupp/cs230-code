#include <stdio.h>

/* ?: statement */
int main (void)
{
    int a = 1, b = 2, c;

    c = a > b ? a : b; /* c = max(a, b) */

    printf("a = %d, b = %d, c = %d\n", a, b, c);
    printf("The condition a > b is %s\n", a > b ? "true" : "false");
}
