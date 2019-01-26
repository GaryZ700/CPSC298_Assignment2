/*Gary Zeri
2321569
zeri@chapman.edu
CPSC298-01
Assignment 2
Header file that allows for importing the Menu class for improved and simplifed terminal text manipulation.*/

#include "Menu.h"

//display function
//has no return value
//displays the menu on the screen
void Menu::display(){

	//clear the screen
//	system(CLR_SCR.c_str());
	
	int textCounter = 0;
	int optionCounter = 0;
	
	//set decimal ponts to two points only
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	//loop over all the componets in the menu
	//and then depending on the componet type, display it on the screen
	for(int i=0; i < componetOrdering.size(); ++i){
	
		if(componetOrdering[i] == 't'){
			cout << text[textCounter];	
			textCounter += 1;
		}
		else{
			cout << options[optionCounter].text;
			optionCounter += 1;
		}
	
	}

}

//-------------------------------------------------------------------

/*addText Function
 * void return
 * text, takes string of text to display at current position in the menu*/
void Menu::addText(string textToDisplay){	

	text.push_back(textToDisplay);	

	//add char to componet ordering to signify that the next componet to display on the screen is a text componet
	componetOrdering.push_back('t');

}

//-------------------------------------------------------------------

/*addOption function
 * void return 
 * optionText, string that represents text to display for the option at this current point
 * identifier, string that represents keyword or text that user must input to select this option*/
void Menu::addOption(string optionText, string identifier, void (*action)(void)){

	//declare and initialize a new option struct
	option structData = {optionText.append("\n"), identifier, action};
	options.push_back(structData);
	
	componetOrdering.push_back('o');
}

//-------------------------------------------------------------------

//parse option function, get input from user based on option identifiers
//has a void return value
//promptText, string to ask user for option, default value is provided
//errorMessage, string that should be displayed if user does not provide the correct input
void Menu::parseOption(string promptText, string errorMessage){

	//prompt user for input and parse it
	string userInput;
	cout << promptText;	
	getline(cin, userInput);
	
	while(true){	

		//iterate through all possible valid input options, and execute coressponding action fucntion if identifiers match
		//if identifiers do not match, then print the error message and try again
		for(int i=0; i < options.size(); ++i){
			
			//check if input matches identifier, then execute an action
			if(options[i].identifier == userInput){
				options[i].action();
				return;
			}
		}

		//if none of the inputs matched the option identifiers, then inform the user of their bad input
		cout << "\n" << errorMessage;
		getline(cin, userInput);
	
	}	
}

//-------------------------------------------------------------------

//parseNumber function
//returns a float that the user inputs
//promptText is string of text to display to user before parsing number, default value is "Please enter a number: "
//errorMessage, is string of text to display if user enters incorrect input, default is, "Input Error! Please enter a number: "
//minRange, float of minmum number that can be accepted as input, default value is the smallest float the system will allow
//maxRange, float of maximum number that can be accepted as input, default value is the largest float the system will allow
float Menu::parseNumber(string promptText, string errorMessage, float minRange, float maxRange){

	float input;
	bool loop = true;
	
	//prompt user for input, and parse it
	cout << "\n" << promptText;

	//performs error checking

	do{
		cin >> input;

		//ensure input is numeric
		while(cin.fail()){

			resetInput();
			cout << errorMessage;
			cin >> input;	
		}

		//ensure input is within boundry conditions
		if(input > maxRange)
			cout << "Warning! Input is greater than " << maxRange << ",  please enter a smaller number.\n";
		else if(input < minRange) 
			cout << "Warning! Input is less than " << minRange << ", please enter a larger number.\n";
		else 
			loop = false;

	}while(loop);

	resetInput();

	return input;

}

//------------------------------------------------------------------

//parseBool function
//returns a bool
//promptText, string to provide to print to user
//errorMessage, string to provide to user if wrong input is given
//truth, string to compare for a return of true
//notTruth, string to compare for a return of false
bool Menu::parseBool(string promptText, string errorMessage, string truth, string notTruth){

	string input;

	cout << "\n" << promptText;
	cin >> input;
			
	//performs error checking
	while(cin.fail() || (input!=truth && input!=notTruth)){
		
		resetInput();	
		cout << errorMessage;
		cin >> input;	
	}

	resetInput();

	if(input == truth)
		return true;
	else 
		return false;

}

//----------------------------------------------------------------

//resetInput function 
//has void return 
void Menu::resetInput(){

	cin.clear();
	cin.ignore(10000, '\n');

}
