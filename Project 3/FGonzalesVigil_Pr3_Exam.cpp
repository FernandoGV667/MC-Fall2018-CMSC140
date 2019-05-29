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
  2. datafile (ifstream)
  3. line (string)
  4. question (string)
  5. userAnswer (char)
  6. fileAnswer (char)
  7. year, month, day (int)

 * List of Output from the program:
  1. Name of User
  2. Birthday (organized YYYY/MM/DD)
  3. Total Questions
  4. Correct answers
  5. Incorrect answers
  6. Results of test (passed or not passed)


 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)

    1.	Start program
    2.	Ask user for filename
    3.	Verify if file already exists and has more than 10 questions
        3.1 IF file doesnt exist or doesnt have more than 10 questions, Show Error, Exit Message and Exit
        3.2 IF file exist AND has more than 10 questions, continue.
    4.  Ask user for Year of Birth
        4.1 IF year of birth  < 16, Show Error, Exit Message and Exit
        4.2 IF year of birth >= 16, continue.
    5.  Ask user for additional information
    6.  Read Question from file and ask user for Y or N answer
        IF user answer matches file answer, Add +1 to Correct answers
        IF user answer doesnt match file answer, Add +1 to Incorrect answers
    7.  Is there a next Question in file?
        IF yes, go to 6.
        IF no, Output # of Correct and Incorrect Answers
    8.  Evaluate if passed test
        IF Correct answer >= 70% of total answers, Congratulate User
        IF Correct answer < 70% of total answers, Output a Did not pass test Message, try again tomorrow.
    9. Print Exit Message
    10. Exit Program

*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    // Initialize constants at start
    const string PROGRAMMER_NAME = "Fernando Gonzales-Vigil";
    const string PROGRAM_TITLE =  "\nDriver Licence Exam\n--------------------\n";
    const string THANK_YOU_MSG = "Thank you for using my program!!\n";
    const string EXIT_MSG = "PROGRAMMER: " + PROGRAMMER_NAME + "\nCMSC140 Common Project 3\n" +
                            "Due Date: 11/09/2018";

    // Initialize variables
    string filename, dummy, line, question, name;
    int year, month, day;
    int testCounter = 0, lineCounter = 0, questionCounter = 1;
    bool isOldEnough = true, isFileOK = false;
    char fileAnswer, userAnswer;
    int correctAnswers = 0, incorrectAnswers = 0, totalAnswers = 0;

    cout << PROGRAM_TITLE << endl;
    cout << "Enter the name of the file to be used: ";
    cin >> filename;
    cin.get();
    ifstream datafile(filename);

    // This while-loop is used to count everyline in the file
    while (getline(datafile, dummy)){
        //This variable add 1 each time getline passes a line to the dummy string
        testCounter++;
        // IF testcounter reaches 20, means the file has 10 questions and 10 answers so its OK
        if (testCounter >= 20){
            isFileOK = true;
        }
    }

    // if the file is OK we can start asking input to the user
    if (isFileOK){
        cout << "\n\n---- Take Exam Taker information ----\n";
        cout << "Birth year: ";
        cin >> year;
        cin.get();

        // We have to verify the user is old enough before asking questions.
        if (2018 - year < 16){
            isOldEnough = false;
            cout << "\n\n YOU HAVE NO AGE FOR A DRIVER LICENCE\n\n";
        } else {
            cout << "\nBirth month: ";
            cin >> month;
            cin.get();
            cout << "\nBirth day: ";
            cin >> day;
            cin.get();
            cout << "\nName: ";
            getline(cin, name);

            cout << "\n\nPreparing questions...\n\n";
            cout << "\n\n****** EXAM STARTS *******\n";

            // Seems like after using getline in a ifstream, you cannot use it again
            // Because of this, I have to close the stream and open it again before using getline again
            // Probably could improve this with more time
            datafile.close();
            datafile.open(filename);
        }

        // Process the file line by line, while there's lines to read and as skip while-loop if age is not enough
        while (getline(datafile,line) && isOldEnough){
            // If it's an even line, it's a question line otherwise it's an answer line
            if (lineCounter % 2 == 0){
                question = line;
                cout << "Question " << questionCounter << ": " << question << endl;
                questionCounter++;
            } else {
                // I couldnt find a simpler way to convert the string line to a char, to easily compare answers
                fileAnswer = line[0];
                cout << "    Your answer (Y or N): ";
                cin >> userAnswer;
                cin.get();
                // We need to verify answers of user with the file answers
                if (toupper(userAnswer) == fileAnswer){
                    correctAnswers++;
                    totalAnswers++;
                } else {
                    incorrectAnswers++;
                    totalAnswers++;
                }
            }
            lineCounter++;
        }

    } else {
        cout << "\n\nTHE SELECTED FILE DOESNT WORK OR IT'S NOT COMPLETE\n\n";
    }

    // If the user is not old enough there's no test completed
    if (isFileOK && isOldEnough){
        // After the end of the test, we close the file
        datafile.close();
        cout << "\n\n****** EXAM COMPLETED ******\n\n";
        cout << "Name: " << name << endl;
        cout << "Birthdate: " << year << "/" << month << "/" << day << endl;
        cout << "Total Questions in the exam: " << totalAnswers << endl;
        cout << "Number of questions answered correctly: " << correctAnswers << endl;
        cout << "Number of questions answered incorrectly: " << incorrectAnswers << endl;
        // We have to cast the result to obtain a percentage of correct answers
        double percent = (correctAnswers / (double) totalAnswers) * 100;

        // A message is shown depending on the results of the Exam
        if ((int) percent > 70){
            cout << "CONGRATULATONS!! YOU PASSED THE EXAM!\n\n";
        } else {
            cout << "You did not pass the exam. You can try again tomorrow!!\n\n";
        }
    }

    // End of program
    cout << THANK_YOU_MSG;
    cout << EXIT_MSG;


    return 0;
}