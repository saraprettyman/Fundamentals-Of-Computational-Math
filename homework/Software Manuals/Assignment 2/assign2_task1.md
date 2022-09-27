**Routine Name:** newton 

**Author:** Sara Prettyman 

**Language:** Python, the IDE I used was PyCharm. 

**Description/Purpose:** This routine will compute the root, x1, of a polynomial, such that the polynomial f(x1)=0. This routine calculates an approximate root, and runs through multiple iterations of itself in order to achieve that root. The initial root, however, is guessed by the user and due to the instability of this root finding approach may not produce the answer based on the initial x1 guess. 

**Input:**  The following inputs were made by the user before the code is run: tolerable error = 0.000001, f = $x * e^{-x}$, $f_{prime}=e^{-x}-x*e^{-x}$, maximum iterations = 100, x1 = -1 (where x1 is the initial guess.) 

**Output:** The output is an approximate solution/guess for the root of the function f, which is denoted as x1. If no root is found in proximity to the guess, the routine will let the user know it has run its maximum number of iterations. 

**Usage/Example:** This routine takes in the 5 input arguments: tolerable error (due to computer error existing, this allows approimate solutions to be found), the maximum iterations (to stop an endless loop of search of a nonexistant solution), f, f prime(the derivative of f), and our initial guess of x1 (which due to the instability of newtons method must be near the root in order to efficiently work). For instance, when the guess is x1 = -1, the output is:

    ```The root of the function using newton method is:  -9.389621148813321e-14```
    
   The root is essentially zero, but due to computer rounding error and the acceptable tolerance, it is displayed a arbitrarily small number. 
    
**Implementation/Code:** The following is the code for newton()

```
"""Task 1. Newton's Method for Root Finding."""
import numpy as np

# Define Newton's Method
def newton(x1, f, f_prime, tol, max_iter):
    current_iter = 0
    error = 10.0 * tol
    while error > tol and current_iter < max_iter:
        x2 = x1-f(x1)/f_prime(x1)
        error = abs(x2-x1)
        current_iter = current_iter + 1
        x1 = x2
        if current_iter >= max_iter:
            print("This initial guess has reached its maximum number of iterations.")
    return x1


# Define f, f_prime, run function and print results
f = lambda x: x * np.exp(-x)
f_prime = lambda x: np.exp(-x) - x * np.exp(-x)
result = newton(-1, f, f_prime, 0.000001, 100)
print("The root of the function using newton method is: ", result)
```

**Last Modified:** September/2022
