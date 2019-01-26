/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch3 Ex1
Program that when given liters of gasoline used by a car, and the number of miles driven by the car, will output the number of miles per gallon the car achived.*/

#include "Menu.h"
using namespace std;

//declare all constants here
const float GALLON_IN_LITER = 0.264179;

//declare all function prototypes here
float calculateMPG(float miles, float liters);
void displayMPG(float mpg);

//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	Menu menu;
	menu.addText("MPG Calculator\n(Due to budget cuts, this program only accepts gas quantity in liters.)\n\n");

	do{
	
		menu.display();

		displayMPG( calculateMPG(
			menu.parseNumber("How many miles can your mechanical horse travel(car), with that amount of fuel?\n"),
			menu.parseNumber("How many liters of gas does your mechanical horse(car), take?\n")
		));
	
	}while(menu.parseBool("Would you like to compute another miles per gallon ratio? y/n\n"));	

	return 0;
}

//////////////////////////////////////////////////////////////////

//calculateMPG function 
//returns a float representing miles per gallon
//miles, float of number of miles the car traveled on specified amount of gas
//liters, float of liters of gas a car uses
float calculateMPG(float miles, float liters){

	float gallons = GALLON_IN_LITER * liters;
	return miles / gallons;
}

//////////////////////////////////////////////////////////////////

//displayMPG function
//has void return 
//mpg, float of miles per gallon to display to the user
void displayMPG(float mpg){

	Menu menu;
	menu.addText("\nYour car has " + to_string(mpg) + " miles per the gallon.\n");
	menu.display();
}
