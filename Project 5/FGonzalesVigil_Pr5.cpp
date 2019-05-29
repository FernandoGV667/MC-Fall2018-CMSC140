/*
 * Class: CMSC140 CRN 24361
 * Instructor: Jim Snyder
 * Project 5
 * Description: Randomly generate 6 numbers for the user to guess and calculate
 * the prize depending on how many numbers are guessed correctly.
 *
 * Due Date: 12/14/2018
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Fernando Gonzales-Vigil
*/

/* List of Input for the program:
  1. Game mode choice – self_pick or auto_pick
  2. Five numbers between 1 and 69 (if game mode is self_pick)
  3. One number between 1 and 26 (if game mode is self_pick)


 * List of Output from the program:
  1. Game title
  2. Game rule
  3. Game result including
    - Prize
    - Sorted user’s numbers
    - Sorted winning numbers
  4. Programmer’s full name
  5. Project number
  6. Project due date


 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)

    1.	Start program
    2.	Print rules of the games
    3.	Ask user if he wants to pick white ball
        3.1 IF Y or y, goto 4.
        3.2 IF N or n, generate 5 random non repeated white balls and assign to user array
    4.  Ask user for 5 white balls, if wrong input, loop until correct.
    5.  Ask user if he wants to pick Powerball
        5.1 IF Y or y, goto 6.
        5.2 IF N or n, generate random powerball and asign to user array
    6.  Ask user for a number between 1 and 26 for powerball if wrong input, loop until correct.
    7.  Generate winner white and red numbers and write to winner array
    8.  Write winner numbers and add timestamp to file
    9.  Evaluate how many points user won according to matching user and winner array
    10. Print total points won, user numbers and winner numbers as a Game Report
    11. Print Exit Message
    12. Exit Program

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
using namespace std;

random_device rd; // random generator seed

int userNumbers[6];
int winnerNumbers[6];
ofstream datafile("powerball_register.txt", ios::app);

string getTimeStamp();

void sortArray(int[], int);

void printArray(int[], int);

void registerWinnerNumbers();

void getUserWhiteBallNumbers(char gameChoice);

void generateRandomWhiteBallNumbers(int[]);

void getUserPowerBallNumber(char);

void generateRandomPowerBall(int[]);

int generateRandomInteger(int, int);

void selfPickWhiteBallNumbers();

void selfPickPowerBall();

bool contains(int[], int, int);

void generateWinnerNumbers();

double evaluatePointsWon();


int main() {


    // Initialize constants at start
    const string PROGRAMMER_NAME = "Fernando Gonzales-Vigil";
    const string PROGRAM_TITLE =  "Number Guessing Game\n--------------------\n\n";
    const string GAME_RULES = "1. Select FIVE numbers from 1 to 69 for the white balls.\n"
                              "2. Select ONE number from 1 to 26 for the red PowerBall.\n"
                              "3. Prize determined by how many of your numbers match the winning numbers.\n";
    const string GAME_REPORT_TITLE = "\n********** Game Report **********\n\n";
    const string LAST_BALL_INFO = "** NOTE: The last number is the Power Ball number!! **\n\n";
    const string GAME_REPORT_CLOSE = "****************************\n";
    const string THANK_YOU_MSG = "\nThank you for using my program!!\n";
    const string EXIT_MSG = "PROGRAMMER: " + PROGRAMMER_NAME + "\nCMSC140 Project 5\n" +
                            "Due Date: 12/14/2018";

    char userChoice;

    cout << PROGRAM_TITLE << GAME_RULES;

    do {
        cout << "Do you want to self pick your white ball numbers? (Y or N): ";
        cin >> userChoice;
    } while (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n');


    getUserWhiteBallNumbers(userChoice);

    do {
        cout << "Do you want to self pick your red ball numbers? (Y or N): ";
        cin >> userChoice;
    } while (userChoice != 'Y' && userChoice != 'y' && userChoice != 'N' && userChoice != 'n');

    getUserPowerBallNumber(userChoice);

    cout << GAME_REPORT_TITLE;

    generateWinnerNumbers();
    registerWinnerNumbers();
    datafile.close();
    double points = evaluatePointsWon();

    cout << "You won " << fixed << setprecision(2) << points << " points for the game.\n\n";
    cout << "Here are your numbers:" << endl;
    printArray(userNumbers, 6);
    cout << "\n";
    cout << "Here are the winning numbers:" << endl;
    printArray(winnerNumbers, 6);
    cout << "\n";

    cout << LAST_BALL_INFO << GAME_REPORT_CLOSE;

    // End of program
    cout << THANK_YOU_MSG;
    cout << EXIT_MSG;

    return 0;
}

// Generate a timestamp string to include in data file
string getTimeStamp(){
    chrono::system_clock::time_point p = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(p);
    return ctime(&t);
}

void registerWinnerNumbers(){
    for (int i = 0;i < 6;i++){
        datafile << winnerNumbers[i] << " ";
    }

    datafile << getTimeStamp() << endl;
}

// Utility function to generate random integers, using C++ 11 method instead of rand()
// "rand() Considered Harmful" : https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
int generateRandomInteger(int min, int max){
    mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}

// utility function to sort array with Selection Sort as requested
void sortArray(int arr[], int size){
    int minIndex;
    for (int  start = 0; start < size-1; start++){
        minIndex = start;
        for (int index = start + 1;index<size;index++){
            if(arr[index] < arr[minIndex]){
                minIndex = index;
            }
        }
        swap(arr[minIndex], arr[start]);
    }
}

// Utility function to print arrays
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";

    }
    cout << endl;
}
//  As required by instructions:
//  Function gets and validates user’s numbers,
//  saves and sorted the numbers in an array.
//  The sorted array needs to be returned/passed out by this function.
//  (using void, returning an array means returning a pointer, beyond the scope of the course)
//  This function accepts one argument: game mode choice.
void getUserWhiteBallNumbers(char gameChoice){

    if (gameChoice == 'Y' || gameChoice == 'y'){
        selfPickWhiteBallNumbers();
    } else if (gameChoice == 'N' || gameChoice == 'n'){
        generateRandomWhiteBallNumbers(userNumbers);
    }
    sortArray(userNumbers, 5);
}

// Required function to get
void getUserPowerBallNumber(char gameChoice){
    if (gameChoice == 'Y' || gameChoice == 'y'){
        selfPickPowerBall();
    } else if (gameChoice == 'N' || gameChoice == 'n'){
        generateRandomPowerBall(userNumbers);
    }
}

// Allow the user to pick Whiteballs, validate range of input and assign to user array
void selfPickWhiteBallNumbers(){
    for (int i = 0; i < 5;i++){
        int whiteBall;
        do {
            cout << "Enter number " << i + 1 << " (between 1 and 69): ";
            cin >> whiteBall;
            if (contains(userNumbers,5,whiteBall)){
                cout << "You cannot repeat the same number, choose another." << endl;
            }
        } while (whiteBall < 1 || whiteBall > 69 || contains(userNumbers,5,whiteBall));
        userNumbers[i] = whiteBall;
    }
}

// Allow the user to pick Powerball, validate range of input and assign to user array
void selfPickPowerBall(){
    int powerBall;
    do {
        cout << "Enter POWERBALL number (between 1 and 26): ";
        cin >> powerBall;
    } while (powerBall < 1 || powerBall > 26);
    userNumbers[5] = powerBall;
}

// Generate and assign the random integer to the parameter array
void generateRandomWhiteBallNumbers(int arr[]){

    for (int i = 0; i < 5;i++){
        int random = 0;
        while (contains(arr,5,random)){
            random = generateRandomInteger(1,69);
        }
        arr[i] = random;
    }
}

// Assign a random integer as the PowerBall to the parameter array
void generateRandomPowerBall(int arr[]){
    arr[5] = generateRandomInteger(1,29);
}

// Uses a linear search to verify if a number is contained in an array: True or False
bool contains(int arr[], int size, int element){
    for (int i = 0; i < size; i++){
        if (arr[i] == element){
            return true;
        }
    }
    return false;
}

// Generate and Sort Winner number series
void generateWinnerNumbers(){
    generateRandomWhiteBallNumbers(winnerNumbers);
    sortArray(winnerNumbers, 5);
    generateRandomPowerBall(winnerNumbers);
}

// Calculate how many matches between user and winner balls and return points as a double
double evaluatePointsWon(){
    double points = 0;
    int countWhite = 0;
    bool hasRedBall = false;
    if (winnerNumbers[5] == userNumbers[5]) {
        hasRedBall = true;
    }
    for (int i = 0; i < 5;i++){
        if(contains(winnerNumbers, 5, userNumbers[i])){
            countWhite++;
        }
    }

    if(hasRedBall){
        switch(countWhite){
            case 5:
                points = 1000000000;
                break;
            case 4:
                points = 50000;
                break;
            case 3:
                points = 100;
                break;
            case 2:
                points = 7;
                break;
            default:
                points = 4;
        }
    } else {
        switch(countWhite){
            case 5:
                points = 1000000;
                break;
            case 4:
                points = 100;
                break;
            case 3:
                points = 7;
                break;
            default:
                points = 0;
        }
    }
    return points;
}
