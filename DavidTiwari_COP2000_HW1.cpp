/*David Tiwari
COP2000 (Tue 6:35-9pm)
8/28/2018
Homework Assignment 1
Purpose: To calculate ingredients needed to fulfill pie order.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Sets all numbers in cout to display 2 decimal places. Idea borrowed from google search (https://stackoverflow.com/questions/22515592/how-to-use-setprecision-in-c).
	cout << fixed << setprecision(2);
	
	//Ingredients based on original recipe for 6 pie crusts.
	const float flour = 15,
		sugar = 8,
		salt = 3,
		butter = 5.25,
		eggs = 6,
		single_pie_divisor = 6; //Used to convert original recipe for 6 pies to recipe for single pie
	
	float total_pies = 0; //Total number of pies needed.

	cout << "How many pies do you wish to make?" << endl;
	cout << "> ";
	cin >> total_pies;
	cout << endl;

	//Total number of each ingredient needed for all pies. Ingredient multiplied by total pies needed, divided by single pie divisor (6) to adjust from original recipe for 6 pies
	float total_flour = total_pies * flour / single_pie_divisor,
		total_sugar = total_pies * sugar / single_pie_divisor,
		total_salt = total_pies * salt / single_pie_divisor,
		total_butter = total_pies * butter / single_pie_divisor,
		total_eggs = total_pies * eggs / single_pie_divisor;


	cout << "Malachi's Pie Shop - Pie Crust Recipe" << endl;
	cout << setfill('-') << setw(37) << "-" << setfill(' ') << endl;
	cout << "You wish to make " << total_pies << " pies." << endl;
	cout << endl;

	//Display total number of each ingredient needed to make all pies.
	cout << left << setw(9) << "Flour" << total_flour << " cups" << endl;
	cout << left << setw(9) << "Sugar" << total_sugar << " tablespoons" << endl;
	cout << left << setw(9) << "Salt" << total_salt << " tablespoons" << endl;
	cout << left << setw(9) << "Butter" << total_butter << " cups" << endl;
	cout << left << setw(9) << "Eggs" << total_eggs << " large eggs" << endl;
	cout << endl;

	return 0;
}