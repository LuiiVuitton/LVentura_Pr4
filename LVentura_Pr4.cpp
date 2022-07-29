/*
 * Class: CMSC140 CRN: 34203
 * Instructor: Rabiha J. Kayed
 * Project<4>
 * Description: (We are creating a program that will collect and store data 
 and calculate the number of employee and total number of days absent.)
 * Due Date: 4/18/2022
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Luis E. Ventura Perez

 * Pseudocode or Algorithm for the program:
	(be sure to indent items with control structure)
	(need to match flow chart submitted in documentation)
  1.Set variables
  2.enter number of employee
  3.collect employee id
  4.enter number of absent days
  5.store data
  6.calc total number of employee
  7.total and average number of absent days 
 (more as needed)
*/


//Code starts
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Variables used
int numOfEmployees, employeeID, numOfDaysAbsent;
string programmerName = "Luis E. Ventura Perez";
string dueDate = "4/18/2022";
double totalDaysAbsent;

int main() 
{
	cout << "\nCalculate the average number of days a company's employees are absent.";//Program title
	cout << endl;

	//User enters the number of employees at the company.
	cout << "\nPlease Enter the number of employees at the company: ";
	cin >> numOfEmployees;
	cout << endl;

	//While loop, number of employees must be greater than 0.
	while (numOfEmployees <= 0)
	{
		cout << "\nInvalid! Number of employees must be greater than 0.";//error message
		cout << "\nPlease Enter the number of employees at the company: ";//re-entry message
		cin >> numOfEmployees;//new input
		cout << endl;
	}
	//If user enters the while loop, Once the numOfEmployees is greater than 0, program will continue.

	//Open file
	fstream absentFile;
	absentFile.open("employeeAbsences.txt", ios::out);
	if (absentFile.is_open()) {
		
		for (int i = 0; i < numOfEmployees; i++) {//forloop used as a counter based on the users number of employee

			cout << "\nPlease enter Employee ID: ";
			cin >> employeeID;
			cout << "\nPlease enter the number of days the employee was absent: ";
			cin >> numOfDaysAbsent;
			cout << endl;

			while (numOfDaysAbsent < 0) {
				cout << "\nInvalid! Number of absent days cannot be negative!";
				cout << "\nPlease re-enter the number of days the employee was absent: ";
				cin >> numOfDaysAbsent;
				cout << endl;
			}

			absentFile << "Employee Absence Report";
			absentFile << endl;
			absentFile << "\nEmployee ID     Days absent";//display title
			absentFile << "\n-----------     -----------";//display title
			
			absentFile.close();//close the file

			absentFile.open("employeeAbsences.txt", ios::app);//open file again to add more data
			if (absentFile.is_open()) {
				absentFile << "\n" << employeeID;
				absentFile << "                 " << numOfDaysAbsent;
				absentFile.close();
			}
		}

		absentFile.open("employeeAbsences.txt", ios::app);//open file again and add more data
		if (absentFile.is_open()) {

			absentFile << endl;
			absentFile << "The " << numOfEmployees << " employee/s were absent a total of " << numOfDaysAbsent << " days.";
			absentFile << endl;
			absentFile << "\nThe average number of days absent is " << numOfEmployees/numOfDaysAbsent << " days.";
			absentFile << endl;
			absentFile << "\nThank you for Testing my Program!!";//thank you message
			absentFile << "\nPROMGRAMMER: " << programmerName;
			absentFile << "\n CMSC 140 Common Project 4";
			absentFile << "\n Due Date: " << dueDate;
		}
	}
	
	//Programmer message display
	cout << "\nThank you for Testing my Program!!";
	cout << "\nPROMGRAMMER: " << programmerName;
	cout << "\n CMSC 140 Common Project 4";
	cout << "\n Due Date: " << dueDate;

	//End Programmer
	system("pause");
	return 0;
}