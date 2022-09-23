import math
import numpy as np


def rf_multiple(x0, f, c):
    x0_list = [x0 + .1 * i for i in range(100)]
    x0_list.remove(0)
    return x0_list


# This is the functional iteration process, and is used to test possible roots
def rootfinding(x0, f, c, tol=0.00000001, max_iter=25):
    # Initial variables and functions
    x0_list = rf_multiple(x0, f, c)
    g = lambda x: x - c * f(x)
    e0 = 100000
    list_position = 0
    global x0_solutions
    x0_solutions = []
    max_list_position = len(x0_list)
    # This test the possible x0 values.
    # If the first one fails, it moves onto the next in x0 list
    while max_list_position > list_position + 1:
        x0 = float(x0_list[list_position])
        list_position = list_position + 1
        iter_num = 0
        # This runs through functional iteration
        while iter_num < max_iter:
            if g(x0) > 100000000 or g(x0) < -1000000000 or e(x0, g) > 30:
                if x0 - .05 < 7 and x0 + .05 > -3:
                    x0 = float(x0_list[list_position + 5])
                    return
                break
            iter_num = iter_num + 1
            x1 = g(x0)
            x0 = x1
            e1 = e(x0, g)
            if e1 < tol:
                if x0 > 7 or x0 < -3:  # test if out of desired solution bounds
                    break
                x0_solutions.append(x0)
                break
            else:
                e0 = e1
            if iter == max_iter:
                break


# This is the error function; essentially used to test if g(x)=x hence if x0 is a root
def e(x, g):
    error = abs(g(x) - x)
    return error


def main(x0, f, c, tol=0.00000001, max_iter=25):
    rootfinding(x0, f, c, tol=0.00000001, max_iter=25)
    x0_solutions.sort()
    print("The list of roots for f(x) is as follows:\n", np.transpose(x0_solutions))


# Testing f(x), when x0 value being tested starts at -3
main(-3, lambda x: 10.14 * math.exp(x ** 2) * math.cos(np.pi / x),
     .00000000001, tol=0.00000001, max_iter=15)
