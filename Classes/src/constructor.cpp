#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
	Student(const string& studentName, int studentID, int studentYear)
		// constructor is function that has no return type and has the same name as the class
		: name{ new string{studentName} }, ID{ studentID }, year{ studentYear }
	{
		cout << "Custom constructor called\n";
	}

	//Student(const char* rawStringName, int studentId, int studentYear)
	//	:name{rawStringName}, ID{studentId}, year{studentYear}
	//{
	//	cout << "Second constructor is called\n";
	//}

	Student(const char* rawStringName, int studentId, int studentYear)
		: Student{ string{rawStringName}, studentId, studentYear }
	{
		cout << "Constructor calling another constructor\n";
	}

	// Destructor
	~Student() // destructor called when object is out of scope
		// is always going to be called when these situatuin happens
	{
		cout << "Student " << *name << " is destructed\n";
		delete name;
	}

	string* name;
	int ID;
	int year;

};

//int main()
//{
//
//	/*Student studentOne("Mohamed", 125, 1);
//	Student studentTwo("Ali", 145, 2);
//
//	vector<Student> students = { studentOne, studentTwo };
//
//	for (Student student : students) {
//		cout << "Student name: " << student.name << '\n';
//		cout << "Student ID: " << student.ID << '\n';
//		cout << "Student Year: " << student.year << '\n';
//	}*/
//
//	Student student("Jamal", 148, 3);
//
//	return 0;
//}