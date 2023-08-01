#include <iostream>
#include "Matrix.h"
#include <windows.h>
using namespace std;
int main()
{
    system("Color 0B");
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    cout << ":-MATRIX 1:-\n\n";
    cin >> m1;
    cout << ":-MATRIX 1:-\n\n";
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






