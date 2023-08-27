"""
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 3 | written in Python | working with: Functions, Math operations, Loops
"""
import math


def main():
    print(inputWithinRange(0, 100))
    print("-" * 40)

    print(doContinue("Is this program written in python?(yes/no)"))
    print("-" * 40)

    print(square(8))
    print("-" * 40)

    print(summation(5))
    print("-" * 40)

    print(sumOfSquare(100))
    print("-" * 40)

    print(factorial(6))
    print("-" * 40)

    print(distance(5, -5, 8, -9))
    print("-" * 40)

    print(isOdd(9))
    print("-" * 40)

    print(isEven(9))


def inputWithinRange(intLowValue, intHighValue):
    """The function will only return a value that is within the inclusive range"""
    intUserInput = int(input("Enter a value: "))

    while intUserInput < intLowValue or intUserInput > intHighValue :
        print("That was not within the range.")
        intUserInput = int(input("Enter a different value: "))
    return intUserInput


def doContinue(strPrompt):
    strUserInput = ""

    while strUserInput != "YES" and strUserInput != "NO":
        strUserInput = input(strPrompt + ": ").upper()

        if strUserInput == "YES":
            return True
        elif strUserInput == "NO":
            return False


def square(intValue):
    return intValue**2


def summation(intValue):
    intTotal = 0
    for intCurrentValue in range(1, intValue+1):
        intTotal += intCurrentValue
    return intTotal


def sumOfSquare(intValue):
    intTotal = 0
    for intCurrentValue in range(1, intValue+1):
        intTotal += square(intCurrentValue)

    return intTotal


def factorial(intValue):
    intTotal = 1
    for step in range(2, intValue + 1):
        intTotal *= step
    return intTotal


def distance(intXOne, intYOne, intXTwo, intYTwo):
    # DistanceFormula: ((x2-X1)^2+(y2-y1)^2)^.5
    return math.sqrt(square(intXTwo - intXOne) + square(intYTwo - intYOne))


def isOdd(intValue):
    intValue = intValue % 2

    if intValue == 1:
        return True
    else:
        return False


def isEven(intValue):
    return not isOdd(intValue)


main()
