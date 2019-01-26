/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch4 Ex4
Program to read in length in feet and inches and then converts that length into meters and centimeters*/

#include "Menu.h"
using namespace std;

//declare all constants here
const float METER_IN_FOOT = 0.3048;
const float CENTIMETER_IN_METER = 100;
const float INCHES_IN_FOOT = 12;

//declare all function prototypes here
void readInput(int& feet, float& inches);
void metricConversion(int feet, float inches, int& meters, float& centimeters);
void displayConversion(int meters, float centimeters);

//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	Menu menu;
	menu.addText("Feet and Inch Convertor Jumbotron\n\n");

	int feet, meters;
	float inches, centimeters;

	do{
	
		menu.display();
		
		readInput(feet, inches);
		metricConversion(feet, inches, meters, centimeters);
		displayConversion(meters, centimeters);
	
	}while(menu.parseBool("Would you like to convert another length to the metric system? y/n\n"));	

	return 0;
}

//////////////////////////////////////////////////////////////////

//readInput function 
//has void return 
//feet, reference to int to store feet value 
//inches, reference to float to store inches value
void readInput(int& feet, float& inches){

	Menu menu;
	feet = menu.parseNumber("Please enter the number of feet to convert(MUST BE A WHOLE NUMBER!!): ");
	inches = menu.parseNumber("Please enter the number of inches to convert(Can be a decimal): ");

}

//////////////////////////////////////////////////////////////////

//metricConversion functoin 
//has void return 
//feet, int of feet to convert to meters
//inches, float of inches to convert to centimeters
//meters, reference to int to store meters in 
//centimeters, reference to float to store centimeters in 
void metricConversion(int feet, float inches, int& meters, float& centimeters){

	meters = feet * METER_IN_FOOT;
	centimeters = (inches / INCHES_IN_FOOT) * METER_IN_FOOT * CENTIMETER_IN_METER;

}


//////////////////////////////////////////////////////////////////

//displayConversion function
//meters, int of meters to display to the user
//centimeters, float of centimeters to display to the user
void displayConversion(int meters, float centimeters){

	Menu menu;
	menu.addText("\nYour measurement converted to the metric system is:\n");
	menu.addText("	" + to_string(meters) + " Meters and " + to_string(centimeters) + " centimeters.\n");
	menu.display();

}
