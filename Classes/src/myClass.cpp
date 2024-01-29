#include "myClass.h"
#include <iostream>

using namespace std;

int MyClass::count = 0;

MyClass::MyClass() 
	:member{0}
{
	++count;
	cout << "Count is now " << count << '\n';
}

MyClass::~MyClass()
{
	--count;
	cout << "Count is now " << count << '\n';

}

int MyClass::getCount()
{
	return count;
}