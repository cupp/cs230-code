#include <stdio.h>

/* Demonstrate logical and relational operators */
int main (void)
{
    int a=1, b=2, c=3, d=3;

    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    printf("(a < b && b < c && c < d) = %d\n", a < b && b < c && c < d);
    printf("(a < b && b < c && c <= d) = %d\n", a < b && b < c && c <= d);
    printf("((a < b && b < c) || c < d) = %d\n", (a < b && b < c) || c < d);
}
