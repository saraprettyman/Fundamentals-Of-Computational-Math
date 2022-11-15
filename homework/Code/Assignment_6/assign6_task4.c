#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){return 1.0/x;}

double trapezoidalApprox(double f(double x), double a, double b, int n){
  double x;
  double h;
  double sum = 0;
  h=fabs(b-a)/n;
  for(int i = 1;i < n; i++){
    x = a + i*h;
    sum = sum + f(x);
  }
  double result = (h/2)*(f(a)+f(b)+2*sum);
  return result;
}

int main(){      
    double x0 = 2.5;
    double sum = 0.0;
    while (sum < 1.0){
        x0 +=.000001;
        sum = trapezoidalApprox(f, 1.0, x0, 20000);}
    printf("e is approximately: %f", x0);

    return 0;

}

 
