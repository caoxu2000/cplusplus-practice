
#include <iostream>
#include <chrono>
#include <string>
using namespace std;

/*
Convert the two structs Student and Department into classes and identify which function
should go to which class and write the prototype in the class. Provide appropriate 
access modifiers to each of the variables and functions. If you think some function(s) do not belong
to any class then provide explanation.
*/
struct Student {
	int Id;
	string FirstName;
    string LastName;
	string City;
	char Gender;
	int Age;
	float GPA;
};

struct Department {
    string DeptName;
    string DeptId;
};

int main()
{
}

string GetFullName(Student s)
{
    return s.FirstName + " " + s.LastName;
}

bool IsStudentHonorStudent(Student s)
{
    return s.GPA > 3.7;
}

string GetDeparmentName(Department d)
{
    return d.DeptName;
}

string GetDeparmentID(Department d)
{
    return d.DeptId;
}

void SelectionSort(Student students[], int count)
{
    
}

void PrintStudent(Student s)
{
    cout << GetFullName(s) << endl;
}
