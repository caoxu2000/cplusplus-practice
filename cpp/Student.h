#ifndef STUDENT
#define STUDENT
#include <iostream>
#include "Course.h"
using namespace std;

class Student 
{
    private:
        string Name;
        int Id;
        Course *classesEnrolled;
        int enrolledClassCount;
    
    public:
        Student(string, int);
        void AddCourse(const Course &c);
        void Print() const;
};
#endif