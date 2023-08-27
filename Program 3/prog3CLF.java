/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 3 | written in Java | Working with: Functions, Math operations, Loops
*/
import java.lang.Math;
import java.util.Scanner;

public class prog3CLF
{   
    static Scanner getInput = new Scanner(System.in);

    public static void main(String[] args)
    {
       
        System.out.println(inputWithinRange(0, 100));
        System.out.println("----------------------------------------");

        System.out.println(doContinue("Is this program written in Java?(yes/no)"));
        System.out.println("----------------------------------------");

        System.out.println(square(8));
        System.out.println("----------------------------------------");
        
        System.out.println(summation(100));
        System.out.println("----------------------------------------");

        System.out.println(sumOfSquares(5));
        System.out.println("----------------------------------------");

        System.out.println(factorial(5));
        System.out.println("----------------------------------------");
        
        System.out.println(distance(5, -5, 8, -9));
        System.out.println("----------------------------------------");

        System.out.println(isOdd(5));
        System.out.println("----------------------------------------");

        System.out.println(isEven(4));
        System.out.println("----------------------------------------");
    }

    
    static int inputWithinRange(int intLowValue, int intHighValue)
    {
        System.out.print("Please enter a value: ");
        int intUserInput = getInput.nextInt();

        while (intUserInput < intLowValue || intUserInput > intHighValue)
        {
            System.out.println("That was not within the range.");
            System.out.print("Enter a different value: ");
            intUserInput = getInput.nextInt();
        }

        return intUserInput;
    }

    
    static boolean doContinue(String strPrompt)
    { 
        String strUserInput = "";
        
        while (strUserInput.equals("YES") == false && strUserInput.equals("NO") == false)
        {
            System.out.print(strPrompt + ": ");
            strUserInput = getInput.nextLine();
            
            strUserInput = strUserInput.toUpperCase();
            
            if (strUserInput.equals("YES") == true)
                return true;
            if (strUserInput.equals("NO") == true)
                return false;
        }
        System.out.println("FAIL, TEST MORE doContinue");
        return false; //Program should never reach this point....
    }


    static int square(int intValue)
    {
        return intValue * intValue;
    }


    static int summation(int intValue)
    {
        int intTotal = 0;
        for(int intCurrentValue = 0; intCurrentValue < intValue + 1; intCurrentValue++)
        {
            intTotal += intCurrentValue;
        }

        return intTotal;
    }


    static int sumOfSquares(int intValue)
    {
        int intTotal = 0;
        for(int intCurrentValue = 0; intCurrentValue < intValue + 1; intCurrentValue++)
        {
            intTotal += square(intCurrentValue);
        }

        return intTotal;
    }


    static int factorial(int intValue)
    {
        int intTotal = 1;
        for(int intCurrentValue = 2; intCurrentValue < intValue + 1; intCurrentValue++)
        {
            intTotal *= intCurrentValue;
        }

        return intTotal;
    }


    static double distance(int intXOne, int intYOne, int intXTwo, int intYTwo)
    {   //DistanceFormula: ((x2-X1)^2+(y2-y1)^2)^.5
        return Math.sqrt(square(intXTwo - intXOne)+ square(intYTwo - intYOne));
    }


    static boolean isOdd(int intValue)
    {
        if (intValue % 2 == 1)
        {
            return true;
        }
        else;
        {
            return false; 
        }        
    }


    static boolean isEven(int intValue)
    {
        return !isOdd(intValue);
    }
}  