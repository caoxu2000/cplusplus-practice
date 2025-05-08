// XuCaoLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Player {
    string name;
    int number;
    int points = 0;
    void setName(string aName) {
        name = aName;
    }
    void setNumber(int aNum) {
        number = aNum;
    };
    string getName() {
        return name;
    };
    int getNumber() {
        return number;
    };
    int getPoints() {
        return points;
    };
    void print(void);
    void addPoints(int p);
};

void Player::print() {
    cout << "Player's name is " << name << endl;
    cout << "Player's number is " << number << endl;
    cout << "Player's score is " << points << endl;
}

void Player::addPoints(int pts) {
    points += pts;
}

int main()
{
    int size = 3;
    vector<Player> playerList(size);
    string input;
    string name;
    int number, points;
    unsigned int i = 0;
    int sum = 0;
    Player vipPlayer;

    while (i < size) {
        cout << "Please enter each play's name, number, points scored: ";
        getline(cin, input);
        stringstream SS(input);
        SS >> name >> number >> points;
        playerList.at(i).setName(name);
        playerList.at(i).setNumber(number);
        playerList.at(i).addPoints(points);
        i++;
        SS.clear();
        name = "";
        number = 0;
        points = 0;
    }
    vipPlayer = playerList.at(0);
    for (i = 0; i < size; i++) {
        playerList.at(i).print();
        sum += playerList.at(i).getPoints();
        if (playerList.at(i).getPoints() > vipPlayer.getPoints()) {
            vipPlayer = playerList.at(i);
        }
    }

    cout << "The total points earned by the team is " << sum << endl;
    cout << "The name of the player who earned the most points is " << vipPlayer.getName() << " and his/her's number is " << vipPlayer.getNumber() << endl;

    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
