/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 3 | written in C++ | Working with: Functions, Math operations, Loops
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int valueWithinRange(int intLowValue, int intHighValue)
    {
    int intUserInput = -1;

    cout << "Enter a value: ";
    cin >> intUserInput;
    //cout << "\n";

    while (intUserInput < intLowValue || intUserInput > intHighValue)
    {

        cout << "That value was not wihin the range.\n";
        cout << "Please enter another value: ";
        cin >> intUserInput;
        //cout << "\n";

    }
    cin.clear();
    fflush(stdin);
    return intUserInput;
    }

bool doContinue(string strPrompt)
    {
    string strUserInput = "";

    while (strUserInput.compare("YES") != 0 || strUserInput.compare("NO") != 0 )
        {
        cout << strPrompt + ": ";
        getline(cin, strUserInput);

        char chrTemp; //Temporary variable to hold Chars of string for uppercasing.

        for (int intIndex = 0; intIndex < strUserInput.length(); intIndex++) //Changes the case of strUserInput to uppercase.
        {
            chrTemp = strUserInput[intIndex];

            chrTemp = toupper(chrTemp);

            strUserInput[intIndex] = chrTemp;
        }

        if(strUserInput.compare("YES") == 0)
            {
            return true;
            }
        if (strUserInput.compare("NO") == 0)
            {
            return false;
            }

        cout << "That input wasn't valid.\n";

        }
    }

int square(int intValue)
    {

    return (intValue * intValue);

    }


int summation(int intValue)
    { //Gauss Summation (numOfTerms * (lastNum + firstNum)) / 2
        return int(intValue * (intValue + 1) / 2);
    }


int sumOfSquare(int intValue)
    {
        int intTotal = 0;

        for(int intStep = 1; intStep < intValue +1; intStep++)
            {
            intTotal = intTotal + square(intStep);
            }
        return intTotal;
    }


int factorial(int intValue)
    {
    int intTotal = 1;

        for(int intStep = 2; intStep < intValue +1; intStep++)
        {
        intTotal = intTotal * intStep;
        }

    return intTotal;
    }


double distance(int x1, int y1, int x2, int y2)
    {
    double dblTotal = sqrt(square(x2-x1)+square(y2-y1));


    return dblTotal;
    }


bool isOdd(int intValue)
    {
    if (intValue % 2 == 1)
        {
        return true;
        }
    else
        {
        return false;
        }
    }

bool isEven(int intValue)
    {
    return !isOdd(intValue);
    }

int main()
{
    cout << (valueWithinRange(0, 100));
    cout << "\n-------------------------------\n";

    cout << (doContinue("This program is written in C++"));
    cout << "\n-------------------------------\n";

    cout << square(8);
    cout << "\n-------------------------------\n";

    cout << summation(100);
    cout << "\n-------------------------------\n";

    cout << sumOfSquare(5);
    cout << "\n-------------------------------\n";

    cout << factorial(5);
    cout << "\n-------------------------------\n";

    cout << distance(5, -5, 8, -9);
    cout << "\n-------------------------------\n";

    cout << isOdd(5);
    cout << "\n-------------------------------\n";

    cout << isEven(5);
    cout << "\n-------------------------------\n";
}
