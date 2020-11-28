#pragma once
#pragma once
#ifndef MATRIX_H_
#define MATRIX_H_
#include <string>

class Matrix
{
private:
    int row = 0;
    int column = 0;
    float* data = 0;

public:
    Matrix(int row, int colunm, float * data);
    Matrix(const Matrix& ma);
    ~Matrix();


    Matrix& operator=(const Matrix& st);

    friend std::ostream& operator << (std::ostream& os, const Matrix& other);

    Matrix operator *(const Matrix& other) const;
    friend Matrix operator *(double real, const Matrix& other);
    friend Matrix operator *(const Matrix& other, double real);
};
#endif
