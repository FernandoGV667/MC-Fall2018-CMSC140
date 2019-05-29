/*
 * Class: CMSC140 CRN 24361
 * Instructor: Jim Snyder
 * Project4
 * Description: Write a program that writes to a file a report of a number of employees, including id and hours absent
 * and the final average of days absent.
 *
 * Due Date: 11/23/2018
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Fernando Gonzales-Vigil
*/

/* List of Input for the program:
  1. Number of employees (employees)
  2. Employee ID for each employee(id)
  3. Days of absence for each employee(days)

 * List of Output from the program:
  1. PROGRAM TITLE
  2. Each employee number (ID) to file
  3. Each number of days per employee to file
  4. Total number of employees and total number of days to file
  5. Average number of days employees are absenting to file
  6. Programmer/Student Fullname
  7. Course/Project Number
  8. Due date

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)

    1.	Start program
    2.	Ask user for number of employees
    3.	Verify if number is valid
        3.1 IF number is valid, start to register employee data
        3.2 IF number is invalid, output error message and return to 2.
    4.  Ask user for employee ID and days absent for each employee
    5.  Verify if input for days absent is correct (0 or positive)
        IF input is valid, sum absent days and continue to next employee
        IF input is negative
            Show Error message
            Return to 4.
    6.  Write total employees and total absent days to file
    7.  Calculate average of absent days per employee
    8.  Write average to file
    9.  Write programmer full name to file
    10. Print Exit Message
    11. Exit Program

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// Prototypes of the 3 required functions - Defined functions are after main function
int numberOfEmployees();
int registerEmployees(ofstream&, int);
double calculateAverage(int, int);

int main() {

    // Initialize constants at start
    const string PROGRAMMER_NAME = "Fernando Gonzales-Vigil";
    const string PROGRAM_TITLE =  "Calculate the average number of days a company's employees are absent.\n";
    const string THANK_YOU_MSG = "\nThank you for using my program!!\n";
    const string EXIT_MSG = "PROGRAMMER: " + PROGRAMMER_NAME + "\nCMSC140 Project 4\n" +
                            "Due Date: 11/23/2018";

    int employees, total;
    double average;

    // Initialize and open the file
    ofstream file("employeeAbsences.txt");

    cout << PROGRAM_TITLE << endl;
    //
    employees = numberOfEmployees();
    total = registerEmployees(file, employees);
    average = calculateAverage(employees, total);

    // Write the calculated average of days and Programmers name to the file before closing file
    file << "The average number of days absent is " << average << " days." << endl;
    file << "\nProgrammer: " << PROGRAMMER_NAME << endl;
    file.close();

    // End of program
    cout << THANK_YOU_MSG;
    cout << EXIT_MSG;
    return 0;
}

// FUNCTIONS ARE DEFINED HERE

// This function asks for the number of employees and validates its 1 or more,
// otherwise shows error message and asks again.
// Validated input is returned
int numberOfEmployees(){

    int employees = 0;
    // while-loop to validate that the number of employees input is 1 or more
    while (employees < 1){
        cout << "Please enter the number of employees in the company: ";
        cin >> employees;
        cin.get();
        // Outputs error message if the input is less than 1
        if (employees < 1) {
            cout << "The number of employees must be 1 or more." << endl;
        }
    }

    return employees;
}

// This function writes input (employee ID and days absent) to a file (passed by reference)
// The function loops the request for info as many times as the number of employees in 2nd parameter
// and returns the sum of all days absent for all employees
int registerEmployees(ofstream& file, int employees){
    // Write title of report and fields in the file
    file << "EMPLOYEE ABSENCE REPORT" << endl;
    file << "employee id" << "   " << "days absent" << endl;

    int total = 0;
    // A for-loop is used to write the ID and days absent for each employee
    for (int i = 0; i < employees;i++ ){
        // id and days are local variables
        int id = 0, days = -1;
        // Ask for employee id from user
        cout << "Please enter an employee ID: ";
        cin >> id;
        cin.get();
        // Write id to file, using fixed width to right justify field of 8 spaces
        file << setw(8) << id;
        // while-loop to validate that input is 0 or more
        while (days < 0){
            // Ask for number of days from user
            cout << "Please enter the number of days this employee was absent: ";
            cin >> days;
            // if input doest validate, output message
            if (days < 0){
                cout << "The number of days must not be negative" << endl;
            } else {
                // if input is valid, write it to file with fixed width to right justify field of 10 spaces
                file << setw(10) << days << endl;
            }
        }
        // Sum total days in each loop to total
        total+=days;
    }
    // Write total of employees and total of absent days to file
    file << "\nThe " << employees << " employees were absent a total of " << total << " days." << endl;
    return  total;
}

// The function divides the total of absent days between all employees to obtain
// the average of days absent per employee
double calculateAverage(int employees, int total){
    return total / (double) employees;
}