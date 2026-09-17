/* Create and destroy matrices and perform arithmetic operations. Demonstrates
 * the example from Chapter 9 (on Dynamic Memory).
 */

#ifndef MATRIX_H_
#define MATRIX_H_

double **create_matrix(int m, int n);
void destroy_matrix(double **p);

double **multiply_matrices(int *mr, int *nr,
                           const double **p1, int m1, int n1,
                           const double **p2, int m2, int n2);

#endif
