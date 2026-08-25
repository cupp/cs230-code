#include <stdio.h>

#define PI      3.1415926535898
enum { DEG, RAD };

/* Demonstrate switch statement */
int main (void)
{
    double angle = 745;
    int angletype = DEG;

    printf("Non-normalised angle: %f (%s)\n", angle, 
        (angletype == DEG) ? "DEG" : "RAD");

    switch (angletype)
    {
    case DEG:
        angle *= PI / 180.0; /* convert to radians */
        /* fall through */
    case RAD:
        while (angle > PI)   /* normalise radians */
            angle -= 2.0*PI;
        while (angle < -PI)
            angle += 2.0*PI;
        angletype = RAD;
        break;
    default:
        printf("Error: Invalid type\n");
        break;
    }

    printf("Normalised angle: %f (%s)\n", angle, 
        (angletype == DEG) ? "DEG" : "RAD");
}
