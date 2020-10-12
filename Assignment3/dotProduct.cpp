#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

double dotProfuct(float a[], float b[], int length)
{
	double result = 0;
	for (int i = 0; i < length; i++)
	{
		result = result + a[i] * b[i];
	}
	return result;
}

int main()
{
	/* This part is for user to input */

	//cout << "Please input the size of the vectors: ";
	//int n = 0;
	//cin >> n;

	//while (n == 0)
	//{
	//	cin.clear();
	//	cin.ignore();
	//	cin >> n;
	//}


	//float* a = new float[n];
	//float* b = new float[n];

	//cout << "Please input the first vector:" << endl;

	//float input = 0;
	//for (int i = 0; i < n; i++)
	//{
	//	cin >> input;
	//	while (input == 0)
	//	{
	//		cin.clear();
	//		cin.ignore();
	//		cin >> input;
	//	}
	//	a[i] = input;
	//	input = 0;
	//}

	//cout << "please input the second vector:" << endl;

	//for (int i = 0; i < n; i++)
	//{
	//	cin >> input;
	//	while (input == 0)
	//	{
	//		cin.clear();
	//		cin.ignore();
	//		cin >> input;
	//	}
	//	b[i] = input;
	//	input = 0;
	//}
	
	/* End of user input part */

	/* This part is just to test, it generats 200M elements */

	int n = 0;

	n = 200000000;

	float* a = new float[n];
	float* b = new float[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() / double(RAND_MAX);
		b[i] = rand() / double(RAND_MAX);
	}

	/* End of test part */

	auto start = chrono::steady_clock::now();
	double result = dotProfuct(a, b, n);
	auto end = chrono::steady_clock::now();

	delete[] a;
	delete[] b;


	cout << "The dot product of the two vectors is " << result << endl;
	cout
		<< "The calculation took "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count() << "μs ≈ "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms ≈ "
		<< chrono::duration_cast<chrono::seconds>(end - start).count() << "s.\n";

	return 0;
}
