/*
 * Class: CMSC140 CRN 24361
 * Instructor: Jim Snyder
 * Project1
 * Description: Write a program that presents itself and interacts with the user (using name and 2 numbers as input),
 *              as prototype to a humanoid robot.
 * Due Date: 10/05/2018
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Fernando Gonzales-Vigil
*/

/* List of Input for the program:
  1. userName (string)
  2. age (int)
  2. firstNumber (int)
  3. secondNumber (int)
  (more as needed)

 * List of Output from the program:
  1. ROBOT_NAME (constant string)
  2. userName (string)
  3. age (int)
  4. ageInMonths (int)
  5. ageInDays (int)
  6. ageInHours (int)
  7. ageInMinutes (long)
  8. ageInSeconds (long)
  9. ageOfDog (int)
  10. ageOfGoldfish (int)
  11. firstNumber (int)
  12. secondNumber (int)
  13. integerQuotient (int)
  14. doubleQuotient (double)
 (more as needed)

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1.Robot presents itself and ask for the user name
  2.Retrieves the user name typed by user
  3.Ask for the age of a person or a pet
  4.Retrieve age typed by the user
  5.Perform calculations based on user data and outputs calculations to user.
  6.Robot asks for a whole number
  7.User inputs whole number
  8.Robot asks for second whole number
  9. User inputs second whole number
  10. Performs calculations based on the 2 whole numbers and outputs calculations to user
  11. Robot says goodbye message and program exits

 (more as needed)
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // these are designed as constants since are assigned from the beginning and wont change during execution
    const string ROBOT_NAME = "Omnius";
    const string PROGRAMMER_NAME = "Fernando Gonzales-Vigil";
    const string INTRO_BANNER = "*****************************Robot Prototype Scripting*****************************\n\n";
    const string EXIT_BANNER = "************************************************************************************\n";
    const string EXIT_MSG = "Thank you for testing my program.\n" + PROGRAMMER_NAME +"\nCMSC140 common project\n";

    // these are variables waiting to be assigned with user input
    string userName;
    int age, firstNumber, secondNumber;

    // ******** INTRO: BANNER, PRESENTATION AND NAME  ********

    cout << INTRO_BANNER;
    // start with presentation and ask for name
    cout << "\nHello, welcome to Montgomery College! My name is " << ROBOT_NAME << ". May I have your name?\n";
    // receive name of the visitor
    cin >> userName;

    // ******** FIRST GAME: CALCULATE AGES ********
    // Ask for age of person or pet
    cout << "Nice to have you with us today, " << userName << "! Let me impress you with a small game.\n";
    cout << "Give me the age of an important person or a pet to you. Please give me only a number!\n";
    // receive age
    cin >> age;
    // output age
    cout << "You have entered number " << age << endl;

    // Calculated variables based on input
    int ageInMonths = age * 12; // 12 months in a year
    int ageInDays = age * 365; // 365 days in a year (NO, a year is not 12 months * 30 days in a month)
    int ageInHours = ageInDays * 24; // 24 hours in a day
    long ageInMinutes = ageInHours * 60; // 60 minutes in an hour
    long ageInSeconds = ageInMinutes * 60; //60 seconds in a minute
    int ageOfDog = age * 7; // 1 dog year = 7 human years
    int ageOfGoldfish = age * 5; // 1 fish year = 5 goldfish year

    // Output calculations based on age
    cout << "If this is for a person, the age can be expressed as " << age << " years or "<< ageInMonths <<
            " months or about " << ageInDays << " days or about " << ageInHours << " hours or about " << ageInMinutes <<
            " minutes or about " << ageInSeconds << " seconds\n";
    cout << "If this is for a dog, it is " << ageOfDog << " years old in human years. ";
    cout << "If this is for a goldfish, it is " << ageOfGoldfish << " years old in human years.\n\n";

    // ******** SECOND GAME: CALCULATE NUMBERS WITH OPERATORS **********

    // Ask for user firstNumber and secondNumber input
    cout << "Let's play another game, "<< userName << ". Give me a whole number\n";
    cin >> firstNumber;
    cout << "Very well. Give me another whole number bigger than zero.\n"; // Included constraint: > 0 to avoid division by 0
    cin >> secondNumber;

    //CALCULATED VARIABLES
    int sum = firstNumber + secondNumber;
    // cast as doubles
    double firstDoubleNumber = (double) firstNumber;
    double  secondDoubleNumber = (double) secondNumber;
    //generate integer and double quotients
    int integerQuotient = firstNumber / secondNumber;
    double doubleQuotient = firstDoubleNumber / secondDoubleNumber;

    //Output calculations according to operators
    cout << "Using the operator '+' in C++, the result of " << firstNumber << " + " << secondNumber << " is " <<
            sum << ". ";
    cout << "Using the operator '/' in C++, the result of " << firstNumber << " / " << secondNumber << " is " <<
            integerQuotient << "; ";
    cout << "However, the result of " << setprecision(1) << fixed << firstDoubleNumber << " / " << secondDoubleNumber <<
            " is about " << doubleQuotient << ".\n\n";


    // ******** OUTRO: GOODBYE, EXIT BANNER AND MESSAGE ********

    cout << "Do you like the games, "<< userName << "? If you do, you can learn more by taking our classes. " <<
            "If you don't, I am sad. " <<
            "You should talk to our Chairman!\n";
    cout << EXIT_BANNER;
    cout << EXIT_MSG;

    return 0;
}