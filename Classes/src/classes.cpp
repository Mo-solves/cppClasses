#include "DynamicInt.h"
#include <iostream>
//#include "DynamicNumber.h"
#include "myClass.h"

using namespace std;

int main()
{

	MyClass mc1;
	MyClass mc2;

	cout << mc1.getCount() << '\n';

	/*DynamicInt dInt1{ 3 };
	DynamicInt dInt2{ 2 };
	DynamicInt dInt3 = 2 * dInt1;

	cout << dInt3.getValue() << '\n';*/

	//DynamicNumber<float> dFloat1{ 21.5f };
	//DynamicNumber<float> dFloat2 = dFloat1;

	//DynamicNumber<float> dFloat3 = move(dFloat1);

	////dFloat1.setValue(22.5);

	//dFloat1 = dFloat2; // copy assignment

	////dFloat1 = move(dFloat3); // move assignment


	//cout << dFloat1.getValue() << '\n';
	//cout << dFloat2.getValue() << '\n';



	return 0;
}