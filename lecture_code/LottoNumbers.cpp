#include <iostream>
using namespace std;

int main()
{
  bool isCovered[99];
  int number; // number read from a file

  // Initialize the array
  for (int i = 0; i < 99; i++)
    isCovered[i] = false;

  // Read each number and mark its corresponding element covered
  cin >> number;
  while (number != 0)
  {
    isCovered[number - 1] = true;
    cin >> number;
  }

  // Check if all covered
  bool allCovered = true; // Assume all covered initially
  for (int i = 0; i < 99; i++)
    if (!isCovered[i]) 
    {
       allCovered = false; // Find one number not covered
       break;
    }

  // Display result
  if (allCovered)
    cout << "The tickets cover all numbers" << endl;
  else
    cout << "The tickets don't cover all numbers" << endl;

  return 0;
}
