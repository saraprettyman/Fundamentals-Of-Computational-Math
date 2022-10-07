#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bisect.c"
#include "newtons.c"
#include "fixedpoint.c"
#include "hybrid_bn.c"
#include "hybrid_bs.c"
#include "secant.c"


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


double main()
{
    printf("Bisection\'s method has the following results:\n");
    double rootval_1 = bisect(fvalue, -0.50 , 0.50, 0.00001);

    printf("Newton\'s method has the following results:\n");
    double rootval_2 = newtons(fvalue, fvalue_prime, 25, 0.00001, -0.50);

    printf("\nSecant\'s method has the following results:\n");
    double rootval_3 = secant(fvalue, 100, 0.000001, -1, 1);

    printf("\nFixedpoint method has the following results:");printf("\nFixed point test 1 \n");
    double rootval_4a = fixedpoint(fvalue, g_test1, 1); printf("\nFixed point test 2\n");
    double rootval_4b = fixedpoint(fvalue, g_test2, 1); printf("\nFixed point test 3\n");
    double rootval_4c = fixedpoint(fvalue, g_test3, 1); 

    printf("\nHybrid bisection/newton method has the following results:\n");
    double rootval_5 = hybrid_bn(fvalue, fvalue_prime, 25, 0.00001, -0.50, 0.5);

    printf("\nHybrid bisection/secant method has the following results:\n");
    double rootval_6 = hybrid_bs(fvalue, 25, 0.00001, -1, 1);
    
    return 0;
}
    