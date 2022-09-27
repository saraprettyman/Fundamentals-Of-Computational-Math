# Import Packages
import math


# This is the functional iteration process, and is used to test possible roots
def root_finding(x0, f, c, tol=0.00000001, max_iter=15):
    g = lambda x: x - c(x) * f(x)
    e0 = 100000
    for i in range(1, max_iter):
        print('x0 = ', round(x0, 3), '| g(x0) = ', round(g(x0), 5),
              '| e(x0) = ', round(e(x0, g), 5))
        x1 = g(x0)
        x0 = x1
        e1 = e(x0, g)
        if e1 < tol:
            return x0
        else:
            e0 = e1
    print('This function has gone through its max iteration')


# This is the error function; essentially used to test if g(x)=x hence if x0 is a root
def e(x, g):
    error = abs(g(x) - x)
    return error


# This main function test out different scenarios of c to see if there are any roots
def main(test_number, c):
    print("This is testing scenario", test_number, "where c is ", c)
    solution = root_finding(.5, lambda x: x * math.exp(-x),
                            lambda x: c, tol=0.00000001, max_iter=25)
    if solution is None:
        print("Scenario", test_number, "has failed to find the root.\n")
    else:
        print('The root is', solution, "in scenario", test_number, "\n")


print("The following scenarios show three fixed point function variations with x0 = .5\n")

"""Testing when c=1; testing the scenario of fixed point function g1(x). 
This results in a number close to, but not zero"""
main(1, 1)


"""Testing when c=-1; testing the scenario of fixed point function g2(x). 
This results in no solution"""
main(2, -1)

""" Testing an alternative c;The user of a constant for the iterations was not sufficient.
Given the function has an exponent, 
a c value of an exponent function seemed more adequate for a more efficient solution."""
print("This is testing scenario 3 where c is e^x")
root = root_finding(.5, lambda x: x * math.exp(-x), lambda x: math.exp(x), tol=0.00000001, max_iter=25)
print('The root is', root, "\n")
