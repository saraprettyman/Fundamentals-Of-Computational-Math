from assign4_task2 import second_derivative, test_function
import numpy as np


def line_regression(xlist:list, ylist:list):
    if len(xlist)!=len(ylist):
        print("xlist and ylist are not of matching size, thus slipe and intercept cannot be found.")
        return None
    
    # Let 'a' be the elements of A, the matrix (X'X)
    a00 = len(xlist)
    a10 = 0
    for i in range(a00):
        a10 += xlist[i]
    a11 = 0
    for i in range(a00):
        a11 += xlist[i]*xlist[i]
    
    # 'c_n" represents the nth component of which c is a label for the vector (X'X)
    c0 = 0
    l = len(ylist)
    for i in range(l):
        c0 += ylist[i]
    c1 = 0
    for i in range(l):
        c1 += ylist[i]*xlist[i]

    det_A = (a00*a11)-(a10*a10)

    # elements of matrix A^-1
    ai00 = a11/det_A
    ai10 = (-1)*a10/det_A
    ai11 = a00/det_A

    # elements of vector beta, where b0 is the intercept and b1 is the slope
    b0 = (c0*ai00)+(c1*ai10) 
    b1 = (c0*ai10)+(c1*ai11) 

    return b0, b1

def main():
    #Test method, knowing f(x)=x
    xlist = [1,2,3,4,5,6,7,8,9]
    ylist = [1,2,3,4,5,6,7,8,9]

    b, a = line_regression(xlist, ylist)
    print("The slope is a:", a, " and the intercept is b: ", b)
    

    #going through different h values on the second derivative
    h = 0.00001
    x0 = np.pi/4
    for i in range(5):
        h = h/2
        approx = second_derivative(test_function, x0, h)
        print("h:", h, ", approximation: ", approx)

main()
