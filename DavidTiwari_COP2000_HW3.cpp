/*
David Tiwari
COP2000 (Tues 6:35pm-9pm)
10/23/2018
Homework Assignment #3
Purpose: To create a program to calculate and display the memberships fees (including compounding interest) for each of the 3 different tiers of membership at Ronda's Gym for the next 10 years.
Note: No seperate analysis submitted this time, rough pseudo-code included as comment at bottom of code.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void DISPLAY_MENU();
int USER_LEVEL_SELECTION();
char PROGRAM_REPEAT();
void GOLD_MEMBERSHIP();
void SILVER_MEMBERSHIP();
void BRONZE_MEMBERSHIP();

int main()
{
	cout << fixed << setprecision(2);
	char REPEAT = 'n';
	int MEMBERSHIP_LEVEL = 0;
	do
	{
		DISPLAY_MENU();
		MEMBERSHIP_LEVEL = USER_LEVEL_SELECTION();

		switch (MEMBERSHIP_LEVEL)
		{
		case 1: GOLD_MEMBERSHIP();
			REPEAT = PROGRAM_REPEAT();
			break;
		case 2: SILVER_MEMBERSHIP();
			REPEAT = PROGRAM_REPEAT();
			break;
		case 3: BRONZE_MEMBERSHIP();
			REPEAT = PROGRAM_REPEAT();
			break;
		default: REPEAT = 'n';
			break;
		}

	} while (REPEAT != 'n' && REPEAT != 'N');

	cout << "Thank you for using Ronda's Fee Calculator!" << endl;

	return 0;
}


void DISPLAY_MENU()
//Displays menu choices
{
	cout << "Welcome to Ronda's Strikeforce Gym" << endl
		<< setfill('-') << setw(35) << "-" << setfill(' ') << endl
		<< "Membership Fee Calculator" << endl
		<< "1. Gold" << endl
		<< "2. Silver" << endl
		<< "3. Bronze" << endl
		<< "4. Quit" << endl;
	cout << endl;
}


int USER_LEVEL_SELECTION()
//Gets input from user
{
	cout << "Please select your membership level from the list above (1-3) and press enter. Select 4 to quit." << endl << "> ";
	int MEMBERSHIP_LEVEL = 0;
	cin >> MEMBERSHIP_LEVEL;

	//Input validation
	while (MEMBERSHIP_LEVEL != 1 && MEMBERSHIP_LEVEL != 2 && MEMBERSHIP_LEVEL != 3 && MEMBERSHIP_LEVEL != 4)
	{
		cout << "You entered an invalid option. Please select an option from the above menu (1-4) and press enter." << endl
			<< "> ";
		cin >> MEMBERSHIP_LEVEL;
	}

	cout << endl;
	return MEMBERSHIP_LEVEL;
}


char PROGRAM_REPEAT()
{
	char RUN_AGAIN = 'n';
	cout << "Would you like to run the program again (Y/N)?" << endl << "> ";
	cin >> RUN_AGAIN;

	//Input Validation
	while (RUN_AGAIN != 'y' && RUN_AGAIN != 'Y' && RUN_AGAIN != 'n' && RUN_AGAIN != 'N')
	{
		cout << "You entered an invalid option. Please enter Y if you would like to run the program again or N to quit." << endl << "> ";
		cin >> RUN_AGAIN;
	}

	cout << endl;
	return RUN_AGAIN;
}


void GOLD_MEMBERSHIP()
{
	const float GOLD_INTEREST_RATE = .01,
		COMPOUNDING_INTEREST_FORMULA_CONSTANT = 1.0; //Literally just a set number that is part of the formula for compounding interest
	float PRINCIPAL = 1200,
		YEARLY_TOTAL = 0;
	int YEAR_COUNTER = 1;
	for (YEAR_COUNTER = 1; YEAR_COUNTER <= 10; YEAR_COUNTER++)
	{
		YEARLY_TOTAL = PRINCIPAL * pow(COMPOUNDING_INTEREST_FORMULA_CONSTANT + GOLD_INTEREST_RATE, YEAR_COUNTER);
		cout << setw(8) << left << "Year" << setw(5) << YEAR_COUNTER << "$" << YEARLY_TOTAL << endl;
	}
	cout << endl;
}

void SILVER_MEMBERSHIP()
{
	const float SILVER_INTEREST_RATE = .02,
		COMPOUNDING_INTEREST_FORMULA_CONSTANT = 1.0; //Literally just a set number that is part of the formula for compounding interest
	float PRINCIPAL = 1200,
		YEARLY_TOTAL = 0;
	int YEAR_COUNTER = 1;
	for (YEAR_COUNTER = 1; YEAR_COUNTER <= 10; YEAR_COUNTER++)
	{
		YEARLY_TOTAL = PRINCIPAL * pow(COMPOUNDING_INTEREST_FORMULA_CONSTANT + SILVER_INTEREST_RATE, YEAR_COUNTER);
		cout << setw(8) << left << "Year" << setw(5) << YEAR_COUNTER << "$" << YEARLY_TOTAL << endl;
	}
	cout << endl;
}

void BRONZE_MEMBERSHIP()
{
	const float BRONZE_INTEREST_RATE = .04,
		COMPOUNDING_INTEREST_FORMULA_CONSTANT = 1.0; //Literally just a set number that is part of the formula for compounding interest
	float PRINCIPAL = 1200,
		YEARLY_TOTAL = 0;
	int YEAR_COUNTER = 1;
	for (YEAR_COUNTER = 1; YEAR_COUNTER <= 10; YEAR_COUNTER++)
	{
		YEARLY_TOTAL = PRINCIPAL * pow(COMPOUNDING_INTEREST_FORMULA_CONSTANT + BRONZE_INTEREST_RATE, YEAR_COUNTER);
		cout << setw(8) << left << "Year" << setw(5) << YEAR_COUNTER << "$" << YEARLY_TOTAL << endl;
	}
	cout << endl;
}

/*PSUEDO-CODE
(Function prototypes)

Main
(MOST OF MAIN BODY IN DO-WHILE LOOP)
Do
1) Display menu (function)
2) Get input from user (function)
	a) Validate input
3)Switch loop
	Case 1 - Gold Membership interest rate (function)
		a) Calculate fees for next 10 years including interest and display for user
		b) Ask to repeat program (function) 
		c) Get user input
			-Validate input
		d) If yes set repeat variable to y (run loop again), if no break out of loop
	Case 2 - Silver Membership interest rate (function)
		a) Calculate fees for next 10 years including interest and display for user
		b) Ask to repeat program (function)
		c) Get user input
			-Validate input
		d) If yes set repeat variable to y (run loop again), if no break out of loop
	Case 3 - Bronze Membership interest rate (function)
		a) Calculate fees for next 10 years including interest and display for user
		b) Ask to repeat program (function)
		c) Get user input
			-Validate input
		d) If yes set repeat variable to y (run loop again), if no break out of loop
	Case 4 - Quit
		a) Break out of loop
While (repeat variable = y)

Thank user

Exit program


Display Menu Function
	a) Cout Menu

Get Input Funtion
	a)Cin menu option
		-Validate input

Gold Rate Function
	a)For loop (repeat 10 times)
		-Calculate compounding interest for gold rate for next 10 years
		-Cout year & fee (organized columns)

Silver Rate Function
	a)For loop (repeat 10 times)
		-Calculate compounding interest for silver rate for next 10 years
		-Cout year & fee (organized columns)

Bronze Rate Function
	a)For loop (repeat 10 times)
		-Calculate compounding interest for bronze rate for next 10 years
		-Cout year & fee (organized columns)

Repeat Function
	a)Ask user to if they would like to repeat program
	b)Cin choice (y/n)
		-Validate input
	c)Return Y/N (for repeat condition in do-while loop)


*/
