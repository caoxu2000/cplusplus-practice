#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string encrypt(string s, int key) {
    string res = "";
    int keyForDigit;
    for (char c : s) {
        c = tolower(c);
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

string decrypt(string s, int key) {
    string res = "";
    int keyForDigit;
    for (char c : s) {
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

void encryptMessageFile(int key) {
    string currLine, encryptedMsg;
    ifstream inFile("message.txt");
    ofstream outFile("encrypted.txt");
    
    if (inFile && outFile) {
        while (getline(inFile, currLine) && inFile) {
            encryptedMsg = encrypt(currLine, key);
            cout << encryptedMsg << endl;
            outFile << encryptedMsg << endl;
        }
    } else {
        cout << "Cannot open the file message.txt" << endl;
    }
    inFile.close();
    outFile.close();
}

void decryptMessageFile(int key) {
    string currLine, decryptedMsg;
    ifstream inFile("encrypted.txt");
    ofstream outFile("decrypted.txt");
    
    if (inFile && outFile) {
        while (getline(inFile, currLine) && inFile) {
            decryptedMsg = decrypt(currLine, key);
            cout << decryptedMsg << endl;
            outFile << decryptedMsg << endl;
        }
    } else {
        cout << "Cannot open the file encrypted.txt" << endl;
    }
    inFile.close();
    outFile.close();
}

int main()
{
    string input1, input2;
    int key, operation;
    bool toContinue = true;
    
    do {
        cout << "Please enter your desired key: ";
        getline(cin, input1);
        stringstream(input1) >> key;
        
        cout << "Please enter your desired operation (1. encrypt, 2. decrypt 3. all other numbers: exit): ";
        getline(cin, input2);
        stringstream(input2) >> operation;
        
        switch (operation) {
            case 1:
                encryptMessageFile(key);
                break;
            case 2:
                decryptMessageFile(key);
                break;
            default:
                cout << "Good Bye!" << endl;
                toContinue = false;
        
        }
    } while (toContinue);

    return 0;
}
