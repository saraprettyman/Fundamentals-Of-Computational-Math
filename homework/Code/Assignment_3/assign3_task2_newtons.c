/*Assignment 3, Newtons*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double fvalue(double);
double fvalue_prime(double);
double newton();

double main(){
    double tol = 0.00001;
    double max_iter = 25;
    double x1 = -0.50;
    double rootval = newton(fvalue, fvalue_prime, max_iter, tol, x1);

    return 0;
}


double newton(double (*f)(double), double (*g)(double), double max_iter, double tol, double x1)
{
    double current_iter = 0.0;
    double error = 10*tol;
    double x2;
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
    printf("The root of this function is %f:\n", x1);
    return 0;
}


double fvalue(double xval)
{
    double fval =  (exp(-1*xval)*xval);
    printf("xval = %f, fval = %f\n", xval, fval);
    return fval;
}


double fvalue_prime(double xval)
{
    double fval_prime = (1-xval)/exp(-1*xval); 
    return fval_prime;
}
