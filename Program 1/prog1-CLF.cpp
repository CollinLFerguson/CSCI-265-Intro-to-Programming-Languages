/*
 Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 1 | written in C++ | working with: Basic input, mathematic operators, basic output
*/

#include <iostream>
#include <string> //Used for getLine()
using namespace std;

void partOne()
//Takes integer input from user, then converts and then prints: hours, minutes, and the remainder.
{
	int intTimeHours = 0;
	int intTimeMinutes = 0;
	int intTotalTime = 0;

	cout << "Enter an integer value of seconds: ";

	cin >> intTotalTime;

	intTimeHours = intTotalTime / 3600;
	intTotalTime = intTotalTime % 3600;

	intTimeMinutes = intTotalTime / 60;
	intTotalTime = intTotalTime % 60;

	cout << "This is " << intTimeHours << " hours, "<<intTimeMinutes<<" minutes, " << intTotalTime<< " seconds\n";//, intTimeMinutes, intTotalTime;

}


void partTwo()
//Asks user for four integer inputs, prints the sum in dollars.
{
	int intQuarters = 0;
	int intDimes = 0;
	int intNickles = 0;
	int intPennies = 0;

	cout << "Enter the number of Quarters: ";
	cin >> intQuarters;
	cout << "Enter the number of Dimes: ";
	cin >> intDimes;
	cout << "Enter the number of Nickles: ";
	cin >> intNickles;
	cout << "Enter the number of Pennies: ";
	cin >> intPennies;

	float fltTotals = ((intQuarters * 25) + (intDimes * 10) + (intNickles * 5) + intPennies);

	fltTotals = fltTotals / 100;

	printf("This is equal to: $%1.2f\n", fltTotals); // Could not get proper formatting with cout.


}


void partThree()
//Takes a variety of string inputs from user. Prints formatted info twice.
{
	string strFirstName;
	string strLastName;
	string strAddress;
	string strCity;
	string strState;
	string strZip;

	cin.ignore(); // get rid of extra space clogging input.... what is causing it??
	cout << "Enter your first name: ";
	getline(cin, strFirstName);

	cout << "Enter your last name: ";
	getline(cin, strLastName);

	cout << "Enter your address: ";
	getline(cin, strAddress);

	cout << "Enter your city: ";
	getline(cin, strCity);

	cout << "Enter your two-digit state abbreviation: ";
	getline(cin, strState);

	cout << "Enter your zip code: ";
	getline(cin, strZip);


	// copied from C version, syntax of loops and toUpper are the same.
	char chrTemp; //Temporary variable to hold Chars of string for uppercasing.

	for (int intIndex = 0; intIndex < strState.length(); intIndex++) //Changes the case of strState to uppercase.
	{
		chrTemp = strState[intIndex];

		chrTemp = toupper(chrTemp);

		strState[intIndex] = chrTemp;
	}

	cout << strFirstName <<" " << strLastName << "\n" << strAddress << "\n" << strCity << ", " << strState << " " << strZip;
	cout << "\n"



}


int main() 
{
	cout << "----------------------------------------\n";
	cout << "Part one: " << endl;
	partOne();

	cout << "----------------------------------------\n";
	cout << "Part two: " << endl;
	partTwo();

	cout << "----------------------------------------\n";
	cout << "Part three: " << endl;
	partThree();


	return 0;

}