#include <iostream>
using namespace std;

int main()
{
    int ken = 1000;

    while (ken>0)
    {
        cout << ken << "-7=";
        ken -= 7;
        cout << ken << endl;
    }

    return 0;
}