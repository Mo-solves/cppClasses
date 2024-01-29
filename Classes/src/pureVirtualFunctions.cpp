#include <iostream>
#include <vector>

using namespace std;

// if u do know its meaning less to make an object of base class, make it abstract
class Vehicle // it is an abstruct concept
	// if there is one pure virtual function, the class automatically becomes abstract
{
public:
	Vehicle(const string& vehicleName, int vehicleCapacity)
		: name{ vehicleName }, capacity{ vehicleCapacity }
	{

	}

	string getName() const
	{
		return name;
	}

	// a pure virtual function, meaning the class is abstruct
	virtual void Run() = 0;

	int getCapacity() const { return capacity; }
	void setCapacity(int newCapacity) {
		if (newCapacity < 0) return;
		capacity = newCapacity;
	}

protected: // weak protection, the child can access it, still not available out side of the family
	string name;


private:
	int capacity;
};

class Car : public Vehicle // car is inherited from vehicle
{
public:
	Car(const string& carName, int carCapacity, float carMileage)
		: Vehicle{ carName, carCapacity
		}, mileage{ carMileage }
	{

	}

	virtual void Run() override // override means we are not creating a new function
		// we are redifining the vehicle part of the run for the car
	{
		cout << name << " with " << mileage << " mileage " << getCapacity() << " people running\n";
	} // case with overhead.

	float getMileage() const { return mileage; } // a getter

private:
	float mileage;

};

//
//int main()
//{
//	/*Vehicle vehicle("LightYears2000", 1000);
//	vehicle.Run();*/
//
//	Car car("Toyota Ry14", 5, 51111);
//	Vehicle* carAsVehicle = &car; // you can hold a reference of the child with a variable of the parent type
//
//	carAsVehicle->Run(); // polymorphism - many forms, uses a v table to find the correct function to call
//
//	car.Run();
//
//	cout << car.getMileage() << '\n';
//
//	return 0;
//}