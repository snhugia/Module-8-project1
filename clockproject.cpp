#include <iostream>
#include <stdlib.h>
using namespace std;

// exits program
bool exitProgram = true;

// time units
int clock24 = 06; 
int hour = 06; 
int minutes = 30; 
int seconds = 25; 

// user input variable
int userInput;

// Makes sure clock doesn't go past 12 or 24.
int control = 0;

//displays time
void showTime()
{
    cout << "***************************  ***************************" << endl;
    cout << "*       12-Hour Clock     *  *        24-Hour Clock    *" << endl;
    cout << "*       ";
// if statements to properly display time
    if (hour < 10)
        cout << "0";
    cout << hour << ":";
    if (minutes < 10)
        cout << "0";
    cout << minutes << ":";
    if (seconds < 10)
        cout << "0";
    cout << seconds << " ";
    if (control == 0)
        cout << "AM";
    else if (control == 1)
        cout << "PM";
    cout << "       *  *        ";
    if (clock24 < 10)
        cout << "0";
    cout << clock24 << ":";
    if (minutes < 10)
        cout << "0";
    cout << minutes << ":";
    if (seconds < 10)
        cout << "0";
    cout << seconds << "         *" << endl;
    cout << "***************************  ***************************" << endl;
}
//displays menu
void displayMenu()
{
    cout << "***************************\n";
    cout << "* 1 - Add One Hour        *\n";
    cout << "* 2 - Add One Minute      *\n";
    cout << "* 3 - Add One Second      *\n";
    cout << "* 4 - Exit Program        *\n";
    cout << "***************************\n";
}
//makes sure clock doesn't go to 13 or 25 while adding
void inputAction()
{
    switch (userInput) {
    case 1:
        clock24++;
        hour++;
         if (hour == 13) {
            hour = 1;
        }
        if (clock24 < 12) {
            control = 0;
        }
        if (clock24 == 24) {
            clock24 = 0;
        }
        if (clock24 >= 12) {
            control = 1;
        }
        break;
    case 2:
        minutes++;
        if (minutes == 60) {
            hour++;
            clock24++;
            minutes = 0;
            if (hour == 13) {
                hour = 1;
            }
            if (clock24 < 12) {
                control = 0;
            }
            if (clock24 >= 12) {
                control = 1;
            }
            if (clock24 == 24) {
                clock24 = 0;
            }
        }
        break;
    case 3:
        seconds++;
        if (seconds == 60) {
            minutes++;
            seconds = 0;
            if (minutes == 60) {
                hour++;
                clock24++;
                minutes = 0;
                if (clock24 >= 12) {
                    control = 1;
                }
                if (clock24 < 12) {
                    control = 0;
                }
                if (hour == 13) {
                    hour = 1;
                }
                if (clock24 == 24) {
                    clock24 = 0;
                }
            }
        }
        break;
    case 4:
        cout << "Program has been exited." << endl;
        exitProgram = false;
        break;
    default:
        cout << "Please enter a valid input" << endl;
    }
}
// displays entire program, calls all functions
int main()
{
    while (exitProgram) {
        showTime();
        inputAction();
        displayMenu();
        cin >> userInput;
    }
    return 0;
}