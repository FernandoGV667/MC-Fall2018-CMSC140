/*
 * Class: CMSC140 CRN 24361
 * Instructor: Jim Snyder
 * Project1
 * Description: Write a program that presents itself and interacts with the user (using name and 2 numbers as input),
 *              as prototype to a humanoid robot.
 * Due Date: 11/09/2018
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Fernando Gonzales-Vigil
*/

/* List of Input for the program:
  1. filename (string)
  2. question (string)
  3. answer (char)
  4. moreQuestions (char)

 * List of Output from the program:
  1. PROGRAM TITLE
  2. Ask for name of the file
  3. Ask for question
  4. Ask for answer
  5. output file: datafile

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)

    1.	Start program
    2.	Ask user for filename
    3.	Verify if file already exists
        3.1 IF file exists, write from the end of the file
        3.2 IF file doesnt exist, create file and write from start.
    4.  Ask user for Question
    5.  Verify length of question
        IF Question is equal or less than 70 chars, continue
        IF Question is more than 70 chars:
            Show Error message
            Return to 4.
    6.  Ask user for Answer to Question
    7.  Verify Answer:
        IF Answer is Y, N, y or n, continue
        IF Answer is not Y, N, y, or n:
            Show error message
            Return to 6.
    8. Ask user if he has more questions to input
        IF Y/y, return to 4.
        IF N/n, continue.
    9. Print Exit Message
    10. Exit Program

*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    const string PROGRAMMER_NAME = "Fernando Gonzales-Vigil";
    const string PROGRAM_TITLE =  "\nExam Question Creation\n----------------------\n";
    const string THANK_YOU_MSG = "Thank you for using my program!!\n";
    const string EXIT_MSG = "PROGRAMMER: " + PROGRAMMER_NAME + "\nCMSC140 Common Project 3\n" +
                            "Due Date: 11/09/2018";

    string filename, question;
    char answer, moreQuestions;
    bool hasMoreQuestions = true;
    int counter = 0;

    cout << PROGRAM_TITLE << endl;
    cout << "Enter the name of the file to be used: ";
    cin >> filename;
    cin.get();
    ofstream datafile(filename, ios::app);

    while (hasMoreQuestions){
        do {
            cout << "Enter a Yes/No question (in one line, no more than 70 characters): ";
            getline(cin, question);
            if (question.length() > 70){
                cout << "Question longer than 70 chars" << endl;
            }
        } while (question.length() > 70);

        datafile << question << "\n";

        do {
            cout << "Enter answer (Y or N):";
            cin >> answer;
            cin.get();
            if (toupper(answer) != 'Y' && toupper(answer) != 'N'){
                cout << "Wrong Input" << endl;
            }
        } while (toupper(answer) != 'Y' && toupper(answer) != 'N');

        datafile << answer << endl;

        cout << "Do you have more questions to enter (Y or N):";
        cin >> moreQuestions;
        cin.get();
        counter++;

        if (moreQuestions == 'N' || moreQuestions == 'n'){
            hasMoreQuestions = false;
        }
    }

    datafile.close();
    cout << "\n" << counter << " questions are added this run\n\n";
    cout << THANK_YOU_MSG;
    cout << EXIT_MSG;

    return 0;
}