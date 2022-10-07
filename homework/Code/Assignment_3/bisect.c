/*Assignment 3, Bisection*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double bisect();

double bisect(double (*f)(double), double a, double b, double tol)
{
    //Initialize the variables
    double fa = (*f)(a);
    double fb = (*f)(b);
    //Test bisection
    if (fa*fb >= 0.0)
    {
        printf("There may not be a root in [a,b]: f(a)*f(b)= %e", fa*fb);
        exit(-1); 
    }
    double c;
    double fc;
    int k = ( (-1)*(int)((log(tol) / log(b-a)) / log(2)) + 1 );

    for(double iter = 0; iter<k; iter++)
    {
        c = 0.5 * (a+b);
        fc = (*f)(c);
        if(fa * fc < 0.0)
        {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    printf("The root value is %f\n", c);
    printf("\n");

    return 0;
}

