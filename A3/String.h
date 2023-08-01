#pragma once
#include <iostream>

using namespace std;
class String
{
    char content[100];

public:
    String();
    String(char str[]);
    String(const String& s);
    String(int x);
    char get(int i);
    char operator [](int i);
    String& operator + (const String& str);
    String& operator - (const String& str);
    bool operator ! ();
    String& operator = (const String& str);
    bool operator == (const String& str);
    int operator () (const char p);
    String operator *(int a);
    String length();
    ~String();
    friend ostream& operator << (ostream& o, const String s);
    friend istream& operator >> (istream& in, String s);
};
