**Routine Name:** secant 

**Author:** Sara Prettyman 

**Language:** Python; the IDE I used was PyCharm. 

**Description/Purpose:** This routine will compute the root, x1, of a polynomial, such that the polynomial f(x1)=0. This routine calculates an approximate root, and runs through multiple iteratiosd of itself in order to achieve that root. The initial root, however, is guessed by the user and due to the instability of this root finding approach may not produce the answer based on the initial x1 guess. 

**Input:**  The following inputs were made by the user before the code is run: tolerable error = 0.000001, f = $x * e^{-x}$, maximum iterations = 100, x1 = -1 (where x1 is the initial guess),  x2 = 1 (where x2 is the other initial guess that does not equal x2.)


**Output:** The output is an approximate solution/guess for the root of the function f, which is denoted as x1. If no root is found in proximity to the guy, the function will let the user know the routine has run its maximum number of iterations. 

**Usage/Example:**  This routine takes in the 5 input arguments: tolerable error (due to computer error existing, this allows approimate solutions to be found), the maximum iterations (to stop an endless loop of search of a nonexistant solution), our initial guess of x1 (which due to the instability of secant method must be near the root in order to efficiently work), and our guess for x2 (this is the point which is created using the derivative each time the function runs). For instance, when the guess is x1 = -1 and x2= 1, the output is:

**Implementation/Code** 

```
import numpy as np

# Define secant function
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


# Define f, run secant, and print results
f = lambda x: x * np.exp(-x)
result = secant(-1, 1, f, 0.000001, 100)
print("The root of the function using secant method is: ", result)
```
**Last Modified:** September/2022
