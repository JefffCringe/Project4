/*
 * Class: CMSC140 CRN 20433
 * Instructor: Grigoriy A. Grinberg
 * Project 4
 * Description: Employee Absences Program
 * Due Date: 11/15/21
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Full Name here: Sean Clemson Casilag
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
ofstream outputFile;

int totalEmployees, totalAbsent, avgAbsent; // Final numbers
int empAbsent; // Temp variable for # of days absent
string empID; // Temp variable for ID
bool valid; // Temp variable for validation
string message, errorMessage;
const string PROGRAMMER = "Sean Clemson Casilag", DUE_DATE = "11/15/21";

// Input Validation
void inputValidate(){
  if(cin.fail()){ // Checks if the cin fails to input value into variable
    valid = 0; // Sets valid to false
    message = errorMessage; // Changes message to error message
    cin.clear();
    cin.ignore(1000,'\n'); // Clears cin to prevent error loop
  }
  else {valid = 1;} // Sets valid to true if input is a number
}

// NumOfEmployees
void NumOfEmployees(){
  message = "Enter number of employees: "; // Initial message output
  errorMessage = "Invalid input. Re-enter number of employees: "; // message variable is changed to this upon error
  valid = 0;
  do{
    cout << message; // Output message variable (will change upon error)
    cin >> totalEmployees;
    inputValidate(); // Check if user input is valid for variable type
    if (totalEmployees < 1){message = errorMessage;} // Check if user input is within bounds
  }
  while(totalEmployees < 1 || !valid); // Loops as long as input is invalid or number is below one
}

// TotDaysAbsent
void TotDaysAbsent(){
  message = "\nEnter employee ID: ";
  errorMessage = "Invalid input. Re-enter employee ID: ";
  valid = 0;
  do{
    cout << message;
    cin >> empID;
    inputValidate();
  }
  while(!valid); // Checks if cin failed, otherwise doesn't validate anything in accordance with directions
  valid = 0;
  message = "Enter Employee " + empID + "'s number of days absent: ";
  errorMessage = "Invalid input. Re-enter number of absent days: ";
  do{
    cout << message;
    cin >> empAbsent;
    inputValidate();
    if (empAbsent < 0){message = errorMessage;}
  }
  while(!valid || empAbsent < 0); // Loops as long as input is invalid or days are negative
  outputFile << setw(5) << empID << setw(25) << empAbsent << endl; // Outputs employee info to file
  totalAbsent += empAbsent;
}

// Find average of two values
double Average(double a, double b){
  return b / a;
}

// Main
int main(){
  // File formatting
  outputFile.open("employeeAbsences.txt");
  outputFile << "EMPLOYEE ABSENCE REPORT\n";
  outputFile << setw(5) << "Employee ID" << setw(25) << "Days absent\n";
  // Begin program
  NumOfEmployees();
  // Loops function for # of employees
  for (int i = 1; i <= totalEmployees; i++){TotDaysAbsent();} 
  // Output final numbers into file
  outputFile << "\nThe "<< totalEmployees << " employees were absent a total of "<< totalAbsent <<" days.\n";
  outputFile << "The average number of days absent is "<< Average(totalEmployees, totalAbsent) <<" days.\n";
  outputFile.close();
  // Credits
  cout << endl
       << "Programmer: " << PROGRAMMER << endl
       << "Due date: " << DUE_DATE << endl;
}

