/*
David Tiwari
COP2000 (Tues 6:35pm-9pm)
11/6/2018
Homework Assignment #4
Purpose: To create a program to compare 3 different racer's finish time and decide who the winner is (or whether there was a tie) based on input from the user.
As with past assignments output has been formatted to closely resemble the examples in the directions.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Prototypes
void displayMenu();
void getNamesAndRaceTimes(string [], double[]);
double getTimeWithValidation();
void findWinner(string[], double[], int);
double raceAverage(double[], int);

int main()
{
	cout << fixed << setprecision(2);

	const int numberOfRacers = 3;
	string racersNames[numberOfRacers] = { "default1", "default2", "default3" };
	double racersTimes[numberOfRacers] = { 0, 0, 0 };

	displayMenu();
	getNamesAndRaceTimes(racersNames, racersTimes);
	findWinner(racersNames, racersTimes, numberOfRacers);
	cout << endl;
	cout << "Overall Race Time Average: " << raceAverage(racersTimes, numberOfRacers) << endl; //Directions ask for average to be output in main function
	return 0;
}

void displayMenu()
{
	//Display menu choices. Typed out exactly as instructed in directions. What drunk sadist came up with these lines and decided to make us all type them out verbatim for full points?
	cout << setfill('*') << setw(69) << "*" << setfill(' ') << endl
		<< "Welcome to Race Results Program" << endl
		<< "You areAsked [sic] to Enter the Three Racer's Names" << endl
		<< "and Their Associated Race Time." << endl << endl
		<< "Please enter a real number for Race Time (the Race Time Must be > 0)." << endl << endl
		<< "Program Developed by: David Tiwari" << endl
		<< setfill('*') << setw(69) << "*" << setfill(' ') << endl;
}

void getNamesAndRaceTimes(string getNames[], double getTimes[]) //Directions mandate the use of the function named 'void getRaceTimes()' however I decided to use a single function to get the inputs and populate both arrays, thus naming it accordingly
{
	//Get all 3 racer's names and times from user
	
	//Constants used to avoid naked integers in array assignments
	const int firstRacersArrayPosition = 0, 
		secondRacersArrayPosition = 1,
		thirdRacersArrayPosition = 2;
	cout << "Please enter the first racer's name. > ";
	cin >> getNames[firstRacersArrayPosition];
	cout << endl
		<< "Please enter the first racer's time. > ";
	getTimes[firstRacersArrayPosition] = getTimeWithValidation();
	cout << endl
		<< "Please enter the second racer's name. > ";
	cin >> getNames[secondRacersArrayPosition];
		cout << endl
		<< "Please enter the second racer's time. > ";
	getTimes[secondRacersArrayPosition] = getTimeWithValidation();
	cout << endl
		<< "Please enter the third racer's name. > ";
	cin >> getNames[thirdRacersArrayPosition];
		cout << endl
		<< "Please enter the third racer's time. > ";
	getTimes[thirdRacersArrayPosition] = getTimeWithValidation();
	cout << endl;
}

double getTimeWithValidation()
{
	//Validates time entered is > 0 before moving on
	double raceTime = 0;
	cin >> raceTime;
	while (raceTime <= 0)
	{
		cout << "You entered an invalid time. Please enter a race time greater than 0. > ";
		cin >> raceTime;
	}
	return raceTime;
}

void findWinner(string allRacerNames[], double allRaceTimes[], int numberOfTimes)
{
	//Calculates if there was a tie, and if not displays the winning racer's name and time

	//Constants used to avoid naked integers in time comparisons
	const int firstRacersArrayPosition = 0, 
		secondRacersArrayPosition = 1,
		thirdRacersArrayPosition = 2;
	int counter = 0;		
	double lowestTime = allRaceTimes[0];
	string winnersName = allRacerNames[0];

	//Attempted a couple different ways to check for a tie within a for loop, but couldn't find anything that worked correctly
	if (allRaceTimes[firstRacersArrayPosition] == allRaceTimes[secondRacersArrayPosition] && allRaceTimes[firstRacersArrayPosition] == allRaceTimes[thirdRacersArrayPosition])
	{
		cout << "We have a 3 way TIE!!! No winner for this race..." << endl;
	}
	else if (allRaceTimes[firstRacersArrayPosition] == allRaceTimes[secondRacersArrayPosition] && allRaceTimes[firstRacersArrayPosition] < allRaceTimes[thirdRacersArrayPosition])
	{
		cout << "We have a TIE " << allRacerNames[firstRacersArrayPosition] << " and " << allRacerNames[secondRacersArrayPosition] << " win!!!" << endl
			<< "***** Your winning time is: " << allRaceTimes[0] << " *****" << endl;
	}
	else if (allRaceTimes[firstRacersArrayPosition] == allRaceTimes[thirdRacersArrayPosition] && allRaceTimes[firstRacersArrayPosition] < allRaceTimes[secondRacersArrayPosition])
	{
		cout << "We have a TIE " << allRacerNames[firstRacersArrayPosition] << " and " << allRacerNames[thirdRacersArrayPosition] << " win!!!" << endl
			<< "***** Your winning time is: " << allRaceTimes[0] << " *****" << endl;
	}
	else if (allRaceTimes[secondRacersArrayPosition] == allRaceTimes[thirdRacersArrayPosition] && allRaceTimes[secondRacersArrayPosition] < allRaceTimes[firstRacersArrayPosition])
	{
		cout << "We have a TIE " << allRacerNames[secondRacersArrayPosition] << " and " << allRacerNames[2] << " win!!!" << endl
			<< "***** Your winning time is: " << allRaceTimes[1] << " *****" << endl;
	}
	else
	{
		for (counter; counter < numberOfTimes; counter++)
		{
			if (allRaceTimes[counter] < lowestTime)
			{
				lowestTime = allRaceTimes[counter];
				winnersName = allRacerNames[counter];
			}
		}
		cout << "Congratulations " << winnersName << "!!! You are the winner!!!" << endl
			<< "***** Your winning time is: " << lowestTime << " *****" << endl;
	}
	
}

double raceAverage(double allRaceTimes[], int numberOfTimes)
{
	//Finds the average race time
	int counter = 0;
	double sumOfRaceTimes = 0;
	double averageRaceTime = 0;

	for (counter; counter < numberOfTimes; counter++)
		sumOfRaceTimes = sumOfRaceTimes + allRaceTimes[counter];

	return averageRaceTime = sumOfRaceTimes /numberOfTimes;
}

