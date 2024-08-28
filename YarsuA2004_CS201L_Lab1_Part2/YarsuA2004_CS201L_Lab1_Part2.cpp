/* YarsuA2004_CS201L_Lab1_Part2.cpp : This file contains the 'main' function.Program execution begins and ends there.
Alexander Yarsulik

CS201 Lab Program 1 - Distance

This program will do the following: 
	a. Either generate 4 random values between -10 and 10 (inclusive) or take user inputs for those 4 values, which are coordinate points - (x1,y1) and (x2,y2).
	b. Calculate the distance of each point to the origin.
	c. Print each point, its distance to the origin, and which point (1 or 2) is closer to the origin.

Websites that I took inspiration from:
Confirming that an input is numeric (in this program, used for the user integer inputs):
https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
*/

#include <iostream>
#include <string>
#include <cmath> // Included cmath to handle the distance calculations.
#include <iomanip> // Included iomanip to be able to output nice looking floats.
using namespace std;

int main() {
	// I deleted the string inputs because they were not needed within the scope of this program.
	int x1, y1, x2, y2;
	float dist1, dist2;
	char choice;

	srand(time(0));

	//get choice from user ‘e’ to enter values or
	//’g’ to generate values using random values

	cout << "How would you like to get the 4 values ('e' to enter values or 'g' to generate values): ";
	cin >> choice;

	if (choice == 'e') { // If the user chooses to input their own integers, the program will ask the user to input them one by one while checking to see if the inputs are actually integers in the range of -10 to 10.
		cout << "User chose to enter values." << endl;

		cout << "Please enter integer x1:" << endl; // Prompts the user to input an integer
		cin >> x1;
		if ((!cin) || ((x1 < -10) || (x1 > 10))) { // If the input is: a) not an integer, or b) an integer beyond the range of -10 to 10;
			cout << "User failed to enter an integer between -10 and 10." << endl; // The program will catch that, output a notice of that fact,
			return 0;															   // And finally end the program.
		}

		cout << "Please enter integer y1:" << endl;
		cin >> y1;
		if ((!cin) || ((y1 < -10) || (y1 > 10))) {
			cout << "User failed to enter an integer between -10 and 10." << endl;
			return 0;
		}

		cout << "Please enter integer x2:" << endl;
		cin >> x2;
		if ((!cin) || ((x2 < -10) || (x2 > 10))) {
			cout << "User failed to enter an integer between -10 and 10." << endl;
			return 0;
		}

		cout << "Please enter integer y2:" << endl;
		cin >> y2;
		if ((!cin) || ((y2 < -10) || (y2 > 10))) {
			cout << "User failed to enter an integer between -10 and 10." << endl;
			return 0;
		}
		
	}

	//else if choice is ‘g’

	else if (choice == 'g') {
		cout << "User chose to generate values." << endl;

		x1 = (rand() % 21) - 10;
		y1 = (rand() % 21) - 10;
		x2 = (rand() % 21) - 10;
		y2 = (rand() % 21) - 10;

		cout << x1 << endl;
		cout << y1 << endl;
		cout << x2 << endl;
		cout << y2 << endl;
	}
	
	else {
		cout << "User did not input either 'e' or 'g'." << endl;
		return 0;
	}

	// After the inputs are verified and/or generated, they are output in various ways.
	cout << "Point One is: (" << x1 << ", " << y1 << ")" << endl;
	cout << "Point Two is: (" << x2 << ", " << y2 << ")" << endl;

	// The distances between both points and the "origin" are calculated, saved, and later compared against eachother.
	dist1 = sqrt(pow(x1, 2) + pow(y1, 2)); 
	dist2 = sqrt(pow(x2, 2) + pow(y2, 2));

	if (dist1 < dist2) { // If Point One is closer to the origin
		cout << "Point One, which has a distance of " << fixed << setprecision(2) << dist1 << " is closer to the origin than Point Two, which has a distance of " << dist2 << "." << endl;
	}
	else if (dist1 > dist2) { // If Point Two is closer to the origin
		cout << "Point Two, which has a distance of " << fixed << setprecision(2) << dist2 << " is closer to the origin than Point One, which has a distance of " << dist1 << "." << endl;
	}
	else { // If both points are equally distant from the origin
		cout << "The two points have the exact same distance.";
	}

	return 0;

}