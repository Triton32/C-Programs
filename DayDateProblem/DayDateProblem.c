#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*<-------------------------------------- Notes -------------------------------------->*/
/*
-For the code below, 0=Sunday, 1=Monday, 2=Tuesday, 3=Wednesday, 4=Thursday, 5=Friday, 6=Saturday

-CenturyCode/Anchor Days:
1500 = 3, which is "Wednesday"
1900 = 3, which is "Wednesday"
2300 = 3, which is "Wednesday"

1600 = 2, which is "Tuesday"
2000 = 2, which is "Tuesday"
2400 = 2, which is "Tuesday"

1700 = 0, which is "Sunday"
2100 = 0, which is "Sunday"
2500 = 0, which is "Sunday"

1800 = 5, which is "Friday"
2200 = 5, which is "Friday"
2600 = 5, which is "Friday"

-Doomsdays: Specific days of the months always is the same days of the week - for example, 2018's doomsday is Wednesday: 3rd of Jan = 12th of December.
Jan = 3(4 if leap year)
Feb = 28(29 if leap year)
Mar = 14
Apr = 4
May = 9
Jun = 6
Jul = 11
Aug = 8
Sep = 5
Oct = 10
Nov = 7
Dec = 12

-Specific months has an specific amount of days.
Jan = 31
Feb = 28
Mar = 31
Apr = 30
May = 31
Jun = 30
Jul = 31
Aug = 31
Sep = 30
Oct = 31
Nov = 30
Dec = 31
*/
/*<------------------------------------------------------------------------------------->*/
int checkIfLeapYear(int year){					//Check if the year inserted is a leap year
	int leapYear;						//Create a new variable to return  if the year is a leap year or not (true or false)
	if ((year % 4 == 0) && (year % 100 != 0)){		//If the year/4 has no remainder and year/100 does have a remainder 
		leapYear = 0;					//Store true=0 into the variable
	}else if (year % 400 == 0){				//If the year can be divided by 400 and has no remainder it is a leap year
		leapYear = 0;					//Store true=0 into the variable
	}else{
		leapYear = 1;					//Store false=1 into the variable
	}
	return leapYear;					//Return true or false (0 or 1)
}

void checkDayExist(int day, int year, int realMonth){		//Check if the day entered is correct by the month January and February
	int leapYear=checkIfLeapYear(year);			//Store if it is a leap year or not (true or false) into variable leapYear
	if (realMonth == 1){					//If the month is 1=January
		if (day < 0 || day > 31){			//If the day entered is not between 0 and 32 (January only has 31 days)
			fprintf(stderr, "Input not valid\n");	//Print that the date entered isnt valid
			exit(1);				//Exit the program
		}
	}else if (realMonth == 2){				//If the month is 2=February
		if(day==29 && leapYear==1){			//If it is a leapYear and the day is 29, continue. Note that the month February only has 28 days within a leap year
			fprintf(stderr, "Input not valid\n");	//Print that the day entered is not valid
			exit(1);				//Exit the program
		}
		
	}
}

int testIfValid(int day, int month, int year){								//Test if the date entered is in format: Mar 29 1996
	if ((day > 0 && day < 32) && (month > 0 && month < 13) && (year > 1499 && year < 2601)){	//If the date is a valid day = 1-31, month = Jan-Dec and year = 1500-2600
		if ((day >=1 && day<=31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)){
			return 0;									//Test if the day is from 1-31 for the specific months, if it is return true=0
		}else if ((day >= 1) && (day <= 30) && (month==4 || month==6 || month==9 || month==11)){
			return 0;									//Test if the day is from 1-30 for the specific months, if it is return true=0
		}else if ((day>=1 && day<=29) && (month==2) || ((year%400==0) || (year%4==0) && (year%100!=0))){
                	return 0;									//Test if the date entered is a valid leap year, if it is return true=0
            	}else if (((day>=1 && day<=28) && (month==2) && (year%4!=0) )){
                	return 0;									//Test if the date entered is a valid leap year, if it is return true=0
		}else{
			return 1;									//Return false if date entered was wrong			
		}
	}else{
		return 1;										//Return false if date entered was wrong	
	}
	
}

int calculateCenturyCode(int century){							//Calculate the century code "anchor day"
	int anchorDay;
	if (century == 1500 || century == 1900 || century == 2300){			//If century entered is 1500, 1900 or 2300, then the anchor day is 3 = "Wednesday"
		anchorDay = 3;								//Store 3 = "Wednesday" into the anchorDay variable
		return anchorDay;							//Return the anchor day
	}else if (century == 1600 || century == 2000 || century == 2400){		//If century entered is 1600, 2000 or 2400, then the anchor day is 2 = "Tuesday"
		anchorDay = 2;								//Store 2 = "Tuesday" into the anchorDay variable
		return anchorDay;							//Return the anchor day
	}else if (century == 1700 || century == 2100 || century == 2500){		//If century entered is 1700, 2100 or 2500, then the anchor day is 0 = "Sunday"
		anchorDay = 0;								//Store 0 = "Sunday" into the anchorDay variable
		return anchorDay;							//Return the anchor day
	}else if (century == 1800 || century == 2200 || century == 2600) {		//If century entered is 1800, 2200 or 2600, then the anchor day is 5 = "Friday"
		anchorDay = 5;								//Store 5 = "Friday" into the anchorDay variable
		return anchorDay;							//Return the anchor day
	}
	return 0;									
}

int main(int argc, char* argv[]){			//Main method
	if ((argc != 4)){				//Check if number of arguments entered is equal to 4
		fprintf(stderr, "Input not valid\n");	//If it is not, print invalid input
		exit(1);				//Exit the program
	}
	char *dayChar;					//Create a pointer variable dayChar to store the integer value of the day
	char *yearChar;					//Create a pointer variable yearChar to store the integer value of the year
	char *monthChar = argv[1];			//Store the month entered into the pointer variable monthChar
	dayChar = argv[2];				//Store the character value of the day into dayChar
	yearChar = argv[3];				//Store the character value of the year into yearChar
	int day = atoi(dayChar);			//Convert the character value of dayChar to an integer value and store it in int variable day
	int year = atoi(yearChar);			//Convert the character value of yeaChar to an integer value and store it in int variable year
	
	int realMonth;					//Store the integer value of the month specified into variable realMonth ex: Mar = 3
	char months[][12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};	//Declare an array that contains the months of the year
	int monthSize = sizeof(months)/sizeof(months[0]);								//Store size of the months array declared
	int i;
	for (i = 0; i < monthSize; i++){		//Create a loop to iterate through the array months
		if (strcmp(months[i], monthChar) == 0){	//Check if the month the user inputted and compare it to array months
			realMonth = i + 1;		//Store the numerical value of the month inputed into realMonth if true
			break;								//Break out of the for loop if month inputted is found
		}
	}
	checkDayExist(day,year,realMonth);						//Check if the day entered is correct by the month January and February
	//Test if the date input is correct
	int validOrNot = testIfValid(day, realMonth, year);				//Test if the date entered is in format: Mar 29 1996
	if (validOrNot != 0){								//If the date is valid
		fprintf(stderr, "Input not valid\n");					//Print not a valid date
		exit(0);								//Print the user input
	}										//Terminate the program
	
	//Step 1: How many times does the number 12 fit as a whole into the last two digits of the year?
	//printf("Step 1: How many times does the number 12 fit as a whole into the last two digits of the year?\n");
	int LTYear= year % 100;							//Find the last two digits of the year entered
	int fitTwelve = LTYear/12; 						//How many times can 12 go into variable LTYear
	//End Step 1
	
	//Step 2: What is the remainder when the last two digits are divided by 12?
	int remainder = LTYear%12;						//Find the remainder of the last two digits of the year entered
	//End Step 2
	
	//Step 3: How many times does 4 fit into the remainder?
	//printf("\nStep 3: How many times does 4 fit into the remainder?\n");
	int fitRemainder = remainder/4;						//How many times does 4 fit into the remainder of the previous step?
	//End Step 3
	
	//Step 4: Calculate the centuries anchor day or "code".
	int century = year - LTYear;						//Find the century of the year inputted by subtracting the year by the last two digits
	int centuryCode = calculateCenturyCode(century);			//Find the century code/anchorday of the year inputted ex: 1700 = 0, which is Sunday
	//End Step 4
	
	//Step 5: Add results from steps 1-4.
	int sumOfSteps = fitTwelve + remainder + fitRemainder + centuryCode;	//Sum all the answeres from steps 1-4
	//End Step 5
	
	//Step 6: Divide the sum by 7 and find the remainder.
	int remainderSum = sumOfSteps%7;					//Find the remainder of the sum to calculate the week day of the doomsday of each month
	switch (remainderSum){							//Use variable remainderSum to iterate through cases
		case 0: remainderSum = 0; //If the remainder of the sum is 0, print the day of the week, Sunday, and break out of the switch statement
			break;
		case 1: remainderSum = 1; //If the remainder of the sum is 1, print the day of the week, Monday, and break out of the switch statement
			break;
		case 2: remainderSum = 2; //If the remainder of the sum is 2, print the day of the week, Tuesday, and break out of the switch statement
			break;
		case 3: remainderSum = 3; //If the remainder of the sum is 3, print the day of the week, Wednesday, and break out of the switch statement
			break;
		case 4: remainderSum = 4; //If the remainder of the sum is 4, print the day of the week, Thursday, and break out of the switch statement
			break;
		case 5: remainderSum = 5; //If the remainder of the sum is 5, print the day of the week, Friday, and break out of the switch statement
			break;
		case 6: remainderSum = 6; //If the remainder of the sum is 6, print the day of the week, Saturday, and break out of the switch statement
			break;
	}
	//End Step 6
	
	//Step 7: Calculate Doomsday, which is the specific days of the months that are always the same days of the week - for example, 2018's doomsday is Wednesday: 3rd of Jan = 12th of December.
	int doomsday;						//Initialize the doomsday of the month variable
	switch (realMonth){					//Use the variable realMonth to iterate through cases
		case 1: realMonth = 1;				//If the numerical value of the month entered is 1, which is January
			if ((year % 4 == 0) && (year%100 != 0)){//Calculate if the year inputted is a leap year. If year mod 4 = 0 and year mod 100 != 0, then it is a leap year	
				doomsday = 4;			//Store 4 into the variable doomsday, which is the 'doomsday' of January if it is a leap year
			}else if (year % 400 == 0){		//If year mod 400 is 0, it is a leap year
				doomsday = 4;			//Store 4 into the variable doomsday, which is the 'doomsday' of January if it is a leap year
			}else{
				doomsday = 3;			//Store 3 inside the variable doomsday, which is the doomsday of January if it is not a leap year
			}
			break;					//Break out of the switch statement after finding the doomsday
		case 2: realMonth = 2;				//If the numerical value of the month entered is 2, which is February
			if ((year % 4 == 0) && (year%100 != 0)){//Calculate if the year inputted is a leap year. If year mod 4 = 0 and year	mod 100 != 0, then it is a leap year	
					doomsday = 29;		//Store 29 into the variable doomsday, which is the 'doomsday' of January if it is a leap year
				}else if (year % 400 == 0){	//If year mod 400 is 0, it is a leap year
					doomsday = 29;		//Store 29 into the variable doomsday, which is the 'doomsday' of January if it is a leap year
				}else{
					doomsday = 28;		//Store 28 into the variable doomsday, which is the doomsday of February if it is not a leap year
				}
			break;					//Break out of the switch statement after finding the doomsday
		case 3: realMonth = 3;				//If the numerical value of the month entered is 3, which is March
			doomsday = 14;				//Store 14 into the variable doomsday, which is the 'doomsday' of March
			break;					//Break out of the switch statement after finding the doomsday
		case 4: realMonth = 4;				//If the numerical value of the month entered is 4, which is April
			doomsday = 4;				//Store 4 into the variable doomsday, which is the 'doomsday' of April
			break;					//Break out of the switch statement after finding the doomsday
		case 5: realMonth = 5;				//If the numerical value of the month entered is 5, which is May
			doomsday = 9;				//Store 9 into the variable doomsday, which is the 'doomsday' of May
			break;					//Break out of the switch statement after finding the doomsday
		case 6: realMonth = 6;				//If the numerical value of the month entered is 6, which is June
			doomsday = 6;				//Store 6 into the variable doomsday, which is the 'doomsday' of June
			break;					//Break out of the switch statement after finding the doomsday
		case 7: realMonth = 7;				//If the numerical value of the month entered is 7, which is July
			doomsday = 11;				//Store 11 into the variable doomsday, which is the 'doomsday' of July
			break;					//Break out of the switch statement after finding the doomsda
		case 8: realMonth = 8;				//If the numerical value of the month entered is 8, which is August
			doomsday = 8;				//Store 8 into the variable doomsday, which is the 'doomsday' of August
			break;					//Break out of the switch statement after finding the doomsday
		case 9: realMonth = 9;				//If the numerical value of the month entered is 9, which is September
			doomsday = 5;				//Store 5 into the variable doomsday, which is the 'doomsday' of September
			break;					//Break out of the switch statement after finding the doomsday
		case 10: realMonth = 10;			//If the numerical value of the month entered is 10, which is October
			doomsday = 10;				//Store 10 into the variable doomsday, which is the 'doomsday' of October
			break;					//Break out of the switch statement after finding the doomsday
		case 11: realMonth = 11;			//If the numerical value of the month entered is 11, which is November
			doomsday = 7;				//Store 7 into the variable doomsday, which is the 'doomsday' of November
			break;					//Break out of the switch statement after finding the doomsday
		case 12: realMonth = 12;			//If the numerical value of the month entered is 12, which is December
			doomsday = 12;				//Store 12 into the variable doomsday, which is the 'doomsday' of December
			break;					//Break out of the switch statement after finding the doomsday
	}
	//End Step 7
	
	//Step 8: Count backwards or forwards from doomsday to the day of the month specified, ex. 11th July 1969 = Friday, 21 July 1969 = Saturday,..., 20th July 1969.
	if (day > doomsday){				//If the day entered is bigger than the doomsday of the month entered, we will count forward
		int counter = day - doomsday;		//Set an counter for the for loop that follows by finding the difference of day and doomsday
		for (i = 0; i < counter; i++){		//Create a loop to count forward until the date entered is reached
			if (remainderSum == 6){		//If the variable remainderSum is 6, which is Saturday
				remainderSum = 0;	//Set the value to 0, which is Sunday, to start a new week
			}else{
				remainderSum++;		//If the remainder is still in the same week, we move a day forward
			}
		}
	}else{						//If the day entered is smaller than the doomsday of the month entered, we will count backward
		int counter = doomsday - day;		//Set an counter for the for loop that follows by finding the difference of doomsday and date
		for (i = 0; i < counter; i++){		//Create a loop to count backward until the date entered is reached
			if (remainderSum == 0){		//If the variable remainderSum is 0, which is Sunday
				remainderSum = 6;	//Set the value to 6, to end the week
			}else{
				remainderSum--;		//If the remainder is still in the same week, we move a day backward
			}
		}
	}
	int dayOfTheWeek = remainderSum;		//Put the variable remainderSum into the variable dayOfTheWeek, which is the day of the week of the date entered
	
	switch (dayOfTheWeek){				//Use variable dayOfTheWeek to iterate through the cases
		case 0: dayOfTheWeek = 0;		//If the variable dayOfTheWeek is equal to 0
			printf("Sun");			//Print that the date entered is on a Sunday to the terminal
			break;				//Break out of the switch statement
		case 1: dayOfTheWeek = 1;		//If the variable dayOfTheWeek is equal to 1
			printf("Mon");			//Print that the date entered is on a Monday to the terminal
			break;				//Break out of the switch statement
		case 2: dayOfTheWeek = 2;		//If the variable dayOfTheWeek is equal to 2
			printf("Tue");			//Print that the date entered is on a Tuesday to the terminal
			break;				//Break out of the switch statement
		case 3: dayOfTheWeek = 3;		//If the variable dayOfTheWeek is equal to 3
			printf("Wed");			//Print that the date entered is on a Wednesday to the terminal
			break;				//Break out of the switch statement
		case 4: dayOfTheWeek = 4;		//If the variable dayOfTheWeek is equal to 4
			printf("Thu");			//Print that the date entered is on a Thursday to the terminal
			break;				//Break out of the switch statement
		case 5: dayOfTheWeek = 5;		//If the variable dayOfTheWeek is equal to 5
			printf("Fri");			//Print that the date entered is on a Friday to the terminal
			break;				//Break out of the switch statement
		case 6: dayOfTheWeek = 6;		//If the variable dayOfTheWeek is equal to 6
			printf("Sat");			//Print that the date entered is on a Saturday to the terminal
			break;				//Break out of the switch statement
	}
	return 0;
}
