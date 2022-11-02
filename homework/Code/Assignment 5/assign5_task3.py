import numpy as np
from assign4_task5 import solve_logi
from assign5_task1 import eulerImplicit
from assign5_task2 import create_graph_analytic
import matplotlib.pyplot as graph
import matplotlib.patches as mpatches
# When alpha is 0.20 and beta is 0.005 and P0 is 10
def print_results():
    #exclicit method graph function
    results1 = solve_logi(0.20,  0.0005, 0,  10, 0.000001, 0.1, 10000)
    xlist1 = []
    ylist1 = []
    for i in range(len(results1)):
        xlist1.append(results1[i][0])
        ylist1.append(results1[i][1])
    xpoints1 = np.array(xlist1)
    ypoints1 = np.array(ylist1) 
    # implicit method graph function
    results2 = eulerImplicit(0.20, 0.0005, 10, 0, 0.00001, 0.1,  500)
    xlist2 = []
    ylist2 = []
    for i in range(len(results2)):
        xlist2.append(results2[i][0])
        ylist2.append(results2[i][1])
    xpoints2 = np.array(xlist2)
    ypoints2 = np.array(ylist2) 
    # Analytic solution graph from t to h
    results3 = create_graph_analytic(200, 0.20, 0.0005, 10)
    xlist3 = []
    ylist3 = []
    for i in range(len(results3)):
        xlist3.append(results3[i][0])
        ylist3.append(results3[i][1])
    xpoints3 = np.array(xlist3)
    ypoints3 = np.array(ylist3) 

    # Graph implicit, explicit, and analytic solution 
    fig, ax = graph.subplots()
    green_patch = mpatches.Patch(color='green', label='Explict')
    red_patch = mpatches.Patch(color='red', label='Analytic')
    blue_patch = mpatches.Patch(color='blue', label='Implicit')
    graph.legend(handles=[red_patch, blue_patch, green_patch]) 
    graph.title('Comparison of the Solutions ')
    graph.loglog(xpoints1, ypoints1, 'o', color = 'g')
    graph.loglog(xpoints2, ypoints2, 'o', color = 'b')
    graph.loglog(xpoints3, ypoints3, 'o', color = 'r')
    
    graph.show()


print_results()
