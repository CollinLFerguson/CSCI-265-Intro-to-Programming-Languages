/*
# Collin L. Ferguson
# Collin.l.ferguson@ndus.edu
# Program 4 | written in CPP | Working with: Files, Functions, Arrays
*/


#include <iostream>
#include <math.h>

#include<fstream>
#include<sstream>

using namespace std;


void createSep()
{
    cout << "------------------------------" <<endl;
}


int findMaxValue(int theArray[], int intLengthOfArray)
{
    int intCurrentLargest = INT_MIN;

    for(int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex++)
    {
        if (intCurrentLargest < theArray[intIndex])
        {
                intCurrentLargest = theArray[intIndex];
        }
    }

    return intCurrentLargest;
}


int findMinValue(int theArray[], int intLengthOfArray)
{
    int intCurrentSmallest = INT_MAX;

    for(int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex++)
    {
        if (intCurrentSmallest > theArray[intIndex])
        {
                intCurrentSmallest = theArray[intIndex];
        }
    }

    return intCurrentSmallest;

}


int findFirstOccurrence(int theArray[], int intLengthOfArray, int intValueToFind)
{
    for(int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex ++)
    {
            if(theArray[intIndex] == intValueToFind)
            {
                return intIndex;
            }
    }
    return -1;
}


int findLastOccurrence(int theArray[], int intLengthOfArray, int intValueToFind)
{
    int intLastOccurrence = -1;
    for (int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex++)
    {
            if (theArray[intIndex] == intValueToFind)
            {
                intLastOccurrence = intIndex;
            }
    }
    return intLastOccurrence;
}


double calculateAverage(int theArray[], int intLengthOfArray)
{
    double dblAverage = 0;
    for(int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex++)
    {
        dblAverage += theArray[intIndex];
    }

    return dblAverage / intLengthOfArray;

}


int findNumberAboveAverage(int theArray[], int intLengthOfArray)
{
    double dblAverage = calculateAverage(theArray, intLengthOfArray);
    int intAboveAverage = 0;

    for (int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex++)
    {
        if (theArray[intIndex] >= dblAverage)
        {
            intAboveAverage += 1;
        }
    }
    return intAboveAverage;
}


int findNumberBelowAverage(int theArray[], int intLengthOfArray)
{
    double dblAverage = calculateAverage(theArray, intLengthOfArray);
    int intBelowAverage = 0;

    for (int intIndex = 0; intIndex <= intLengthOfArray - 1; intIndex++)
    {
        if (theArray[intIndex] < dblAverage)
        {
            intBelowAverage += 1;
        }
    }
    return intBelowAverage;
}


double standardDeviation(int theArray[], int intArrayLength)
{
    double dblAverage = calculateAverage(theArray, intArrayLength);
    double dblArrayAverage = 0;

    for(int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        dblArrayAverage += pow(theArray[intIndex] - dblAverage, 2);
    }
    dblArrayAverage = sqrt(dblArrayAverage / intArrayLength);
    return dblArrayAverage;
}


int main()
{
    string strFilename = "";
    ifstream inFile;

    bool bolFileFound = false; //Opening a file.

    while(bolFileFound == false)
    {
        cout << "Enter the file's name: ";
        cin >> strFilename;


        inFile.open(strFilename);

        if (inFile.is_open())
        {
            bolFileFound = true;
        }
        else
        {
            cout << "That was not a valid filename." << endl;
        }
    }

    int theArray[50];

    int intTempNumber;
    int intIndex = 0;
    int intArrayLength;

    while (inFile >> intTempNumber)
    {
        theArray[intIndex] = intTempNumber;
        intIndex++;
    }

    intArrayLength = intIndex+1;

    printf("%d\n", intArrayLength);

    inFile.close();

    cout << findMaxValue(theArray, intArrayLength)<<endl;
    createSep();
    cout << findMinValue(theArray, intArrayLength)<<endl;
    createSep();
    cout << findFirstOccurrence(theArray, intArrayLength, 6)<<endl;
    cout << findFirstOccurrence(theArray, intArrayLength, 1)<<endl;
    createSep();
    cout << findLastOccurrence(theArray, intArrayLength, 6)<<endl;
    cout << findLastOccurrence(theArray, intArrayLength, 1)<<endl;
    createSep();
    cout << calculateAverage(theArray, intArrayLength)<<endl;
    createSep();
    cout << findNumberAboveAverage(theArray, intArrayLength)<<endl;
    createSep();
    cout << findNumberBelowAverage(theArray, intArrayLength)<<endl;
    createSep();
    cout << standardDeviation(theArray, intArrayLength);

    return 0;
}
