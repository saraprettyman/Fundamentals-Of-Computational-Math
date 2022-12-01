#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Initialization of Variables 
double matrix1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
double matrix2[3][3] = {{9.0,8.0,7.0}, {6.0,5.0,4.0}, {3.0,2.0,1.0}};
int m = 3; // Total number of rows
int n = 3; // Total number of columns


// Method
static double **hadamardM(int m, int n, double a[m][n], double b[m][n]){
    double **c;
    c = malloc(sizeof(double*)*m);
    printf("    \n");
    for(int i = 0; i < m; i++) {
        c[i] = malloc(sizeof(double*)*n);
    }

    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    return c;

}


// Implementation Example
int main(){
    double** r1;
    r1 = hadamardM(m, n, matrix1, matrix2);
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            printf("%.2f    ", r1[i][j]);
        }
    printf("\n");
    }
}
