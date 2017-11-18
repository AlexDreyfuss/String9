#include "MyStrings.h"
class MyStrings;

/*Empty constructor for empty string*/
MyStrings::MyStrings() : theString(nullptr), mysize(0)
{
	
}

/*Constructor that gets string*/
MyStrings::MyStrings(char * str)
{
	size_t size = strlen(str);
	theString = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		theString[i] = str[i];
	}
	mysize = size;
	theString[mysize] = '\0';
}
/* copy constructor to copy a string
Input: MyStrings object
Output: Nada
*/
MyStrings::MyStrings(MyStrings & str) : mysize(str.mysize)
{
	
	theString = new char[mysize + 1];
	for (size_t i = 0; i < mysize; i++)
	{
		theString[i] = str.CharAt(i);
	}
	theString[mysize] = '\0';
}
/* Destructor that kills the string */
MyStrings::~MyStrings()
{
	if(theString)
		delete [] theString;
}

/* method gets the length of the string
Input:
Output sizeof the string
*/
size_t MyStrings::GetLength() const
{
	return mysize;
}

/*
this method get char at index from string
input: index of string
output: char at index instring
*/
char MyStrings::CharAt(size_t index) const
{
	char result = NULL;
	if (index < GetLength())
	{
		result = theString[index];
	} 
	return result;
}

/* the method appends a string to the current string
Input: a string
Output: a pointer to the new string
*/
char* MyStrings::Append(MyStrings & otherString)
{	
	if (0 < otherString.GetLength())
	{
		size_t tmpsize = otherString.GetLength();
		char * newstr = new char[mysize + tmpsize + 1];
		for (size_t i = 0; i < mysize; i++)
		{
			newstr[i] = theString[i];
		}
		for (size_t i = 0; i < tmpsize; i++)
		{
			newstr[mysize + i] = otherString.CharAt(i);
		}
		newstr[mysize + tmpsize] = '\0';
		delete [] theString;
		theString = newstr;
		mysize += tmpsize;
	}
	return theString;
}

/* the method appends a string to the current string
Input: a string
Output: a pointer to the new string
*/
char * MyStrings::Append(char * otherString)
{
	size_t otherlength = strlen(otherString);
	if (0 < otherlength)
	{
		char * newstr = new char[mysize + otherlength + 1];
		for (size_t i = 0; i < mysize; i++)
		{
			newstr[i] = theString[i];
		}
		for (size_t i = 0; i < otherlength; i++)
		{
			newstr[mysize + i] = otherString[i];
		}
		newstr[mysize + otherlength] = '\0';
		delete[] theString;
		theString = newstr;
		mysize += otherlength;
	}
	return theString;
}
/* The method compares the current string to another
Input: a String
Output: boolean value if they are the same*/
bool MyStrings::Compare(const MyStrings &otherString) const
{
	bool isSame = true;
	if (mysize == otherString.GetLength())
	{
		for (size_t i = 0; i < mysize && isSame; i++)
		{
			if (theString[i] != otherString.CharAt(i))
				isSame = false;
		}
	}
	return isSame;
}

/* The method compares the current string to another
Input: a String
Output: boolean value if they are the same*/
bool MyStrings::Compare(const char * otherString) const
{
	bool isSame = true;
	if (mysize == strlen(otherString))
	{
		for (size_t i = 0; i < mysize && isSame; i++)
		{
			if (theString[i] != otherString[i])
				isSame = false;
		}
	}
	return isSame;
}

/* method isempty
Input: 
Output: boolean if empty*/
bool MyStrings::IsEmpty() const
{
	return (0 == GetLength());
}

/* clears the string
Xors the size*/
void MyStrings::Clear()
{
	mysize = 0;
}
/*	this operator lets you assign Mystrings object to current String
*/
void MyStrings::operator=(MyStrings & d1)
{
	Assign(d1);
}
/* method that assigns new string to current
Input: string
Output: pointer to new string*/
char*  MyStrings::Assign(MyStrings & otherString)
{
	size_t otherlength = otherString.GetLength();
	if (nullptr != &otherString && 0 < otherlength)
	{
		delete[] theString;
		char* tmpstr = new char[otherlength + 1];
		for (size_t i = 0; i < otherlength; i++)
		{
			tmpstr[i] = otherString.CharAt(i);
		}
		tmpstr[otherlength] = '\0';
		theString = tmpstr;
		return theString;

	}
}
 
/* method that assigns new string to current
Input: string
Output: pointer to new string*/
char * MyStrings::Assign(char * otherString)
{
	size_t otherlength = strlen(otherString);
	if (nullptr != otherString && 0 < otherlength)
	{
		delete[] theString;
		char* tmpstr = new char[otherlength + 1];
		for (size_t i = 0; i < otherlength; i++)
		{
			tmpstr[i] = otherString[i];
		}
		tmpstr[otherlength] = '\0';
		theString = tmpstr;
		return theString;

	}
}

/* Output operator to write to console cuurrent String
Input: output object and the string object
Output: the output object  to repeat output*/
ostream & operator<<(ostream & os, const MyStrings & dt)
{
	os << dt.theString;
	return os;
}
/* Comparison operator to compare 2 objects 
Input: two MyStrings
Output: boolean value according to the the comparison*/
bool operator==(const MyStrings & d1, const MyStrings & d2)
{
	return d1.Compare(d2);
}

