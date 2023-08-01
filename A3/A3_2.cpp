#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    system("Color 0B");
    Array arr1(3, 1);
    Array arr2(3, 2);

    Array arr_sum = arr1 + arr2;
    Array arr_diff = arr1 - arr2;



    bool are_equal = (arr1 == arr2);
    if (!arr1 == true)
    {
        cout << "Array 1 is empty\n";
    }
    else
    {
        cout << "Array 1 is not empty\n";
    }


    Array arr3 = arr1;
    arr3 += arr2;
    arr3 -= arr1;



    cout << "Enter 3 values for Array 4:\n";
    Array arr4;
    cin >> arr4;
    cout << "Array 4:\n" << arr4 << "\n";

    cout << "Array 1:\n" << arr1 << "\n";
    cout << "Array 2:\n" << arr2 << "\n";
    cout << "Array 1 + Array 2:\n" << arr_sum << "\n";
    cout << "Array 1 - Array 2:\n" << arr_diff << "\n";
    if (are_equal == true)
    {
        cout << "Array 1 == Array 2\n";
    }
    else
    {
        cout << "Array 1 != Array 2\n";
    }
    cout << "Array 3:\n" << arr3 << "\n";


    return 0;
}


