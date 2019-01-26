/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch4 Ex2
Program that computes the area of an arbitrary triangle.*/

#include <cmath>
#include "Menu.h"
using namespace std;

//declare all constant strings here
const string NOT_A_TRIANGLE = "Please enter your sides again, the last three sides did not make up a valid triangle.\n\n";
const string STANDARD_MESSAGE = "Arbitray Triangle Area Calculator Pro\n\n";

//declare all function prototypes here
void computeTriangleStats(float a, float b, float c, float& area, float& perimeter);
void displayTriangleStats(float area, float perimeter);
bool isTriangle(float a, float b, float c);

//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	bool loop = true;	
	float a, b, c, area, perimeter;
	string message = STANDARD_MESSAGE;

	do{

		Menu menu;

		menu.addText(message);
		menu.display();
				
		a = menu.parseNumber("\nPlease enter the length of side a: ");
		b = menu.parseNumber("\nPlease enter the length of side b: ");
		c = menu.parseNumber("\nPlease enter the length of side c: ");

		//check if triangle is a valid triangle,
		//if yes, continue with computation, 
		//if not, inform the user of their error
		if(isTriangle(a,b,c)){

			computeTriangleStats(a, b, c, area, perimeter);
			displayTriangleStats(area, perimeter);

			loop = menu.parseBool("\nWould you like to compute the area and perimeter for another triangle? y/n\n");
			message = STANDARD_MESSAGE;
		}
		else
			message = NOT_A_TRIANGLE;

	
	}while(loop);	

	return 0;
}

//////////////////////////////////////////////////////////////////

//computeTriangleStats function
//has no return value 
//a, float of triangle side a
//b, float of triangle side b
//c, float of triangle side c
//area, reference to float to store area of triangle
//perimeter, reference to float to store permieter of triangle
void computeTriangleStats(float a, float b, float c, float& area, float& perimeter){

	perimeter = a + b + c;

	float semiPerimeter = perimeter/2;
	float aTerm = semiPerimeter - a;
	float bTerm = semiPerimeter - b;
	float cTerm = semiPerimeter - c;

	area = sqrt(semiPerimeter * aTerm * bTerm * cTerm);
}

//////////////////////////////////////////////////////////////////

//displayTriangleStats function
//has void return value
//area, float of triangle area
//perimeter, float of tirangle permimeter
void displayTriangleStats(float area, float perimeter){

	Menu menu;
	menu.addText("\nTriangle Area: " + to_string(area));
	menu.addText("\nTriangle Perimeter: " + to_string(perimeter));
	menu.addText("\n");
	menu.display();
}

//////////////////////////////////////////////////////////////////

//isTriangle functiecifying whether or not the side lengths form a triangle
//returns a bool spcifying whether values for a, b, and c form a triangle or not 
//a, float of triangle side a
//b, float of triangle side b
//c, float of triangle side c
bool isTriangle(float a, float b, float c){
	if(a+b>c && a+c>b && b+c>a)
		return true;
	else
		return false;
}
