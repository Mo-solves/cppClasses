//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class DynamicInt
//{
//public:
//	DynamicInt()
//		:intPtr{ new int {0} }
//	{
//
//	}
//
//	DynamicInt(const DynamicInt& other) // copy constructor
//		:intPtr{ new int {other.getValue()} } // a deep copy
//	{
//		cout << "Copy con\n";
//	}
//
//	// move constructor
//	// && converts value to rvalue
//	DynamicInt(DynamicInt&& other) noexcept
//		:intPtr{ other.intPtr } // a shallow copy
//	{
//		cout << "Move con\n";
//		other.intPtr = nullptr; // the other one no longer owns the ptr
//	}
//
//	DynamicInt(int value)
//		: intPtr{ new int {value} }
//	{
//		cout << "One param constructor\n";
//	}
//
//	DynamicInt& operator=(const DynamicInt& rhs) // a copy assignment operator
//	{
//		cout << "copy assignment\n";
//		if (intPtr == rhs.intPtr) return *this; // do a self assignment check
//		// not the best solution here, because we should use the ==
//		// deep copy
//		*intPtr = rhs.getValue();
//
//		return *this; // this is the pointer that points to the current object we are working
//	}
//
//	void setValue(int newValue)
//	{
//		if (newValue < 0) return;
//		*intPtr = newValue;
//	}
//
//	int getValue() const
//	{
//		if (intPtr) return *intPtr;
//		return 0;
//	}
//
//	~DynamicInt()
//	{
//		cout << "Destructed\n";
//		delete intPtr; // frees the memory
//	}
//
//private:
//	int* intPtr;
//};
//
//// move constructor
//
//DynamicInt ConstructDynamicInt(int val)
//{
//	DynamicInt dInt{ val };
//	return dInt;
//}

//int main()
//{
//	// r value is temp value, about to be destroyed, not associated to any variable in the current scope
//	// if a value is not a rvalue, its lvalue 
//	DynamicInt intcOne{ 20 }; // an rvalue apeared on the right side of
//	// the = sign, move will be used
//	DynamicInt intcTwo{ 21 }; //default copy constructor assignment will just copy all the value
//
//	intcOne = intcTwo = intcOne;
//
//	cout << "cTwo " << intcTwo.getValue() << '\n';
//
//	return 0;
//}