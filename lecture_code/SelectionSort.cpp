#include <iostream>
#include "SelectionSort.h"
using namespace std;

void selectionSort(double [], int);
void printArray(double list[], int arraySize); // function prototype

int main()
{
  double list[] = {2, 9, 5, 4, 8, 1, 6};
  selectionSort(list, 7);

  printArray(list, 7);
  return 0;
}

void printArray(double list[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    cout << list[i] <<  " ";
  }
}
