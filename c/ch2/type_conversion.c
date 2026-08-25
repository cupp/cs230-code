#include <stdio.h>

/* Look at effect of various type conversions. */
int main (void)
{
    char cresult;
    int iresult;
    unsigned uresult;

    iresult = 0.5 + 3/5;
    printf("Integer division: %d %f\n", iresult, 0.5 + 3/5);

    iresult = 0.5 + 3/5.0;
    printf("Floating division: %d %f\n", iresult, 0.5 + 3/5.0);

    cresult= 235; /* value too big for signed char - will be negative */
    printf("Conversions from char: %c %d %u\n", cresult, (int)cresult, (unsigned char)cresult);

    iresult = -66000;
    printf("Conversions from int: %d %u %d \n", iresult, (unsigned)iresult, (short)iresult);

    uresult = (unsigned)-66000; /* negative value will represent a positive unsigned */
    printf("Conversions from unsigned: %u %d %d \n", uresult, (int) uresult, (short)uresult);
}
