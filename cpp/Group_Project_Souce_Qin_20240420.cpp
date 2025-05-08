#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <vector>
#include <ctype.h>
#include <stdlib.h>

using namespace std;


void drawGallow(int wrongGuessCount) {// display picture based on wrong guess count
	//CHECK FORMATTING
	switch (wrongGuessCount) {
		case 1:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |    " << endl
			<< "   |   " << endl
			<< "   |" << endl
			<< "  ============" << endl << endl;
			break;
		case 2:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |    |   " << endl
			<< "   |" << endl
			<< "   |" << endl
			<< "  ============" << endl << endl;
			break;
		case 3:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |   /|   " << endl
			<< "   |" << endl
			<< "   |" << endl
			<< "  ============" << endl << endl;
			break;
		case 4:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |   /|\\   " << endl
			<< "   |" << endl
			<< "   |" << endl
			<< "  ============" << endl << endl;
			break;
		case 5:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |   /|\\   " << endl
			<< "   |   /   " << endl
			<< "   |" << endl
			<< "  ============" << endl << endl;
			break;
		case 6:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |    O     " << endl
			<< "   |   /|\\   " << endl
			<< "   |   / \\   " << endl
			<< "   |Your Dead " << endl
			<< "  ============" << endl << endl;
			break;
		default:
			cout << endl << endl
			<< "   +----+     " << endl
			<< "   |    |     " << endl
			<< "   |         " << endl
			<< "   |      " << endl
			<< "   |     " << endl
			<< "   |" << endl
			<< "  ============" << endl << endl;
	}
	return;
}

string selectSecret() { //read file; choose word
	string wordList = "CommonWords.txt";
	ifstream inputFile (wordList);//open file
	string currLine;
	int wordCount = 0;
	string word;


	if (!inputFile) {
		cout << "Error opening file" << endl;
	}
	else {
		while (getline(inputFile, currLine)) {
			wordCount++; //count lines
		}

		random_device rd;
		default_random_engine generator(rd());
		uniform_int_distribution<int> distribution(1, wordCount);

		int wordChoice = distribution(generator); //get random word in list

		inputFile.clear();
		inputFile.seekg(0); //back to start

		for (int i = 0; i < wordChoice; i++) {
			getline(inputFile, word);
		}
		inputFile.close();
	}
	return word;
}

bool validation(const string guess, const string wrongLetters, const string guessState) {
	bool valid = false;
	char temp;
	stringstream(guess) >> temp;
	if (guess.length() == 1 && isalpha(temp)) {//if char and only one char
		if (wrongLetters.find(temp) == string::npos && guessState.find(temp) == string::npos){ //and not already guessed
			valid = true; //its a valid guess
		}
		else {
			cout << "You have already guessed that letter. Choose again." << endl;
		}
	}

	return valid;
}

int guess(string& guessState, const string word, string& wrongLetters){//take inp and call validation func
	string letter;
	int wrongGuessCount = 0;
	int letterPos = 0;
	char temp;

	do {//take the guess
		cout << "Guess a letter." << endl;
		getline(cin, letter);
	} while (!validation(letter, wrongLetters, guessState));//but only if its valid

	stringstream(letter) >> temp;
	temp = tolower(temp);

	if (word.find(temp) == string::npos) {//it doesnt exist in string, increment and add the bad guess to wrong Letters
		wrongGuessCount++;
		wrongLetters.push_back(temp);
	}
	else { //if it exists update the guessState
		for (int i = 0; i < word.length(); ++i) {
			if (word.at(i) == temp) {
				guessState.at(i) = temp;
			}
		}
	}
	return wrongGuessCount;
}


void printGameState(int& wrongGuessCount, string guessState, string missedLetters, string word) {//Display function
	system("clear");//clear previous write
	drawGallow(wrongGuessCount); //prints top part
	cout << "Missed letters:" << missedLetters << endl;
	for (int i = 0; i < guessState.length(); ++i) {//prints the _ _ _
	    cout << guessState.at(i) << ' ';
	}
	cout << endl;

	if (guessState == word) {//prints the winning message
	    cout << "You win! You've got the correct word!" << endl;
	}
}

bool gameOver(const int wrongGuessCount, const string guessState, const string word) {//is the game over
  const int NUM_WRONG_TRIES = 6; // number of wrong tries in the game
	bool isGameOver = false;
	if (NUM_WRONG_TRIES == wrongGuessCount) {//if user has reached number of wrong tries
		isGameOver = true;//the game is over
	}
	else if (guessState == word) {// if user has guessed all the correct letters in the word
	    isGameOver = true;//the game is over
	}
	return isGameOver;
}

int main() {
	int wrongGuessCount = 0;
	string word;
	int num = 0;
	string wrongLetters;

	word = selectSecret(); //pick a rand word
	num = word.length(); //get length

	string guessState(num, '_'); //init guessState var to all _

	do {//main game loop
		printGameState(wrongGuessCount,guessState,wrongLetters, word); //print the picture
		wrongGuessCount += guess(guessState, word,wrongLetters); //take the input and update counter
	} while (!gameOver(wrongGuessCount, guessState, word));

	printGameState(wrongGuessCount, guessState, wrongLetters, word);//print dead screen

	cout << "Do you want to play again? (Y or N)?" << endl;
	getline(cin, word);
	if ((word == "Y") || (word == "y")){
		main();
	}

	return 0;
}
