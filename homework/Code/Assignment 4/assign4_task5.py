import numpy as np

def logi_generator(a,b):
    def dx(t,p):
        return a*p-b*p*p
    return dx


def solve_logi(a, b, t0, P0, tol, h, maxiters):
    logi = logi_generator(a,b)

    iters = 0
    err = 10*tol

    t1 = t0
    P1 = P0

    listOfPoints = [[t1,P1]]

    while (err>tol and iters<maxiters):
        t2 = t1 + h
        P2 = P1 + h*logi(t1, P1)

        err = np.abs(P1 - P2)

        listOfPoints.append([t2,P2])

        iters += 1 

        t1 = t2 
        P1 = P2

    return listOfPoints


def main(a, b, P0):
    results = solve_logi(a, b, 0, P0, 0.000001, 0.1, 10000)
    result_print = results[len(results)-1][1]
    print("The first solution of alpha = ", a, ", beta = ", b, ", P0 =  ", P0, " is: \n", round(result_print, 8), "\n")
    return None 


main(0.20, 0.0005, 10)
main(0.01, 0.0005, 10)
main(2.00, 0.0005, 10)
