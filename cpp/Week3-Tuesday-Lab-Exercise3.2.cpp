#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// This program uses a structure to hold data about a rectangle
// It calculates the area and perimeter of a box

// Xu Cao

// Fill in code to declare a structure named dimensions that
// contains 2 float members, length and width
struct dimensions {
	float length;
	float width;
};
// Fill in code to declare a structure named rectangle that contains
// 3 members, area, perimeter, and sizes. area and perimeter should be
// floats, whereas sizes should be a dimensions structure variable
struct results {
	float area;
	float perimeter;
};

struct rectangle {
	results res;
	dimensions sizes;
};


results static computeResults(rectangle rect) {
	results res;
	res.area = rect.sizes.length * rect.sizes.width;
	res.perimeter = 2 * (rect.sizes.length + rect.sizes.width);

	return res;
}

int main()
{
	// Fill in code to define a rectangle structure variable named box.
	rectangle box;
	results res;
	cout << "Enter the length of a rectangle: ";

	// Fill in code to read in the length to the appropriate location
	cin >> box.sizes.length;
	cout << "Enter the width of a rectangle: ";

	// Fill in code to read in the width to the appropriate location
	cin >> box.sizes.width;
	cout << endl << endl;

	res = computeResults(box);
	cout << fixed << showpoint << setprecision(2);

	cout << "The area of the rectangle is " << res.area << endl;

	cout << "The perimeter of the rectangle is " << res.perimeter << endl;

	return 0;
}