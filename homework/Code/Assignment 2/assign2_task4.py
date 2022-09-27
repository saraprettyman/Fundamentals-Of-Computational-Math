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
