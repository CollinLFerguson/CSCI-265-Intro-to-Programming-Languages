"""
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 1 | written in Python | working with: Basic input, mathematic operators, basic output
"""


def main():
    print("Part 1")  # Convert from seconds
    partOne()
    print("Part 2")  # Convert to dollars
    partTwo()
    print("Part 3")  # Work with output
    partThree()


def partOne():
    """Takes integer input from user, then converts and then prints: hours, minutes, and the remainder."""
    intTotalTime = int(input("Enter an integer value of seconds: "))

    intTimeHours = intTotalTime // 3600
    intTotalTime %= 3600

    intTimeMinutes = intTotalTime // 60
    intTotalTime %= 60

    print("This is %d hours, %d minutes, %d seconds" % (intTimeHours, intTimeMinutes, intTotalTime))


def partTwo():
    """Asks user for four integer inputs, prints the sum in dollars."""
    intQuarters = int(input("Enter the number of quarters: ")) * 25
    intDimes =    int(input("Enter the number of dimes   : ")) * 10
    intNickels =  int(input("Enter the number of nickels : ")) * 5
    intPennies =  int(input("Enter the number of pennies : "))

    fltTotal = (intQuarters + intDimes + intNickels + intPennies)/100

    print("This is equal to: $%1.2f" % fltTotal)


def partThree():
    """Takes a variety of string inputs from user. Prints formatted info twice."""
    strFirstName = input("Enter your first name: ")
    strLastName =  input("Enter your last name : ")
    strAddress =   input("Enter your address   : ")
    strCity =      input("Enter your city      : ")
    strState =     input("Enter your state     : ").upper()
    strZip =       input("Enter your zip code  : ")


    print("%s %s\n%s\n%s, %s %s" % (strFirstName, strLastName, strAddress, strCity, strState, strZip))

    print("------------------")

    print(strFirstName, end=" ")
    print(strLastName)
    print(strAddress)
    print(strCity, end=" ")
    print(strState, end=" ")
    print(strZip)

main()