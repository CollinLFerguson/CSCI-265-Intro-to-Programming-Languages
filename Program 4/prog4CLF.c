/*
# Collin L. Ferguson
# Collin.l.ferguson@ndus.edu
# Program 4 | written in C | Working with: Files, Functions, Arrays
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void createSep()
{
    printf("\n-------------------------------\n");
}


int findMaxValue(int theArray[], int intArrayLength)
{
    int intCurrentLargest = INT_MIN;

    for (int intIndex = 0; intIndex <= intArrayLength -1; intIndex++)
    {
        if(theArray[intIndex] > intCurrentLargest)
        {
            intCurrentLargest = theArray[intIndex];
        }
    }

    return intCurrentLargest;
}


int findMinValue(int theArray[], int intArrayLength)
{
    int intCurrentSmallest = INT_MAX;

    for (int intIndex = 0; intIndex <= intArrayLength -1; intIndex++)
    {
        if(theArray[intIndex] < intCurrentSmallest)
        {
            intCurrentSmallest = theArray[intIndex];
        }
    }

    return intCurrentSmallest;
}


int findFirstOccurrence(int theArray[], int intArrayLength, int intValueToFind)
{
    for(int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        if(theArray[intIndex] == intValueToFind)
        {
            return intIndex;
        }
    }
    return -1;
}


int findLastOccurrence(int theArray[], int intArrayLength, int intValueToFind)
{
    int intCurrentLastIndex = -1;
    for(int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        if(theArray[intIndex] == intValueToFind)
        {
            intCurrentLastIndex = intIndex;
        }
    }
    return intCurrentLastIndex;
}


float calcualteAverage(int theArray[], int intArrayLength)
{
    float fltTotal = 0;
    for(int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        fltTotal += theArray[intIndex];
    }
    return fltTotal / (float)intArrayLength;
}


int findNumbersAboveAverage(int theArray[], int intArrayLength)
{
    float fltAverage = calcualteAverage(theArray, intArrayLength);
    int intNumAboveAverage = 0;
    for (int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        if(theArray[intIndex] >= fltAverage)
        {
            intNumAboveAverage += 1;
        }
    }
    return intNumAboveAverage;
}


int findNumbersBelowAverage(int theArray[], int intArrayLength)
{
    float fltAverage = calcualteAverage(theArray, intArrayLength);
    int intNumBelowAverage = 0;
    for(int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        if(theArray[intIndex] < fltAverage)
        {
            intNumBelowAverage += 1;
        }
    }
    return intNumBelowAverage;
}


float standardDeviation(int theArray[], int intArrayLength)
{
    float fltAverage = calcualteAverage(theArray, intArrayLength);
    float fltListAverage = 0;

    for(int intIndex = 0; intIndex <= intArrayLength - 1; intIndex++)
    {
        fltListAverage += pow(theArray[intIndex] - fltAverage, 2);
    }

    fltListAverage = sqrt(fltListAverage / intArrayLength);
    return fltListAverage;

}


int main()
{
    int theArray[5];

    char strLine[10];
    char fileName[50];

    int bolFileFound = 0;

    FILE* inFile;

    while(bolFileFound == 0) //Reading from a file.
    {
        printf("Enter the name of the file: ");
        scanf("%[^\n]%*c", fileName);
        inFile = fopen(fileName, "r");

        if(inFile == NULL)
        {
            printf("Unable to open that file.\n");
        }
        else
        {
            bolFileFound = 1;
        }
    }

    int intIndex = 0;

    while(fgets(strLine, sizeof(strLine), inFile))
    {
        theArray[intIndex] = atoi(strLine);
        intIndex++;
    }

    fclose(inFile);

    int intArrayLength = intIndex; //sizeof(theArray) //static array size makes this impossible.

    printf("%d", findMaxValue(theArray, intArrayLength));
    createSep();
    printf("%d", findMinValue(theArray, intArrayLength));
    createSep();
    printf("%d", findMinValue(theArray, intArrayLength));
    createSep();
    printf("%d\n",findFirstOccurrence(theArray, intArrayLength, 6));
    printf("%d",findFirstOccurrence(theArray, intArrayLength, 1));
    createSep();
    printf("%d\n",findLastOccurrence(theArray, intArrayLength, 6));
    printf("%d",findLastOccurrence(theArray, intArrayLength, 1));
    createSep();
    printf("%1.6f",calcualteAverage(theArray, intArrayLength));
    createSep();
    printf("%d", findNumbersAboveAverage(theArray, intArrayLength));
    createSep();
    printf("%d", findNumbersBelowAverage(theArray, intArrayLength));
    createSep();
    printf("%1.6f",standardDeviation(theArray, intArrayLength));

    return 0;
}
