#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

string getWeekday(int year) {
    int totalDays = 0;
    for (int y = 1900; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    string weekdays[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    return weekdays[totalDays % 7];
}

int main() {
    int year;
    cout << "Enter a year: ";
    cin >> year;

    cout << "January 1st, " << year << " is a " << getWeekday(year) << endl;
    return 0;
}
