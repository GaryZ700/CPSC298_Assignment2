/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch5 Ex2
Program that takes an array of chars and then deletes any duplicates contained within the array*/

#include <iomanip>
#include "Menu.h"
using namespace std;

//declare all constants here
const int ARRAY_SIZE = 10;

//declare all function prototypes here
void deleteRepeats(char (&array)[ARRAY_SIZE], int& size);
string arrayToString(char array[ARRAY_SIZE], int size);

//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	Menu menu;

	int size = 8;
	char a[ARRAY_SIZE];
	a[0] = 'a';
	a[1] = 'a';
	a[2] = 'b';
	a[3] = 'c';
	a[4] = 'c';
	a[5] = 'b';
	a[6] = 'a';
	a[7] = 'c';

	menu.addText("Original array: " + arrayToString(a, size) + "\n");
	
	deleteRepeats(a, size);	

	menu.addText("Non duplicates array: " + arrayToString(a, size) + "\n\n");
	menu.display();

	return 0;
}

//////////////////////////////////////////////////////////////////

//deleteRepeats function 
//has a void return value
//array, reference to array variable storing char data
//size, reference to int containging the size of the array
void deleteRepeats(char (&array)[10], int& size){

	int sizeModifier = 0;

	//loop over array twice to check for duplicates
	for(int i=0; i<size; ++i){
		
		int counter = 1;
		//check whether current value in the array is a duplicate of another value
		//if yes, then place value from another position in this location
		//if no other location has a new value, then return since the array is already composed of unique elements
		while(array[i] == '\0'){
		
			if(i+counter > size){
				size -= counter-1;
				return;
			}
			
			array[i] = array[i+counter];
			counter += 1;
		}
		for(int j=i+1; j<size; ++j){
		
			//check if current position of array is duplicate to another position on the array
			//if yes, then set duplicate equal to '\0'
			if(array[i] == array[j]){
				array[j] = '\0';
			}
		}
	}
}

//////////////////////////////////////////////////////////////////

//arrayToString function 
//returns a string version of the array
//array, array of chars to print to the screen
//size, int of size of char array
string arrayToString(char array[], int size){

	ostringstream stringArray;
	
	stringArray << array[0];

	for(int i=1; i<size; i++){
	
		stringArray << "," << array[i]; 
	
	}

	return stringArray.str();

}
