#include <stdlib.h>
#include <assert.h>
#include "matrix.h"

double **create_matrix(int m, int n)
/* Dynamically allocate an (m x n) matrix. Returns a pointer to the 
 * beginning of the matrix, and NULL if allocation fails.  */
{
    double **p, *q;
    int i;
    assert(m>0 && n>0);

    /* Allocate pointer array. */
    p = (double **)malloc(m * sizeof(double *));
    if (p == NULL) return p;

    /* Allocate entire matrix as a single 1-D array. */
    q = (double *)malloc(m * n * sizeof(double));
    if (q == NULL) { free(p); return NULL; }

    /* Assign pointers into appropriate bits of matrix. */
    for (i = 0; i < m; ++i, q += n)
        p[i] = q;

    return p;
}

void destroy_matrix(double **p)
/* Destroy a matrix. Notice, due to the method by which this matrix
 * was created, the size of the matrix is not required. */
{
    free(p[0]);
    free(p);
}

double **multiply_matrices(int *mr, int *nr,
                           const double **p1, int m1, int n1,
                           const double **p2, int m2, int n2)
/* Multiply two matrices and create a new matrix for the result. This is a 
 * rather inefficient implementation using array indices, a better solution 
 * would use pointer arithmetic. 
 * The values of parameters mr and nr are the dimensions of the result matrix
 * and are given the values m1 and n2, respectively, by this function.
 * Returns a pointer to the result matrix if successful, NULL if fails. The
 * client is responsible for destroying the result matrix. */
{
    double **r;
    int i, j, k;

    assert(n1 == m2); /* requirement to perform multiply */
    
    /* Create result matrix. */
    *mr = m1; *nr = n2;
    r = create_matrix(m1, n2);
    if (!r) return NULL;

    /* Perform multiply. */
    for (i = 0; i < m1; ++i)
        for (j = 0; j < n2; ++j) {
            r[i][j] = 0;
            for (k = 0; k < n1; ++k)
                r[i][j] += p1[i][k] * p2[k][j];
        }

    return r;
}

/* 
 * Implementations of the earlier matrix functions from the textbook. Refer
 * to the text for further discussion on these functions.
 */

double **create_matrix1(int m, int n)
/* Dynamically allocate an (m x n) matrix. Returns a pointer to the beginning
 * of the matrix. This function does not check for memory-allocation errors. */
{
    double **p;
    int i;

    p = (double **)malloc(m * sizeof(double *));
    for (i = 0; i < m; ++i)
        p[i] = (double *)malloc(n * sizeof(double));
    return p;
}

double **create_matrix2(int m, int n)
/* Dynamically allocate an (m x n) matrix. Returns a pointer to the 
 * beginning of the matrix, and NULL if allocation fails. */
{
    double **p;
    int i;
    assert(m>0 && n>0);

    /* Allocate pointer array. */
    p = (double **)malloc(m * sizeof(double *));
    if (p == NULL) return p;

    /* Allocate rows. */
    for (i = 0; i < m; ++i) {
        p[i] = (double *)malloc(n * sizeof(double));
        if (p[i] == NULL)
            goto failed;
    }
    return p;

    /* Allocation failed, delete already allocated memory. */
failed:
    for (--i; i>=0; --i)
        free(p[i]);
    free(p);
    return NULL;
}

void destroy_matrix1(double **p, int m, int n)
/* Destroy an (m x n) matrix. Notice, the n variable
 * is not used, it is just there to assist using the function. */
{
    int i;
    assert(m>0 && n>0);

    for (i = 0; i < m; ++i)
        free(p[i]);
    free(p);
}
