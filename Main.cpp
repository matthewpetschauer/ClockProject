
// Matt Petschauer
// CS 210 - Professor Hecker
// Clock Project
// 6/2/2024



//Include libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Clock.h"

//Use standard namespace
using namespace std;

//declare functions
void DisplayMenu();
void DisplayClocks(Clock& normalTime, Clock& militaryTime);
void GetTimeChange(int selection, Clock &time, Clock &militaryTime);
void FormatTime(string &formattedTime, string &formattedMilitaryTime, int time, int militaryTime);
void Run();
string FormatWithLeadingZero(int value);

//Declare global variables
Clock normalClock;
Clock militaryClock;
int selection;

int main()
{
	//Run Program
	Run();

	return 0;
}


void Run()
{
	//Loop until user ends program
	while (true)
	{
		//Display updated clock to user
		DisplayClocks(normalClock, militaryClock);
		//Display menu to user
		DisplayMenu();
		//Get user input
		GetTimeChange(selection, normalClock, militaryClock);
	}
}

/// <summary>
/// Updates the clocks based on the user selections
/// </summary>
/// <param name="selection"></param>
/// <param name="normalClock"></param>
/// <param name="militaryClock"></param>
void GetTimeChange(int selection, Clock &normalClock, Clock &militaryClock)
{
	//Determines if the loop should continue
	bool isGettingInput = true;

	//Loop until system receives valid input
	while (isGettingInput)
	{
		//Get user input
		cin >> selection;
		//Determine next step
		switch (selection)
		{
			//If user chooses 1, add one hour to clocks, end loop
			case 1:
				normalClock.Time += 3600;
				militaryClock.Time += 3600;
				isGettingInput = false;
				break;
			//If user chooses 2, add one minute to clocks, end loop
			case 2:
				normalClock.Time += 60;
				militaryClock.Time += 60;
				isGettingInput = false;
				break;
			//If user chooses 3, add one second to clocks, end loop
			case 3:
				normalClock.Time += 1;
				militaryClock.Time += 1;
				isGettingInput = false;
				break;
			//If user chooses 4, end program
			case 4:
				cout << "Goodbye!";
				exit(1);
			//If invalid input, notify user and continue loop
			default:
				cout << "\nNot a valid input, please try again\n" << endl;
				DisplayMenu();
				isGettingInput = true;
		}
	}
}

/// <summary>
/// Displays menu to user
/// </summary>
void DisplayMenu()
{
	cout << "1 - Add One Hour" << endl;
	cout << "2 - Add One Minute" << endl;
	cout << "3 - Add One Second" << endl;
	cout << "4 - Exit Program\n" << endl;
}

/// <summary>
/// Displays updated clocks to user
/// </summary>
/// <param name="normalTime"></param>
/// <param name="militaryTime"></param>
void DisplayClocks(Clock &normalTime, Clock &militaryTime)
{
	//Declare variables for clock design, data
	string formattedTime, formattedMilitaryTime;
	string border = "*******************    *******************\n";
	string side = "*                 *    *                 *";

	//Format time for display
	FormatTime(formattedTime, formattedMilitaryTime, normalTime.Time, militaryTime.Time);

	//Output clocks
	cout << border;
	cout << side + "\n" + side << endl;
	cout << "*  12 Hour Clock  *    *  24 Hour Clock  *" << endl;
	cout << setfill('0') << setw(2) << "*   " + formattedTime + "   *    *    " + formattedMilitaryTime + "     *" << endl;
	cout << side + "\n" + side << endl;
	cout << border << endl;
}

/// <summary>
/// Formats time for display to user
/// </summary>
/// <param name="formattedTime"></param>
/// <param name="formattedMilitaryTime"></param>
/// <param name="time"></param>
/// <param name="militaryTime"></param>
void FormatTime(string &formattedTime, string &formattedMilitaryTime, int time, int militaryTime)
{
	//Perform calculations for 12 hour clock display based on total time in seconds
	int timeHour12 = (time / 3600) % 12;
	string hour12 = timeHour12 == 0? to_string(12) : FormatWithLeadingZero(timeHour12);
	string minute12 = FormatWithLeadingZero((time % 3600) / 60);
	string second12 = FormatWithLeadingZero(time % 60);
	string AmPm = (time / 3600) % 24 < 12 ? " AM" : " PM";

	//Perform calculations for 24 hour clock display based on total time in seconds
	string hour24 = FormatWithLeadingZero((militaryTime / 3600) % 24);
	string minute24 = FormatWithLeadingZero((militaryTime % 3600) / 60);
	string second24 = FormatWithLeadingZero(militaryTime % 60);

	//Set string variables with formatted time for display
	formattedTime = hour12 + ":" + minute12 + ":" + second12 + AmPm;
	formattedMilitaryTime = hour24 + ":" + minute24 + ":" + second24;
}

/// <summary>
/// Adds a leading zero if value passed in is single digit
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
string FormatWithLeadingZero(int value)
{
	//If value contains a single digit, return value with a leading zero
	if (value < 10) {
		return "0" + to_string(value);
	}
	return to_string(value);
}