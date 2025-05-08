#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;

class Rectangle {
    private:
        double length, width;
        char *description;
        Rectangle(string);
    public:
        double getWidth() const {return width;}
        double getLength() const {return length;}

        void setWidth(double w) { width = w;}
        void setLength(double l) {length = l;}

        Rectangle(double, double);
        Rectangle(string, string);
        Rectangle(double, double, string);

        bool IsSquare();
        ~Rectangle();
};



#endif