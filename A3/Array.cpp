#include <iostream>
#include "Array.h"

using namespace std;


    Array::Array()
    {
        s = 1;
        val = new int[s];
        val[0] = 0;
    }

    Array::Array(int xs, int xval)
    {
        s = xs;
        val = new int[s];
        for (int i = 0; i < s; i++)
        {
            val[i] = xval;
        }
    }

    Array::Array(int xs)
    {
        s = xs;
        val = new int[s];
        for (int i = 0; i < s; i++)
        {
            val[i] = 0;
        }
    }

    Array::Array(const Array& arr)
    {
        s = arr.s;
        val = new int[s];
        for (int i = 0; i < s; i++)
        {
            val[i] = arr.val[i];
        }
    }

    int Array::operator [] (int i)
    {
        return val[i];
    }

    void Array::operator = (const Array arr)
    {
        for (int i = 0; i < s; i++)
        {
            val[i] = arr.val[i];
        }
    }

    Array Array::operator + (const Array arr)
    {
        Array r;
        for (int i = 0; i < s; i++)
        {
            r.val[i] = arr.val[i] + val[i];
        }
        return r;

    }

    Array Array::operator - (const Array arr)
    {
        Array r;
        for (int i = 0; i < s; i++)
        {
            r.val[i] = arr.val[i] - val[i];
        }
        return r;

    }

    void Array::operator ++ ()
    {
        for (int i = 0; i < s; i++)
        {
            val[i]++;
        }
    }

    Array& Array::operator --()
    {
        for (int i = 0; i < s; i++)
        {
            val[i]--;
        }
        return *this;
    }


    bool Array::operator == (const Array arr)
    {
        for (int i = 0; i < s; i++)
        {
            if (val[i] == arr.val[i])
            {
                continue;
            }
            else
                return false;
        }
        return true;

    }

    bool Array::operator !()
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    void Array::operator += (const Array& arr)
    {
        for (int i = 0; i < s; i++)
        {
            arr.val[i] += val[i];
        }
    }

    void Array::operator -= (const Array& arr)
    {
        for (int i = 0; i < s; i++)
        {
            arr.val[i] -= val[i];
        }
    }

    int Array::operator ()(int idx, int vxal)
    {
        if (idx > s || idx < s)
            return -1;

        else
        {
            for (int i = idx; i < s - 1; i++)
            {
                val[i] = val[i + 1];
            }
            return 1;
        }

    }

    istream& operator>>(istream& is, Array& arr)
    {
        cout << "Enter the size of the array: ";
        is >> arr.s;
        arr.val = new int[arr.s];
        cout << "Enter the values of the array: ";
        for (int i = 0; i < arr.s; i++)
        {
            is >> arr.val[i];
        }
        return is;
    }

    ostream& operator<<(ostream& os, const Array& arr)
    {
        os << "[ ";
        for (int i = 0; i < arr.s; i++)
        {
            os << arr.val[i] << ", ";
        }
        os << "]";
        return os;
    }

    Array::~Array()
    {
        delete[] val;
    }

