/* 
    Assignment: Chapter 7 Excersise 21

    Date: 12/12/2024

    Programmer: Vincent Epefanio

    Reqirements: Write a program that creates a two-dimensional array initialized with test data. Use any data type you wish. The program should have the following functions:
• getTotal—This  function  should  accept  a  two-dimensional  array  as  its  argument  and return the total of all the values in the array.
• getAverage—This function should accept a two-dimensional array as its argument and return the average of all the values in the array.
• getRowTotal—This  function  should  accept  a  two-dimensional  array  as  its  first  argument  and  an  integer  as  its  second  argument.  The  second  argument  should  be  the subscript of a row in the array. The function should return the total of the values in the specified row.
• getColumnTotal—This function should accept a two-dimensional array as its first argument and an integer as its second argument. The second argument should be the subscript of a column in the array. The function should return the total of the values in the specified column.
• getHighestInRow—This function should accept a two-dimensional array as its first argument and an integer as its second argument. The second argument should be the subscript of a row in the array. The function should return the highest value in the specified row of the array.
• getLowestInRow—This function should accept a two-dimensional array as its first argument  and  an  integer  as  its  second  argument.  The  second  argument  should  be  the subscript of a row in the array. The function should return the lowest value in the
Display the options in a menu to call the various functions.


    */


#include <iostream>
#include <limits>
using namespace std;

const int ROWS = 3;   
const int COLS = 4;

int getTotal(int arr[ROWS][COLS]);
double getAverage(int arr[ROWS][COLS]);
int getRowTotal(int arr[ROWS][COLS], int row);
int getColumnTotal(int arr[ROWS][COLS], int col);
int getHighestInRow(int arr[ROWS][COLS], int row);
int getLowestInRow(int arr[ROWS][COLS], int row);
void displayMenu();

int main() {
    
    int arr[ROWS][COLS] = {
        { 5, 10, 15, 20 },
        { 2, 7, 12, 17 },
        { 3, 6, 9, 12 }
    };

    int choice;
    do {
        displayMenu();  
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Total of all values: " << getTotal(arr) << endl;
                break;
            case 2:
                cout << "Average of all values: " << getAverage(arr) << endl;
                break;
            case 3:
                {
                    int row;
                    cout << "Enter row number (0 to " << ROWS - 1 << "): ";
                    cin >> row;
                    if (row >= 0 && row < ROWS) {
                        cout << "Total of row " << row << ": " << getRowTotal(arr, row) << endl;
                    } else {
                        cout << "Invalid row number!" << endl;
                    }
                }
                break;
            case 4:
                {
                    int col;
                    cout << "Enter column number (0 to " << COLS - 1 << "): ";
                    cin >> col;
                    if (col >= 0 && col < COLS) {
                        cout << "Total of column " << col << ": " << getColumnTotal(arr, col) << endl;
                    } else {
                        cout << "Invalid column number!" << endl;
                    }
                }
                break;
            case 5:
                {
                    int row;
                    cout << "Enter row number (0 to " << ROWS - 1 << "): ";
                    cin >> row;
                    if (row >= 0 && row < ROWS) {
                        cout << "Highest value in row " << row << ": " << getHighestInRow(arr, row) << endl;
                    } else {
                        cout << "Invalid row number!" << endl;
                    }
                }
                break;
            case 6:
                {
                    int row;
                    cout << "Enter row number (0 to " << ROWS - 1 << "): ";
                    cin >> row;
                    if (row >= 0 && row < ROWS) {
                        cout << "Lowest value in row " << row << ": " << getLowestInRow(arr, row) << endl;
                    } else {
                        cout << "Invalid row number!" << endl;
                    }
                }
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
        cout << endl;
    } while (choice != 7);  // Loop until the user chooses to exit

    return 0;
}

// Function to get the total of all values in the 2D array
int getTotal(int arr[ROWS][COLS]) {
    int total = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total += arr[i][j];
        }
    }
    return total;
}

// Function to get the average of all values in the 2D array
double getAverage(int arr[ROWS][COLS]) {
    int total = getTotal(arr);
    return static_cast<double>(total) / (ROWS * COLS);
}

// Function to get the total of a specific row
int getRowTotal(int arr[ROWS][COLS], int row) {
    int total = 0;
    for (int j = 0; j < COLS; j++) {
        total += arr[row][j];
    }
    return total;
}

// Function to get the total of a specific column
int getColumnTotal(int arr[ROWS][COLS], int col) {
    int total = 0;
    for (int i = 0; i < ROWS; i++) {
        total += arr[i][col];
    }
    return total;
}

// Function to get the highest value in a specific row
int getHighestInRow(int arr[ROWS][COLS], int row) {
    int highest = arr[row][0];
    for (int j = 1; j < COLS; j++) {
        if (arr[row][j] > highest) {
            highest = arr[row][j];
        }
    }
    return highest;
}

// Function to get the lowest value in a specific row
int getLowestInRow(int arr[ROWS][COLS], int row) {
    int lowest = arr[row][0];
    for (int j = 1; j < COLS; j++) {
        if (arr[row][j] < lowest) {
            lowest = arr[row][j];
        }
    }
    return lowest;
}

// Function to display the menu
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Get total of all values in the array" << endl;
    cout << "2. Get average of all values in the array" << endl;
    cout << "3. Get total of a specific row" << endl;
    cout << "4. Get total of a specific column" << endl;
    cout << "5. Get highest value in a specific row" << endl;
    cout << "6. Get lowest value in a specific row" << endl;
    cout << "7. Exit" << endl;
}
