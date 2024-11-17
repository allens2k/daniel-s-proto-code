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


class Blackjack{
public:

void setup();
void setmon(float);
char hitloop();
char wincond();
private:
int dcv=0;
int pcv=0;
int pic1;
int pic2;
vector<string>player;
int d1;
int d2;
vector<string>dealer;
float mon;
float winnings=0;
};




int carddraw();
string cardtype(int c);
int cardtypev(int c);


#include <iostream>
using namespace std;

int main() {

	//introduction
	string name;
		float money;
		cout << "Welcome to the Hands On Casino where we would like to get hands on with you!!" << endl;
		cout<<"What is your name dear customer?"<<endl;
		cin>>name;
		cout<<"Hello "<<name<<". How much money do you want to spend at our fine establishment($1 minimum bet):";
		cin>>money;
		while(money<1){
			cout<<"$1 is required to make a bet. Please input the amount of money you want to spend:";
			cin>>money;
		}
		cout<<"You entered "<<money<<endl;
     Blackjack game;
     game.setmon(money);
     char gameloop1='t';    //change these values to char
     char gameloop2='t';

	 do{

     game.setup();
     do{
     gameloop2=game.hitloop();
     }while(gameloop2=='t');
     game.wincond();

	 }while(gameloop1=='t');

	return 0;
}

char inputval(){

	                                                                            //fyi bug isolation is around here somewhere
	cout<<"do you want to hit?(type t for yes and f for no)"<<endl;
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

char inputvalend(){

	                                                                            //fyi bug isolation is around here somewhere
	cout<<"do you want to play again?(type t for yes and f for no):"<<endl;
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
				char end=inputvalend();
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

void Blackjack::setmon(float b){
	mon=b;
}

void Blackjack::setup(){
	 pic1=carddraw();

	 pic2=carddraw();





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

	 d1=carddraw();

	 d2=carddraw();



	vector<string>dealer;

	cout<<"the dealer has pulled a "<<cardtype(d1)<<endl;

	dcv+=cardtypev(d1);

	dcv+=cardtypev(d2);

	cout<<"the value in the dealer's hand is "<<dcv<<endl; //note will need to delete this for actual game

	dealer.push_back(cardtype(d1));

	dealer.push_back(cardtype(d2));

	carddraw();

	carddraw();

	carddraw();

}

char Blackjack::hitloop(){
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
				return 't';
		}
	else{
		cout<<"lets see what you won"<<endl;
		return 'f';
	}


}



char Blackjack::wincond(){


	if((pcv<=21 && pcv>dcv)|| (pcv==21 && dcv>pcv)){    //won
		cout<<"You just won:"<<mon*29<<" dollars"<<endl;
		float winwin=mon*29;
		winnings+=winwin;
		cout<<"your current winnings are :"<<winnings<<endl;;
		char out1=endgame();
        if(out1=='t'){
        	return 't';
        }

	}
	//tie
	if(pcv==dcv){
		cout<<"tie"<<endl;
		cout<<"your current winnings are :"<<winnings<<endl;
		char out2=endgame();
		 if(out2=='t'){
		        	return 't';
		        }


	}
//lose
	if((dcv<=21 && dcv>pcv)|| (dcv==21 && pcv>dcv)){          //this is not working
		cout<< "you just lost"<< mon*-1<< " dollars"<<endl;
		float lostlost=mon*-1;
		winnings+=lostlost;
		cout<<"your current winnings are :"<<winnings<<endl;
		char out3=endgame();

		 if(out3=='t'){
		        	return 't';
		        }


	}

	else{
		return 'f';
	}

}
