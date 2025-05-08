// This program performs a linear search on a character array

// Xu Cao

#include <iostream>
using namespace std;

int searchList(int[], int, int); // function prototype

const int SIZE = 8;

int main()
{
    int nums[SIZE] = {3, 6, -19, 5, 5, 0, -2, 99};
    int found;
    int num;
    string yesOrNo;
    bool toContinue = true;
    
    do {
        cout << "Enter an integer to search for: " << endl;
        cin >> num;

        found = searchList(nums, SIZE, num);

        if (found == -1)
            cout << "The integer " << num
                 << " was not found in the list" << endl;
        else
            cout << "The integer " << num << " is in the " << found + 1
                 << " position of the list" << endl;
        cout << "Do you want to continue? ";
        cin >> yesOrNo;
        
        if (yesOrNo == "n") {
            toContinue = false;
        }
    } while(toContinue);

    return 0;
}

//*******************************************************************
//    searchList
//
//  task:           This searches an array for a particular value
//  data in:       List of values in an array, the number of
//                   elements in the array, and the value searched for
//                   in the array
//  data returned: Position in the array of the value or -1 if value
//                   not found
//
//*******************************************************************

int searchList(int List[], int numElems, int value)
{
    for (int count = 0; count <= numElems - 1; count++)
    {
        if (List[count] == value)
            // each array entry is checked to see if it contains
            // the desired value.
            return count;
            // if the desired value is found, the array subscript
            // count is returned to indicate the location in the array
    }

    return -1;    // if the value is not found, -1 is returned
}
