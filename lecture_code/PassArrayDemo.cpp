#include <iostream>
using namespace std;

const int ARRAY_SIZE = 5;


void printArray(int list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] <<  " ";
  }
}



int main()
{
  int numbers[ARRAY_SIZE] = {1, 4, 3, 6, 8};
  printArray(numbers, ARRAY_SIZE);

  return 0;
}

