"""Tolerable error is usually around 10^(-5). Due to computer error existing, it allows
approximate solutions to be found so the code isn't stuck in a loop. The maximum iterations of
the method is around 25-200 depending on the program need. This exist to stop
an endless loop of searching for a non-existent solutions. a and b are the lower
and upper bound, respectively, of the guessed interval. Begin and end are the bounds of the
interval of guessed solutions."""
import numpy as np


# Define Newton's Method
def newton(x1, f, f_prime, tol, max_iter):
    current_iter = 0
    error = 10.0 * tol
    while error > tol and current_iter < max_iter:
        x2 = x1 - f(x1) / f_prime(x1)
        error = abs(x2 - x1)
        current_iter = current_iter + 1
        x1 = x2
        if current_iter >= max_iter:
            print("This initial guess has reached its maximum number of iterations.")
    return x1


# Define secant function
def secant(x0, x1, f, tol, max_iter):
    current_iter = 0
    error = 10.0 * tol
    while error > tol and current_iter < max_iter:
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0))
        error = abs(x2 - x1)
        current_iter = current_iter + 1
        x0 = x1
        x1 = x2
        if current_iter >= max_iter:
            print("This initial guess has reached its maximum number of iterations.")
    return x1


# Hybrid bisection/secant method
def bisection(f, a, b):
    try:
        return f(a) * f(b) < 0
    except FloatingPointError:
        return False


def sub_intervals(begin, end):
    x0_list = []
    int_guess = begin
    while int_guess < -0.01:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.001
    int_guess = 0.01
    while 0.01 <= int_guess <= end:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.001
    return x0_list


def hybrid_bs(f, a, b, tol, begin, end):
    init_index = 0
    solutions = []
    x0_list = sub_intervals(begin, end)
    while init_index + 1 < len(x0_list):
        if bisection(f, a, b):
            x = secant(a, b, f, tol, 25)
            if x is not None:
                solutions.append(x)
        a = x0_list[init_index]
        b = x0_list[init_index + 1]
        init_index += 1
    if len(solutions) == 0:
        print("There are no solutions in the interval: ",
              "[", x0_list[0], ",", x0_list[len(x0_list) - 1], "]")
    else:
        print("The solutions are: ", np.transpose(solutions))
    return solutions.sort


# Hybrid bisection/newton method
def hybrid_bn(f, f_prime, a, b, tol, begin, end):
    init_index = 0
    solutions = []
    x0_list = sub_intervals(begin, end)
    while init_index + 1 < len(x0_list):
        if bisection(f, a, b):
            x0 = 0.5 * (a + b)
            x = newton(x0, f, f_prime, tol, 25)
            if x is not None:
                solutions.append(x)
        a = x0_list[init_index]
        b = x0_list[init_index + 1]
        init_index += 1
    if len(solutions) == 0:
        print("There are no solutions in the interval: ",
              "[", x0_list[0], ",", x0_list[len(x0_list) - 1], "]")
    else:
        print("The solutions are: ", np.transpose(solutions))
    return solutions.sort
