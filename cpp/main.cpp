#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle r1(10, 20);
    Rectangle r2(5, 5);

    Rectangle *ptr;
    ptr = &r1;

    ptr = new Rectangle(9.9, 10.1, "This should have been square");

    cout << "Is r1 square? " << r1.IsSquare() << endl;
    cout << "Is r2 square? " << r2.IsSquare() << endl;
    cout << "Is ptr square? " << ptr->IsSquare() << endl;

    delete ptr;
}