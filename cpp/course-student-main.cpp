// This program demonstrates the Course class.
#include "Course.h"
#include "Student.h"
int main()
{
   // Create a Course object.
   Course csCourse1("CS1 Fundamentals", // Course name
     "Kramer", "Shawn", "CS3010",       // Instructor info
     "Starting Out with C++", "Gaddis", // Textbook title and author
     "Addison-Wesley");                 // Textbook publisher
                   
    Course csCourse2("CS2 Fundamentals", // Course name
     "John", "Smith", "CS3011",       // Instructor info
     "Advanced Starting Out with C++", "Gaddis", // Textbook title and author
     "Addison-Wesley");                 // Textbook publisher

    Student s("Student 1", 1);
    s.AddCourse(csCourse1);
    s.AddCourse(csCourse2);

   // Display the course info.
   csCourse1.print();
   csCourse2.print();
   
   s.Print();
   return 0;
} 