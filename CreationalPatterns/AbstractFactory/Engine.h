#pragma once
#include"stdafx.h"

class Engine
{
protected:
	unsigned int power;
	std::string type;
public:
	~Engine() {}
	virtual const std::string& get_type() const = 0;	//Pure Virtual Function - just make this class abstract
	void info()const
	{
		cout << type << "Power: " << power << "HP" << endl;;//Horse Powers
	}
};

class SportEngine :public Engine
{
public:
	SportEngine()
	{
		this->power = 250;
		this->type = "SportEngine";
	}
	~SportEngine() {}
	const std::string& get_type()const
	{
		return this->type;
	}
};
class TruckEngine :public Engine
{
public:
	TruckEngine()
	{
		this->type = "TruckEngine";
		this->power = 500;
	}
	~TruckEngine() {}
	const std::string& get_type()const
	{
		return this->type;
	}
};