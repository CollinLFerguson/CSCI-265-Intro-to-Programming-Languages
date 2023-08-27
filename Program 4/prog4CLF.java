/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 4 | written in Java | Working with: Files, Functions, Arrays
*/
import java.lang.Math;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.Arrays;


public class prog4CLF
{
    public static void main(String[] args)
    {  
        int[] theArray = {};
        
        //reading from a file:
        
        String strFileName = "";
        Scanner getFileInput = null;
        Scanner getUserInput = new Scanner(System.in);
        boolean bolFileFound = false;

        while (bolFileFound != true)
        {
            System.out.println("Enter the name of the file: ");
            strFileName = getUserInput.nextLine();

            try {
                getFileInput = new Scanner(new File(strFileName));
                bolFileFound = true;
            } catch (FileNotFoundException e) {
                System.out.println("That file was not found.");
                //getFileInput = new Scanner(System.in); //I need this to avoid "May not be initialized" for sure a better way to do this...
            }
        }
        
        while (getFileInput.hasNextInt())
        {
            theArray = Arrays.copyOf(theArray, theArray.length + 1); //Creates a copy of the array with an extra index position.
            theArray[theArray.length - 1] = getFileInput.nextInt();   // puts the next line of the file into the newly created index position.
        }
        getFileInput.close();
        getUserInput.close();
        
        
        System.out.println(findMaxValue(theArray));
        createSep();
        System.out.println(findMinValue(theArray));
        createSep();
        System.out.println(findFirstOccurrence(theArray, 6));     
        System.out.println(findFirstOccurrence(theArray, 3));     
        createSep();
        System.out.println(calcAverage(theArray));
        createSep();
        System.out.println(findNumbersAboveAverage(theArray));
        createSep();
        System.out.println(findNumbersBelowAverage(theArray));
        createSep();
        System.out.format("%1.6f", standardDeviation(theArray));
    }


    static int findMaxValue(int[] theArray)
    {
        int intCurrentMax = Integer.MIN_VALUE;

        for(int intIndex = 0; intIndex <= theArray.length - 1; intIndex++)
        {
            if (intCurrentMax < theArray[intIndex])
            {
                intCurrentMax = theArray[intIndex];
            }

        } 

        return intCurrentMax;
    }

    
    static int findMinValue(int[] theArray)
    {
        int intCurrentMin = Integer.MAX_VALUE;

        for(int intIndex = 0; intIndex <= theArray.length - 1; intIndex++)
        {
            if (intCurrentMin > theArray[intIndex])
            {
                intCurrentMin = theArray[intIndex];
            }

        } 

        return intCurrentMin;
    }


    static int findFirstOccurrence(int[] theArray, int intValueToFind)
    {
        for(int intIndex = 0; intIndex <= theArray.length - 1; intIndex++)
        {
            if (intValueToFind == theArray[intIndex])
            {
                return intIndex;
            }

        } 
        return -1;

    }

    static int findLastOccurrence(int[] theArray, int intValueToFind)
    {
        int intLastOccurrence = -1;
        
        for(int intIndex = 0; intIndex < theArray.length - 1; intIndex++)
        {
            if (intValueToFind == theArray[intIndex])
            {
                intLastOccurrence = intIndex;
            }

        } 
        return intLastOccurrence;
    }


    static double calcAverage(int[] theArray)
    {
        double dblAverage = 0;
        for (int intIndex = 0; intIndex <= theArray.length - 1; intIndex++ )
        {
            dblAverage += theArray[intIndex];
        }
        dblAverage = dblAverage / theArray.length;

        return dblAverage;
    }


    static int findNumbersAboveAverage(int[] theArray)
    {
        double dblAverage = calcAverage(theArray); 
        int intAboveAverage = 0;

        for(int intIndex = 0; intIndex <= theArray.length - 1; intIndex++)
        {
            if (theArray[intIndex] >= dblAverage)
            {
                intAboveAverage += 1;
            }
        }
        return intAboveAverage;
    }


    static int findNumbersBelowAverage(int[] theArray)
    {
        double  dblAverage = calcAverage(theArray); 
        int intBelowAverage = 0;

        for(int intIndex = 0; intIndex <= theArray.length - 1; intIndex++)
        {
            if (theArray[intIndex] < dblAverage)
            {
                intBelowAverage += 1;
            }
        }
        return intBelowAverage;
    }


    static double standardDeviation(int[] theArray)
    {
        double dblAverage = calcAverage(theArray);
        double dblArrayAverage = 0;

        for (int intIndex = 0; intIndex <= theArray.length - 1; intIndex++)
        {
            dblArrayAverage += Math.pow(theArray[intIndex] - dblAverage, 2);
        }
        dblArrayAverage = Math.sqrt(dblArrayAverage / theArray.length);

        return dblArrayAverage;
    }

    
    static void createSep()
    {
        System.out.println("--------------------------------------");
    }
}