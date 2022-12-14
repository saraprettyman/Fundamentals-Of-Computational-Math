#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Power Method
void mvp(int m, int n, double A[m][n], double b[n], double x[m])
// x += Ab
{
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            x[row] += A[row][col] * b[col];
        }
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

static double rayleighQuotient(int m, int n, double a[m][n], double x0[n], double x1[n], double q0[n])
{
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

void scale(int n, double v[n])
{
    for (int i = 0; i < n; i++)
    {
        v[i] /= v[i] / n;
    }
}

static double errorPower(int n, double x0[n], double x1[n])
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
        err = errorPower(n, x0, x1);
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
    double result = rayleighQuotient(m, n, a, x0, x1, q0);
    return result;
}

// Inverse power method shifted
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

static void jacobisolve(int n, double a[n][n], double y[n], double x[n], double tol, int maxiters)
{
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
}

static void prodmv(int n, double a[n][n], double b[n], double x[n])
// x += Ab
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i] += a[i][j] * b[j];
        }
    }
}

static double dot(int n, double a[n], double b[n])
{
    double p = 0;
    for (int i = 0; i < n; i++)
    {
        p += a[i] * b[i];
    }
    return p;
}

static void scaleToLast(int n, double v[n])
{
    for (int i = 0; i < n; i++)
    {
        v[i] /= v[n - 1];
    }
}

static double error(int n, double u[n], double v[n])
{
    double err = 0.0;
    for (int i = 0; i < n; i++)
    {
        err += fabs(u[i] - v[i]);
    }
    return err;
}

static double powershifted(int n, double s, double a[n][n], double tol, int maxiters)
{
    double err = 10.0 * tol;
    int iters = 0;
    double xk[n];
    double xk1[n];
    double p[n];
    for (int i = 0; i < n; i++)
    {
        xk[i] = 1.0;
        a[i][i] -= s;
    }
    while (err > tol && iters < maxiters)
    {
        iters++;
        jacobisolve(n, a, xk, xk1, tol, 20);
        scaleToLast(n, xk1);
        for (int i = 0; i < 1; i++)
        {
        }
        err = error(n, xk, xk1);
        for (int i = 0; i < n; i++)
        {
            xk[i] = xk1[i];
        }
    }
    prodmv(n, a, xk1, p);
    for (int i = 0; i < 1; i++)
    {
    }
    double num = dot(n, xk1, p);
    // printf("\naxkxk\n");
    for (int i = 0; i < 1; i++)
    {
        a[i][i] += s;
    }
    double denom = dot(n, xk1, xk1);
    double result = num / denom;
    return result + s;
}

int main()
{
    // Initialization of matrices
    // a is mxn, x0 is n
    int m = 10;
    int n = 10;
    double a[10][10];
    printf("The generated random matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
            printf("%.2f, ", a[i][j]);
        }
    }
    double x0[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    double x1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double q0[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double tol = 0.0001;
    int maxIter = 25;
    
    // Create variables
    double lambdas[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double minLambda;
    double maxLambda;
    double step;

    // Initialize variables
    minLambda = 126.11091;
    maxLambda = powerMethod(m, n, a, x0, x1, q0, tol, maxIter);
    step = fabs(maxLambda - minLambda) / n;
    printf("\n\nThe eigenvalues are:");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        lambdas[i] = powershifted(n, minLambda, a, tol, maxIter);
        printf("%.2f, ", lambdas[i]);
        minLambda = minLambda + step;
    }
}
