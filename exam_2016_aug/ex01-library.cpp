#include <iostream>
#include <vector>
#include "ex01-library.h"

using namespace std;

// Exercise 1 (a)
// Check and correct if necessary
void display(double * * A, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// Exercise 1 (b)
// Implement this function
void reset(double * * A, unsigned int n, double x){
    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            A[i][j] = x;
        }
    }
}

// Exercise 1 (c)
// Implement this function
vector<double> sumRows(double * * A, unsigned int n){
    vector<double> res;
    for(unsigned int i = 0; i < n; i++){
        double curr_row_sum = 0;
        for(unsigned int j = 0; j < n; j++){
            curr_row_sum += A[i][j];
        }
        res.push_back(curr_row_sum);
    }
    return res;
}

// Exercise 1 (d)
// Implement this function
vector<double> sumCols(double * * A, unsigned int n){
    vector<double> res;
    for(unsigned int j = 0; j < n; j++){
        double curr_col_sum = 0;
        for(unsigned int i = 0; i < n; i++){
            curr_col_sum += A[i][j];
        }
        res.push_back(curr_col_sum);
    }
    return res;
}

// Exercise 1 (e)
// Implement this function
void reduce(double * * A, unsigned int n){

    double * * copy = new double *[n];
    for(unsigned int i = 0; i<n; i++){
        copy[i] = new double[n];
    }

    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            copy[i][j] = A[i][j];
        }
    }



    for(unsigned int i = 0; i < n; i++){
        for(unsigned int j = 0; j < n; j++){
            // Left upper corner
            if(i == 0 && j == 0){
                A[i][j] = copy[0][1] + copy[1][0]; 
                continue;
            }
            // Right upper corner
            if(i == 0 && j == n-1){
                A[i][j] = copy[i][j-1] + copy[i+1][j];
                continue;
            }
            // Left down corner
            if(i == n-1 && j==0){
                A[i][j] = copy[i-1][j] + copy[i][j+1];
                continue;
            }
            // Right down corner
            if(i == n-1 && j==n-1){
                A[i][j] = copy[i][j-1] + copy[i-1][j] ; 
                continue;
            }
            //  First row
            if(i==0){
                A[i][j] = copy[i][j-1] + copy[i][j+1] + copy[i+1][j];
                continue;
            }
            // First column
            if(j==0){
                A[i][j] = copy[i-1][j] +  copy[i+1][j] + copy[i][j+1]; 
                continue;
            }
            // Last column 
            if(j==n-1){
                A[i][j] = copy[i-1][j] +  copy[i+1][j] + copy[i][j-1];
                continue;
            }
            // Last row
            if(i==n-1){
                A[i][j] = copy[i][j-1] + copy[i][j+1] + copy[i-1][j];
                continue;
            }
            // All other inside
            A[i][j] = copy[i][j-1] + copy[i][j+1] + copy[i-1][j] + copy[i+1][j];     
        }
    }

    for(unsigned int i = 0; i<n; i++){
        delete[] copy[i];
    }
    delete[] copy;
}

// Do not modify
void print(vector<double> & v){
    for(unsigned int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}