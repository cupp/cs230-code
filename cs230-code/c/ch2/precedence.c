#include <stdio.h>

/* Demonstrate operators precedence */
int main (void)
{
    char s[100];
    char t[] = "Hello World";
    int i;

    /* Default precedence is wrong */
    i = 0;
    while (s[i] = t[i] != '\0')
        ++i;
    printf("Without (): %s\n", s);

    /* Parentheses enforce correct precedence */
    i = 0;
    while ((s[i] = t[i]) != '\0')
        ++i;
    printf("With (): %s\n", s);
}
