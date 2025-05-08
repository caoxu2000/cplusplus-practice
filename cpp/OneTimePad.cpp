#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;

void encrypt(string originalStr, string padStr, ostream &outFile) {
    bitset<8> oriBits, padBits, cipherBits;
    unsigned long cipherLongInt;
    
    for (int i = 0; i < originalStr.size(); i++) {
        oriBits = static_cast<bitset<8>>(originalStr.at(i));
        padBits = static_cast<bitset<8>>(padStr.at(i));
        cipherBits = oriBits ^ padBits;
        cipherLongInt = cipherBits.to_ulong();
        
        if (cipherLongInt < CHAR_MAX) {
            outFile << cipherLongInt << ' ';
        }
    }
    cout << "File encryption done." << endl;
}

char decrypt(unsigned long uLong, char c) {
    return static_cast<char>((static_cast<bitset<8>>(static_cast<char>(uLong)) ^ static_cast<bitset<8>>(c)).to_ulong());
}



int main()
{
    
    string currLine, oneTimePad, encryptedMsg, message, encryptedFileName = "encrypted.txt", decrptedFileName = "decrpted.txt", dictionaryFileName = "dictionary.txt";
    cout << "Please enter your message: ";
    getline(cin, message);
    
    ifstream inFile(dictionaryFileName);
    ofstream outFile(encryptedFileName);
    
    if (inFile && outFile) {
        int i = 0;
        while (getline(inFile, currLine) && inFile && i < message.size()) {
            currLine.pop_back();
            oneTimePad += currLine;
            i += currLine.size();
        }
        if (i > message.size()) {
            oneTimePad = oneTimePad.substr(0, message.size());
        }
        encrypt(message, oneTimePad, outFile);
        
        inFile.close();
        outFile.close();
    }
    else {
        cout << "Cannot open the file " << endl;
    }
    
    inFile.open(encryptedFileName);
    outFile.open(decrptedFileName);
    currLine = "";
    if (inFile && outFile) {
        string originalMsg;
        while (getline(inFile, currLine) && inFile) {
            unsigned long cipherLongInt;
            stringstream ss(currLine);
            
            for (char c : oneTimePad) {
                ss >> cipherLongInt;
                originalMsg += decrypt(cipherLongInt, c);
            }
        }
        outFile << originalMsg << endl;
        
        inFile.close();
        outFile.close();
        cout << "File decryption done." << endl;
        
    }
    else {
        cout << "Cannot open the file " << endl;
    }
    return 0;
}
