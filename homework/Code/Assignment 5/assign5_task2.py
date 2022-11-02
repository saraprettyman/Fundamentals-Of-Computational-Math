import numpy as np
# This creates the function that produces the analytic results 
def solveAnalyticLogi(t, a, b, P0):
    def create_Solution(a, b, P0):

        C = P0/(b*P0-a) # constant from integral solution

        def solution(t):

            return (C*a*np.exp(a*t))/(b*(C*np.exp(a*t)) - 1)

        return solution

    return(create_Solution(a, b, P0)(t))


# The prints the results to the user for different t, a, b, and P0 values
def printAnalytic(t, a, b, P0):
    results = solveAnalyticLogi(t, a, b, P0)
    print("The first solution of alpha = ", a, ", beta = ", b, ", P0 =  ", P0, " is: \n", round(results, 8), "\n")
    return None 


# This creates the list of x and y values for the derivative
def create_graph_analytic(t, a, b, P0):
    x = 0
    analytic_results = []
    for x in range (t):
        y = solveAnalyticLogi(x, a, b, P0)
        analytic_results.append([x,y])
    return analytic_results


# Show results of three different alpha values
printAnalytic(200, 0.20, 0.0005, 10)
printAnalytic(500, 0.01, 0.0005, 10)
printAnalytic(200, 2.00, 0.0005, 10)

