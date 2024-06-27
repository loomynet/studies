#include <iostream>

using namespace std;

int main() 
{

	int stnr = 84816;
	int taskvcount = 16;
	int tasknr = stnr % taskvcount;

	cout << tasknr;



	return 0;
}