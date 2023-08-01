#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Array
{
    int s;
    int * val;

    public:
    Array() 
    {
        s = 1;
        val = new int[s];
        val[0] = 0;
    }

    Array(int xs, int xval) 
    {
        s = xs;
        val = new int[s];
        for (int i = 0; i < s; i++) 
        {
            val[i] = xval;
        }
    }

    Array(int xs) 
    {
        s = xs;
        val = new int[s];
        for (int i = 0; i < s; i++) 
        {
            val[i] = 0;
        }
    }

    Array(const Array &arr) 
    {
        s = arr.s;
        val = new int[s];
        for (int i = 0; i < s; i++) 
        {
            val[i] = arr.val[i];
        }
    }

    int operator [] (int i)
    {
        return val[i];
    }

    void operator = (const Array arr)
    {
        for (int i = 0; i < s; i++)
            {
                val[i] = arr.val[i];
            }   
    }

    Array operator + (const Array arr)
    {
        Array r;
        for (int i = 0; i < s; i++)
        {
            r.val[i] = arr.val[i] + val[i];
        }
        return r;
        
    }

    Array operator - (const Array arr)
    {
        Array r;
        for (int i = 0; i < s; i++)
        {
            r.val[i] = arr.val[i] - val[i];
        }
        return r;
        
    }

    void operator ++ ()
    {   
        for (int i = 0; i < s; i++)
        {
            val[i]++;
        }
    }
    
    Array & operator --() 
    {
        for (int i = 0; i < s; i++) 
        {
            val[i]--;
        }
        return *this; 
    }


    bool operator == (const Array arr)
    {
        for (int i = 0; i < s; i++)
        {
            if(val[i] == arr.val[i])
            {
                continue;
            }
            else
                return false;
        }
        return true;
        
    }

    bool operator !()
    {
        if (s == 0)
            return true;
        else
            return false;    
    }

    void operator += (const Array & arr)
    {
        for (int i = 0; i < s; i++)
        {
            arr.val[i] += val[i];
        }
    }

    void operator -= (const Array & arr)
    {
        for (int i = 0; i < s; i++)
        {
            arr.val[i] -= val[i];
        }
    }

    int operator ()(int idx, int vxal)
    {
        if (idx > s || idx < s)
            return -1;

        else
        {
            for (int i = idx; i < s-1; i++)
            {
                val[i] = val[i+1];
            }
            return 1;
        }

    }

	 friend istream& operator>>(istream& is, Array& arr)
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

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
	    os << "[ ";
	    for (int i = 0; i < arr.s; i++)
	    {
	        os << arr.val[i] << ", ";
	    }
	    os << "]";
	    return os;
	}

    ~Array()
    {
        delete[] val;
    }
};

int main()
{
   system("Color 0B");
    Array arr1(3, 1);
    Array arr2(3, 2);
  




    bool are_equal = (arr1 == arr2);
    if (!arr1  == true)
    {
        cout<<"Array 1 is empty\n";
    }
    else
    {
        cout<<"Array 1 is not empty\n";
    }


    Array arr3 = arr1;
    arr3 += arr2;
    arr3 -= arr1;
 


	Array arr4;
    cin >> arr4;
    cout << "Array 4:\n" << arr4 << "\n";

    cout << "Array 1:\n" << arr1 << "\n";
    cout << "Array 2:\n" << arr2 << "\n";
//    cout << "Array 1 + Array 2:\n" << arr1 + arr4 << "\n";
//    cout << "Array 1 - Array 2:\n" << arr4 - arr1 << "\n";
    if(are_equal == true)
    {
    	cout<<"Array 1 == Array 2\n";
	}
	else
	{
		cout<<"Array 1 != Array 2\n";
	}
    cout << "Array 3:\n" << arr3 << "\n";


    return 0;
}

