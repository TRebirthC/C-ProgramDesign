#include <iostream>
using namespace std;


template <typename T>
T max5(T a[])
{
	T max;
	max = a[0];
	for (int i = 1; i < 5; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	double b[] = { 1.1,2.0,3.0,4.0,5.5 };
	cout << "Max int = " << max5(a) << endl;
	cout << "Max double = " << max5(b) << endl;
	return 0;
}
