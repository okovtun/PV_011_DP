#include<iostream>
#include<string>
using namespace std;

typedef int Cable;

class EuropeanSocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;	//����
	virtual Cable neutral() = 0;//0
	virtual Cable earth() = 0;	//����������
};

class Socket :public EuropeanSocketInterface
{
public:
	int voltage()
	{
		return 220;
	}

	Cable live()
	{
		return 1;
	}
	Cable neutral()
	{
		return -1;
	}
	Cable earth()
	{
		return 0;
	}
};

class USASocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;	//����
	virtual Cable neutral() = 0;//0
};

class Kettle
{
	USASocketInterface* power;
public:
	void plugIn(USASocketInterface* supply)
	{
		power = supply;
	}

	void boil()
	{
		if (power->voltage() > 110)
		{
			cout << "Kettle on fire" << endl;
		}
		if (power->live() == 1 && power->neutral() == -1)
		{
			cout << "Water boiling" << endl;
		}
	}
};

class Adapter :public USASocketInterface
{
	EuropeanSocketInterface* socket;

public:
	void plugIn(EuropeanSocketInterface* socket)
	{
		this->socket = socket;
	}

	int voltage()
	{
		return 110;
	}

	Cable live()
	{
		return socket->live();
	}
	Cable neutral()
	{
		return socket->neutral();
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	Socket socket;
	Kettle kettle;
	Adapter adapter;
	
	kettle.plugIn(&adapter);	//������ ���������� � ��������
	adapter.plugIn(&socket);	//������� ��������� � �������

	kettle.boil();
}