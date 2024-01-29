#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
	Student(const string& studentName, int studentID, int studentYear)
		// constructor is function that has no return type and has the same name as the class
		: name{ studentName }, ID{ studentID }, year{ studentYear }
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
		cout << "Student " << name << " is destructed\n";

	}

	// Member functions

	void SayHello()
	{
		cout << name << " says hello\n";
	}

	void IncrementYear()
	{
		++year;
		switch (year)
		{
		case 1:
			cout << name << " is in freshman\n";
			break;
		case 2:
			cout << name << " is in 2nd year\n";
			break;
		case 3:
			cout << name << " is in last year\n";
			break;
		default:
			cout << name << " Graduated\n";
			break;
		}

	}

	bool isGraduated() {
		return year > 4;
	}

	//void setID(int newID) {
	//	if (newID < 0) {
	//		cout << "wrong ID value, should be positive\n";
	//		return;
	//	}

	//	ID = newID;
	//}

	// getters offten paired with const, meaning you are not altering
	// the state of the member variable

	int getId() const {
		return ID;
	}

private:
	string name;
	const int ID;
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
//	Student student("Jamal", 148, 0);
//
//	student.getId();
//
//
//	//student.SayHello();
//
//	//student.setID(-1);
//	//cout << student.getId() << '\n';
//
//	//while (!student.isGraduated()) {
//	//	student.IncrementYear();
//	//}
//	return 0;
//}