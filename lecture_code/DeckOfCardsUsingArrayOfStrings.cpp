#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int NUMBER_OF_CARDS = 52;

// Shuffle the elements in an array
void shuffle(int list[], int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    // Generate an index randomly
    int index = rand() % NUMBER_OF_CARDS;
    int temp = list[i];
    list[i] = list[index];
    list[index] = temp;
  }
}

int main()
{
  int deck[NUMBER_OF_CARDS];
  const string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
  const string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
    "9", "10", "Jack", "Queen", "King"};

  // Initialize cards
  for (int i = 0; i < NUMBER_OF_CARDS; i++)
    deck[i] = i;

  // Shuffle the cards
  shuffle(deck, NUMBER_OF_CARDS);

  // Display the first four cards
  for (int i = 0; i < 4; i++)
  {
    cout << ranks[deck[i] % 13] << " of "
      << suits[deck[i] / 13] << endl;
  }

  return 0;
}
