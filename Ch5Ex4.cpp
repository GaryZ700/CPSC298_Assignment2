/*Gary Zeri
ID:2321569
zeri@chapman.edu
CPSC298-01
Assignment 2, Ch5 Ex4
Program to read in integer values for an array and then print the array values in a column with number of occurances of each number in the array.*/

#include <iomanip>
#include "Menu.h"
#include "Dictionary.h"

using namespace std;

//declare all function prototypes here
void displayUniqueIntegers(Dictionary dict);

//////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

	Dictionary dict;

	Menu menu;
	menu.addText("Integer Counter & Sorter");
	menu.display();

	int data[50];
	int dataSize = menu.parseNumber("How many numbers would you like to add to this dataset?\nMax is 50.\n", "Input was not a number, try again.",1,50);

	//loop to construct data set from the user
	for(int i=0; i<dataSize; ++i){
		
		int count;		
		//get string of number from user
		string integer = to_string(menu.parseNumber("\n\n" + to_string(dataSize - i) + " Numbers left to add.\nPlease enter a numbe to add: "));	

		//check whether dictionary alreadly contains the data
		//if yes, then add increment numKey count by one
		//else set numKey count to 1
		if(dict.contains(integer))
			count = dict.getNumKey(integer) + 1;
		else	
			count = 1;

		//add integer and count to the dict
		dict.addKeyNum(integer, count);
	}

	dict.sortKey(true);
	displayUniqueIntegers(dict);

	return 0;
}

//////////////////////////////////////////////////////////////////

//displayUniqueIntegers function
//has void return value 
//dict, dictionary containing sorted data to display to the user
void displayUniqueIntegers(Dictionary dict){

	Menu menu;
	menu.addText("Result from Interger Analysis:\n\n");
	menu.addText("Number		Count\n");

	//loop over all unique integers
	for(int i=0; i<dict.getKeyNumber(); i++){

		string key = dict.getKey(dict.getKeyNumber()-i-1);	
	
		menu.addText(key + "		" + to_string(dict.getNumKey(key))  + "\n");
	}

	menu.display();
}
