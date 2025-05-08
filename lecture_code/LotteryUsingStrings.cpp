#include <iostream>
#include <string> // for using strings
#include <ctime> // for time function
#include <cstdlib> // for rand and srand functions
using namespace std;

int main()
{
  string lottery;
  srand(time(0));
  int digit = rand() % 10; // Generate first digit
  lottery += static_cast<char>(digit + '0'); 
  digit = rand() % 10; // Generate second digit
  lottery += static_cast<char>(digit + '0');

  // Prompt the user to enter a guess
  cout << "Enter your lottery pick (two digits): ";
  string guess;
  cin >> guess;

  cout << "The lottery number is " << lottery << endl;

  // Check the guess
  if (guess == lottery)
    cout << "Exact match: you win $10,000" << endl;
  else if (guess[1] == lottery[0] && guess[0] == lottery[1])
    cout << "Match all digits: you win $3,000" << endl;
  else if (guess[0] == lottery[0] || guess[0] == lottery[1]
        || guess[1] == lottery[0] || guess[1] == lottery[1])
    cout << "Match one digit: you win $1,000" << endl;
  else
    cout << "Sorry, no match" << endl;

  return 0;
}