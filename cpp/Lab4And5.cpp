// This program finds the average time spent programming by a student
// each day over a three day period.

// Xu Cao

#include <iostream>
using namespace std;

int main()
{
    int numStudents, numDays;
    float numHours, total, average;
    int student, day = 0; // these are the counters for the loops

    cout << "This program will find the average number of hours a day"
        << " that a student spent programming over a long weekend" << endl;

    cout << "How many students are there?" << endl;
    cin >> numStudents;

    for (student = 1; student <= numStudents; student++)
    {
        total = 0;
        cout << "Please enter the number of days in a long weekend? " << endl;
        cin >> numDays;

        for (day = 1; day <= numDays; day++)
        {
            cout << "Please enter the number of hours worked by student "
                << student << " on day " << day << "." << endl;
            cin >> numHours;
            total = total + numHours;
        }

        average = total / numDays;

        cout << endl;
        cout << "The average number of hours per day spent programming by "
            << "student " << student << " is " << average
            << endl << endl << endl;
    }
    return 0;
}

