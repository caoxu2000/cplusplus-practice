// XuCao0513.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string encrypt(string s, vector<int> keys) {
    string res;
    int key, keyForDigit;
    char c;
    for (int i = 0; i < s.size(); i++) {
        c = tolower(s.at(i));
        key = keys.at(i % keys.size());
        if (isalpha(c)) {
            c = 'a' + (c - 'a' + key) % 26;
        }
        else if (isdigit(c)) {
            keyForDigit = key % 10;
            c = '0' + (c - '0' + keyForDigit) % 10;
        }
        res += c;
    }
    return res;
}

string decrypt(string s, vector<int> keys) {
    string res;
    int key, keyForDigit;
    char c;
    for (int i = 0; i < s.size(); i++) {
        c = s.at(i);
        key = keys.at(i % keys.size());
        if (isalpha(c)) {
            if ((c - 'a' - key) < 0) {
                c = c - key + 26;
            }
            else {
                c = c - key;
            }
        }
        else if (isdigit(c)) {
            keyForDigit = key % 10;
            if ((c - '0' - keyForDigit) < 0) {
                c = c - keyForDigit + 10;
            }
            else {
                c = c - keyForDigit;
            }
        }
        res += c;
    }
    return res;
}

int main()
{
    string input, ss;
    int key1, key2, key3, key4, key5;
    vector<int> keys;

    cout << "Please enter your message: ";
    getline(cin, input);
    cout << "Please enter 5 keys: ";
    getline(cin, ss);
    stringstream(ss) >> key1 >> key2 >> key3 >> key4 >> key5;

    keys.push_back(key1);
    keys.push_back(key2);
    keys.push_back(key3);
    keys.push_back(key4);
    keys.push_back(key5);

    string encryptedMsg = encrypt(input, keys);
    cout << encryptedMsg << endl;
    cout << decrypt(encryptedMsg, keys) << endl;

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
