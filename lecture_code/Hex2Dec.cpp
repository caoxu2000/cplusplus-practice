#include <iostream>
#include <string>
#include <cctype>
using namespace std;



int hex2Dec(const string& hex)
{
  int decimalValue = 0;
  for (unsigned i = 0; i < hex.size(); i++)
    decimalValue = decimalValue * 16 + hexCharToDecimal(hex[i]);

  return decimalValue;
}

int hexCharToDecimal(char ch)
{
  ch = toupper(ch); // Change it to uppercase
  if (ch >= 'A' && ch <= 'F')
    return 10 + ch - 'A';
  else // ch is '0', '1', ..., or '9'
    return ch - '0';
}



int main()
{
  // Prompt the user to enter a hex number as a string
  cout << "Enter a hex number: ";
  string hex;
  cin >> hex;

  cout << "The decimal value for hex number " << hex
    << " is " <<  hex2Dec(hex) << endl;

  return 0;
}