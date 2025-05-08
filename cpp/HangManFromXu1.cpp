#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <vector>

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
    vector<int> wordIndex;


    if (!inputFile) {
        cout << "Error opening file" << endl;
    }
    else {
        while (getline(inputFile, currLine)) {
            wordCount++; //count lines
            wordIndex.push_back(wordCount);
        }
        
        random_device rd; //ensures new set of numbers every time
        default_random_engine generator(rd());
        uniform_int_distribution<int> distribution(1, wordCount);

        int wordChoice = distribution(generator);
        inputFile.clear();
        inputFile.seekg(wordIndex.at(wordChoice));
        getline(inputFile, word);
        
        inputFile.close();
    }
    return word;
}

int guessValidation(vector<char>& guess, string word) {
    char letter;
    string temp;
    int wrongGuessCount = 0;
    unsigned long letterPos = 0;
    
    cout << "Guess a letter." << endl;
    getline(cin, temp);
    stringstream(temp) >> letter;

    if (word.find(letter) != string::npos) {
        wrongGuessCount++;
    }
    else {
        letterPos = word.find(letter);

    }

    return wrongGuessCount;
}

bool gameOver() {
    return true;
}

void printGameState() {
    int num = 0;
    cout << "You have played " << num << " times." << endl;
}

void printWordSoFar(const string word) {
    string input, currWord = word, printOutWord;
    char letter;
    int wrongGuessCount = 0;
    unsigned long letterPos, num = 0;
    
    do {
        cout << "Guess a letter." << endl;
        getline(cin, input);
        stringstream(input) >> letter;
        wrongGuessCount++;
    } while (currWord.find(letter) == string::npos);
    
    cout << "the number of wrong guesses: " << wrongGuessCount << endl;
    
    num = word.length();
    vector<char> guess(num, '_');
    
    while (currWord.find(letter) != string::npos) {
        letterPos = currWord.find(letter);
        guess.at(letterPos) = letter;
        currWord.replace(letterPos, 1, "*");
    }
    
    for (int i = 0; i < num; i++) {
        printOutWord += guess.at(i);
    }
    cout << printOutWord << endl;
}

int main() {
//    int wrongGuessCount = 0;
//    string word;
//    unsigned long num = 0;
//
//    word = selectSecret();
//    num = word.length();
//    vector<char> guess(num, '_');
//
//    do {
//        printGameState();
//        wrongGuessCount = guessValidation(guess, word);
//        drawGallow(wrongGuessCount);
//    } while (!gameOver());
    string word = "aaronera";
    printWordSoFar(word);
    return 0;
}
