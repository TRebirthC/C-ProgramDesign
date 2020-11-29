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
	cout << "Matrix a(2, 2, da)" << endl;
	cout << a;
	Matrix b(a);
	cout << "Matrix b(a)" << endl;
	cout << b;
	Matrix c = b;
	cout << "Matrix c = b" << endl;
	cout << c;
	Matrix d = 3 * c;
	cout << "Matrix d = 3 * c" << endl;
	cout << d;
	Matrix e = d * 6;
	cout << "Matrix e = d * 6" << endl;
	cout << e;
	float* df = new float[2 * 3 + 1];
	for (int i = 0; i < 6; i++)
	{
		df[i] = i;
	}
	df[6] = 0;
	Matrix f(2, 3, df);
	cout << "Matrix f(2, 3, df)" << endl;
	cout << f;
	float* dg = new float[2 * 3 + 1];
	for (int i = 0; i < 6; i++)
	{
		dg[i] = 6-i;
	}
	dg[6] = 0;
	Matrix g(3, 2, dg);
	cout << "Matrix g(2, 3, dg)" << endl;
	cout << g;
	a = f * g;
	cout << "a = f * g" << endl;
	cout << a;
	b = g * f;
	cout << "b = g * f" << endl;
	cout << b;
	c = d * g;
	cout << "c = d * g" << endl;
	cout << c;
	
	return 0;
}
