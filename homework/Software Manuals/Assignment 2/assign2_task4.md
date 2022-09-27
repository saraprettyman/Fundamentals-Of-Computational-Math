**Routine Name:** hybrid_bn

**Author:** Sara Prettyman 

**Language:** Python, the IDE I used was PyCharm. 

**Description/Purpose:** This routine will compute the root, x1, of a polynomial, such that the polynomial f(x1)=0. This routine calculates an approximate root, and runs through multiple iterations of itself in order to achieve that root. This method is more stable than newtons method alone, and the bisection combination results in a more efficient root finding process. 

**Input:**  Tolerable error = 0.0000001, f =$10.14 * e^{x^2} * cos(\frac{\pi}{x})$, $f_{prime}=10.14(2e^{x^2}*x*cos(\frac{pi}{x})+\frac{(\pi*sin(\frac{pi}{x})}{x^2*e^{x^2}}$, maximum iterations = 100, a (this is initial lower bound guess of the interval), b (this is the initial upper bound guess of the interval).

**Output:** The output is an approximate solution/guess for the root of the function f, which is denoted as x1. If no root is found in proximity, the function will let the user know the routine has run its maximum number of iterations.

**Usage/Example:**   This routine takes in the 5 input arguments: tolerable error (due to computer error existing, this allows approimate solutions to be found),f, f prime(the derivative of f), b (this is the initial upper bound guess of the interval). The routine uses the function test_if_negative to see if there is a root in the interval, and if so perfroms newtons methods to find an approximation of the root. After root is found or determined not to be there, the next interval is tested by adding 0.001 to a and b, and testing the new interval. For instance, when the guess is x1 = -1 and x2= 1, the output is:

    ```The solutions are:  [-2.00000000e+00 -6.66666667e-01 -4.00000000e-01 -2.85714286e-01
     -2.22222222e-01 -1.81818182e-01 -1.53846154e-01 -1.33333333e-01
     -1.17647059e-01 -1.05263158e-01 -9.52380952e-02 -8.69565217e-02
     -8.00000000e-02 -7.40740741e-02 -6.89655172e-02 -6.45161290e-02
     -6.06060606e-02 -5.71428571e-02 -5.40540541e-02 -5.12820513e-02
     -4.87804878e-02 -4.65116279e-02 -4.44444444e-02 -4.25531915e-02
     -4.08163265e-02 -3.92156863e-02 -3.77358491e-02 -3.63636364e-02
     -3.50877193e-02 -3.38983051e-02 -3.27868852e-02 -3.17460317e-02
     -3.07692308e-02 -3.27868852e-02 -2.73972603e-02 -2.66666667e-02
     -2.35294118e-02 -2.15053763e-02 -1.94174757e-02 -1.55038760e-02
     -1.73913043e-02 -1.65289256e-02 -1.55038760e-02 -1.04712042e-02
      1.04712042e-02  1.55038760e-02  1.65289256e-02  1.73913043e-02
     -7.28066957e-04  1.94174757e-02  2.15053763e-02  2.35294118e-02
      2.66666667e-02  2.73972603e-02  3.27868852e-02  3.07692308e-02
      3.17460317e-02  3.27868852e-02  3.38983051e-02  3.50877193e-02
      3.63636364e-02  3.77358491e-02  3.92156863e-02  4.08163265e-02
      4.25531915e-02  4.44444444e-02  4.65116279e-02  4.87804878e-02
      5.12820513e-02  5.40540541e-02  5.71428571e-02  6.06060606e-02
      6.45161290e-02  6.89655172e-02  7.40740741e-02  8.00000000e-02
      8.69565217e-02  9.52380952e-02  1.05263158e-01  1.17647059e-01
      1.33333333e-01  1.53846154e-01  1.81818182e-01  2.22222222e-01
      2.85714286e-01  4.00000000e-01  6.66666667e-01  2.00000000e+00] ```

**Implementation/Code:** The following is the code for hybrid_bn

```
"""Task 4. Bisection/Newton Method for Root Finding."""
import numpy as np


# BISECTION Method
def test_if_negative(f, a, b):
    try:
        return f(a) * f(b) < 0
    except FloatingPointError:
        return False


# NEWTONS method
def newton(x1, f, f_prime, tol, max_iter):
    current_iter = 0
    error = 10.0 * tol
    while error > tol and current_iter < max_iter:
        x2 = x1 - f(x1) / f_prime(x1)
        error = abs(x2 - x1)
        current_iter += 1
        x1 = x2
    return x1


# Hybrid
def sub_intervals():
    x0_list = []
    int_guess = -3.0
    # To avoid the singularity, the guesses come before -0.01 and after 0.01
    while int_guess < -0.01:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.001
    int_guess = 0.01
    while 0.01 <= int_guess <= 7:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.001
    return x0_list


def hybrid_bn(f, f_prime, a, b, tol):
    init_index = 0
    solutions = []
    while init_index + 1 < len(x0_list):
        if test_if_negative(f, a, b):
            x0 = 0.5*(a+b)
            x = newton(x0, f, f_prime, tol, 25)
            if x is not None:
                solutions.append(x)
        a = x0_list[init_index]
        b = x0_list[init_index+1]
        init_index += 1
    if len(solutions) == 0:
        print("There are no solutions in the interval: ",
              "[", x0_list[0], ",", x0_list[len(x0_list) - 1], "]")
    else:
        print("The solutions are: ", np.transpose(solutions))
    return solutions.sort


# functions/initialization
f = lambda x: 10.14 * np.exp(x ** 2) * np.cos(np.pi / x)
f_prime = lambda x: 10.14 * (2 * np.exp(x ** 2) * x * np.cos(np.pi / x) + (np.pi * np.sin(np.pi / x)) / (x ** 2) * np.exp(x ** 2))
x0_list = sub_intervals()

# main code
hybrid_bn(f, f_prime, x0_list[0], x0_list[1], 0.0000001)

```
