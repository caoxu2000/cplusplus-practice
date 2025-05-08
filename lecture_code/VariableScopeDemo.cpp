#include <iostream>
using namespace std;




int y; // Global variable, default to 0

void t1()
{
  int x = 1;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;
  x++;
  y++;
}

void t2()
{
  int x = 1;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;
}

int main()
{
  t1();
  t2();

  return 0;
}
