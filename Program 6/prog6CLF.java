/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 6 | written in Java | Working with: Files, Hashmaps, Formatted output
*/

import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.lang.Float;

public class prog6CLF
{
    public static void main(String[] args)
    {
        String strFileName = "partInfo.txt";
        
        HashMap<String, Float> theDictionary = readParts(strFileName);

        System.out.format("Length of the list: %d\n", totalParts(theDictionary));
        System.out.print("\n");
        System.out.println("Parts above limit: ");
        printList(partsGreaterThan(theDictionary, 40));
        System.out.print("\nLeast Expensive part: ");
        System.out.println(leastExpensivePart(theDictionary));
        System.out.print("\nMost Expensive part: ");
        System.out.println(mostExpensivePart(theDictionary));
        System.out.print("\nAverage Price: ");
        System.out.format("%6.2f", averagePrice(theDictionary));
        printParts(theDictionary);
    }

    static HashMap<String, Float> readParts(String strFileName)
    {
        Scanner getFileInput = null;
       
        try {
            getFileInput = new Scanner(new File(strFileName));
        } catch (FileNotFoundException e) {

        }

        HashMap <String, Float> theDictionary = new HashMap<String, Float>();

        while(getFileInput.hasNext())
        {
            String[] currentEntry = getFileInput.nextLine().split(":", 2);
            theDictionary.put(currentEntry[0], Float.parseFloat(currentEntry[1]));

            //Splits the string on the ":", the left half is given as the key. The right half is parsed as a float and given as the value.
        }

        getFileInput.close(); //Closes file
        return theDictionary;
    } 
    
    static int totalParts(HashMap<String, Float> theDictionary)
    {
        return theDictionary.size();
    }

    static String[] partsGreaterThan(HashMap<String, Float> theDictionary, int upperLimit)
    {
        String[] partsAboveLimit = new String[20];
        int index = 0; //Used to populate string list.
     
        for(String key : theDictionary.keySet())
        {
            if(theDictionary.get(key) >= upperLimit)
            {
                partsAboveLimit[index] = key;
                index++;
            }
        }
        return partsAboveLimit;
    }

    static void printList(String[] theList)
    //Used to make verifying partsGreaterThan easier
    {
        for(int index = 0; index < (theList.length); index++)
        {
            if (theList[index] != null)
            {
                System.out.println(theList[index]);
            }
        }
    }

    static String leastExpensivePart(HashMap<String, Float> theDictionary)
    {
        String currentCheapestPart = "";
        float currentLowestValue = Float.MAX_VALUE;

        for(String key : theDictionary.keySet())
        {
            if(theDictionary.get(key) < currentLowestValue)
            {
                currentCheapestPart = key;
                currentLowestValue = theDictionary.get(key);
            }

        }
        return currentCheapestPart;
    }

    static String mostExpensivePart(HashMap<String, Float> theDictionary)
    {
        String currentMostExpensivePart = "";
        float currentHighestValue = Float.MIN_VALUE;

        for(String key : theDictionary.keySet())
        {
            if(theDictionary.get(key) > currentHighestValue)
            {
                currentMostExpensivePart = key;
                currentHighestValue = theDictionary.get(key);
            }

        }
        return currentMostExpensivePart;
    }

    static float averagePrice(HashMap<String, Float> theDictionary)
    {
        float total = 0;

        for(String key : theDictionary.keySet())
        {
            total += theDictionary.get(key);
        }
        total = total / totalParts(theDictionary);

        return (float) total;
    }

    static void printParts(HashMap<String, Float> theDictionary)
    {
        System.out.print("\n\nParts List:");
        for(String key : theDictionary.keySet())
        {
            System.out.format("\n%-30s     |     %6.2f", key, theDictionary.get(key));
        }
    }



}