#include <iostream>
#include <vector>

using namespace std;

class Vehicle
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

	virtual void Run()  // virtual means the child can override it
	{
		cout << name << " with " << capacity << " people running\n";
	}

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
	}

	float getMileage() const { return mileage; }

private:
	float mileage;

};


//int main()
//{
//	Vehicle vehicle("LightYears2000", 1000);
//	vehicle.Run();
//
//	Car car("Toyota Ry14", 5, 51111);
//	Vehicle* carAsVehicle = &car; // you can hold a reference of the child with a variable of the parent type
//
//	carAsVehicle->Run();
//
//	car.Run();
//
//	cout << car.getMileage() << '\n';
//
//	return 0;
//}