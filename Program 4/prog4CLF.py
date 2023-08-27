# Collin L. Ferguson
# Collin.l.ferguson@ndus.edu
# Program 4 | written in Python | Working with: Files, Functions, Lists

import math


def main():
    fileFound = False
    outFile = None

    theList = []

    while fileFound == False:
        outFile = input("Please enter the name of the file: ")
        try:
            outFile = open(outFile, "r")
            fileFound = True
        except:
            print("That file could not be found.")

    for line in outFile:
        theList.append(int(line))

    print(findMaxValue(theList))
    print("-" * 40)
    print(findMinValue(theList))
    print("-" * 40)
    print(findFirstOccurrence(theList, 1))
    print(findFirstOccurrence(theList, 6))
    print("-" * 40)
    print(findLastOccurrence(theList, 1))
    print(findLastOccurrence(theList, 6))
    print("-" * 40)
    print(calculateAverage(theList))
    print("-" * 40)
    print(findNumberAboveAverage(theList))
    print("-" * 40)
    print(findNumberBelowAverage(theList))
    print("-" * 40)
    print("%1.6f" % standardDeviation(theList))


def findMaxValue(theList):
    intCurrentLargest = -2147483647

    for intCurrentValue in theList:
        if intCurrentValue > intCurrentLargest:
            intCurrentLargest = intCurrentValue
    return intCurrentLargest


def findMinValue(theList):
    intCurrentSmallest = 2147483647

    for intCurrentValue in theList:
        if intCurrentValue < intCurrentSmallest:
            intCurrentSmallest = intCurrentValue
    return intCurrentSmallest


def findFirstOccurrence(theList, intValueToFind):
    for intIndex in range(0, len(theList)):
        if theList[intIndex] == intValueToFind:
            return intIndex
    return -1


def findLastOccurrence(theList, intValueToFind):
    intLastOccurrence = -1
    for intIndex in range(0, len(theList)):
        if theList[intIndex] == intValueToFind:
            intLastOccurrence = intIndex
    return intLastOccurrence


def calculateAverage(theList):
    intAverage = 0
    for intIndex in range(0, len(theList)):
        intAverage += theList[intIndex]
    return intAverage / len(theList)


def findNumberAboveAverage(theList):
    fltAverage = calculateAverage(theList)
    intNumAboveAverage = 0

    for intIndex in range(0, len(theList)):
        if theList[intIndex] >= fltAverage:
            intNumAboveAverage += 1

    return intNumAboveAverage


def findNumberBelowAverage(theList):
    fltAverage = calculateAverage(theList)
    intNumAboveAverage = 0

    for intIndex in range(0, len(theList)):
        if theList[intIndex] < fltAverage:
            intNumAboveAverage += 1

    return intNumAboveAverage


def standardDeviation(theList):
    fltAverage = calculateAverage(theList)
    fltListAverage = 0

    for intIndex in range(0, len(theList)):
        fltListAverage += (theList[intIndex] - fltAverage)**2

    fltListAverage = math.sqrt(fltListAverage / len(theList))
    return fltListAverage


main()
