// XuCao031824.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    fstream inout;

    inout.open("murphy.txt", ios::in);
    string name;

    while (!inout.eof()) // Continue if not end of file
    {
        inout >> name;
        cout << name << endl;
    }

    inout.close();

    return 0;
    fstream inout;

    // Create a file
    inout.open("city.txt", ios::out | ios::app);

    // Write cities
    inout << "Dallas" << " " << "Houston" << " " << "Atlanta" << " ";

    inout.close();



    string city;

    // Open the file
    inout.open("city.txt", ios::in);
    while (!inout.eof()) // Continue if not end of file
    {
        inout >> city;
        cout << city << " ";
    }

    inout.close();

    return 0;

    string input;		// To hold file input
    fstream nameFile;	// File stream object

    // Open the file in input mode.
    nameFile.open("names2.txt", ios::in);

    // If the file was successfully opened, continue.
    if (nameFile)
    {
        
        while (getline(nameFile, input, '$'))
        {
            // Read an item from the file.

           // While the last read operation 
           // was successful, continue.
            // Display the last item read.
            cout << input << endl;

            // Read the next item.
            
        }
   
        nameFile.close();
    }
    else
    {
        cout << "ERROR: Cannot open file.\n";
    }
    
    
    string fileName;		// To hold the file name
    char ch;			// To hold a character

    ifstream inFile;		// Input file
    ofstream outFile("out.txt"); // Open a file for output.

    // Get the input file name.
    cout << "Enter a file name: ";
    getline(cin, fileName);

    // Open the file for input.
    inFile.open(fileName);

    // If the input file opened successfully, continue.
    if (inFile && outFile)
    {

        // While the last read operation was
        // successful, continue.
        while (inFile.get(ch) && inFile)
        {
            // Write uppercase char to file 2.
            outFile.put(toupper(ch));
        }

        // Close the two files.
        inFile.close();
        outFile.close();
        cout << "File conversion done.\n";
    }
    else
        cout << "Cannot open " << fileName << endl;
    return 0;
}

