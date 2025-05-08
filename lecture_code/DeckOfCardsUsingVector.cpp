#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const int NUMBER_OF_CARDS = 52;

void displayRank(int rank)
{
  if (rank == 0)
    cout << "Ace of ";
  else if (rank == 10)
    cout << "Jack of ";
  else if (rank == 11)
    cout << "Queen of ";
  else if (rank == 12)
    cout << "King of ";
  else
    cout << rank << " of ";
}

void displaySuit(int suit)
{
  if (suit == 0)
    cout << "Clubs" << endl;
  else if (suit == 1)
    cout << "Diamonds" << endl;
  else if (suit == 2)
    cout << "Hearts" << endl;
  else if (suit == 3)
    cout << "Spades" << endl;
}

int main()
{
  vector<int> deck(NUMBER_OF_CARDS);

  // Initialize cards
  for (int i = 0; i < NUMBER_OF_CARDS; i++)
    deck[i] = i;

  // Shuffle the cards
  srand(time(0));
  for (int i = 0; i < NUMBER_OF_CARDS; i++)
  {
    // Generate an index randomly
    int index = rand() % NUMBER_OF_CARDS;
    int temp = deck[i];
    deck[i] = deck[index];
    deck[index] = temp;
  }

  // Display the first four cards
  for (int i = 0; i < 4; i++)
  {
    displayRank(deck[i] % 13);
    displaySuit(deck[i] / 13);
  }

  return 0;
}
