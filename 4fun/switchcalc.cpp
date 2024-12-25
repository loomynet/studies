#include <iostream>

using namespace std;

int main() {
  int action;
  double a, b;

  cout << "=========================== Calculator ==========================="
       << endl;
  cout << "This program performs basic arithmetic operations on two numbers."
       << endl;
  cout << "Here is a list of available operations: " << endl;
  cout << "1 - Addition" << endl
       << "2 - Substraction" << endl
       << "3 - Multiplication" << endl
       << "4 - Division" << endl
       << endl
       << "Choose the operation by entering its index number: ";

  cin >> action;

  cout << "Now, set the variables: ";
  cout << "The first number is: ";
  cin >> a;
  cout << "The second mumber is: ";
  cin >> b;

  switch (action) {
    case 1:
      cout << a << " + " << b << " = " << a + b << endl;
      break;
    case 2:
      cout << a << " - " << b << " = " << a - b << endl;
      break;
    case 3:
      cout << a << " * " << b << " = " << a * b << endl;
      break;
    case 4:
      cout << a << " / " << b << " = " << a / b << endl;
      break;
    default:
      cout << "Error! The index number does not exist!" << endl;
      break;
  }

  return 0;
}