/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 1 | written in Java | working with: Basic input, mathematic operators, basic output
*/

import java.util.Scanner; // used to get input from user. 


public class prog1CLF{
    static Scanner getInput = new Scanner(System.in);  //scanner object used to capture input.
    // Made global to more easily access getInput.
    public static void main(String[] args)
    {
        System.out.println("Part one: Convert from seconds");
        partOne();

        System.out.println("----------------------------------------");
        System.out.println("Part two: Convert to dollars");
        partTwo();

        System.out.println("----------------------------------------");
        System.out.println("Part three: Work with output");
        partThree();
    }
    

    static void partOne()
    //Takes integer input from user, then converts and then prints: hours, minutes, and the remainder.
    {        
        int intTotalTime;
        int intHours;
        int intMinutes;

        System.out.format("Enter an integer value of seconds: ");
        intTotalTime = getInput.nextInt();
        
        intHours = intTotalTime / 3600;
        intTotalTime = intTotalTime % 3600;

        intMinutes = intTotalTime / 60;
        intTotalTime = intTotalTime % 60;

        System.out.format("This is %d hours, %d minutes, %d seconds.\n", intHours, intMinutes, intTotalTime);
    }


    static void partTwo()
    //Asks user for four integer inputs, prints the sum in dollars.
    {
        System.out.format("Enter the number of quarters: ");  //Uses .format for printing to remove the endline character.
        int intQuarters = (getInput.nextInt()) * 25;
        System.out.format("Enter the number of dimes: ");
        int intDimes = getInput.nextInt() * 10;
        System.out.format("Enter the number of nickles: ");
        int intNickles = getInput.nextInt() * 5;
        System.out.format("Enter the number of pennies: ");
        int intPennies = getInput.nextInt();

        float fltTotals = (intQuarters + intDimes + intNickles + intPennies);
        fltTotals = fltTotals / 100;
        System.out.format("This is $%1.2f\n", fltTotals);
    }


    static void partThree()
    //Takes a variety of string inputs from user. Prints formatted info twice.
    {
        getInput.nextLine(); // Junk Cleanup again. What is causing this!
        
        System.out.format("Enter your first name: ");
        String strFirstname = getInput.nextLine();
        
        System.out.format("Enter your last name: ");
        String strLastName = getInput.nextLine();

        System.out.format("Enter your address: ");
        String strAddress = getInput.nextLine();
        
        System.out.format("Enter your city: ");
        String strCity = getInput.nextLine();

        System.out.format("Enter your two digit state abbreviation: ");
        String strState = getInput.nextLine();

        System.out.format("Enter your zip: ");
        String strZip = getInput.nextLine();

        strState = strState.toUpperCase();

        System.out.format("\n%s %s\n%s\n%s, %s %s\n\n", strFirstname, strLastName, strAddress, strCity, strState, strZip);
        
        System.out.format("%s ", strFirstname);
        System.out.format("%s\n", strLastName);
        System.out.format("%s\n", strAddress);
        System.out.format("%s, ", strCity);
        System.out.format("%s ", strState);
        System.out.format("%s\n\n", strZip);
    }


}
