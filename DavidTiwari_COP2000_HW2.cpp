/*David Tiwari
COP2000 (Tues 6:35pm-9pm)
10/2/2018
Homework Assignment #2
Purpose: To create a program to calculate the area of the floor for a room based on the room's shape.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << fixed << setprecision(2);

	//Constants
	const float Pi = 3.14f;

	//Variables
	float width = 0,
		length = 0,
		radius = 0;
	int room_shape_selection = 0;

	//Present menu options
	cout << "Haverly's Room Calculator:" << endl;
	cout << setfill('-') << setw(26) << "-" << setfill(' ') << endl;
	cout << "1. Square Room" << endl
		<< "2. Rectangular Room" << endl
		<< "3. Round Room" << endl
		<< "4. Quit" << endl << endl;

	//Ask user to select an option from above
	cout << "Please select an option from above (1-4) and press enter." << endl << "> ";
	cin >> room_shape_selection;
	cout << endl;

	//Validate entry
	while (room_shape_selection != 1 && room_shape_selection != 2 && room_shape_selection != 3 && room_shape_selection != 4) //Went through 50+ google results and tried over a dozen ways to invalidate input if the user enters a decimal (ex: 1.2, 2.5, etc.) but could not find anything that worked correctly.
	{
		cout << "You have entered an invalid selection. Please enter an option from above (1-4) and press enter." << endl << "> ";
		cin >> room_shape_selection;
		cout << endl;
	}
	
	//Display room shape selection and ask for measurements
	switch (room_shape_selection)
	{
		case 1:
		{
			cout << "Square Room" << endl
				<< "Please enter either the width or length of the room in feet." << endl
				<< "> ";
			cin >> width;
			//Validate entry
			while (width <= 0)
			{
				cout << "You entered an invalid measurement. Please enter either the width or length of the room in feet." << endl
					<< "> ";
				cin >> width;
			}
			cout << endl;

			float area_of_square = width * width;

			cout << "Area of room = " << area_of_square << " sq/ft" << endl;
		}
		break;
	
		case 2:
		{
			cout << "Rectangle Room" << endl
				<< "Please enter the width of the room in feet." << endl
				<< "> ";
			cin >> width;
			//Validate entry
			while (width <= 0)
			{
				cout << "You entered an invalid measurement. Please enter the width of the room in feet." << endl
					<< "> ";
				cin >> width;
			}
			cout << endl;
			cout << "Please enter the length of the room in feet." << endl
				<< "> ";
			cin >> length;
			//Validate entry
			while (length <= 0)
			{
				cout << "You entered an invalid measurement. Please enter the length of the room in feet." << endl
					<< "> ";
				cin >> length;
			}
			cout << endl;

			float area_of_rectangle = width * length;

			cout << "Area of room = " << area_of_rectangle << " sq/ft" << endl;
		}
		break;

		case 3:
		{
			cout << "Round Room" << endl
				<< "Please enter the radius of the room in feet." << endl
				<< "> ";
			cin >> radius;
			//Validate entry
			while (radius <= 0)
			{
				cout << "You entered an invalid measurement. Please enter the radius of the room in feet." << endl
					<< "> ";
				cin >> radius;
			}
			cout << endl;

			float area_of_circle = (radius * radius) * Pi;

			cout << "Area of room = " << area_of_circle << " sq/ft" << endl;
		}
		break;
		default:
		{
		break;
		}
	}
	
	cout << endl << "Thank you for using Haverly's Room Calculator!" << endl;
	
	return 0;
}