#include <iostream>
#include <math.h> 

using namespace std;

int main() 
{
	//No.16

	double x;

	cout << "Please, set a variable x: ";
	cin >> x;

	double zone = (pow(x, 2) + 2 * x - 3 + (x + 1) * sqrt(pow(x, 2) - 9)) / (pow(x, 2) - 2 * x - 3 + (x - 1) * sqrt(pow(x, 2) - 9));
	double ztwo =  sqrt((x+3)/(x-3)) ;

	cout << endl << "z1 is equal to: " << zone << endl;
	cout << endl << "z2 is equal to: " << ztwo << endl;

	return 0;
}