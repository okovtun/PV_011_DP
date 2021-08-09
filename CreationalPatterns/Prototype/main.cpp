#include<iostream>
#include<string>
#include<map>
using namespace std;

class Car
{
	std::string model;
	const unsigned int MAX_SPEED;
	unsigned int doors;
public:
	Car(std::string model,  unsigned int doors, unsigned int MAX_SPEED = 250) :
		model(model), 
		MAX_SPEED(MAX_SPEED < 400 ? MAX_SPEED : 250), 
		doors(doors)
	{}
	virtual ~Car() {}
	virtual Car* clone() = 0;	//Этот метод является обязательным для прототипа
	virtual void info()const
	{
		cout << model << endl;
		cout << "Number of doors: " << doors << endl;
		cout << "Max speed:\t" << MAX_SPEED << endl;
	}
};

class BMW_3 :public Car
{
public:
	BMW_3() :Car("BMW-3", 3, 250){}
	~BMW_3(){}
	Car* clone()
	{
		return new BMW_3(*this);	//CopyConstructor
	}
};
class BMW_5 :public Car
{
public:
	BMW_5() :Car("BMW-5", 4, 280) {}
	~BMW_5(){}
	Car* clone()
	{
		return new BMW_5(*this);
	}
};
class BMW_7 :public Car
{
public:
	BMW_7() :Car("BMW-7", 5, 320) {}
	~BMW_7(){}
	Car* clone()
	{
		return new BMW_7(*this);
	}
};

class BMWfactory
{
	static map<int, Car*> prototype;
public:
	static Car* Factory(unsigned int model_number)
	{
		/*switch (model_number)
		{
		case 3: bmw[3]->clone();
		case 5: bmw[5]->clone();
		case 7: bmw[7]->clone();
		}*/
		return prototype[model_number]->clone();
	}
};
map<int, Car*> BMWfactory::prototype =
{
	std::pair<int, Car*>(3, new BMW_3),
	std::pair<int, Car*>(5, new BMW_5),
	std::pair<int, Car*>(7, new BMW_7),
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Car* bmw = BMWfactory::Factory(7);
	bmw->info();
}