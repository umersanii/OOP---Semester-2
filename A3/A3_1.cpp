#include <iostream>
#include "String.h"
#include <windows.h>

using namespace std;
int main()
{
    system("Color 0B");

    String s1;
    cout << "s1 = " << s1 << endl;

    String s2("hello");
    cout << "s2 = " << s2 << endl;

    String s3(s2);
    cout << "s3 = " << s3 << endl;

    String s4(String("world"));
    cout << "s4 = " << s4 << endl;

    s1 = s2;
    cout << "s1 = " << s1 << endl;

    s3 = String("new string");
    cout << "s3 = " << s3 << endl;

    String s5 = s2 + "!";
    cout << "s5 = " << s5 << endl;

    bool equal = (s2 == s3);
    cout << "s2 == s3: " << equal << endl;

    if (!s2 == true)
    {
        cout << "s2 is empty\n";
    }
    else
    {
        cout << "s2 is not empty\n";
    }

    cout << "s2[1] = " << s2[1] << endl;

    cout << "Enter a string: ";
    String s6;
    cin >> s6;
    cout << "s6 = " << s6 << endl;

    String s7;
    cout << "d\n";
    cin >> s7;
    cout << "s7 = " << s7 << endl;

    String s8 = s2 * 3;
    cout << "s8 = " << s8 << endl;

    String s9 = s2 - s1;
    cout << "s9 = " << s9 << endl;

    return 0;
}
S
