#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string encrypt(string s, vector<int> keys) {
    string res = "";
    int key, keyForDigit;
    char c;
    for (int i = 0; i < s.size(); i++) {
        c = tolower(s.at(i));
        key = keys.at(i % keys.size());
        if (isalpha(c)) {
            c = 'a' + (c + key - 'a') % 26;
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
    string res = "";
    int key, keyForDigit;
    char c;
    for (int i = 0; i < s.size(); i++) {
        c = s.at(i);
        key = keys.at(i % keys.size());
        if (isalpha(c)) {
            if ((c - 'a' - key) < 0) {
                c = c - key + 26;
            } else {
                c = c - key;
            }
        }
        else if (isdigit(c)) {
            keyForDigit = key % 10;
            if ((c - '0' - keyForDigit) < 0) {
                c = c - keyForDigit + 10;
            } else {
                c = c - keyForDigit;
            }
        }
        res += c;
    }
    return res;
}



int main()
{
    string input1, input2, input3, encryptedMsg, decryptedMsg;
    int key, operation;
    bool toContinue = true;
    
    do {
        vector<int> keys;
        cout << "Please enter your message: ";
        getline(cin, input1);
        
        cout << "Please enter your desired keys: ";
        getline(cin, input2);
        stringstream ss(input2);
        while (ss >> key) {
            keys.push_back(key);
        }
        
        cout << "Please enter your desired operation (1. encrypt, 2. decrypt 3. all other numbers: exit): ";
        getline(cin, input3);
        stringstream(input3) >> operation;
        
        encryptedMsg = encrypt(input1, keys);
        decryptedMsg = decrypt(input1, keys);
        
        switch (operation) {
            case 1:
                cout << encryptedMsg << endl;
                break;
            case 2:
                cout << decryptedMsg << endl;
                break;
            default:
                cout << "Good Bye!" << endl;
                toContinue = false;
        
        }
    } while (toContinue);

    return 0;
}
