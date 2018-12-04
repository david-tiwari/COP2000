/*David Tiwari
11/20/18
COP2000 Tues 6:30-9:00pm
Homework Assignment #5
Purpose: To make a number guessing puzzle game with 3 unique boards that are presented one-time each in a random order until the user has completed all 3 successfully or guessed incorrectly 3 times.
Notes: Not sure if using this many loops within main makes thing messy or if I could've done this in a more clean and efficient manner, but this was the best way I found to avoid continuosly passing ridiculous amounts of variables back and forth between functions just to keep main() smaller.
For example, I had attempted to make a couple of the if-else's in main() a function of their own since there are 2 practically identical uses, but was having a problem getting them to run correctly within the loop. Since the program compiles and runs correctly I decided to leave them as they were.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;

//Functions listed as required in homework constraints are all named appropriately, however values passed may differ slightly from what is listed in assignment instructions
void instructions();
int beginGame(int[]);
void displayBoard(int);
void showArray(int[][3], const int, const int);
int getUserGuess();
bool testWinner(int[], int, int);
bool playAgain();
int exitProgram();

int main()
{
	srand(time(NULL)); //Generates seed for random number

	const int numberOfUniqueGameBoards = 3;
	int correctAnswersForEachBoard[numberOfUniqueGameBoards] = { 14, 15, 8 }, //Used to keep track of which boards have been correctly answered
		randomBoardToBePlayed = -1; //Randomly generated number returned from beginGame() to decide which of the 3 boards are displayed
	int usersGuess = -1,
		boardsCompleted = 0; //Used to keep track of how many boards have been guessed successfully, quitting the program once all 3 are completed
	bool answerCorrect = false, //Bool returned from testWinner() comparing whether the users guess matches the correct answer for displayed board
		repeatProgram = false; //Bool returned from playAgain() to repeat program if user chooses to play again

	instructions();
	do
	{
		int incorrectGuesses = 0; //Defined within loop so it reinitializes each time the program is repeated

		randomBoardToBePlayed = beginGame(correctAnswersForEachBoard);
		displayBoard(randomBoardToBePlayed);
		usersGuess = getUserGuess();
		if (usersGuess == 0) //See note above regarding cleaning up code
		{
			return exitProgram();
		}
		else
		{
			answerCorrect = testWinner(correctAnswersForEachBoard, randomBoardToBePlayed, usersGuess);
		}

		while (answerCorrect == false && incorrectGuesses < 2) //Allows user 3 guesses per board
		{
			incorrectGuesses = incorrectGuesses++;
			cout << "I am sorry that was incorrect...";
			usersGuess = getUserGuess();
			if (usersGuess == 0) //See note above regarding cleaning up code
			{
				return exitProgram();
			}
			else
			{
				answerCorrect = testWinner(correctAnswersForEachBoard, randomBoardToBePlayed, usersGuess);
			}
		}

		if (answerCorrect == false && incorrectGuesses >= 2) //Stops users from guessing more than 3 times per board
		{
			cout << "Sorry...you are out of guesses..." << endl;
			repeatProgram = playAgain();
		}
		else if (answerCorrect == true && boardsCompleted < 3) 
		{
			boardsCompleted = boardsCompleted++;
			cout << "You are a number genius!!" << endl;
			cout << endl;
			if (boardsCompleted < 3) //Stops program from asking if the user would like to complete the program after already successfully guess all 3 boards
			{
				repeatProgram = playAgain();
			}
		}
	} while (repeatProgram == true && boardsCompleted < 3); //Only allows the program to repeat if user chooses and if there is at least one board that has not been successfully answered yet

	if (repeatProgram == false)
	{
		return exitProgram();
	}

	if (boardsCompleted >= 3) //Congratulates the user and quits the program if all 3 boards have been successfully solved
	{
		cout << "*** You are the number guessing champion!! CONGRATULATIONS!! ***";
	}
	return 0;
}

void instructions() //Displays introduction text and directions for the game
{
	cout << setfill('*') << setw(60) << "*" << setfill(' ') << endl
		<< setw(40) << "MISSING NUMBERS GAME" << endl
		<< setw(40) << "A fun brain game..." << endl
		<< endl;
	cout << setw(59) << "Please Enter a whole number to guess the missing number..." << endl
		<< setw(48) << "Program Developed by: \"David Tiwari\"" << endl
		<< setfill('*') << setw(60) << "*" << setfill(' ') << endl;
}

int beginGame(int playedBoard[]) //Chooses a random board to play
{
	const int maxValueForRandomSelection = 3;
	int randomBoardSelection = (rand() % maxValueForRandomSelection);

	while (playedBoard[randomBoardSelection] == -1) //Re-generates a random number if board has already been completed
	{
		randomBoardSelection = (rand() % maxValueForRandomSelection);
	}
	 
	return randomBoardSelection;
}

void displayBoard(int randomBoard)
{
	const int gameBoardRows = 4,
		gameBoardColumns = 3;
	//Array holding values for the 3 unique game boards. -1 used in last row of each array as placeholder value for number user will attempt to guess. Correct answer values are stored in correctAnswersForEachBoard[]
	int gameBoard2[gameBoardRows][gameBoardColumns] = { {90, 9, 45},
														{66, 12, 48},
														{34, 7, 70},
														{44, -1, 26} },
		gameBoard1[gameBoardRows][gameBoardColumns] = { {28, 10, 55},
														{89, 17, 98},
														{22, 4, 31},
														{69, -1, 78} },
		gameBoard0[gameBoardRows][gameBoardColumns] = { {38, 11, 83},
														{15, 6, 33},
														{10, 2, 20},
														{86, -1, 95} };

	switch (randomBoard) //Determines which board to display for the user to coincide with the random choice from beginGame()
	{
	case 0:
		showArray(gameBoard0, gameBoardRows, gameBoardColumns);
		break;
	
	case 1:
		showArray(gameBoard1, gameBoardRows, gameBoardColumns);
		break;
	
	case 2:
		showArray(gameBoard2, gameBoardRows, gameBoardColumns);
		break;
	
	}

}

void showArray(int gameBoardArray[][3], const int gameBoardRows, const int gameBoardColumns) //Non-board specific function containing loop to cout array values
{
	int rowIndex = 0,
		columnIndex = 0;
	const int lastRow = 1, //Used to avoid naked integer in loop parameters
		arrayRow3 = 3, //Used in non-looped cout of last column to avoid naked integers
		arrayColumn0 = 0, //Used in non-looped cout of last column to avoid naked integers
		arracyColumn2 = 2; //Used in non-looped cout of last column to avoid naked integers
	for (rowIndex; rowIndex < gameBoardRows - lastRow; rowIndex++) //Display up to but not including the last row
	{
		for (columnIndex = 0; columnIndex < gameBoardColumns; columnIndex++)
		{
			cout << setw(6) << gameBoardArray[rowIndex][columnIndex] << " ";
		}
		cout << endl;
	}
	cout << setw(6) << gameBoardArray[arrayRow3][arrayColumn0] << " " << setw(6) << "?" << " " << setw(6) << gameBoardArray[arrayRow3][arracyColumn2] << endl; //Displays last row outside of loop to allow for non-array symbol ("?") to be shown for the value the user will be attempting to guess 
}

int getUserGuess() //Gets users guess and validates input
{
	int usersGuess = -1;

	cout << "Enter Guess or 0 to Exit >> ";
	cin >> usersGuess;
	
	//Input validation
	while (usersGuess < 0)
	{
		cout << "You entered an invalid number. Please enter a number greater than 0 and press Enter. >> ";
		cin >> usersGuess;
		cout << endl;
	}
	return usersGuess;
}

bool testWinner(int answerBoard[], int currentBoard, int usersGuess) //Compares usersGuess against correct answer for displayed board to determine if guess was correct or not
{
	if (usersGuess == answerBoard[currentBoard])
	{
		answerBoard[currentBoard] = -1; //Changes value in correctAnswersForEachBoard[] if correct to allow beginGame() to keep track of which boards have been successfully completed
		return true;
	}
	else if(usersGuess != answerBoard[currentBoard])
	{
		return false;
	}

}

bool playAgain() //Checks whether the user would like to play the game again after either guessing correctly or exceeding the number of allowed guesses
{
	int usersChoice = -1;
	cout << "Do you wish to play again?? Enter 0 to Exit or any number to continue...>> ";
	cin >> usersChoice;

	while (usersChoice < 0)
	{
		cout << "You entered an invalid number. Please enter a number greater than 0 to play again or 0 to Exit...>> ";
		cin >> usersChoice;
	}

	if (usersChoice == 0)
	{
		return false;
	}
	else if (usersChoice > 0)
	{
		return true;
	}
}

int exitProgram() //Displays message and quits program
{
	cout << "Thank you for playing! Exiting program..." << endl;
	cout << endl;
	return 0;
}
