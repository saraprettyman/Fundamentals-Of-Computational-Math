# Implicit Euler Method implementation
import numpy as np
from root_finding import secant


def eulerImplicit(a, b, P0, t0, tol, h,  maxiters):
    # Define the function
    f = lambda p: a*p-b*p*p

    # Define implicit function at the second P value
    def create_implicit(f, h, P0):
        def g(P1):
            return (P0 - P1 + h * (f(P1)))
        return g

    # Initialization of variables 
    iters = 0
    error = 10*tol
    listOfPoints = [[t0, P0]]

    # Create list of t values and derivatives 
    while (error>tol and iters<maxiters):
        target = create_implicit(f, h, P0)

        P1 = secant(P0, P0+2*h, target, .0001, 200) 
        error = np.abs(P1-P0)
        iters = iters + 1
    
        t0 = t0+h
        P0 = P1
        listOfPoints.append([t0, P0])

    return listOfPoints

# Print results of different test alphas and betas
result1 = eulerImplicit(0.20, 0.0005, 10, 0, 0.00001, 0.1,  500)
print("The solution for alpha is 0.20 and beta is 0.0005, is, with [t0,P0]: ",result1[len(result1)-1])
result2 = eulerImplicit(0.01, 0.0005, 10, 0, 0.00001, 0.1,  500)
print("The solution for alpha is 0.01 and beta is 0.0005, is, with [t0,P0]: ",result2[len(result2)-1])
result3 = eulerImplicit(2.00, 0.0005, 10, 0, 0.00001, 0.1,  500)
print("The solution for alpha is 2.00 and beta is 0.0005, is, with [t0,P0]: ",result3[len(result3)-1])
