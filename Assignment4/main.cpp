#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	float* da = new float[2 * 2 + 1];
	da[0] = 1;
	da[1] = 2;
	da[2] = 1;
	da[3] = 2;
	da[4] = 0;
	Matrix a(2, 2, da);
	cout << a;
	Matrix b(a);
	cout << a;
	cout << b;
	Matrix c = b;
	cout << c;
	Matrix d = 3 * c;
	cout << d;
	Matrix e = d * 6;
	cout << e;
	a = b * c;
	cout << a;
	
	return 0;
}
