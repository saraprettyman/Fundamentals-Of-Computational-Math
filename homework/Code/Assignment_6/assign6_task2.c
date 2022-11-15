#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f(double x){return powf(1.0-powf(x,2.0), 0.5);}

 
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
    double pi = 4 * trapezoidalApprox(f, 0.0, 1.0, 2000000);
    printf("The estimated approximation of Pi to the 8th decimal place is: %.8f", pi);

    return 0;

}
