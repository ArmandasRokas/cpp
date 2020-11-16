#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
void display(double *A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i*n+j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
void reset(double *A, unsigned int n, double x){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i*n+j] = x;
        }
    }
}

// Exercise 1 (c)
// Implement this function
void reduce(double * A, unsigned int n){
    double * copy = new double[n*n];

    for(int i = 0; i < n*n; i++){
        copy[i] = A[i]; 
    }


    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            // Left upper corner
            if(i == 0 && j == 0){
                A[0] = copy[1] + copy[1*n]; 
                continue;
            }
            // Right upper corner
            if(i == 0 && j == n-1){
                A[n-1] = copy[n-2] + copy[n+n-1];
                continue;
            }
            // Left down corner
            if(i == n-1 && j==0){
                A[(n-1)*n] = copy[(n-2)*n] + copy[(n-1)*n+1];
                continue;
            }
            // Right down corner
            if(i == n-1 && j==n-1){
                A[i*n+j] = copy[(n-1)*n+(n-2)] + copy[(n-2)*n+(n-1)] ; 
                continue;
            }
            //  First row
            if(i==0){
                A[j] = copy[j-1] + copy[j+1] + copy[n + j];
                continue;
            }
            // First column
            if(j==0){
                A[i*n] = copy[(i-1)*n] +  copy[(i+1)*n] + copy[i*n+1]; 
                continue;
            }
            // Last column 
            if(j==n-1){
                A[i*n + n-1] = copy[(i-1)*n + n-1] +  copy[(i+1)*n + n-1] + copy[i*n + n-2];
                continue;
            }
            // Last row
            if(i==n-1){
                A[(i*n)+j] = copy[(i*n)+j-1] + copy[(i*n)+j+1] + copy[((i-1)*n)+j];
                continue;
            }
            // All other inside
            A[i*n+j] = copy[i*n+j-1] + A[i*n+j+1] + copy[(i-1)*n+j] + copy[(i+1)*n+j];     
        }
    }

    delete[] copy;
}

// Exercise 1 (d)
// Implement this function
vector<double> sumRows(double * A, unsigned int n){
    
    vector<double> row_sums; 
    
    for(unsigned int i = 0; i < n; i++){
        double curr_row_sum = 0;
        for(unsigned int j = 0; j < n; j++){
            curr_row_sum += A[i*n+j];
        }
        row_sums.push_back(curr_row_sum);
    }

    return row_sums;
    
}

// Exercise 1 (e)
// Implement this function
vector<double> sumCols(double * A, unsigned int n){
    
    vector<double> col_sums; 
    
    for(unsigned int j = 0; j < n; j++){
        double curr_col_sum = 0;
        for(unsigned int i = 0; i < n; i++){
            curr_col_sum += A[i*n+j];
        }
        col_sums.push_back(curr_col_sum);
    }

    return col_sums;
    
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}