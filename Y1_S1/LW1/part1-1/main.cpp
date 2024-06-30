#include <iostream>

using namespace std;

int main()
{
	double width;
	double height;
	double res;

	cout << "This program calculates rectangle area, please, enter input data:" << endl;
	cout << endl << "Rectange width (cm) is: ";
	cin >> width;
	cout << endl << "Rectangle height (cm) is: ";
	cin >> height;

	res = width * height;

	cout << endl << "Area of the rectangle is: " << res << " sq.cm" << endl;

	return 0;

}