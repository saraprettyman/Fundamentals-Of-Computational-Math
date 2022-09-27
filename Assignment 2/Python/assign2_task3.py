"""Task 2. Probably Secant Method for Root Finding."""
import math


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


f = lambda x: x * math.exp(-x)
result = secant(-1, 1, f, 0.000001, 100)
print("The root of the function using secant method is: ", result)