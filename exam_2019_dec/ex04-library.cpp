#include "ex04-library.h"
#include <iostream>

//Do not modify
Piece::~Piece(){}

//Do not modify
void Piece::printPosition(){
	cout << "(" << r << "," << c << ")" << endl;
}

//Exercise 4 (a) implement methods of WhitePiece
WhitePiece::WhitePiece(int r, int c){
	this->r = r;
	this->c = c;
};

string WhitePiece::getColor(){
	return "white";
};

string WhitePiece::printCode(){
	return "W";
};

void WhitePiece::moveRight(){
	this->c++;
	this->r--;
}

void WhitePiece::moveLeft(){
	this->c--;
	this->r--;
}



//Exercise 4 (b) implement methods of BlackPiece
//put your code here

BlackPiece::BlackPiece(int r, int c){
	this->r = r;
	this->c = c;
};

string BlackPiece::getColor(){
	return "black";
};

string BlackPiece::printCode(){
	return "B";
};

void BlackPiece::moveRight(){
	this->c--;
	this->r++;
}

void BlackPiece::moveLeft(){
	this->c++;
	this->r++;
}