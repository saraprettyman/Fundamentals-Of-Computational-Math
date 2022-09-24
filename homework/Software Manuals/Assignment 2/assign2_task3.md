**Routine Name:** verbose

**Author:** Sara Prettyman 

**Language:** Python, the IDE I used was PyCharm. 

**Description/Purpose:** This routine produces a table of the results from the Bisection method, Newton's method, and Secant Method of the fucntion $f(x)=x*e^{-x}$. The table displays the iteration number, approximate location of the root and the absolute value of the error in the approximation. Its purpose is for if the user wishes to the steps each individual function went through in order to reach the solution and/or did not reach a solution. 

**Input:**  There are no inputs needed in this case, besides the added verbose = True command, but the inputs were made by the user before the code is run. The input in the terminal is:
    
    ```
    python assign2_task3.md -v
    ```
   which will call the function verbose and run it for all the preceeding methods in the verbose routine. 

**Output:** The output is a 3 column table for each function being run, with it titled "the estimated root of f(x) using" followed by the method name/type. The columns show the number of iterations until the solution was met, or reached its maximum numberr of iterations and did not produce a result. 

**Usage/Example:**  The usage is purely for demonstrative purposes, displaying the results. For instance when newtons method is called it beings with: 

    ```
    ---------------------------------------------------------------------
    Estimating root of f(x) using newton's method:
    iter: | approx root: | abs value of the error in the approximation: 
    ```
**Implementation/Code:** The following is code for verbose() 
```
"""Task 3"""
import numpy as np
import sys


# Newton's method
def newton(x1, f, f_prime, tol, max_iter, verbose):
    current_iter = 0
    error = 10.0 * tol
    if verbose:
        print("---------------------------------------------------------------------")
        print("Estimating root of f(x) using newton's method:")
        print("iter: | approx root: | abs value of the error in the approximation: ")
    while error > tol and current_iter < max_iter:
        if verbose:
            print("%5.0f" % current_iter, "|", "%9.10f" % x1, "|", "%8.10f" % error)
        x2 = x1-f(x1)/f_prime(x1)
        error = abs(x2-x1)
        current_iter = current_iter + 1
        x1 = x2
        if current_iter >= max_iter:
            print("This initial guess has reached its maximum number of iterations.")
    return None


# Secant Method
def secant(x0, x1, f, tol, max_iter, verbose):
    current_iter = 0
    error = 10.0 * tol
    if verbose:
        print("---------------------------------------------------------------------")
        print("Estimating roots of f(x) using secant method:")
        print("iter: | approx root: | abs value of the error in the approximation: ")
    while error > tol and current_iter < max_iter:
        if verbose:
            print("%5.0f" % current_iter, "|", "%9.10f" % x1, "|", "%8.10f" % error)
        x2 = x1-(f(x1)*(x1-x0))/(f(x1)-f(x0))
        error = abs(x2-x1)
        current_iter = current_iter + 1
        x0 = x1
        x1 = x2
        if current_iter >= max_iter:
            print("This initial guess has reached its maximum number of iterations.")
    return None


# Bisection Method
def bisection(verbose, c_text, x0, f, c, tol=0.00000001, max_iter=15):
    g = lambda x: x - c(x) * f(x)
    e0 = 100000
    if verbose:
        print("---------------------------------------------------------------------")
        print("Estimating root of f(x) using bisection method when c is ", c_text, ": ")
        print("iter: | approx root: | abs value of the error in the approximation: ")
    for i in range(1, max_iter):
        x1 = g(x0)
        x0 = x1
        e1 = abs(g(x0) - x0)
        if verbose:
            print("%5.0f" % i, "|", "%9.10f" % x1, "|", "%8.10f" % e1)
        if e1 < tol:
            return x0
        else:
            e0 = e1
    return None


# Create verbose command, and run all root finding methods with it
def verbose():
    verbose = False
    if len(sys.argv) == 2:
        if sys.argv[1] == "-v":
            verbose = True
    f = lambda x: x * np.exp(-x)
    f_prime = lambda x: np.exp(-x) - x * np.exp(-x)
    result_n = newton(-1, f, f_prime, 0.000001, 100, verbose)
    result_s = secant(-1, 1, f, 0.000001, 100, verbose)
    result_b1 = bisection(verbose, 1, .5, lambda x: x * np.exp(-x),
                          lambda x: 1, tol=0.00000001, max_iter=25)
    result_b2 = bisection(verbose, -1, .5, lambda x: x * np.exp(-x),
                          lambda x: -1, tol=0.00000001, max_iter=25)
    result_b3 = bisection(verbose, "x*e^(-x)", .5, lambda x: x * np.exp(-x),
                          lambda x: np.exp(x), tol=0.00000001, max_iter=25)

verbose()

```
