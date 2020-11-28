#include <iostream>
#include "ex03-library.h"

//Do not modify
TemperatureScalesConverter::TemperatureScalesConverter() {
	//By default we add a measurement of 0 C which corresponds to 32 F.
	CTemperatures.push_back(0);
	FTemperatures.push_back(32);
}

//Exercise 3 (a) Check and correct this method
void TemperatureScalesConverter::print(){
	cout << CTemperatures.size() <<" Celsius measurements:";
	for(int i = 0; i < CTemperatures.size() - 1; i++){
		cout<< ' ' << CTemperatures[i];
	}
	cout << endl;
	
	cout << FTemperatures.size() <<" Fahrenheit measurements:";
	for(int i = CTemperatures.size() - 1; i > 0; i--){
		cout<< ' ' << CTemperatures[i];
	}
	cout << endl;
}

//Exercise 3 (b) Implement this method
double TemperatureScalesConverter::convertToF(double CTemperature){
	//put your code here
}

//Exercise 3 (c) Implement this method
double TemperatureScalesConverter::convertToC(double FTemperature){
	//put your code here
}

//Exercise 3 (d) Implement this method
bool TemperatureScalesConverter::addMeasurement(string scale, double temperature){
	//put your code here
}