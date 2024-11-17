#include <iostream>
#include <cstring> 
using namespace std;

void countLetters(const char* str, int& capitalCount, int& smallCount);
void countLetters(const string& str, int& capitalCount, int& smallCount);

int main() {
    int studentCode = 84816;
    int taskVarCount = 25;
    cout << "Individual task number: " << studentCode % taskVarCount << endl;

    // User input
    const int ARRAY_SIZE = 3;
    char cStringArray[ARRAY_SIZE][256];
    string stringArray[ARRAY_SIZE];

    // Input loop for C-strings
    cout << "Enter " << ARRAY_SIZE << " strings:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cin.getline(cStringArray[i], 256);
        stringArray[i] = cStringArray[i];
    }

    // Output for C-strings
    cout << "\nResults for C-strings:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int capitalCount = 0, smallCount = 0;
        countLetters(cStringArray[i], capitalCount, smallCount);
        cout << "String: " << cStringArray[i] << ", Capitals: " << capitalCount << ", Smalls: " << smallCount << endl;
    }

    // Output for std::string
    cout << "\nResults for std::string:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int capitalCount = 0, smallCount = 0;
        countLetters(stringArray[i], capitalCount, smallCount);
        cout << "String: " << stringArray[i] << ", Capitals: " << capitalCount << ", Smalls: " << smallCount << endl;
    }

    return 0;
}

// Functions
void countLetters(const char* str, int& capitalCount, int& smallCount) {
    capitalCount = 0;
    smallCount = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') capitalCount++;
        else if (str[i] >= 'a' && str[i] <= 'z') smallCount++;
    }
}

void countLetters(const string& str, int& capitalCount, int& smallCount) {
    capitalCount = 0;
    smallCount = 0;
    for (char ch : str) {
        if (ch >= 'A' && ch <= 'Z') capitalCount++;
        else if (ch >= 'a' && ch <= 'z') smallCount++;
    }
}
