/*Assignment 5, Vector Properties*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double vect1[3] = {1.0, 2.0, 5.0}; // this is vector of 3 elements
double vect2[3] = {2.0, 3.0, 4.0}; // this is vector <2,3,4>
double vect3[3] = {1.0, 1.0, 1.0};

double matrix1[3][3] = {{1.0,2.0,3.0}, {4.0,5.0,6.0}, {7.0,8.0,9.0}};
double matrix2[3][3] = {{9.0,8.0,7.0}, {6.0,5.0,4.0}, {3.0,2.0,1.0}};


// Vector operations
double * vectAddition(double array1[], double array2[], int size){
    static double results[3];
    for (int i = 0; i < size; i++){
        results[i] = vect1[i] + vect2[i];
    }
        return results;
}

double * vectSubtraction(double array1[], double array2[], int size){
    static double results[3];
    for (int i = 0; i < size; i++){
        results[i] = vect1[i] - vect2[i];
    }
        return results;
}

double * vectScalarMultiply(double array1[], double constant, int size){
    static double results[3];
    for (int i = 0; i < size; i++){
        results[i] = vect1[i] * constant;
    }
    return results;
}

double vectLength(double array1[], int size){
    double funct = 0;
    for (int i = 0; i < size; i++){
        funct = array1[i] * array1[i] + funct;
    }
    double sol = sqrt(funct);
    return sol;
}

double vectDotProduct(double array1[], double array2[], int size){
    double funct;
    for (int i = 0; i < size; i++){
        funct = vect1[i] * vect2[i] + funct;
    }
    return funct;
}

double vectCrossProduct(double array1[], double array2[]){
    return array1[0] * array2[1] - array1[1] * array2[0];
}

double vectTriProduct(double array1[], double array2[], double array3[]){
    // Creating matrix
    double matrix[3][3];
    matrix[0][0] = array1[0];
    matrix[0][1] = array1[1];
    matrix[0][2] = array1[2];
    matrix[1][0] = array2[0];
    matrix[1][1] = array2[1];
    matrix[1][2] = array2[2];
    matrix[2][0] = array3[0];
    matrix[2][1] = array3[1];
    matrix[2][2] = array3[2];
    // Do indiviual cross product calculations
    double x1 = matrix[0][0]*(matrix[1][1]*(matrix[2][2])-matrix[2][1]*(matrix[1][2]));
    double x2 = matrix[0][1]*(matrix[1][0]*(matrix[2][2])-matrix[2][0]*(matrix[1][2]));
    double x3 = matrix[0][2]*(matrix[1][0]*(matrix[2][1])-matrix[2][0]*(matrix[1][1]));
    double result = x1 - x2 + x3;
    return result;
}

// Matrix operations
double **sumOfTwoMatrices(double matrix4[][3], double matrix5[][3]){
    double **matrix3;
    matrix3 = malloc(sizeof(double*)*3);
    printf("    \n");


    for(int i = 0; i < 3; i++) {
        matrix3[i] = malloc(sizeof(double*)*3);
    }

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
        matrix3[i][j] = matrix4[i][j] + matrix5[i][j];
    }
    }
    return matrix3;
}

double **diffTwoMatrices(double matrix4[][3], double matrix5[][3]){ //note that this is matrix5-matrix4
    double **matrix3;
    matrix3 = malloc(sizeof(double*)*3);
    printf("    \n");


    for(int i = 0; i < 3; i++) {
        matrix3[i] = malloc(sizeof(double*)*3);
    }

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
        matrix3[i][j] = matrix5[i][j] - matrix4[i][j];
    }
    }
    return matrix3;
}

double **produceTwoMatrices(double matrix4[][3], double matrix5[][3]){ //note that this is matrix5-matrix4
    double **matrix3;
    matrix3 = malloc(sizeof(double*)*3);
    printf("    \n");


    for (int i = 0; i < 3; i++) {
        matrix3[i] = malloc(sizeof(double*)*3);
    }

    int n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matrix3[i][j] += matrix4[i][k] * matrix5[k][j];
            }
        }
    }
    return matrix3;
}



int main(){
    // Declaring variables
    int i;
    double *r1;
    double *r2;
    double *r3;
    double r4;
    double r5;
    double r6;
    double r7;
    double **r8;
    double **r9;
    double **r10;

    // Defining variables
    r1 = vectAddition(vect1, vect2, 3);
    r2 = vectSubtraction(vect1, vect2, 3);
    r3 = vectScalarMultiply(vect1, 4, 3);
    r4 = vectLength(vect1, 3);
    r5 = vectDotProduct(vect1, vect2, 3);
    r6 = vectCrossProduct(vect1, vect2);
    r7 = vectTriProduct(vect1, vect2, vect3);
    r8 = sumOfTwoMatrices(matrix1, matrix2);
    r9 = diffTwoMatrices(matrix1,matrix2);
    r10 = produceTwoMatrices(matrix1,matrix2);
    
    // Show original matrices
    printf("Matrix1 is:\n");
    for (int i=0; i < 3; i++)
                {
                    for(int j=0; j < 3; j++)
                    {
                        printf("%.2f    ", matrix1[i][j]);
                    }
                    printf("\n");
                }
    printf("Matrix2 is:\n");
    for (int i=0; i < 3; i++)
                {
                    for(int j=0; j < 3; j++)
                    {
                        printf("%.2f    ", matrix2[i][j]);
                    }
                    printf("\n");
                }
    printf("Vector1 is: ");
    printf("< ");
    for (i = 0; i < 3; i++){
        printf ("%.2f ", vect1[i]);}
    printf(">\n\n");


    printf("Vector2 is: ");
    printf("< ");
    for (i = 0; i < 3; i++){
        printf ("%.2f ", vect2[i]);}
    printf(">\n\n");

    printf("Vector3 is: ");
    printf("< ");
    for (i = 0; i < 3; i++){
        printf ("%.2f ", vect3[i]);}
    printf(">\n\n");


    // Show results of addition vectors
    printf("The addition of vector1 and vector2 is: ");
    printf("< ");
    for (i = 0; i < 3; i++)
        printf ("%.2f ", r1[i]);
    printf(">\n\n");

    // Show results of subtraction vectors
    printf("The subtraction of vector2 from vector1 is: ");
    printf("< ");
    for (i = 0; i < 3; i++)
        printf ("%.2f ", r2[i]);
    printf(">\n\n");

    // Show results of Scalar Multiply method
    printf("The scalar multiplication of vector1 and vector2 is: ");
    printf("< ");
    for (i = 0; i < 3; i++)
        printf ("%.2f ", r3[i]);
    printf(">\n\n");

    // Show results of Vector Length/ vector norm method
    printf("The vector length of vector1 is: %.3f\n\n", r4);

    // Show results of vector dot product method
    printf("The vector dot product of vector1 and vector2 is: %.3f\n\n", r5);
    
    // Show results of the cross product method
    printf("The cross product of vector vector1 and vector2 is: %.3f\n\n", r6);

    // Show results of the vector tri product
    printf("The vector tri product of vector1 and vector2 and vector3 is: %.3f\n", r7);

    // Show results of sum of two matrics 
    printf("\nThe sum of matrix one and matrix two is: \n");
    for (int i=0; i < 3; i++)
            {
                for(int j=0; j < 3; j++)
                {
                    printf("%.2f    ", r8[i][j]);
                }
                printf("\n");
            }
    
    // Show results of the difference of two matrics 
    printf("\nThe difference of matrix one and matrix two is: \n");
    for (int i=0; i < 3; i++)
            {
                for(int j=0; j < 3; j++)
                {
                    printf("%.2f    ", r9[i][j]);
                }
                printf("\n");
            }
    
      // Show results of the product of two matrics 
        printf("\nThe product of matrix one and matrix two is: \n");
        for (int i=0; i < 3; i++)
                {
                    for(int j=0; j < 3; j++)
                    {
                        printf("%.2f    ", r10[i][j]);
                    }
                    printf("\n");
                }
     

}
