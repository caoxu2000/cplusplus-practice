#include "Rectangle.h"
#include <cstring>
#include <string>
Rectangle::Rectangle(string d)
{
    description = new char[d.length() + 1];
    strcpy(description, d.c_str());
    cout << description << endl;
}

Rectangle::Rectangle(double w, double l) : Rectangle("Default description for rectangle ")
{
    width = w; 
    length = l;
}

Rectangle::Rectangle(string w, string l) : Rectangle("Default description for rectangle ")
{
    width = stod(w); 
    length = stod(l);
}

Rectangle::Rectangle(double w, double l, string d): Rectangle(d)
{
    width = w; 
    length = l;
}

bool Rectangle::IsSquare()
{
    return (length == width);
}

Rectangle::~Rectangle()
{
    cout << "Destructor called to destroy " << description << endl;
    delete [] description;
}