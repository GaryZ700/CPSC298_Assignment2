/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch4 Ex11
Program that simulates a game show a set number of times and then prints how many times the user has won the grand prize.*/

#include <cstdlib>
#include <ctime>
#include "Menu.h"
using namespace std;

//declare all constants here
const int NUMBER_OF_GAMES = 10000;

//declare all function prototypes here
void getChances(bool (&doors)[4], int& choice);


//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	Menu menu;
	bool doors[4];
	int choice, results=0;
	
	//set random seed for random number generator
	srand(time(NULL));
	
	for(int i=0; i<NUMBER_OF_GAMES; ++i){
			
		getChances(doors, choice);

		if(doors[choice])
			results += 1;
	}

	menu.addText("That One Game Show!\nThe Home PC Edition\n\n");
	menu.addText("The contestant would have won by sticking to his first choice a total of " + to_string(results) + " times.\n");
	menu.addText("This means the contestant would have won dishsoap a total of " + to_string(NUMBER_OF_GAMES - results) + " times.\n");
	menu.display();

	return 0;
}

//////////////////////////////////////////////////////////////////

//getChances function
//has a void return value 
//doors, bool array of length four, will store the either true or false for whether each door will contain the money or the dish soap. The 4th random bool represents whether the new door option will contain the money or the soap.
void getChances(bool (&doors)[4], int& choice){
	
	int moneyLocation = rand() % 3 + 1;	
	
	for(int i=0; i<4; ++i){
		
		if(i==moneyLocation)
			doors[i] = true;
		else
			doors[i] = false;
	
	}

	if(moneyLocation % 2 == 0)
		doors[3] = true;
	else 
		doors[3] = false;

	choice = rand() % 3;

}
