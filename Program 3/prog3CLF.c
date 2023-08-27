/*
Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 3 | written in C | Working with: Functions, Math operations, Loops
*/

# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <math.h>

#define true 1
#define false 0


int inputWithinRange( int intLowValue, int intHighValue)
{
    int intUserInput = -1;

    printf("Enter a value: ");
    scanf("%d", &intUserInput);
    fflush(stdin);

    while (intUserInput < intLowValue || intUserInput > intHighValue)
    {
        printf("That value was outside the range\n");
        printf("Enter a value: ");
        scanf("%d", &intUserInput);
        fflush(stdin);
    }

    return intUserInput;
}


int doContinue(char *strPrompt)
{
    char strUserInput[10];

    while (true)
    {
        printf("%s: ", strPrompt);
        scanf("%[^\n]%*c", strUserInput);

        char chrTemp = ""; //Temporary variable to hold Chars of string for uppercasing.

        for (int intIndex = 0; intIndex <= strlen(strUserInput); intIndex++)
        {
            chrTemp = strUserInput[intIndex];

            chrTemp = toupper(chrTemp);

            strUserInput[intIndex] = chrTemp;
        }
        if(strcmp(strUserInput, "YES") == 0)
        {
            return true;
        }
        if(strcmp(strUserInput, "NO") == 0)
        {
            return false;
        }
        else
        {
            printf("That input wasn't recognized.\n");
        }
        fflush(stdin);
    }
}


int square(int intValue)
{
    return intValue * intValue;
}


int summation(int intValue)
    { //Gauss Summation (numOfTerms * (lastNum + firstNum)) / 2
        return (intValue * (intValue + 1) / 2);
    }


int sumOfSquare(int intValue)
{
    int intTotal = 0;
    for(int intStep = 1; intStep < intValue+1; intStep++)
    {
        intTotal = intTotal + square(intStep);
    }
    return intTotal;
}


double distance(double x1, double y1, double x2, double y2)
{
    return  sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}


int isOdd(int intValue)
{
    if (intValue % 2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int isEven (int intValue)
{
    return !isOdd(intValue);
}



int main()
{
    printf("------------------------\n");
    printf("%d\n", inputWithinRange(0,100));

    printf("------------------------\n");
    printf("%d\n", doContinue("Is this program written in C?(yes/no)"));

    printf("------------------------\n");
    printf("%d\n", square(8));

    printf("------------------------\n");
    printf("%d\n", summation(100));

    printf("------------------------\n");
    printf("%d\n", sumOfSquare(5));

    printf("------------------------\n");
    printf("%lf\n", distance(5, 10, 8, -9));

    printf("------------------------\n");
    printf("%d\n", isOdd(4));

    printf("------------------------\n");
    printf("%d\n", isEven(4));

    return 0;
}
