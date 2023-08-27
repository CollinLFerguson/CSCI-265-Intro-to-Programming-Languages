/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 6 | written in CPP | Working with: Files, Hashmaps, Formatted output
*/

#include <iostream>
#include <unordered_map>
#include<fstream>
#include<sstream>
#include <limits>

using namespace std;

unordered_map<string, float> readParts(string fileName)
{
    unordered_map <string, float> theDictionary;
    ifstream inFile;
    inFile.open(fileName);



    string tempStorage;
    string currentLine[1];
    while(inFile >> tempStorage)
    {
        //cout << endl << "Temp Storage: " << tempStorage << endl;

        currentLine[0] = tempStorage.substr(0,tempStorage.find(":"));
        currentLine[1] = tempStorage.substr(tempStorage.find(":")+1, tempStorage.length());

        //cout << currentLine[0] << " ";
        //cout << currentLine[1] <<endl;

        theDictionary[currentLine[0]] = stof(currentLine[1]);
    }

    inFile.close();
    return theDictionary;
}


string* partsGreaterThan(unordered_map<string, float> theDictionary, float upperLimit)
{
    string* partsList = new string[20]; //Allocates memory so that it can be returned.

    int index = 0;
    unordered_map <string, float>::iterator iter;
    for(iter = theDictionary.begin();iter != theDictionary.end(); ++iter)
    {
        if(iter->second > upperLimit)
        {
            partsList[index] = iter->first;
            index++;
        }
    }
    return partsList;
}


void printArray(string* theArray)
{   //Used to make verifying partsGreaterThan easier
    for(int index = 0; index < 20; index++)
    {
        if(theArray[index] != "\0")
        {
            cout << theArray[index] << endl;
        }
    }
}


string leastExpensivePart(unordered_map<string, float> theDictionary)
{
    float currentCheapest = numeric_limits<float>::max(); //Maximum float value
    string cheapestPart = "";
    unordered_map <string, float>::iterator iter;
    for(iter = theDictionary.begin();iter != theDictionary.end(); ++iter)
    {
        if (iter->second < currentCheapest)
        {
            currentCheapest = iter->second;
            cheapestPart = iter->first;
        }

    }
    return cheapestPart;
}


string mostExpensivePart(unordered_map<string, float> theDictionary)
{
    float currentMostExpensive = numeric_limits<float>::lowest(); //Minimum float value
    string mostExpensivePartName = "";
    unordered_map <string, float>::iterator iter;
    for(iter = theDictionary.begin();iter != theDictionary.end(); ++iter)
    {
        if (iter->second > currentMostExpensive)
        {
            currentMostExpensive = iter->second;
            mostExpensivePartName = iter->first;
        }

    }
    return mostExpensivePartName;
}


float averagePrice(unordered_map<string, float> theDictionary)
{
    float total = 0.0;
    int totalEntries = 0;
    unordered_map <string, float>::iterator iter;
    for(iter = theDictionary.begin();iter != theDictionary.end(); ++iter)
    {
        total += iter->second;
        totalEntries += 1;
    }
    total = total/totalEntries;
    return total;
}


void printParts(unordered_map<string, float> theDictionary)
{
    cout << "Parts List:" << endl;

    unordered_map <string, float>::iterator iter;
    for(iter = theDictionary.begin();iter != theDictionary.end(); ++iter)
    {
        printf("%-30s     |     %6.2f\n", iter->first.c_str(), iter->second);
    }
}


int main()
{
    string fileName = "partInfo.txt";
    unordered_map<string, float> theDictionary = readParts(fileName);

    string* partsList = partsGreaterThan(theDictionary, 40); //pointer is put into a var so I can deallocate it.
    cout << "Parts above $40.00: " << endl;

    printArray(partsList);
    delete[] partsList; //frees the memory I needed to allocate to pass the pointer in partsGreaterThan().

    cout << endl <<  "Least expensive part: " << endl;
    cout << leastExpensivePart(theDictionary)<< endl;

    cout << endl <<  "Most expensive part: " << endl;
    cout << mostExpensivePart(theDictionary) << endl;

    cout << endl <<  "Average Price: " << endl;
    printf("%6.2f", averagePrice(theDictionary));

    cout << endl << endl;
    printParts(theDictionary);


    return 0;
}
