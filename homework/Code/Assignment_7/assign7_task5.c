#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Initialization of Variables
double u[3] = {1.0, 2.0, 5.0}; // this is vector of 3 elements
double v[3] = {2.0, 3.0, 4.0};
int m = 3;
int n = 3;


// Methods
static double **outv(int m, int n, double a[m], double b[n]){
    double **c;
    c = malloc(sizeof(double*)*m);

    printf("    \n");

    for(int i = 0; i < m; i++) {
        c[i] = malloc(sizeof(double*)*n);
    }

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i] * b[j];
        }
    }

    return c;

}


// Implementation Example
int main(){
    double** r1;
    r1 = outv(m, n, u, v);
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            printf("%.2f    ", r1[i][j]);
        }
    printf("\n");
    }
}
