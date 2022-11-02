import numpy as np
import math
import matplotlib.pyplot as graph


def function():
    return lambda x: math.exp(-x**2)


def simpsons_method(f, a, b, n):
    # Initialize variables
    f_oddsum = 0
    f_evensum = 0
    # Initialize functions 
    step = (b-a)/n
    int_sum = (f(a)+f(b))/2
    x_i = a + step

    # Simpsons process 
    while x_i + 2*step < b:
        f_oddsum += f(x_i)
        f_evensum += f(x_i+step)
        x_i += 2*step
    results = (step/3)*(f(a)+f(b)+4*f_oddsum+2*f_evensum)
    return results


def create_list():
    step_list = []
    ylist = []

    step = 0.25

    for i in range(8):
        step_list.append(step)
        augment = simpsons_method(f, a, b, np.ceil((np.pi/4)/step))
        ylist.append(augment)
        step /= 2
    return step_list, ylist

def print_results():
    step_list, ylist = create_list()
    xpoints = np.array(step_list)
    ypoints = np.array(ylist) 
    graph.loglog(xpoints, ypoints, 'o')
    graph.show()


def show_simpsons(f, a, b, n):
    result = simpsons_method(f, a, b, n)
    print("The Simpson's approximation of the equation with", n, "iterations is: ", result)


# defining variables
a = 0
b = math.pi/4
f = function()


# Testing out different n values
show_simpsons(f, a, b, 2)
show_simpsons(f, a, b, 4)
show_simpsons(f, a, b, 8)
show_simpsons(f, a, b, 16)

print_results()
