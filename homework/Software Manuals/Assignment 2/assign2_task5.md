**Routine Name:** hybrid_bs

**Author:** Sara Prettyman 

**Language:** Python, the IDE I used was PyCharm. 

**Description/Purpose:** This routine will compute the root, x1, of a polynomial, such that the polynomial f(x1)=0. This routine calculates an approximate root, and runs through multiple iteratiosd of itself in order to achieve that root. This method is more stable than secant method alone, and the bisection combination results in a more efficient root finding process. 

**Input:**  Tolerable error = 0.0000001, f =$10.14 * e^{x^2} * cos(\frac{\pi}{x})$, maximum iterations = 100, a (this is initial lower bound guess of the interval), b (this is the initial upper bound guess of the interval)

**Output:**  The output is an approximate solution/guess for the root of the function f, which is denoted as x1. If no root is found in proximity, the function will let the user know the routine has run its maximum number of iterations.

**Usage/Example:**   This routine takes in the 4 input arguments: tolerable error (due to computer error existing, this allows approimate solutions to be found), function f, the maximum iterations (to stop an endless loop of search of a nonexistant solution), a (this is initial lower bound guess of the interval), b (this is the initial upper bound guess of the interval). The routine uses the function test_if_negative to see if there is a root in the interval, and if so perfroms secant methods to find an approximation of the root. After root is found or determined not to be there, the next interval is tested by adding 0.001 to a and b, and testing the new interval. For instance, when the guess is x1 = -1 and x2= 1, the output is:

    ```
    The solution s are:  [-2.         -0.66666667 -0.4        -0.28571429 -0.22222222 -0.18181818
     -0.15384615 -0.13333333 -0.11764706 -0.10526316 -0.0952381  -0.08695652
     -0.08       -0.07407407 -0.06896552 -0.06451613 -0.06060606 -0.05714286
     -0.05405405 -0.05128205 -0.04878049 -0.04651163 -0.04444444 -0.04255319
     -0.04081633 -0.03921569 -0.03773585 -0.03636364 -0.03508772  0.00881058
     -0.03508772 -0.10526316 -0.02985075 -0.02898551 -0.02739726 -0.02597403
     -0.02298851 -0.02061856 -0.01904762 -0.02816901 -0.0173913  -0.016
     -0.016      -0.01036269  0.00626959  0.016       0.016       0.01801802
      0.02666667 -0.34958065  0.02197802  0.02352941  0.02531646         nan
      0.02898551  0.03076923  0.03174603  0.03278689  0.03389831  0.03508772
      0.03636364  0.03773585  0.03921569  0.04081633  0.04255319  0.04444444
      0.04651163  0.04878049  0.05128205  0.05405405  0.05714286  0.06060606
      0.06451613  0.06896552  0.07407407  0.08        0.08695652  0.0952381
      0.10526316  0.11764706  0.13333333  0.15384615  0.18181818  0.22222222
      0.28571429  0.4         0.66666667  2.        ]
        ```

**Implementation/Code:** The following is the code for hybrid_bs()

```
"""Task 5. Bisection/Secant Method for Root Finding."""
import numpy as np
import math


# BISECTION Method
def bisection(f, a, b):
    try:
        return f(a) * f(b) < 0
    except FloatingPointError:
        return False


# Secant method
def secant(x0, x1, f, tol, max_iter):
    current_iter = 0
    error = 10.0 * tol
    while error > tol and current_iter < max_iter:
        x2 = x1-(f(x1)*(x1-x0))/(f(x1)-f(x0))
        error = abs(x2-x1)
        current_iter = current_iter + 1
        x0 = x1
        x1 = x2
        if current_iter >= max_iter:
            print("This initial guess has reached its maximum number of iterations.")
    return x1


# Hybrid
def sub_intervals():
    x0_list = []
    int_guess = -3.0
    while int_guess < -0.01:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.001
    int_guess = 0.01
    while 0.01 <= int_guess <= 7:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.001
    return x0_list

def hybrid_bs(f, a, b, tol):
    init_index = 0
    solutions = []
    while init_index + 1 < len(x0_list):
        if bisection(f, a, b):
            x = secant(a, b, f, tol, 25)
            if x is not None:
                solutions.append(x)
        a = x0_list[init_index]
        b = x0_list[init_index+1]
        init_index += 1
    if len(solutions) == 0:
        print("There are no solutions in the interval: ",
              "[", x0_list[0], ",", x0_list[len(x0_list) - 1], "]")
    else:
        print("The solution s are: ", np.transpose(solutions))
    return solutions.sort


# functions/initialization
f = lambda x: 10.14 * np.exp(x ** 2) * np.cos(np.pi / x)
x0_list = sub_intervals()

# main code
hybrid_bs(f, x0_list[0], x0_list[1], 0.0000001)
```
