//#pragma once
//
//template<typename T>
//class DynamicNumber
//{
//
//public:
//	DynamicNumber() // default constructor
//		:ptr{ new T{} }
//	{
//
//	}
//
//	// one parameters constructor
//	explicit DynamicNumber(const T& other)
//		: ptr{ new T{other} }
//	{
//
//	}
//
//	// The big five
//
//	~DynamicNumber()
//	{
//		delete ptr;
//	}
//
//	// copy constructor
//	DynamicNumber(const DynamicNumber& other)
//		:ptr{ new T{other.getValue()} }
//	{
//
//	}
//
//	// move constructor - shallow copy
//	DynamicNumber(DynamicNumber&& other) noexcept
//		: ptr{ other.ptr } // transfer ownership of the pointer to this
//	{
//		other.ptr = nullptr; // removes the ownership of the other
//	}
//
//	// copy assignment operator
//	DynamicNumber& operator=(const DynamicNumber& other) noexcept
//	{
//		if (*this == other) return *this;
//
//		if (ptr == nullptr)
//		{
//			ptr = new T{ other.getValue() };
//		}
//		else
//		{
//			*ptr = other.getValue();
//
//		}
//
//		return *this;
//	}
//
//	// move assignment operator
//	DynamicNumber& operator=( DynamicNumber&& other) noexcept
//	{
//		if (*this = other) return *this;
//		delete ptr;
//		ptr = other.ptr;
//		other.ptr = nullptr;
//	}
//
//	// == operator
//	bool operator==(const DynamicNumber& other)
//	{
//		if (ptr == other.ptr) return true;
//		if (getValue() == other.getValue()) return true;
//
//		return false;
//	}
//
//	T getValue() const
//	{
//		if (ptr)
//			return *ptr;
//
//		return T{};
//	}
//
//	void setValue(const T& newValue)
//	{
//		*ptr = newValue;
//	}
//
//private:
//	T* ptr;
//};