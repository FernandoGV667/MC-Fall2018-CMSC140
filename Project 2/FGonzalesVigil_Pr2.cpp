/*
 * Class: CMSC140 CRN 24361
 * Instructor: Jim Snyder
 * Project1
 * Description: Write a program that presents itself and interacts with the user (using name and 2 numbers as input),
 *              as prototype to a humanoid robot.
 * Due Date: 10/26/2018
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Fernando Gonzales-Vigil
*/

/* List of Input for the program:
  1. countryName
  2. userOption
  3. userTemp
  4. userDistance
  5. userWeight


  (more as needed)

 * List of Output from the program:
  1. Converter Toolkit options
  2. Temperature in Fahreheit or Distance in miles or Weight in pounds.
  3. The user's country name
  4. Programmers

 (more as needed)

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)

    1.	Start program
    2.	Ask user for Country Name
    3.	Print the Computer Toolkit options
    4.	Receive input option from User
        IF Input >=1 OR <=4 PRINT “WRONG NUMBER” and Return to 3
        4.1	IF 1: ASK FOR TEMPERATURE IN CELCIUS
            4.1.1 Receive Input from User
            IF Input <-273 PRINT ERROR MESSAGE AND GO TO 5
            4.2.2	Calculate and Print Temperature in Fº
        4.2	IF 2: ASK FOR DISTANCE IN KM
            4.2.1 Receive Input from User
            IF Input <0 PRINT ERROR MESSAGE AND GO TO 5
            4.2.2	Calculate and Print Distance in Miles
        4.3	IF 3: ASK FOR WEIGHT IN KG
            4.3.1	Receive Input from User
            IF Input <0 PRINT ERROR MESSAGE AND GO TO 5
            4.3.2	Calculate and Print Distance in Lbs.
    5.	Print error message according to wrong input
    6.	Print “$(Country Name) sounds fun!”
    7.	Print Exit Message
    8.	Exit Program

*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // these are designed as constants since are assigned from the beginning and wont change during execution
    const string PROGRAMMER_NAME = "Fernando Gonzales-Vigil";
    const string TOOLKIT_ERROR_MSG = "Option not available, please choose from the listed options:\n";
    const string TEMP_ERROR_MSG = "!!!That temperature does not exist!!!\n";
    const string DIST_ERROR_MSG = "!!!Program does not convert negative distance!!!\n";
    const string WEIGHT_ERROR_MSG = "!!!Program does not convert negative weight!!!\n";
    const string THANK_YOU_MSG = "Thank you for testing my program!!\n";
    const string EXIT_MSG = "PROGRAMMER: " + PROGRAMMER_NAME + "\nCMSC140 Common Project 2\n" +
                            "Due Date: 10/26/2018";
    const string TOOLKIT_TITLE =  "\nConverter Toolkit\n=================\n";
    const string TOOLKIT_OPTIONS = "1. Temperature Converter\n2. Distance Converter\n3. Weight Converter\n4. Quit\n"
                                   "Enter your choice (1-4): ";

    // Flag for options menu, to be used by the while loop
    bool optionIsValid = false;

    // Variables assigned by user input
    string countryName;
    int userOption, userTemp;
    double userDistance, userWeight;

    // Variables calculated by program
    int tempFahrenheit;
    double distMiles, weightPounds;


    // Start of Program - Ask for Country
    cout << "Enter a country name: ";
    cin >> countryName;
    cin.get();


    // STARTS MENU

    // Creates an infinite loop as long as the user doesnt input a valid option
    while (!optionIsValid) {
        cout <<  TOOLKIT_TITLE << TOOLKIT_OPTIONS;
        cin >> userOption;
        cin.get();
        // If the user enters a valid option, the flag turns to true and the while-loop is allowed to exit
        if (userOption >= 1 && userOption <= 4){
            optionIsValid = true;
        }
    }

    switch (userOption) {
        case 1:
            // Temperature Converter
            cout << "Please enter temperature in Celcius (such as 24) : ";
            cin >> userTemp;
            cin.get();
            // Input validation
            if (userTemp < -273){
                cout << TEMP_ERROR_MSG;// -273ºC is 0º Kelvin or absolute 0. There's no temp below.
                break;
            }
            tempFahrenheit = (userTemp * 9/5) + 32;
            cout << "It is " << tempFahrenheit << " in Fahrenheit.\n";
            break;
        case 2:
            // Distance Converter
            cout << "Please enter distance in Kilometers (such as 18.54) : ";
            cin >> userDistance;
            cin.get();
            // Input validation
            if (userDistance < 0){
                cout << DIST_ERROR_MSG;
                break;
            }
            distMiles = userDistance / 1.6;
            cout << "It is " << setprecision(2) << fixed << distMiles << " in miles.\n";
            break;
        case 3:
            // Weight Converter
            cout << "Please enter weight in Kilograms (such as 81.4) : ";
            cin >> userWeight;
            // Input validation
            if (userWeight < 0){
                cout << WEIGHT_ERROR_MSG;
                break;
            }
            cin.get();
            weightPounds = userWeight * 2.2;
            cout << "It is " << setprecision(1) << fixed << weightPounds << " in pounds.\n";
            break;
        case 4:
            break;
    }

    // Return Country mention and EXIT PROGRAM
    cout << countryName << " sounds fun!\n\n";
    cout << THANK_YOU_MSG;
    cout << EXIT_MSG;


    return 0;
}