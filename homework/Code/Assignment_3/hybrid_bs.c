/*Assignment 3, Hybrid Binomial and Secant Method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double hybrid_bs();

double hybrid_bs(double (*f)(double), double max_iter, double tol, double a, double b)
{
    double x0;
    double current_iter = 0.0;
    double error = 10.0*tol;
    /*This is bisection first, if true then perform newtons method*/
    if ((*f)(a)*(*f)(b)<0)
    {
        double x1 = b;
        double x0 = a;
        double x2;
        while (error > tol && current_iter < max_iter)
        {
            x2 = x1-((*f)(x1)*(x1-x0))/((*f)(x1)-(*f)(x0));
            error = fabs(x2-x1);
            current_iter = current_iter + 1;
            x0 = x1;
            x1 = x2;
            if (current_iter >= max_iter)
            {
                printf("This initial guess has reached its maximum number of iterations.");
            }
            
        }
        printf("The solutions is: %f", x1);
        return 0;
    }
    else {
        printf("There is no solution in this interval");
        return 0;
    }

    return 0;
}
