#include <stdio.h>

/* Demonstrate constants */
int main (void)
{
    int x = 1234, y = 02322, z = 0x4D2; /* three equivalent integer constants */
    double a = 1., b = 1.3, c = 1.65e-2;/* double-precision floating point constants*/
    float d = 3.14f, e = 2.f;           /* single-precision floating point constants*/
    double f = 3 + 7 + 9.2;             /* constant expression */
    int m = 'a', n = '\n', p = '7';     /* character constants */
    char s[20] = "This is a string";    /* string constant */

    /* Print integers */
    printf("Integers:\n");
    printf("x = %d (dec)\tx = %o (oct)\tx = %x (hex)\n", x, x, x);
    printf("x = %d (dec)\ty = %d (dec)\tz = %d (dec)\n\n", x, y, z);

    /* Print floats */
    printf("Floats:\n");
    printf("a = %f\tb = %f\tc = %f\n", a, b, c);
    printf("d = %f\te = %f\tf = %f\n\n", d, e, f);

    /* Print characters */
    printf("Characters:\n");
    printf("m = %c (char code)\tm = %d (int)\n", m, m);
    printf("n = %c (char code)\tn = %d (int)\n", n, n);
    printf("p = %c (char code)\tp = %d (int)\n\n", p, p);

    /* Print string */
    printf("String:\n");
    printf("%s\n\n", s);
}
