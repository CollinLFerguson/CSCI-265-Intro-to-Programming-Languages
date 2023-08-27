# Collin L. Ferguson
# Collin.l.ferguson@ndus.edu
# Program 6 | written in Python | Working with: Files, Formatted output, dictionaries


def main():
    print("Hello World")
    fileName = "partInfo.txt"

    theDictionary = readParts(fileName)
    print("Total Parts:", totalParts(theDictionary))

    print("Parts above Limit:", partsGreaterThan(theDictionary, 44.40))

    print("Cheapest part:", leastExpensivePart(theDictionary))

    print("Most expensive part:", mostExpensivePart(theDictionary))

    print("Average cost: $%5.2f" % averagePrice(theDictionary))

    printParts(theDictionary)


def readParts(fileName):
    fileName = open(fileName)
    theDictionary = {}

    for currentLine in fileName:
        theDictionary[(currentLine.split(sep=":"))[0]] = float((currentLine.split(sep=":"))[1])

    fileName.close()
    return theDictionary


def totalParts(theDictionary):
    return len(theDictionary)


def partsGreaterThan(theDictionary, upperLimit):
    partsAboveLimit = []

    for currentKey in theDictionary.keys():
        if theDictionary[currentKey] >= upperLimit:
            partsAboveLimit.append(currentKey)

    return partsAboveLimit


def leastExpensivePart(theDictionary):
    currentLowestValue = 1000  # Maximum price is less than 1000
    cheapestPart = ""
    for currentKey in theDictionary.keys():
        if theDictionary[currentKey] < currentLowestValue:
            currentLowestValue = theDictionary[currentKey]
            cheapestPart = currentKey

    return cheapestPart


def mostExpensivePart(theDictionary):
    currentHighestValue = -1  # Maximum price is less than 1000
    currentMostExpensivePart = ""

    for currentKey in theDictionary.keys():
        if theDictionary[currentKey] > currentHighestValue:
            currentHighestValue = theDictionary[currentKey]
            currentMostExpensivePart = currentKey

    return currentMostExpensivePart


def averagePrice(theDictionary):
    averageCost = 0.0
    for price in theDictionary:
        averageCost += theDictionary[price]
    averageCost = averageCost / len(theDictionary)

    return averageCost


def printParts(theDictionary):
    print("\n\n")
    for key in theDictionary:
        print("%-30s     |     %6.2f" % (key, theDictionary[key]))


main()
