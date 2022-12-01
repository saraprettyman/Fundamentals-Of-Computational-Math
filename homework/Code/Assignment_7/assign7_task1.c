#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>


#define NUM_THREADS 4


// Initalization of example variables
double a[3][3] = {{2.0,2.0,2.0},{3.0,3.0,3.0},{4.0,4.0,4.0}};
double b[3][2] = {{1.0,1.0},{2.0,2.0},{3.0,3.0}};
int m = 3; // m is the both matrices row totals
int n = 3; // n is the first matrix columns
int p = 2; // p is the second matrix columns

// Methods 
static double dotProduct(int n, double a[n], double b[n]){
    double c;
    c = 0;
    for (int i=0; i < n; i++){
        c += a[i] * b[i];
    }
    return c;
}

static double** prodmOMP(int m, int n, int p, double a[m][n], double b[n][p]){
    double **c;
    c = malloc(sizeof(double*)*m);
    printf("    \n");

     for(int i = 0; i < m; i++){
        c[i] = malloc(sizeof(double*)*p);
    }
    
    omp_set_num_threads(NUM_THREADS);

    for (int i = 0; i < m; i++) {
        #pragma omp parallel
        {

            int id = omp_get_thread_num();
            int count = omp_get_num_threads();
        
        for (int j = id; j < p; j+=count) {
            double tempb[n];
            for(int t = 0; t < n; t++){tempb[t] = b[t][j]; }
                c[i][j] = dotProduct(n, a[i], tempb);

            }

          }

        #pragma omp barrier

      }

    return c;

}


// Implementation example
int main(){  
    double** r1;
    r1 = prodmOMP(m, n, p, a, b);
    printf("The matrix multiplication result is:\n");
    for(int i=0; i < 2; i++){
        for(int j=0; j < 2; j++){
            printf("%.2f    ", r1[i][j]);
        }
    printf("\n");
    }
}
