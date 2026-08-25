#include <stdio.h>

/* Demonstrate printf conversion specifiers */
int main (void)
{
    printf("Character values: %c %c %c\n", 'a', 'b', 'c');
    printf("Floating-point values: %f %f %f\n", 3.556, 2e3, 40.1f);
    printf("Scientific notation:   %e %e %e\n", 3.556, 2e3, 40.1f);

    /* Right-justify string with space for 15 chars, print only first 10 letters */
    printf("%15.10s\n", "Hello World\n"); 
}
