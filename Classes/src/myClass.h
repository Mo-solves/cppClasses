#pragma once

class MyClass
{
public:
	MyClass();
	~MyClass();

	static int getCount();
	

private:
	int member;
	static int count; // it is a variable that does not belong to any instance
	// it is independent variable that is shared by all instance, means there is only one
};