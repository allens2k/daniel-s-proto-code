//============================================================================
// Name        : blackjack.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	string name;
	float mon;
	cout << "Welcome to the Hands On Casino where we would like to get hands on with you!!" << endl;
	cout<<"What is your name dear customer?"<<endl;
	cin>>name;
	cout<<"Hello "<<name<<". How much money do you want to spend at our fine establishment($1 minimum bet):";
	cin>>mon;
	while(mon<1){
		cout<<"$1 is required to make a bet. Please input the amount of money you want to spend:";
		cin>>mon;
	}
	cout<<"You entered "<<mon<<endl;
	return 0;



	//test cases: name(for all of them is trump):
	//test case one for money inputed: $24
	//test case two for money inputed: $0.01
	//test case three for money inputed: $-0.01
}
