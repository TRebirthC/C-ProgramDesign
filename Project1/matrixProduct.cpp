#include<iostream>
#include<cblas.h>
using namespace std;

struct Matrix
{
	int row;
	int column;
	float *data;
};

Matrix matrixProduct(Matrix a, Matrix b)
{
	int ra = a.row;
	int rb = b.row;
	int ca = a.column;
	int cb = b.column;
	if (ca != rb)
	{
		cout << "The two matrix do not match." << endl;
		return a;
	}
	Matrix* result = new Matrix;
	result->row = ra;
	result->column = cb;
	float* data = new float[ra * cb];
	float* da = a.data;
	float* db = b.data;
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
				cout << da[x + z] <<" ";
				cout << db[y + z* cb] << endl;
			}
			cout << endl;
			data[j * ra + i] = sum;
		}
	}
	result->data = data;
	return *result;
}

int main()
{
	Matrix* a = new Matrix;
	a->column = 3;
	a->row = 2;
	a->data = new float[6];
	for(int i=0;i<6;i++)
	{
		a->data[i] = i;
	}
	Matrix* b = new Matrix;
	b->column = 2;
	b->row = 3;
	b->data = new float[6];
	for (int i = 0; i < 6; i++)
	{
		b->data[i] = 6-i;
	}
	Matrix c = matrixProduct(*a, *b);
	for (int i = 0; i < 4; i++)
	{
		cout << c.data[i] << " ";
	}
	return 0;
}
