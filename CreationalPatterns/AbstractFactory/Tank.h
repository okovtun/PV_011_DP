#pragma once
#include"stdafx.h"

class Tank
{
protected:
	std::string type;
	unsigned int volume;
public:
	virtual const std::string& get_type()const = 0;	//Pure Virtual Function - just make this class abstract
	void info()const
	{
		cout << type << ", volume" << volume << " liters\n";
	}
};
class SportTank :public Tank
{
public:
	SportTank()
	{
		this->type = "SportTank";
		this->volume = 60;
	}
	~SportTank() {}
	const std::string& get_type()const
	{
		return this->type;
	}
};
class TruckTank :public Tank
{
public:
	TruckTank()
	{
		this->type = "TruckTank";
		this->volume = 200;
	}
	~TruckTank(){}
	const std::string& get_type()const
	{
		return this->type;
	}
};