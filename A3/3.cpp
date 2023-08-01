#include <iostream>
using namespace std;
class Matrix
{
    int r;
    int c;
    int **ar;

public:
    Matrix() : r(0), c(0), ar(NULL) {}

    Matrix(int row, int col)
    {   
        r = row;
        c = col;
        ar = new int*[row];

        for(int i = 0; i < row; i++)
        {
            ar[i] = new int[col];
            for(int j = 0; j < col; j++)
            {
                ar[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix& mat)
    {
        r = mat.r;
        c = mat.c;
        ar = new int*[mat.r];
        for(int i = 0; i < mat.r; i++)
        {
            ar[i] = new int[mat.c];
            for(int j = 0; j < mat.c; j++)
            {
                ar[i][j] = mat.ar[i][j];
            }
        }
    }

    ~Matrix()
    {
        for(int i = 0; i < r; i++)
        {
            delete[] ar[i];
        }
        delete[] ar;
    }
	get()
	{
		return r;
	}
	
    Matrix& operator=(const Matrix& mat)
    {
        if(this == &mat)
        {
            return *this;
        }
        for(int i = 0; i < r; i++)
        {
            delete[] ar[i];
        }
        delete[] ar;
        r = mat.r;
        c = mat.c;
        ar = new int*[r];
        for(int i = 0; i < r; i++)
        {
            ar[i] = new int[c];
            for(int j = 0; j < c; j++)
            {
                ar[i][j] = mat.ar[i][j];
            }
        }
        return *this;
    }

    Matrix& operator ++()
    {   
        for(int i = 0; i < this->r; i++)
        {
            for(int j = 0; j < this->c; j++)
            {
                ++ar[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& mat) const
    {
        Matrix result(r, c);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                result.ar[i][j] = ar[i][j] + mat.ar[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& mat) const
    {
        Matrix result(r, c);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                result.ar[i][j] = ar[i][j] - mat.ar[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& mat) const
    {
        Matrix result(r, mat.c);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < mat.c; j++)
            {

                    result.ar[i][j] = ar[i][j] * mat.ar[i][j];
                
            }
        }
        return result;
    }

    bool operator == (const Matrix& mat)
    {
        if(mat.r == r && mat.c == c)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < mat.r; i++)
            {
                for (int j = 0; j < mat.c; j++)
                {
                   if(mat.ar[i][j] == ar[i][j])
                    continue;
                    else
                    return false;
                }
                
            }
            return true;
        }
    }

    void operator += (const Matrix &mat)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ar[i][j] + mat.ar[i][j];
            }
        }
    }

     void operator -= (const Matrix &mat)
    {
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                ar[i][j] - mat.ar[i][j];
            }
        }
    }
    
    friend ostream& operator<<(ostream& os, const Matrix& mat)
    {
        for(int i = 0; i < mat.r; i++)
        { os<<"[";
            for(int j = 0; j < mat.c; j++)
            {
                os << mat.ar[i][j] << " ";
            }
            os << "]" << "\n";
        }

    }

    friend istream& operator>>(istream& is, Matrix& mat) 
    {
    
           
        for (int i = 0; i < mat.r; i++) 
        {
            for (int j = 0; j < mat.c; j++) 
            {
                is >> mat.ar[i][j];
            }
        
        }
    
    return is;
	}


};

    



int main()
{

    Matrix m1(2,2);
    Matrix m2(2,2);

    cin >> m1;
    cin >> m2;
  


    cout << "Matrix 1:\n" << m1 << endl;
    cout << "Matrix 2:\n" << m2 << endl;


    Matrix m3 = m1 + m2;
    cout << "Matrix 3 (sum of Matrix 1 and 2):\n" << m3 << endl;


    Matrix m4 = m1 - m2;
    cout << "Matrix 4 (difference of Matrix 1 and 2):\n" << m4 << endl;


    Matrix m5 = m1 * m2;
    cout << "Matrix 5 (product of Matrix 1 and 2):\n" << m5 << endl;



    if (m1 == m2)
    {
        cout << "Matrix 1 is equal to Matrix 2" << endl;
    }
    else
    {
        cout << "Matrix 1 is not equal to Matrix 2" << endl;
    }
  


    Matrix m7 = ++m1;
    cout << "Matrix 1 after post-decrement:\n" << m1 << endl;
    cout << "Matrix 7 (copy of Matrix 1 before decrement):\n" << m7 << endl;

 


    m1 += m2;
    cout << "Matrix 1 after compound assignment addition:\n" << m1 << endl;


    m2 -= m1;
    cout << "Matrix 2 after compound assignment subtraction:\n" << m2 << endl;

    return 0;
}

