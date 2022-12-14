#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static double resid(int n, double a[n][n], double y[n], double x[n])
{
    double axsquare;
    for (int i = 0; i < n; i++)
    {
        double p = 0.0;
        for (int j = 0; j < n; j++)
        {
            p += a[i][j] * x[j];
        }
        axsquare += p * p;
    }
    return powf(axsquare, 0.5);
}

static void gaussSeidel(int n, double a[n][n], double y[n], double tol, int maxiters, double result[n])
{
    int iters = 0;
    double x[n];
    double p[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 1.0;
        p[i] = 1.0;
    }
    double err = 10 * tol;
    while (iters < maxiters && err > tol)
    {
        for (int i = 0; i < n; i++)
        {
            x[i] = y[i];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    x[i] -= a[i][j] * p[j];
                }
                if (i > j)
                {
                    x[i] -= a[i][j] * x[j];
                }
                if (i < j)
                {
                    x[i] -= a[i][j] * p[j];
                }
            }
            x[i] /= a[i][i];
        }
        for (int i = 0; i < n; i++)
        {
            p[i] = x[i];
        }
        err = resid(n, a, y, x);
        iters++;
    }

    double diff = 0;
    for (int i = 0; i < n; i++)
    {
        result[i] = x[i] + diff;
        diff *= -1;
        diff += result[i];
    }
}

int main()
{
    // initialization of variables
    int n = 100;
    double a[100][100];
    double y[100];
    double tol = 0.000001;
    double maxiters = 25;
    double result[100];

    // Generating Result vector
    for (int i = 0; i < n; i++)
    {
        result[i] = 0;
    }

    // Generating the Matrix A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
        }
    }

    // Generating the Y vector
    for (int i = 0; i < n; i++)
    {
        y[i] = rand() % 100;
    }

    gaussSeidel(n, a, y, tol, maxiters, result);

    printf("< ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2g, ", result[i]);
    }
    printf(">");
}
