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
    string counterAsStr;
    stringstream ss;
    int count = 0;
    char ch = str.at(0);
    string newStr;
    for (unsigned int i = 0; i < str.size(); i++) {
        if ((str.at(i) == ch) && i != str.size() - 1) {
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
    // adding the last count
    count += 1;
    ss << count;
    ss >> ch;
    newStr.at(newStr.size() - 1) = ch;

    return newStr;
}

int main()
{
    string fileName("ASCII_ART.txt");
    string myLine;

    ifstream inFile(fileName);
    ofstream outFile("ASCII_ART_comp.txt");
   

    if (inFile && outFile) {
        while (getline(inFile, myLine) && inFile) {
            outFile << compressString(myLine) << endl;
        }

        inFile.close();
        outFile.close();
        cout << "File compression done." << endl;
    }
    else {
        cout << "Cannot open the file" << fileName << endl;
    }

    return 0;
}
