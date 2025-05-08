#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char s1[25];
  char s2[] = "Texas, USA"; // Let C++ figure out the size of s2
  char s3[] = "Dallas"; // Let C++ figure out the size of s3

  strncpy_s(s1, s2, 19); // Copy s2 to s1
  cout << "The string in s1 is " << s1 << endl;

  cout << "The length of string s1 is " << strlen(s1) << endl;

  strncat(strncat(s1, ", ", 19), s2, 19);

  cout << "The string in s1 is " << s1 << endl;
  cout << "The string in s2 is " << s2 << endl;

  cout << "strcmp(s2, s3) is " << strcmp(s2, s3) << endl;

  // Conversion functions
  cout << atoi("42") + atoi("56") << endl;
  cout << atof("3.5") + atof("5.5") << endl;

  char s[10];
  itoa(42, s, 2); // Radix 2 (binary)
  cout << "42 is " << s << " in binary" << endl;

  itoa(42, s, 10); // Radix 10
  cout << s << endl;

  itoa(42, s, 16); // Radix 16 (hexadecimal)
  cout << "42 is " << s << " in hex" << endl;

  return 0;
}
