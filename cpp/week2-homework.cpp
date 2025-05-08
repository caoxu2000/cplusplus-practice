// This program will read in a group of test scores (positive integers from 1 to 100)
// from the keyboard and then calculate and output the average score
// as well as the highest and lowest score. There will be a maximum of 100 scores.

// Xu Cao

#include <iostream>
#include <fstream>
using namespace std;

typedef int GradeType[100];


float findAverage(const GradeType, int); // finds average of all grades
int findHighest (const GradeType, int); // finds highest of all grades
int findLowest (const GradeType, int); // finds lowest of all grades

int main()

{
    GradeType grades;    // the array holding the grades.
    int numberOfGrades;    // the number of grades read.
    int pos = 0; // index of the array

    float avgOfGrades;    // contains the average of the grades.
    int highestGrade;    // contains the highest grade.
    int lowestGrade;    // contains the lowest grade.
    
    
    string fileName, output;
    string myLine;
    
    cout << "Enter a file name: ";
    getline(cin, fileName);
    while(true) {
        if (fileName == "Data.txt") {
            break;
        }
        else {
            cout << "File not found. Please enter the file name again: ";
            getline(cin, fileName);
        }
    }
    
    ifstream inFile(fileName);
    output = "average.txt";
    ofstream outFile(output);
    
    if (inFile && outFile) {
        while (getline(inFile, myLine) && inFile) {
            grades[pos++] = stoi(myLine);
        }
        numberOfGrades = pos;

        avgOfGrades = findAverage(grades, numberOfGrades);
        outFile << "The average of all the grades is " << avgOfGrades << endl;
        
        inFile.close();
        cout << "Read In Grades From File Done." << endl;
        outFile.close();
        cout << "Output average grade to average.txt" << endl;
    }
    else {
        cout << "Cannot open the file " << fileName << endl;
    }

    return 0;
}

//********************************************************************************
//    findAverage
//
// task:    This function receives an array of integers and its size.
//    It finds and returns the average of the numbers in the array
// data in:    array of floating point numbers
// data returned: average of the numbers in the array
//
//********************************************************************************

float findAverage (const GradeType array, int size)
{

    float sum = 0;    // holds the sum of all the numbers
    for (int pos = 0; pos < size; pos++) {
        sum = sum + array[pos];
    }
    return (sum / size); //returns the average

}
