#pragma once
#include <iostream>
using namespace std;
/* 
this is a custom string class which has string features
1. GetLength() -get lenth of string
2. Assign() - set a new string 
3. CharAt() - get char at given index
4. Append() - append string to current 
5. Compare() between two strings
6. IsEmpty() - check if cuurent is empty
7. Clear(); - clears the current string
8. operator<<() - output operator
9. operator==() - comparison operator
10. operator=() - assignment operator
*/

class MyStrings 
{
	char * theString;
	size_t mysize;
public:
	MyStrings();
	MyStrings(char * str);
	MyStrings(MyStrings &str);
	~MyStrings();
	size_t GetLength() const;

	char* Assign(MyStrings & otherString);
	char* Assign(char * otherString);

	char CharAt(size_t index) const;

	char* Append(MyStrings & otherString);
	char* Append(char* otherString);

	bool Compare(const MyStrings & otherString) const;
	bool Compare(const char* otherString) const;

	bool IsEmpty() const;
	void Clear();
	friend ostream& operator<<(ostream& os, const MyStrings& dt);
	friend bool operator==(const MyStrings& d1, const MyStrings& d2);
	void operator=(MyStrings& d1);

};
