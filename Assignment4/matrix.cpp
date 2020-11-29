#include <iostream>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int r, int c, float * d)
{
	row = r;
	column = c;
	d[r * c] ++;
	data = d;
}

Matrix::Matrix(const Matrix& ma)
{
	row = ma.row;
	column = ma.column;
	ma.data[ma.row * ma.column]++;
	data = ma.data;
}

Matrix::~Matrix()
{
	int index = row * column;
	if (data[index] == 1) 
	{
		delete[] data;
	}
	else
	{
		data[index]--;
	}
}

std::ostream& operator<< (std::ostream& os, const Matrix& other)
{
	cout << "row: " << other.row << endl;
	cout << "column: " << other.column << endl;
	for (int i = 0; i < other.row; i++)
	{
		for (int j = 0; j < other.column; j++)
		{
			cout << other.data[i * other.column + j] << " ";
		}
		cout << endl;
	}
	return os;
}

Matrix& Matrix::operator=(const Matrix& ma)
{
	data[row * column]--;
	float* temp = data;
	int index = row * column;
	row = ma.row;
	column = ma.column;
	data = ma.data;
	data[row * column]++;
	if (temp[index] == 0)
	{
		delete[] temp;
	}
	return *this;
}

Matrix operator *(double real, const Matrix& other)
{
	float* data = other.data;
	int row = other.row;
	int column = other.column;
	float* new_data = new float[row * column + 1];
	for (int i = 0; i < row * column; i++)
	{
		new_data[i] = data[i] * real;
	}
	new_data[row * column] = 0;
	return Matrix(row, column, new_data);
}

Matrix operator *(const Matrix& other, double real)
{
	float* data = other.data;
	int row = other.row;
	int column = other.column;
	float* new_data = new float[row * column + 1];
	for (int i = 0; i < row * column; i++)
	{
		new_data[i] = data[i] * real;
	}
	new_data[row * column] = 0;
	return Matrix(row, column, new_data);
}

Matrix Matrix::operator *(const Matrix& other) const
{
	int ra = row;
	int rb = other.row;
	int ca = column;
	int cb = other.column;

	if (ra == 0 | rb == 0 | ca == 0 | cb == 0)
	{
		cout << "The input matrix are illegal." << endl;
		return *this;
	}

	if (ca != rb)
	{
		cout << "The two matrix do not match." << endl;
		return *this;
	}

	float* new_data = new float[ra * cb + 1];
	float* da = data;
	float* db = other.data;

	if (da == 0 | db == 0)
	{
		cout << "The input matrix are illegal." << endl;
		return *this;
	}

	if (ca % 5 == 0)
	{
		float sum = 0;
		for (int i = 0; i < ra; i++)
		{
			for (int j = 0; j < cb; j++)
			{
				sum = 0;
				int x = i * ca;
				int y = j;
				for (int z = 0; z < ca / 5; z++)
				{
					sum = sum + da[x + 5 * z + 0] * db[y + (5 * z + 0) * cb];
					sum = sum + da[x + 5 * z + 1] * db[y + (5 * z + 1) * cb];
					sum = sum + da[x + 5 * z + 2] * db[y + (5 * z + 2) * cb];
					sum = sum + da[x + 5 * z + 3] * db[y + (5 * z + 3) * cb];
					sum = sum + da[x + 5 * z + 4] * db[y + (5 * z + 4) * cb];
				}
				new_data[j * ra + i] = sum;
			}
		}
	}
	else
	{
		float sum = 0;
		for (int i = 0; i < ra; i++)
		{
			for (int j = 0; j < cb; j++)
			{
				sum = 0;
				int x = i * ca;
				int y = j;
				for (int z = 0; z < ca; z++)
				{
					sum = sum + da[x + z] * db[y + z * cb];
				}
				new_data[j * ra + i] = sum;
			}
		}
	}
	new_data[ra * cb] = 0;
	Matrix result(ra, cb, new_data);

	return result;
}
