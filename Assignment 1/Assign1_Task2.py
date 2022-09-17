from tabulate import tabulate
import numpy as np
from mpmath import mp  # use this package so that the function doesn't display overflow error

# Initialize result tables columns
global iter_column
global x0_column
global error_column
iter_column = []
x0_column = []
error_column = []


# This is the functional iteration process, and is used to test possible roots
def root_finding(x0, f, c):
    # initial variables, values
    g = lambda x: x - c * f(x)
    tol = mp.power(10, -10000000)
    e0 = 100000
    iter_num = 1
    max_iter = 15
    while iter_num <= max_iter:
        # add values to columns for table
        iter_column.append(iter_num)
        x0_column.append(x0)
        error_column.append(e(x0, g))
        # variables that change during each iteration
        iter_num = iter_num + 1
        x1 = g(x0)
        x0 = x1
        e1 = e(x0, g)
        # how to tell if root is found
        if e1 < tol:
            return x0
        else:
            e0 = e1


# This is the error function; essentially used to test if g(x)=x hence if x0 is a root
def e(x, g):
    error = abs(g(x) - x)
    return error


def rf_additive_list(x0, f, c):
    x0_list = [x0 + .1 * i for i in range(100)]
    for x0 in x0_list:
        root = root_finding(x0, f, c)
        if root is not None:
            return root
    print("This x0 iteration is not the solution")


def results(w, y, z):
    col_names = ["iteration", "approximate location of the root",
                 "absolute value of the error in the approximation"]
    a = np.array([w, y, z])
    print(tabulate(np.transpose(a), headers=col_names, tablefmt="presto"))


def main():
    while True:
        x0 = .5
        root = rf_additive_list(x0, lambda x: x * mp.exp(-x), 1)
        if root is not None:
            print("The root is", root)
            print("The results table is as follows:")
            results(iter_column, x0_column, error_column)
            break


# The main function is testing g1(x), and the value x0=.5
main()
