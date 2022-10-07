/*Assignment 3, Fixed Point  Method*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double g_test1();
double g_test2();
double g_test3();
double fixedpoint();


double g_test1(double x, double(*f)())
{
    return (x-(*f)(x));
}

double g_test2(double x, double(*f)())
{
    return (x+(*f)(x));
}

double g_test3(double x, double(*f)())
{
    return (x-exp(x)*f(x));
}

double fixedpoint(double (*f)(), double (*g)(), double x_0) {
    int iters = 0;
    int max_iters = 25;
    double tol = 0.00001;
	double error = 10 * tol;
	double x_k = x_0;
	while (error > tol && iters < max_iters) {
		double x_k1 = (*g)(x_k, f);
		error = fabs(x_k - x_k1);
		iters++;
		x_k = x_k1;
	}
	if (error <= tol) 
    { 
         printf("The solution is %f\n", x_k);
    }else{
        printf("There is no solution for this test\n");
    }

    return 0;
}