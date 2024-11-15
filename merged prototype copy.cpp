//============================================================================
// Name        : merged.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

int carddraw();
int game(float mon);
string cardtype(int c);
int cardtypev(int c);

//have random number vector with size 25
//loop with random number generator
//pass random number vector stuff into the card vector --this may be a bad idea how would draw work
#include <iostream>
using namespace std;

int main() {

	//introduction
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


   // cout<<carddraw();
   // int c=carddraw(); either use scrand everytime a card is called or tweak new random number generator
int gametrack=1;
   // cout<<cardtype(c);

do{
	gametrack=game(mon);



}while(gametrack==1);
	return 0;
}

char inputval(){
	cout<<"do you want to hit?(type t for yes and f for no)"<<endl;
	                                                                            //fyi bug isolation is around here somewhere

		char in;
		cin>>in;
		while(in!='t' && in!='f'){
			cout<<"you didn't type t or f. If you want to hit, type t. If you do not, type f"<<endl;
			cin>>in;
		}
	if(in=='t'){
		return 't';
	}
	else{
		return 'f';
	}
}

char endgame(){
	cout<<"do you want to play again?(type t for yes and f for no):"<<endl;
				char end=inputval();
				if(end=='t'){
	             return 't';
				}
				else{
				cout<<"exiting game";
				exit(0);
				}
}

int carddraw(){

	 vector<int>cd(3);


	//deck of cards
		random_device rng;

			mt19937 gen(rng());

			uniform_int_distribution<>deck(1,13);
	         //cout<<"the elements of the vector are"<<endl;
			//for(int i=0; i<cd.size(); i++){
				//int random=dis(gen);
			//	cd[i]=deck(gen);
				//a[i]=random;

				//cout<<cd[i]<<endl;
		//	}

	int card;

	 //card=cd[cd.size()-1];

     card=deck(gen);
	//cout<<"the card drawn is"<<card<<endl;

	return card;
}



string cardtype(int c){
	switch(c){
	case 1:
		return "Ace";
		break;
	case 2:
		return "2";
		break;
	case 3:
		return "3";
		break;
	case 4:
		return "4";
		break;
	case 5:
		return "5";
		break;
	case 6:
		return "6";
		break;
	case 7:
		return "7";
		break;
	case 8:
		return "8";
		break;
	case 9:
		return "9";
		break;
	case 10:
		return "10";
		break;
	case 11:
		return "King";
		break;

	case 12:
		return "Queen";
		break;

	case 13:
		return "Jack";
		break;

	default:
		return "no such card present";
	}
}


int cardtypev(int c){


	switch(c){
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;

	case 4:
		return 4;
		break;

	case 5:
		return 5;
		break;

	case 6:
		return 6;
		break;

	case 7:
		return 7;
		break;

	case 8:
		return 8;
		break;

	case 9:
		return 9;
		break;

	case 10:
		return 10;
		break;

	case 11:
		return 10;
		break;

	case 12:
		return 10;
		break;

	case 13:
		return 10;
		break;

	}


	return 0;
}

int game(float mon){
	float m=mon;


//brainstorm section:
//use of vector to store values of drawn cards
//reveals hidden card once player done hitting
//need borlean value for cardgame playing in motion
//need borlean value for hitting and standing

	//deck of cards


carddraw();

carddraw();

carddraw();

	//player:
//do-while loop for the player.
bool playmotion=true;
do{


	//player card hand at start:
	int pic1=carddraw();

	int pic2=carddraw();

	int pcv=0;

	vector<string>player;

	//cout<<"the first card is"<<pic1<<"the second one is"<<pic2;

	cout<<"you have a "<<cardtype(pic1)<<" and a "<<cardtype(pic2)<<" in your hand."<<endl;

	pcv+=cardtypev(pic1);

	pcv+=cardtypev(pic2);

	cout<<"the value in you hand is "<<pcv<<endl;

	player.push_back(cardtype(pic1));

	player.push_back(cardtype(pic2));

	cout<<"the cards currently in your hand are"<<endl;
	for(int i=0; i<player.size(); i++){
		cout<<player[i]<<endl;
	}

	//dealer card intro:

	int d1=carddraw();

	int d2=carddraw();

	int dcv=0;

	vector<string>dealer;

	cout<<"the dealer has pulled a "<<cardtype(d1)<<endl;

	dcv+=cardtypev(d1);

	dcv+=cardtypev(d2);

	cout<<"the value in the dealer's hand is "<<dcv<<endl; //note will need to delete this for actual game

	dealer.push_back(cardtype(d1));

	dealer.push_back(cardtype(d2));


	bool hit=true;
	while(hit==true){                                                     //lets try to build user input
    char in=inputval();

	if(in=='t'){
		int input=carddraw();
		pcv+=cardtypev(input);

		player.push_back(cardtype(input));

		cout<<"the cards currently in your hand are"<<endl;
			for(int i=0; i<player.size(); i++){
				cout<<player[i]<<endl;
			}
			cout<<"the value in you hand is "<<pcv<<endl;

		//use rule that dealer hits until they reach a combined card value of 17:
			if(dcv<17){
				int din=carddraw();
				dcv+=cardtypev(din);
				dealer.push_back(cardtype(din));
				cout<<"the value in the dealer's hand is(before reach 17): "<<dcv<<endl;
			}
			cout<<"the value in the dealer's hand is "<<dcv<<endl;

	}
	else{

		break;
		 hit=false;


	}

	}
	//hitsection end here
	cout<<"hello am at end";
	cout<<"the value of pcv is"<<pcv;//i am not reaching the win condition
	if((pcv<=21 && pcv>dcv)|| (pcv==21 && dcv>pcv)){    //won
		cout<<"You just won:"<<m*29<<" dollars"<<endl;
		char out=endgame();
		if(out=='t'){
			continue;
		}
	}
	//tie
	if(pcv==dcv){
		cout<<"tie";
		char out=endgame();
		if(out=='t'){
		continue;
				}


	}
//lose
	if((dcv<=21 && dcv>pcv)|| (dcv==21 && pcv>dcv)){          //this is not working
		cout<< "you just lost"<< m*-1<< " dollars"<<endl;
		char out=endgame();
				if(out=='t'){
				continue;
						}

	}

	//cout<<"do you want to play again?(type y for yes and n for no):"<<endl;
	//char end;
	//	cin>>end;
	//	while(end!='y' && end!='f'){
	//		cout<<"you didn't type y or f. If you want to play again, type t. If you do not, type f"<<endl;
	//		cin>>end;
	//	}
	//if(end=='t'){

	//}
	//else{
	//playmotion=false;
	//exit(0);
	//}
}while(playmotion==true);

	//if win:
return 0;
}
