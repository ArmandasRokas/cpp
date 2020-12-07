#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(int number, string owner, double balance) {
	this->number = number;
	this->owner = owner;
	this->balance = balance;
}

double BankAccount::getBalance() const {
	return balance;
}

int BankAccount::getNumber() const {
	return number;
}

const string BankAccount::getOwner() const {
	return owner;
}

void BankAccount::print() const {
	cout << "Account number " << number << " owned by " << owner << " contains " << balance << endl;
}

bool BankAccount::transferMoney(BankAccount &to, double value) {
	if(value < 0 || balance < value){
		cout << "Transfer failed" << endl;
		return false;
	} else {
		balance -= value;
		to.balance += value;
		cout << "Transfer succeeded" << endl;
		return true;
	}
}

bool BankAccount::wrongTransferMoney(BankAccount to, double value) {
	if(value < 0 ||balance < value){
		cout << "Transfer failed" << endl;
		return false;
	}
	else{
		balance-=value;
		to.balance += value;
		cout << "Transfer succeeded" << endl;
		return true;
	}
}

bool BankAccount::withdraw(double value) {
	if(value < 0 ||balance < value){
		return false;
	} else {
		balance-=value;
		return true;
	}
}

bool BankAccount::deposit(double value) {
	balance += value;
	return true;
}
