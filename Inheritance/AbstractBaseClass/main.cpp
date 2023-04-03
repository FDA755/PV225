#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;  //это чисто-виртуальный метод и благодар€ ему, клас Vehicle €вл€етс€ обстрактным.
};
class GroundVehicle : public Vehicle {};

class Bulldozer : public GroundVehicle
{
public:
	void move()
	{
		cout << "≈здит где угодно на гусеничном ходу" << endl;
	}
};
class Car : public Vehicle {};
class SportCar :public Car
{
public:
	void move()
	{
		cout << "≈здит высокой скорости по идеальной дороге" << endl;
	}
};
class Jeep :public Car
{
public:
	void move()
	{
		cout << "≈здит где угодно" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	/*Vehicle V;
	GroundVehicle GV;*/
	Bulldozer bull; bull.move();
	SportCar bmw;		bmw.move();
	Jeep jeep;		jeep.move();
}