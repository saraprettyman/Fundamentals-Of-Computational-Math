import numpy as np


# This is the second derivative
def second_derivative(f, x0, h):
    return (f(x0+h)-2*f(x0)+f(x0-h))/(h**2)


# This is defining the function with input x
def test_function(x):
    n = lambda x: ((x-np.pi/2)*np.tan(x)**2)
    d = lambda x: (x**2+65)
    f = n(x)/d(x)
    return f


# Taking the second derivative of the test function, with different h values
def main(h):
    x0 = np.pi/4
    result = second_derivative(test_function, x0, h)
    print("The second derivative of the test function when h = ", h, " is ", result, "\n")
    return None


main(0.01)
main(0.001)
main(0.0001)
main(0.00001)
main(0.000001)
