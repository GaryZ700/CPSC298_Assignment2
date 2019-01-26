/*Gary Zeri
2321569
zeri@chapman.edu
CPSC298-01
Assignment 2
Header file that allows for importing the Dictionary class for Python dictionary like use.*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Dictionary{

	private:

	       	struct keyValue{
			string key;
			float value;
		};
		const string KEY_IN_USE="Key specified is already in use.";
		const string KEY_NOT_FOUND="Key spcefied was not found in the dictionary.";
		int numKeysSize=0;
		void error(string errorMessage);
		void append(float *&array, float item, int &size);
		void shift(keyValue *&array, int size, int startShift, int shiftAmount);
		void append(keyValue *&array, string key, float value, int &size);	
		keyValue *numKeys;
	public:
		void addKeyNum(string key, float number);
		bool contains(string key);
		bool contains(string key, int &index);
		float getNumKey(string key);
		void sortKey(bool numeric=false);
		int getKeyNumber();
		string getKey(int index);
		
};
