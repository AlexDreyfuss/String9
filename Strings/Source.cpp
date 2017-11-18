// written by alexandre dreyfuss
// class: my own String class
// as need for a custom string class i wrote my own to be more safe
#include  <iostream>
#include "MyStrings.h"

using namespace std;
/* a main function to check the string class*/
void main()
{
	MyStrings newString("append string: ");
	std::cout << "test 1: append string"<< endl;
	std::cout << newString.Append(*(new MyStrings("test1")))<< endl;
	std::cout << newString.Append("add char* string") << endl;


	std::cout << "test 2: assign String" << endl;
	MyStrings* tmp = new MyStrings("Test2");
	std::cout << newString.Assign(*tmp) << endl;
	std::cout << newString.Assign("assigned char* string") << endl;

	std::cout << "test 3: compare String" << endl;
	std::cout << newString.Compare("assigned char* string") << endl;

	std::cout << "test 4: is epmty String" << endl;
	std::cout << newString.IsEmpty() << endl;

	std::cout << "test 5: is clear String" << endl;
	newString.Clear();
	std::cout << newString.Append("test5") << endl;
	delete tmp;

	std::cout << "test 6: copy constructor" << endl;
	MyStrings Copied = newString;
	std::cout << "test 7: assignment" << endl;
	Copied = newString;
	std::cout << Copied << endl;

	std::cout << "test 6: comparison function" << endl;
	bool check = (Copied == newString);
	std::cout << check << endl;
	system("PAUSE");
}