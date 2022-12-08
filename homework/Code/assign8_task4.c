#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 4

void mvp(int m, int n, double A[m][n], double b[n], double x[m])
// x += Ab
{
    for (int row = 0; row < m; row++)

        for (int col = 0; col < n; col++)
        {
            x[row] += A[row][col] * b[col];
        }
}

double vectDotProduct(double array1[], double array2[], int size)
{
    double funct = 0;
    for (int i = 0; i < size; i++)
    {
        funct = array1[i] * array2[i] + funct;
    }
    return funct;
}

void scale(int n, double v[n])
{
    for (int i = 0; i < n; i++)
    {

        v[i] /= v[n - 1];
    }
}

static double error(int n, double x0[n], double x1[n])
{

    double err = 0.0;
    for (int i = 0; i < n; i++)
    {
        err += fabs(x1[i] - x0[i]);
    }
    return err;
}

static double powerMethod(int m, int n, double a[m][n], double x0[n], double x1[n], double q0[n], double tol, int maxiter)
{
    double err;
    for (int iter = 0; iter < maxiter; iter++)
    {
        mvp(m, n, a, x0, x1);
        scale(n, x1);
        err = error(n, x0, x1);
        if (err < tol)
        {
            break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                x0[i] = x1[i];
            }
            for (int i = 0; i < n; i++)
            {

                x1[i] = 0;
            }
        }
    }

    // Find lambda from rayleigh quotient

    double numerator;

    double denominator;

    double result;

    // Ax

    mvp(m, n, a, x1, q0);

    // Ax*x

    numerator = vectDotProduct(x1, q0, n);

    // x*x

    denominator = vectDotProduct(x1, x1, n);

    // lambda

    result = numerator / denominator;

    return result;
}

int main()
{

    // Initialization of matrices

    // a is mxn, x0 is n

    int m = 10;

    int n = 10;

    double a[10][10];

    printf("The generated random matrix is:\n");

    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int count = omp_get_num_threads();
        for (int i = id; i < n; i += count)
        {
            printf("\n");
            for (int j = 0; j < n; j++)
            {
                a[i][j] = rand() % 100;
                printf("%.2f, ", a[i][j]);
            }
        }
#pragma omp barrier
    }

    double x0[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    double x1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    double q0[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    double tol = 0.0001;

    int maxIter = 25;

    double lambda;

    lambda = powerMethod(m, n, a, x0, x1, q0, tol, maxIter);

    printf("\n\nThe largest eigenvalue is: %.5f", lambda);
}