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

static double *jacobisolve(int n, double a[n][n], double y[n], double tol, int maxiters)
{
    double *x;
    x = malloc(sizeof(double *) * n);
    double dinverse[n];
    double lu[n][n];
    for (int i = 0; i < n; i++)
    {
        x[i] = 1.0;
        dinverse[i] = 1.0 / a[i][i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                lu[i][j] = a[i][j];
            }
            else
            {
                lu[i][j] = 0;
            }
        }
    }
    int iters = 0;
    double err = 10.0 * tol;
    while (err > tol && iters < maxiters)
    {
        iters++;
        double lux[n];
        double y_lux[n];
        for (int i = 0; i < n; i++)
        {
            lux[i] = 0;
            for (int j = 0; j < n; j++)
            {
                lux[i] += (lu[i][j] * x[j]);
            }
            y_lux[i] = y[i] - lux[i];
        }
        double x1[n];
        for (int i = 0; i < n; i++)
        {
            x1[i] = dinverse[i] * y_lux[i];
            x[i] = x1[i];
        }
        err = resid(n, a, y, x);
    }
    return x;
}

int main()
{
    // initialization of variables
    int n = 100;
    double a[100][100];
    double y[100];
    double tol = 0.000001;
    double maxiters = 25;
    double *r1;

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

    r1 = jacobisolve(n, a, y, tol, maxiters);

    printf("< ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f, ", r1[i]);
    }
    printf(">");
}
