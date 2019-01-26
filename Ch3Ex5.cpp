/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch3 Ex5
Program to provide fashion advice to the user.*/

#include <cmath>
#include "Menu.h"
using namespace std;

//declare all function prototypes here
float getHatSize(float weight, float height);
float getJacketSize(float weight, float height, int age);
float getWaistSize(float weight, int age);
void displaySizes(float hatSize, float jacketSize, float waistSize);

//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	Menu menu;
	menu.addText("Fashion Diva Deluxe Software\n\n");

	float weight;
	float height;
	int age;

	do{
	
		menu.display();
		
		weight = menu.parseNumber("Kind Sir or Madam, please enter your weight in pounds: ");
		height = menu.parseNumber("Kind Sir or Madam, please enter your height in inches: ");
		age = menu.parseNumber("Kind Sir or Madam, please enter you age: ");

		displaySizes(getHatSize(weight, height), getJacketSize(weight, height, age), getWaistSize(height, age));	

	}while(menu.parseBool("Would you like your virtual fashionista to provide you more sizing advice? y/n\n"));	

	return 0;
}

//////////////////////////////////////////////////////////////////

//getHatSize function 
//returns a float to represent hat size
//weight, float of person's weight in lbs.
//height, float of person's height in inches.
float getHatSize(float weight, float height){
	
	return (weight / height) * 2.9;
}

//////////////////////////////////////////////////////////////////

//getJacketSize function 
//returns float of jacket size
//weight, float of person's weight in lbs.
//height, float of person's height in inches.
//age, int of person's age
float getJacketSize(float weight, float height, int age){
	
	float ageAdjustment=0.0;
	if(age > 30)
		ageAdjustment = (floor( (age - 30) / 10)) * (1/8);

	return ((height * weight ) / 288.0) + ageAdjustment;  
}

//////////////////////////////////////////////////////////////////

//getWaistSize function
//returns float of waist size
//weight, float of person's weight in lbs.
//age, int of person's age
float getWaistSize(float weight, int age){
	
	float ageAdjustment = 0.0;
	if(age > 28)
		ageAdjustment = (floor( (age - 28) / 2) ) * (1/10);

	return (weight / 5.7) + ageAdjustment; 

}

//////////////////////////////////////////////////////////////////

//displaySizes function, has a void return
//hatSize, float of person's hatsize
//jacketSize, float of person's jacketSize
//waistSize, float of person's waistSize
void displaySizes(float hatSize, float jacketSize, float waistSize){

	Menu menu;
	menu.addText("\nHat Size: " + to_string(hatSize) + " in.");
	menu.addText("\nJacket Size: " + to_string(jacketSize) + "in.");
	menu.addText("\nWaist Size: " + to_string(waistSize));
	menu.addText("\n");
	menu.display();

}
