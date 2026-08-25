/* Fahrenheit to Celcius conversion table (K & R page 15) */
#include <stdio.h>

#define LOWER   0   /* lower limit of temp. table (in Fahrenheit) */
#define UPPER   300 /* upper limit */
#define STEP    20  /* step size */

int main(void)
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d \t%6.1f\n", fahr, (5.0/9.0) * (fahr-32.0));
}
