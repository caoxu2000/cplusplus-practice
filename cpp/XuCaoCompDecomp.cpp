// XuCaoCompDecomp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

string compressString(string str) {
    string input;
    string counterAsStr, lastCounterAsStr;
    stringstream ss;
    int count = 0;
    int lastCount;
    char ch = str.at(0);
    string newStr;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str.at(i) == ch && i != str.size() - 1) {
            count++;
        }
        else {
            newStr += ch;
            ss << count;
            ss >> counterAsStr;
            newStr += counterAsStr;
            ss.clear();
            ch = str.at(i);
            count = 1;
        }
    }
    // handle if last two characters are different scenario
    if (str.at(str.size() - 1) != str.at(str.size() - 2)) {
        newStr += ch;
        newStr += "1";
    } else {
        // adding 1 to the last count
        // remove the last count
        for (int j = 0; j < counterAsStr.size(); j++) {
            newStr.pop_back();
        }
        ss << counterAsStr;
        ss >> lastCount;
        lastCount += 1;
        ss.clear();
        ss << lastCount;
        ss >> lastCounterAsStr;
        newStr += lastCounterAsStr;
    }

    return newStr;
}

string decompressString(string str) {
    string decompressedLine;
    char ch;
    int count;
    stringstream ss;
    ss << str;
    while (!ss.eof()) {
        ss.get(ch);
        ss >> count;
        for (int i = 0; i < count; i++) {
            decompressedLine += ch;
        }
    }
    return decompressedLine;
}

int main()
{
    string fileName;
    string myLine;

    cout << "Enter a file name: ";
    getline(cin, fileName);
    
    ifstream inFile(fileName);
    ofstream outFile(fileName + ".comp");
   

    if (inFile && outFile) {
        while (getline(inFile, myLine) && inFile) {
            outFile << compressString(myLine) << endl;
        }
        
        inFile.close();
        outFile.close();
        cout << "File compression done." << endl;
    }
    else {
        cout << "Cannot open the file " << fileName << endl;
    }
    inFile.open(fileName + ".comp");
    outFile.open(fileName + ".decomp");
    
    if (inFile && outFile) {
        while (getline(inFile, myLine) && inFile) {
            outFile << decompressString(myLine) << endl;
        }
        
        inFile.close();
        outFile.close();
        cout << "File decompression done." << endl;
    }
    else {
        cout << "Cannot open the file " << fileName << endl;
    }
    return 0;
}

