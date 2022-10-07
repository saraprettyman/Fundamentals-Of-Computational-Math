/*Assignment 3, Secant Method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double secant(double (*f)(double), double max_iter, double tol, double x0, double x1)
{
    double current_iter = 0.0;
    double error = 10*tol;
    double x2;
    while (error > tol && current_iter < max_iter)
    {
        x2 = x1-(f(x1)*(x1-x0))/(f(x1)-f(x0));
        error = fabs((double) x2-x1);
        current_iter = current_iter + 1;
        x0 = x1;
        x1 = x2;
        if (current_iter >= max_iter)
        {
            printf("This initial guess has reached its maximum number of iterations.");
        }
    }
    printf("The root of this function is %f\n ", x1);
    return 0;
}


