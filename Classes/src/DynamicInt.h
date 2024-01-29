#pragma once

#include <iostream>
#include <vector>

using namespace std;

class FriendClass {

};

class DynamicInt
{
public:
	DynamicInt()
		:intPtr{ new int {0} }
	{

	}

	// ******* start THE BIG FIVE *************
	// if none of these are customly made, then defaults ones will be provided automatically, and do shallow copy
	// in fact, others will not be automatically provided.

	// copy constructor
	DynamicInt(const DynamicInt& other) // copy constructor
		:intPtr{ new int {other.getValue()} } // a deep copy
	{
		cout << "Copy con\n";
	}

	// move constructor
	// && converts value to rvalue
	DynamicInt(DynamicInt&& other) noexcept
		:intPtr{ other.intPtr } // a shallow copy
	{
		cout << "Move con\n";
		other.intPtr = nullptr; // the other one no longer owns the ptr
	}

	// destructor
	~DynamicInt()
	{
		cout << "Destructed\n";
		delete intPtr; // frees the memory
	}

	// copy assignment operator
	DynamicInt& operator=(const DynamicInt& rhs) noexcept // a copy assignment operator
	{
		cout << "copy assignment\n";
		if (*this == rhs) return *this; // do a self assignment check
		// not the best solution here, because we should use the ==
		// deep copy
		*intPtr = rhs.getValue();

		return *this; // this is the pointer that points to the current object we are working
	}

	// move assignment operator
	DynamicInt& operator=(DynamicInt&& rhs) noexcept // move assignment operator
	{
		cout << "Move assignment\n";
		if (*this == rhs) return *this; // self assignment guard. needed to prevent deletion of this.ptr


		delete intPtr; // free this memory.
		intPtr = rhs.intPtr; // giving ownership to this
		rhs.intPtr = nullptr; // rhs giving up ownership
	}

	// ******* end THE BIG FIVE *************


	bool operator==(const DynamicInt& other) // this defines what happens when a == b
	{
		if (intPtr == other.intPtr) return true;
		if (getValue() == other.getValue()) return true;

		return false;
	}

	bool operator!=(const DynamicInt& other)
	{
		return !(*this == other);
	}

	bool operator>(const DynamicInt& other)
	{
		return getValue() > other.getValue();
	}

	bool operator<(const DynamicInt& other)
	{
		return getValue() < other.getValue();
	}

	bool operator<=(const DynamicInt& other)
	{
		return getValue() <= other.getValue();
	}

	bool operator>=(const DynamicInt& other)
	{
		return getValue() >= other.getValue();
	}

	

	void setValue(int newValue)
	{
		if (newValue < 0) return;
		*intPtr = newValue;
	}

	int getValue() const
	{
		if (intPtr) return *intPtr;
		return 0;
	}


	DynamicInt(int value)
		: intPtr{ new int {value} }
	{
		cout << "One param constructor\n";
	}

	// this function is a friend of the DynamicInt class
	// friend breaks the private protection, all together
	/*friend DynamicInt operator*(const DynamicInt& lhs, const DynamicInt& rhs)
	{
		return DynamicInt{ *lhs.intPtr * *rhs.intPtr };
	}*/
	friend FriendClass; // this enables FriendCLass to access intPtr, 
	// not recommended if you can manage with out friend

private:
	int* intPtr;
};

// move constructor

DynamicInt ConstructDynamicInt(int val)
{
	DynamicInt dInt{ val };
	return dInt;
}

//DynamicInt operator*(const DynamicInt& lhs, const DynamicInt& rhs);
//DynamicInt operator*(int lhs, const DynamicInt& rhs);
//DynamicInt operator*(const DynamicInt& lhs, int rhs);

// favor facility functions like this instead of member
DynamicInt operator*(const DynamicInt& lhs, const DynamicInt& rhs)
{
	return DynamicInt{ lhs.getValue() * rhs.getValue() };
}