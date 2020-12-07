#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c) {
    Complex** res = new Complex*[m];
    for(int i=0; i<m; i++){
        res[i] = new Complex[n];
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            res[i][j] = c;
        }
    }

    return res;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n) {
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< A[i][j].re;
            if(A[i][j].im>=0){
                cout << '+';
            }
            cout << A[i][j].im << "i" ;
            if(j==n-1){
                cout << endl;
            } else {
                cout << ' ';
            }
        }
        
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n) {
    Complex c = {0,0};
    Complex** A = createMatrix(n,n,c);
    Complex d = {1,0};
    for(int i=0; i<n; i++){
        A[i][i] = d;
    }
    return A;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p) {
    for(int i=0; i<m; i++){
        for(int j=0;j<p;j++){
            Complex sum{0,0};

            for(int column_A=0; column_A < n; column_A++){
            //    for(int row_B=0; row_B < n; row_B++){
                  //  sum = add(sum, mult(A[i][column_A],B[row_B][j] ));
                  sum = add(sum, mult(A[i][column_A],B[column_A][j] )); 
              //  }
            }
            C[i][j] = sum; 
        
        }
    }
    /*
    C[0][0] =add(mult(A[0][0],B[0][0]), mult(A[0][1], B[1][0]));
    C[0][1] =add(mult(A[0][0],B[0][1]), mult(A[0][1], B[1][1]));
    C[0][2] =add(mult(A[0][0],B[0][2]), mult(A[0][1], B[1][2]));

    C[1][0] =add(mult(A[1][0],B[0][0]), mult(A[1][1], B[1][0]));
    C[1][1] =add(mult(A[1][0],B[0][1]), mult(A[1][1], B[1][1]));
    C[1][2] =add(mult(A[1][0],B[0][2]), mult(A[1][1], B[1][2]));

    C[2][0] =add(mult(A[2][0],B[0][0]), mult(A[2][1], B[1][0]));
    C[2][1] =add(mult(A[2][0],B[0][1]), mult(A[2][1], B[1][1]));
    C[2][2] =add(mult(A[2][0],B[0][2]), mult(A[2][1], B[1][2]));
    */
}

// Do not modify
Complex add(Complex c, Complex d) {
    Complex result = { c.re + d.re, c.im + d.im };
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d) {
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows) {
    for (unsigned int i = 0; i < nRows; i++) { delete[] A[i]; }
    delete[] A;
}
