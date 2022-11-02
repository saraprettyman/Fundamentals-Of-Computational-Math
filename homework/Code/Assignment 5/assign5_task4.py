import numpy as np
import math


def function():
    return lambda x: math.exp(-x**2)

a = 0
b = math.pi/4
f = function()

def trapezoid_method(f, a, b, n):
    step = (b-a)/n
    count = 1
    int_sum = (f(a)+f(b))/2

    while count < n:
        int_sum += f(a+count*step)
        count += 1
    results = int_sum*step
    print("The trapezoidal approximation of the equation with", n, "iterations is: ", results)
    return results


# Testing out different n values
trapezoid_method(f, a, b, 2)
trapezoid_method(f, a, b, 4)
trapezoid_method(f, a, b, 8)
trapezoid_method(f, a, b, 16)
