#pragma once
#include"Engine.h"
#include"Tank.h"

class Car
{
protected:
	Engine* engine;
	Tank* tank;
public:
	//Car(Engine* engine, Tank* tank):engine(engine), tank(tank){}
	Car(Engine* engine, Tank* tank):engine(engine), tank(tank)
	{

	}
	~Car()
	{
		delete engine;
		delete tank;
	}
	void info()const
	{
		engine->info();
		tank->info();
	}
};