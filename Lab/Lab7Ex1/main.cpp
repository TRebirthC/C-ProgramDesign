#include <iostream>
#include "candybar.h"
using namespace std;

int main()
{
	CandyBar* cb = new CandyBar;
	cout << "Call the set function of Passing by pointer:" << endl;
	setCandyBar(cb);

	cout << "Call the show function of Passing by pointer:" << endl;
	showCandyBar(cb);

	CandyBar& cb2 = *cb;
	cout << "Call the set function of Passing by reference:" << endl;
	setCandyBar(cb2);

	cout << "Call the show function of Passing by reference:" << endl;
	showCandyBar(cb2);

	delete cb;
	return 0;
}
