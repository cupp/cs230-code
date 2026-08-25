#include <stdio.h>

/* Demonstrate for loop */
int main (void)
{
    char tmp, str[] = "Hello World";
    int i, j;

    printf("%s\n", str);

    /* Reverse the string in-place */
    for (j=0; str[j] != '\0'; ++j)
        ;
    for (i=0, --j; i < j; ++i, --j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }

    printf("%s\n", str);
}
