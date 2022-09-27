import numpy as np
import math
from tabulate import tabulate

# Initialize result tables columns
global iter_column
global x0_column
global error_column
iter_column = []
x0_column = []
error_column = []


# This is the function from task 1
def f_task1():
    return lambda x: x * math.exp(-x)

# This is the function from task 2
def f_task3():
    return lambda x: 10.14 * math.exp(x ** 2) * math.cos(np.pi / x)

# This is to test if function crosses the x-axis, thus if root exist
def test_if_negative(f, a, b):
    try:
        return f(a) * f(b) < 0
    except FloatingPointError:
        return False

# This determines the more efficient number of iterations to test
def calc_iteration(tol, a, b):
    k = int(((np.log(tol) / np.log(b - a)) / np.log(2))) + 1
    return k

# Create the list of respective x0 guesses for each task
def create_list1():
    x0_list = []
    input_string = input('What is your guess for the lower endpoint of task 1?')
    int_guess = float(input_string)
    input_string = input('What is your guess for the upper endpoint of task 1?')
    upper_guess = float(input_string)
    while int_guess < upper_guess:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.1
    return x0_list

def create_list3():
    x0_list = []
    int_guess = -3.0
    while int_guess < 7:
        x0_list.append(int_guess)
        int_guess = int_guess + 0.1
    return x0_list

# This is the results table
def results(w, y, z):
    col_names = ["iteration", "approximate location of the root",
                 "absolute value of the error in the approximation"]
    a = np.array([w, y, z])
    print(tabulate(np.transpose(a), headers=col_names, tablefmt="presto"))

# This function test bisection of two points a and b in f
def solve(f, a, b, tol):
    if test_if_negative(f, a, b) == True:  # see if previous test is true.
        k = calc_iteration(tol, a, b)
        for i in range(1, k):
            c = 0.5 * (a + b)
            # this creates our columns for our results table
            iter_column.append(i)
            x0_column.append(c)
            error_column.append(abs(b-a))
            if f(a) * f(c) < 0: # Break interval into two
                b = c
                if i == k - 1:
                    return 0.5 * (a + b)
            else:
                a = c
                if i == k - 1:
                    return 0.5 * (a + b)

# This function runs through each iteration of f(x),
# While testing bisection for each iteration. It prints results
def task_output(f, functions_list, task_num):
    x0_list = functions_list
    init_index = 0
    solutions = []
    while init_index < len(x0_list) - 1:
        x = solve(f, x0_list[init_index], x0_list[init_index + 1], tol=0.000000001)
        if x is not None:
            solutions.append(x)
        init_index = init_index + 1
    if len(solutions) == 0:
        print("There are no solutions in the interval: ",
              "[", x0_list[0], ",", x0_list[len(x0_list)-1], "]")

    else:
        print("\n\n\n\n\nThe solutions to task", task_num, " are: ", np.transpose(solutions))

    return results(iter_column, x0_column, error_column)

# This test task one followed by task two
task_output(f_task1(), create_list1(), 1)
task_output(f_task3(), create_list3(), 3)
