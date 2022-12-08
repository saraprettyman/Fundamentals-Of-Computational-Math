#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void kroneckerMatrices(int m, int n, int p, int q, int a[m][n], int b[p][q], int c[m * p][n * q])
{
    // #pragma omp parallel for
    for (int rowa = 0; rowa < m; rowa++)
    {
        for (int cola = 0; cola < n; cola++)
        {
            for (int rowb = 0; rowb < p; rowb++)
            {
                for (int colb = 0; colb < q; colb++)
                {
                    c[rowa * p + rowb][cola * q + colb] = a[rowa][cola] * b[rowb][colb];
                }
            }
        }
    }
}

int main()
{
    // Initialization of matrices
    // a is mxn
    // b is pxq
    // c is mpxnq
    const int m = 3;
    const int n = 3;
    const int p = 3;
    const int q = 2;

    int a[3][3] = {{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
    int b[3][2] = {{1, 1}, {2, 2}, {3, 3}};
    int c[9][6];

    kroneckerMatrices(m, n, p, q, a, b, c);
    for (int row = 0; row < m * p; row++)
    {
        for (int column = 0; column < n * q; column++)
        {
            printf("%.2d    ", c[row][column]);
        }
        printf("\n");
    }
}
