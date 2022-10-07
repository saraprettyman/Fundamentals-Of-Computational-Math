/*Assignment 3, Hybrid Binomial and Newtons Method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double hybrid_bn();


double hybrid_bn(double (*f)(double), double (*g)(double) , double max_iter, double tol, double a, double b)
{
    int init_index = 0;
    double x0;
    /*This is bisection first, if true then perform newtons method*/
    if ((*f)(a)*(*f)(b)<0)
    {
        double current_iter = 0.0;
        double error = 10*tol;
        double x2 = b;
        double x1 = a;
        while (error > tol && current_iter < max_iter)
        {
            x2 = x1-(*f)(x1)/(*g)(x1);
            error = fabs((double) x2-x1);
            current_iter = current_iter + 1;
            x1 = x2;
            if (current_iter >= max_iter)
            {
                printf("This initial guess has reached its maximum number of iterations.");
            }
        }
        printf("The solutions is:%f\n", x1);
        return x1;
    }
    else {
        printf("There is no solution in this interval");
        return 0;
    }

    return 0;
}
