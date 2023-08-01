#include <iostream>
#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

class Matrix
{
	int r; int c; int** ar;
public:

	Matrix() : r(0), c(0), ar(nullptr) {}
	Matrix(int row, int col);
	Matrix(const Matrix& mat);
	~Matrix();
	Matrix& operator=(const Matrix& mat);
	Matrix& operator ++();
	Matrix operator+(const Matrix& mat) const;
	Matrix operator-(const Matrix& mat) const;
	Matrix operator*(const Matrix& mat) const;
	bool operator == (const Matrix& mat);
	void operator += (const Matrix& mat);
	void operator -= (const Matrix& mat);
	friend ostream& operator<<(ostream& os, const Matrix& mat);
	friend istream& operator>>(istream& is, Matrix& mat);

};
#endif // !MATRIX_H

