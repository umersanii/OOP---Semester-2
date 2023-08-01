#include <iostream>
#ifndef	ARRAY_H
#define ARRAY_H
using namespace std;
class Array 
{
	int s;
	int* val;

public:
	Array();
	Array(int xs,int xval);
	Array(int xs);
	Array(const Array& arr);
	int operator [] (int i);
	void operator = (const Array arr);
	Array operator + (const Array arr);
	Array operator - (const Array arr);
	void operator ++ ();
	Array& operator --();
	bool operator == (const Array arr);
	bool operator !();
	void operator += (const Array& arr);
	void operator -= (const Array& arr);
	int operator ()(int idx, int vxal);
	friend istream& operator>>(istream& is, Array& arr);
	friend ostream& operator<<(ostream& os, const Array& arr);
	~Array();

};
#endif // !1

