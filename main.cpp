/*
 * main.cpp (Project one)
 *
 *  Date: 27 Sep 2020
 *  Author: Chase Patten
 */



#include <iostream>
#include <ctime>  // Used to help pull the amount of seconds elapsed since January 1, 1970
using namespace std;

void display_clock(int hours, int minutes, int seconds, int twelve_hour) {
	// Displays 12-hour clock with AM
	if (twelve_hour < 12) { // Helps to determine if it is AM or PM
		cout << "**********************" << "     " << "**********************\n";
		cout << "*    12-hour Clock   *" << "     " << "*   24-hour Clock    *\n";
		cout << "*     " << twelve_hour << ":" << minutes << ":" << seconds << " A M    *" << "    " << " *      " << hours << ":" << minutes << ":" << seconds << "       *\n";
		cout << "**********************" << "     " << "**********************\n";
	}
	
	else if (twelve_hour >= 12) {  // Helps to determine if it is AM or PM
		// Displays 12-hour clock with PM
		cout << "**********************" << "     " << "**********************\n";
		cout << "*    12-hour Clock   *" << "     " << "*   24-hour Clock    *\n";
		cout << "*     " << twelve_hour << ":" << minutes << ":" << seconds << " P M    *" << "    " << " *      " << hours << ":" << minutes << ":" << seconds << "       *\n";
		cout << "**********************" << "     " << "**********************\n";
	}
}



// Displays the menu for the user to make a choice from
void display_menu() {
	cout << "1 - Add One Hour\n2 - Add One Minute \n3 - Add One Second \n4 - Exit Program\n"; 

}



// Used to calculate the current hours
int calculate_hours() {
	int current_time;
	int days;
	int hours;

	current_time = time(0); // Get current time elapsd in seconds since January 1, 1970 at midnight
	days = current_time / 86400; // Divide the current seconds by how many seconds in a day
	hours = ((current_time - (days * 86400)) / 3600); // Used to determine the hours
	
	return hours;
}


// Used to calculate the current minutes
int calculate_minutes() {
	int current_time = time(0);
	int minutes;
	int days = current_time / 86400;

	minutes = (current_time - (days * 86400) - (calculate_hours() * 3600)) / 60; // Used to determine the minutes

	return minutes;
}


// Used to calculate the current seconds
int calculate_seconds() {
	int current_time = time(0);
	int hours = calculate_hours();
	int minutes = calculate_minutes();
	int days = current_time / 86400;
	int seconds = (current_time - (days * 86400) - (hours * 3600) - (minutes * 60)); // Used to determine the seconds

	return seconds;
}


// Used to convert the current hours to a 12-hour format
int convert_twelve_hour() {
	int current_time = time(0); // Get current time elapsd in seconds since January 1, 1970 at midnight
	int days = current_time / 86400; // Divide the current seconds by how many seconds in a day
	int hours = ((current_time - (days * 86400)) / 3600); // Used to determine the hours
	hours = hours % 12;
	return hours;
}

int main() {
	int user_input = 0;
	int current_hours = calculate_hours(); // Calls function to calculate current hours
	int current_minutes = calculate_minutes(); // Calls functions to calculate current minutes
	int current_seconds = calculate_seconds(); // Calls functions to calculate current seconds
	int current_twelve = convert_twelve_hour(); // Calls functions to convert 24-hour format to 12-hour format

	while (user_input != 4) {
	
		display_clock(current_hours, current_minutes, current_seconds, current_twelve); // Displays the current time in twelve hour format
		

		
		cout << "Please make your selection from the options presented below:\n\n";  // Used to prompt the user to make a selection form the menu
		display_menu(); // Calls the menu function to display the menu options
		cout << "\nWhat is your choice: ";
		cin >> user_input;  // User input is stored here


		// Determines by user input what action will be taken
		// Adds one hour to both clocks
		if (user_input == 1) {
			cout << "1 - Add One Hour\n";
			current_hours = current_hours + 1;
			current_twelve = current_twelve + 1;
			system("CLS"); // Used to clear the screen of clutter as command is executed
			continue;
		}

		// Adds one minute to both clocks
		if (user_input == 2) {
			cout << "2 - Add One Minute\n";
			current_minutes = current_minutes + 1;
			system("CLS"); // Used to clear the screen of clutter as command is executed
			continue;
		}

		if (user_input == 3) {
			cout << "3 - Add One Second\n";
			current_seconds = current_seconds + 1;
			system("CLS"); // Used to clear the screen of clutter as command is executed
			continue;
		}
	}
	cout << "Program finished.";
	return 0;
}