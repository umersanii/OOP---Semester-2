#include <iostream>
#include "Matrix.h"
using namespace std;

    

    Matrix::Matrix(int row, int col)
    {
        r = row;
        c = col;
        ar = new int* [row];

        for (int i = 0; i < row; i++)
        {
            ar[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                ar[i][j] = 0;
            }
        }
    }

    Matrix::Matrix(const Matrix& mat)
    {
        r = mat.r;
        c = mat.c;
        ar = new int* [mat.r];
        for (int i = 0; i < mat.r; i++)
        {
            ar[i] = new int[mat.c];
            for (int j = 0; j < mat.c; j++)
            {
                ar[i][j] = mat.ar[i][j];
            }
        }
    }

    Matrix::~Matrix()
    {
        for (int i = 0; i < r; i++)
        {
            delete[] ar[i];
        }
        delete[] ar;
    }

    Matrix& Matrix::operator=(const Matrix& mat)
    {
        if (this == &mat)
        {
            return *this;
        }
        for (int i = 0; i < r; i++)
        {
            delete[] ar[i];
        }
        delete[] ar;
        r = mat.r;
        c = mat.c;
        ar = new int* [r];
        for (int i = 0; i < r; i++)
        {
            ar[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                ar[i][j] = mat.ar[i][j];
            }
        }
        return *this;
    }

    Matrix& Matrix::operator ++()
    {
        for (int i = 0; i < this->r; i++)
        {
            for (int j = 0; j < this->c; j++)
            {
                ++ar[i][j];
            }
        }
        return *this;
    }

    Matrix Matrix::operator+(const Matrix& mat) const
    {
        Matrix result(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                result.ar[i][j] = ar[i][j] + mat.ar[i][j];
            }
        }
        return result;
    }

    Matrix Matrix::operator-(const Matrix& mat) const
    {
        Matrix result(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                result.ar[i][j] = ar[i][j] - mat.ar[i][j];
            }
        }
        return result;
    }

    Matrix Matrix::operator*(const Matrix& mat) const
    {
        Matrix result(r, mat.c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < mat.c; j++)
            {

                result.ar[i][j] = ar[i][j] * mat.ar[i][j];

            }
        }
        return result;
    }

    bool Matrix::operator == (const Matrix& mat)
    {
        if (mat.r == r && mat.c == c)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < mat.r; i++)
            {
                for (int j = 0; j < mat.c; j++)
                {
                    if (mat.ar[i][j] == ar[i][j])
                        continue;
                    else
                        return false;
                }

            }
            return true;
        }
    }

    void Matrix::operator += (const Matrix& mat)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ar[i][j] + mat.ar[i][j];
            }
        }
    }

    void Matrix::operator -= (const Matrix& mat)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ar[i][j] - mat.ar[i][j];
            }
        }
    }

    ostream& operator<<(ostream& os, const Matrix& mat)
    {
        for (int i = 0; i < mat.r; i++)
        {
            os << "[";
            for (int j = 0; j < mat.c; j++)
            {
                os << mat.ar[i][j] << " ";
            }
            os << "]" << "\n";
            
        }
        return os;
    }

    istream& operator>>(istream& is, Matrix& mat)
    {
       
        for (int i = 0; i < mat.r; i++)
            {
                for (int j = 0; j < mat.c; j++)
                {   
                    cout << "Matrix Element: [" << i + 1 << "][" << j + 1 << "]: ";
                    is >> mat.ar[i][j];
                    cout << "\n";
                }

            }

            
        
        return is;
    }


