#include <iostream>
using namespace std;

int main() {
  int symbolCount;
  char symbol;
  int lineType;

  cout << "This program makes vartical or horizontal lines." << endl;
  cout << "Input symbol count: ";
  cin >> symbolCount;
  cout << endl << "Choose the symbol: ";
  cin >> symbol;
  cout << endl
       << "Choose the line type:" << endl
       << "1 - horizontal line" << endl
       << "2 - vertical line" << endl;
  cin >> lineType;

  if (lineType == 1) {
    while (symbolCount > 0) {
      cout << symbol;
      symbolCount--;
    }
  }

  else if (lineType == 2) {
    while (symbolCount > 0) {
      cout << symbol << endl;
      symbolCount--;
    }
  }

  else {
    cout << "Error! The line type identifier is incorrect! Restart the program."
         << endl;
  }

  return 0;
}