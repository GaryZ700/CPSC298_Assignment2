/*Gary Zeri
2321569
zeri@chapman.edu
CPSC298-01
Assignment 2
Header file that allows for importing the Menu class for improved and simplifed terminal text manipulation.*/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

//depending on the OS being run, decide on a clear screen command to use
#ifdef _WIN32
	static const string CLR_SCR = "cls";
#else
	static const string CLR_SCR = "clear";
#endif

class Menu{

	private:
		vector<char> componetOrdering;
		vector <string> text;
		struct option {

			string text;
			string identifier;
			void (*action)();
		};
		vector<option> options;
		void resetInput();

	public:
		float parseNumber(string promptText="Please enter a number: ", string errorMessage="Input error! Please enter a number: ", float minRange=numeric_limits<float>::min(), float maxRange=numeric_limits<float>::max());
		void addText(string textToDisplay);
		void addOption(string option, string identifier, void (*action)(void)=0);
		void parseOption(string promptText="\n\nPlease select an option: ", string errorMessage="\n\nPlease try again, that was not a correct option.\n");
		void display();
		bool parseBool(string promptText="Please enter y to confirm, and n to cancel: ", string errorMessage="Please try again, input was not understood.\n", string truth="y", string notTruth="n");
};
