#include <iostream>
#include "ex01-library.h"

using namespace std;

//Exercise 1 (a) Implement this function
cell ** createAndInitBoard(int n){
	cell ** res = new cell*[n];
	for(int i=0; i<n; i++){
		res[i] = new cell[n];
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			res[i][j].color = computeColor(i,j);
			res[i][j].status = emptyC; 

			if(i<3 && res[i][j].color == dark){
				res[i][j].status = blackPiece;
			}

			if(i>n-4 && res[i][j].color == dark){
				res[i][j].status = whitePiece;
			}
		}
	}
	return res;
}

//Exercise 1 (b) Implement this function
cell ** duplicateBoard(cell ** A, int n){
	cell** res = new cell*[n];
	for(int i=0; i<n; i++){
		res[i] = new cell[n];
	}
	for(int i=0; i < n; i++){
		for(int j=0; j<n; j++){
			res[i][j].color = A[i][j].color;
			res[i][j].status = A[i][j].status;
		}
	}
	return res;
}

//Exercise 1 (c) Implement this function
bool moveRight(cell ** A,int n,int r, int c){	
	switch(A[r][c].status){
		case emptyC:
			return false;
		case blackPiece:
			if( c<1 || r>n-2 || A[r+1][c-1].status != emptyC ){
				return false;
			} else {
				A[r][c].status = emptyC;
				A[r+1][c-1].status = blackPiece;
				return true;
			}
		case whitePiece:
			if( c>n-2 || r<1 || A[r-1][c+1].status != emptyC ){
				return false;
			} else {
				A[r][c].status = emptyC;
				A[r-1][c+1].status = whitePiece;
				return true;
			}			
	}
	return false;
}

//Exercise 1 (d) Implement this function
bool moveLeft(cell ** A,int n,int r, int c){
	switch(A[r][c].status){
		case emptyC:
			return false;
		case blackPiece:
			if( c>n-2 || r>n-2 || A[r+1][c+1].status != emptyC ){
				return false;
			} else {
				A[r][c].status = emptyC;
				A[r+1][c+1].status = blackPiece;
				return true;
			}
		case whitePiece:
			if( c<1 || r<1 || A[r-1][c-1].status != emptyC ){
				return false;
			} else {
				A[r][c].status = emptyC;
				A[r-1][c-1].status = whitePiece;
				return true;
			}			
	}
	return false;
}
//Do not modify
cellColor computeColor(int r,int c){
	if((r%2 == 0 && c%2 == 0) || (r%2 != 0 && c%2 != 0)){
		return bright;
	}
	return dark;
}

//Do not modify
void printBoard(cell ** A, int n){
	cout << ' ';
	for(int c=0;c<n;c++){
		cout << c;
	}
	cout << endl;
	for(int r=0;r<n;r++){
		cout << r;
		for(int c=0;c<n;c++){
			//Print ' ' or '#' if empty, or the piece color (W or B)
			switch (A[r][c].status) {
			case emptyC:
				cout << ((A[r][c].color==bright)?' ':'#');
				break;
			case whitePiece:
				cout << "W";
				break;
			case blackPiece:
				cout << "B";
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}
