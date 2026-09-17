#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "matrix.h"

void print_matrix(double **x, int m, int n)
{
    int i,j;

    for (i=0; i<m; ++i) {
        for (j=0; j<n; ++j)
            printf("%f ", x[i][j]);
        printf("\n");
    }
}

int main(void)
{
    double **p, **q, **r;
    int m,n;

    p = create_matrix(2,3);
    q = create_matrix(3,2);

    p[0][0] = 1.; p[0][1] = 2.; p[0][2] = 3.;
    p[1][0] = 4.; p[1][1] = 5.; p[1][2] = 6.;

    q[0][0] = 9.; q[0][1] = 8.;
    q[1][0] = 7.; q[1][1] = 6.;
    q[2][0] = 5.; q[2][1] = 4.;

    r = multiply_matrices(&m, &n, p, 2,3, q, 3,2);

    printf("\nMatrix p:\n");
    print_matrix(p,2,3);

    printf("\nMatrix q:\n");
    print_matrix(q,3,2);

    printf("\nMatrix r:\n");
    print_matrix(r,m,n);

    destroy_matrix(p);
    destroy_matrix(q);
    destroy_matrix(r);
}
