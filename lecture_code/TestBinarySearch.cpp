#include <iostream>
#include "BinarySearch.h"
using namespace std;

int main()
{
  const int listSize = 8;

  int list[] = {3, 4, 7, 10, 15, 19, 40, 50};

  cout << binarySearch(list, 11, listSize);

  return 0;
}
