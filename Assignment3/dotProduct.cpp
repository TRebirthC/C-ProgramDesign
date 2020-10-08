#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;

double dotProfuct(vector<float> a, vector<float> b)
{
	double result = 0;
	for (int i = 0; i < a.size(); i++)
	{
		result = result + a[i] * b[i];
	}
	return result;
}

int main()
{
	cout << "Please input the size of the vectors: ";
	int n = 0;
	cin >> n;
	while (n == 0)
	{
		cout << "Your input is illegal, please input the size again: " <<endl;
		cin.clear();
		cin.ignore();
		cin >> n;
	}
	

	vector<float> a;
	vector<float> b;

	cout << "Please input the first vector:" << endl;

	float input = 0;
	for (int i = 0; i < n; i++) 
	{
		cin >> input;
		while (input == 0)
		{
			cout << "Your input is illegal, please input the float again: " << endl;
			cin.clear();
			cin.ignore();
			cin >> input;
		}
		a.push_back(input);
		input = 0;
	}

	cout << "Please input the second vector:" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		while (input == 0)
		{
			cout << "Your input is illegal, please input the float again: " << endl;
			cin.clear();
			cin.ignore();
			cin >> input;
		}
		b.push_back(input);
		input = 0;
	}

	
	auto start = chrono::steady_clock::now();
	double result = dotProfuct(a, b);
	auto end = chrono::steady_clock::now();


	cout << "The dot product of the two vectors is " << result << endl;
	cout
		<< "The calculation took "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count() << "μs ≈ "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms ≈ "
		<< chrono::duration_cast<chrono::seconds>(end - start).count() << "s.\n";

	return 0;
}
