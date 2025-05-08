#include <iostream>
#include "Course.h"
#include "Student.h"

Student::Student(string name, int id)
{
    Name = name;
    Id = id;
    classesEnrolled = nullptr;
    enrolledClassCount = 0;
}

void Student::AddCourse(const Course &c)
{
    enrolledClassCount++;
    if (classesEnrolled == nullptr)
    {
        classesEnrolled = new Course[enrolledClassCount];
        classesEnrolled[0] = c;    
    }
    else 
    {
        Course *oldClasses = classesEnrolled;
        classesEnrolled = new Course[enrolledClassCount]();
        for (int i = 0; i < enrolledClassCount-2; i++)
            classesEnrolled[i] = oldClasses[i];
        
        classesEnrolled[enrolledClassCount-1] = c;
        delete []oldClasses;
    }  
}

void Student::Print() const
{
    cout << "Student : " << Id << " - " << Name << " Course count: " << enrolledClassCount << endl;
    for (int i = 0; i < enrolledClassCount; i++)
    {
        classesEnrolled[i].print();
    }

    cout << "-----------------------------------------------------------------------" << endl;
}  