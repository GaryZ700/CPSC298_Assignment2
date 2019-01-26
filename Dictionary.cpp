/*Gary Zeri
2321569
zeri@chapman.edu
CPSC298-01
Assignment 2
Provides implementation of the dictionary class, similar in purpose to the dictionary class of python.*/

#include "Dictionary.h"

//addKeyNum function
//has a void return 
//keyName, string of keyName to add to the dictionary 
//number, float to associate with the keyName
void Dictionary::addKeyNum(string keyName, float number){

	int location;

	//check if dictionary alreadly contains the specified key
	//if yes, then find location of the key, and change the the value to the specifed number
	if(contains(keyName, location)){
		(*(numKeys + location)).value = number;
		return;	
	}

	//append new key and number value 
	append(numKeys, keyName, number, numKeysSize);
} 

/////////////////////////////////////////////////////////////////////////////////

//contains function
//returns a bool to represent whether this dictionary contains the specifed key
//key, string of key name to see if it is contained in this dictionary
bool Dictionary::contains(string key){
	
	//loop over all keys in the key dictionary 
	 for(int i=0; i<numKeysSize; i++){

		//cout << *(numKeys+i) << endl;
		if((*(numKeys+i)).key == key){
			return true;
		}
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////////

//contains function
//returns a bool to represent whether this dictionary contains the specifed key
//key, string of key name to see if it is contained in this dictionary
//index, reference to int where index of location can be passed to, default value is nullptr.
bool Dictionary::contains(string key, int &index){
	
	//loop over all keys in the key dictionary 
	 for(int i=0; i<numKeysSize; i++){

		//cout << *(numKeys+i) << endl;
		if((*(numKeys+i)).key == key){
			index = i;
			return true;
		}
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////////

//error function 
//has a void return 
//errorMessage, string of errorMessage to display to the user
void Dictionary::error(string errorMessage){

	cout << endl << endl << "Dictionary Error: \n";
	cout << "    " << errorMessage << endl;

}

/////////////////////////////////////////////////////////////////////////////////

//append function overload for strings
//*array, is pointer to array for keyValues
//key, string of item to attach to the *array
//value, float value to attach to the *array
//size, reference to integer of size of *array
void Dictionary::append(keyValue *&array, string key, float value, int &size){

	//increment size by one
	size += 1;
	
	//place previous values into a holder
	keyValue *holder = array;
	
	//init new array with new size
	array = new keyValue[size];
	
	//reappend data to the new bigger array
	for(int i=0; i<size-1; ++i){
	
		*(array+i) = *(holder+i);
	}

	//add in new value to the array
	(*(array + size-1)).key = key;
	(*(array + size-1)).value = value;

}

/////////////////////////////////////////////////////////////////////////////////

//append function overload for numbers
//*array, is pointer to array for floats
//item, float of item to attach to the *array
//size, reference to integer of size of array
void Dictionary::append(float *&array, float item, int &size){

	//increment size by one
	size += 1;
	
	//place previous values into a holder
	float *holder = array;
	
	//init new array with new size
	array = new float[size];
	
	//reappend data to the new bigger array
	for(int i=0; i<size-1; ++i){
	
		*(array+i) = *(holder+i);
	}

	//add in new value to the array
	(*(array + size-1)) = item;

}

/////////////////////////////////////////////////////////////////////////////////

//getKeyNum function 
//returns a float specific to the key passed in 
//key, string of key to acess number of
float Dictionary::getNumKey(string key){

	int location=-1;

	//iterate thorugh all keys in the keyNum pointer array
	for(int i=0; i<numKeysSize; ++i){
	
		if( (*(numKeys+i)).key == key)
			location = i;

	}

	//check if key was found,
	//if yes, then return the value associated with the key,
	//if not, then print an error message to the user	
	if(location == -1){
		error(KEY_NOT_FOUND);
		return 0;
	}
	else
		return (*(numKeys + location)).value;

}

/////////////////////////////////////////////////////////////////////////////////

//sortKey function 
//has a void return 
//numeric, bool of whether keys should be treated as numbers not strings for comparison purposes
void Dictionary::sortKey(bool numeric){

	int holderSize = 1;
	keyValue *holder = new keyValue[numKeysSize];
	
	//set first value in holder equal to first value in numKeys
	*holder = *numKeys;
	cout << "test";
	//iterate thorugh all values in numKeys, except for the first value 
	for(int i=1; i<numKeysSize; i++){

		//get key from numKeys
		float key = stof( (*(numKeys+i)).key );

		//loop over all values in the holder arry
		for(int h=0; h<holderSize; h++){
			
			int index = holderSize - h - 1;
			float holderKey = stof((*(holder+index)).key);
			cout << h << " NEW ITERATION OF HOLDER";	

			//check whether holderKey is less than key
			if(holderKey < key){
		
				cout << holderKey << " less than " << key << endl << "\n\n";
				shift(holder, holderSize, index+1, 1);
				
				*(holder+index+1) = *(numKeys+i);

				holderSize += 1;	
				
				break;
			}

			//if loop reaches end of holder, but no holder value is smaller than the currently considered value, then add the current value to the end of the holder array 
			else if(h==holderSize-1){
				
				cout << key  << "@@@@@@@@" << endl << endl;	
				shift(holder, holderSize, 0, 1);
				*(holder) = *(numKeys+i);
				holderSize += 1;
				break;
			}
			cout << h << "!!!!!!!" << endl;	
		}
	}
	
	
	numKeys = holder;

}

/////////////////////////////////////////////////////////////////////////////////

//shift function 
//array, referene to string array pointer
//size, int of array size,
//shiftStart, int index of where to start shifting elements
//shiftAmount, int of how many units to shift the elemetns by 
void Dictionary::shift(keyValue *&array, int size, int startShift, int shiftAmount){

	//loop over all the elements to shift, starting with the last element
	for(int i=0; i<size-startShift; ++i){
		
		*(array+size-i) = *(array+size-1-i);		
	}
}

/////////////////////////////////////////////////////////////////////////////////

//getKeyNumber function 
//return int representing the total number of keys in this dictionary
int Dictionary::getKeyNumber(){

	return numKeysSize;
}

/////////////////////////////////////////////////////////////////////////////////

//getKey function
//returns string of specified key
//index, int that refers to which key to return 
string Dictionary::getKey(int index){

	return (*(numKeys+index)).key;

}
