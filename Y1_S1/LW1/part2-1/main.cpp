#include <iostream>

using namespace std;

int main () 
{

double a;
double b;
double square_a;
double square_b;
double add;
double sub;
double multiplication;
double division;

cout << "Enter the first number: ";
cin >> a;
cout << "Enter the second number: ";
cin >> b;

square_a = a * a;
square_b = b * b;
add = a + b;
sub = a - b;
multiplication = a * b;
division = a / b;

cout << endl << "Square of " << a << " " << "is" << " " << square_a << endl;
cout << endl << "Square of " << b << " " << "is" << " " << square_b << endl;
cout << endl << a << " + " << b << " = " << add << endl;
cout << endl << a << " - " << b << " = " << sub << endl;
cout << endl << a << " * " << b << " = " << multiplication << endl;
cout << endl << a << " / " << b << " = " << division << endl;

return 0;

}