#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define num_threads 4


// Initialization of variables
double u[3] = {1.0, 2.0, 5.0}; // this is vector of 3 elements
double v[3] = {2.0, 3.0, 4.0};
int n = 3;


// Methods 
static double* hadvomp(int n, double u[n], double v[n]){
    double* w;
    w = malloc(sizeof(double*)*n);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int count = omp_get_num_threads();
        for(int i = id; i < n; i += count){
            w[i] = u[i]*v[i];
        }        

    #pragma omp barrier
    

    }
    return w;

}


// Implementation Example
int main(){
    double* r1;
    r1 = hadv(n, u, v);
    printf("The resulting vector is: ");
    printf("< ");
    for (int i = 0; i < 3; i++){
        printf ("%.2f ", r1[i]);}
    printf(">\n\n");

}
