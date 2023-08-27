/*
 Collin L. Ferguson
Collin.l.ferguson@ndus.edu
Program 1 | written in C | working with: Basic input, mathematic operators, basic output 
*/

# include <ctype.h> //Allows use of the toupper() function used in part 2
# include <stdio.h>


void partOne()
/*Takes integer input from user, then converts and then prints: hours, minutes, and the remainder.*/
{
	int intTimeTotal;
	printf("Enter an integer value of seconds: ");
	scanf_s("%d", &intTimeTotal);
	printf("\n");
	
	int intTimeHours;
	int intTimeMinutes;
	
	intTimeHours = intTimeTotal / 3600;
	intTimeTotal = intTimeTotal % 3600;

	intTimeMinutes = intTimeTotal / 60;
	intTimeTotal = intTimeTotal % 60;

	printf("This is %d hours, %d minutes, %d seconds\n\n", intTimeHours, intTimeMinutes, intTimeTotal);



}


void partTwo()
/*Asks user for four integer inputs, prints the sum in dollars.*/
{
	int intQuarters;
	int intDimes;
	int intNickles;
	int intPennies;

	printf("Enter the number of quarters: ");
	scanf_s("%d", &intQuarters);


	printf("Enter the number of Dimes: ");
	scanf_s("%d", &intDimes);

	printf("Enter the number of Nickles : ");
	scanf_s("%d", &intNickles);

	printf("Enter the number of Pennies: ");
	scanf_s("%d", &intPennies);

	intQuarters = intQuarters * 25;
	intDimes = intDimes * 10;
	intNickles = intNickles * 5;

	float fltTotal = (intQuarters + intDimes + intNickles + intPennies); //Converts all variables to floats so it can be divided accurately
	fltTotal = fltTotal / 100;

	printf("This is equal to: $%1.2f\n", fltTotal);

}


void partThree()
/*Takes a variety of string inputs from user. Prints formatted info twice.*/
{
	char strFirstName[24] = "";
	char strLastName[56] = "";
	char strAddress[56] = "";
	char strCity[36] = "";
	char strState[8] = ""; // Only allow 2 digit state abbreviations
	char strZip[16] = "";
	
	//char junk[1];

	fflush(stdin); //Flush out an extra space 
	printf("Enter your first name: ");
	fscanf_s(stdin, "%[^\n]s",strFirstName, sizeof(strFirstName) - 1);
	fflush(stdin);
	
	printf("%s\n", strFirstName);

	printf("Enter your last name: ");
	fscanf_s(stdin, "%[^\n]s", strLastName, sizeof(strLastName) - 1);

	printf("Enter your Address: ");
	//fgets(strAddress, 50, stdin);
	fscanf_s(stdin, "%[^\n]s", strAddress, sizeof(strAddress) - 1);
	//fflush(stdin);

	printf("Enter your city: ");
	//fgets(strCity, 30, stdin);
	fscanf_s(stdin, "%[^\n]s", strCity, sizeof(strCity) - 1);
	//fflush(stdin);

	printf("Enter your two-digit state abbreviation: ");
	//fgets(strState, 2, stdin);
	fscanf_s(stdin, "%[^\n]s", strState, sizeof(strState) - 1);
	//fflush(stdin);

	printf("Enter your zip code: ");
	//fgets(strZip, 12, stdin);
	fscanf_s(stdin, "%[^\n]s", strZip, sizeof(strZip) - 1);
	//fflush(stdin);

	char chrTemp = ""; //Temporary variable to hold Chars of string for uppercasing.

	for (int intIndex = 0; intIndex <= 1; intIndex++) //Changes the case of strStrate to uppercase.
	{
		chrTemp = strState[intIndex];
		
		chrTemp = toupper(chrTemp);
		
		strState[intIndex] = chrTemp;
	}
	

	printf("%s %s %s %s %s %s\n", strFirstName, strLastName, strAddress, strCity, strState, strZip);
	//printf("%s", strFirstName);
	printf("\n%s %s\n%s\n%s, %s %s\n\n", strFirstName, strLastName, strAddress, strCity, strState, strZip);
	

	printf("%s ", strFirstName);
	
	printf("%s\n", strLastName);
	printf("%s\n", strAddress);
	printf("%s, ", strCity);
	printf("%s ", strState);
	printf("%s\n", strZip);
	
}	


void main()
{
	printf("Hello World!\n");

	printf("----------------------------------------\n");
	printf("Part 1: Convert from seconds\n");
	//partOne();
	
	printf("----------------------------------------\n");
	printf("Part 2: Convert to dollars\n");
	//partTwo();
	
	printf("----------------------------------------\n");
	printf("Part 3:  Work with output\n");
	partThree();

}