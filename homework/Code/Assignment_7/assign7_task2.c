#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Initialization of Variables 
double u[3] = {1.0, 2.0, 5.0}; // this is vector of 3 elements
double v[3] = {2.0, 3.0, 4.0};
int n = 3;


// Method
static double* hadamardV(int n, double u[n], double v[n]){
    double* w;
    w = malloc(sizeof(double*)*n);
    for(int i = 0; i < n; i ++){
            w[i] = u[i]*v[i];
}
    return w;
}


// Implementation Example
int main(){
    double* r1;
    r1 = hadamardV(n, u, v);
    printf("The resulting vector is: ");
    printf("< ");
    for (int i = 0; i < 3; i++){
        printf ("%.2f ", r1[i]);}
    printf(">\n\n");

}
