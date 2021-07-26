#include<iostream>
#include<string>
using namespace std;

class Computer
{
	std::string type;
	std::string cpu;
	size_t ram;
	std::string disk;
	std::string gpu;
public:
	void set_type(const std::string& type)
	{
		this->type = type;
	}
	void set_cpu(const std::string& cpu)
	{
		this->cpu = cpu;
	}
	void set_ram(size_t ram)
	{
		this->ram = ram;
	}
	void set_disk(const std::string& disk)
	{
		this->disk = disk;
	}
	void set_video(const std::string& gpu)
	{
		this->gpu = gpu;
	}

	void info()const
	{
		cout << type << endl;
		cout << cpu << endl;
		cout << ram << endl;
		cout << disk << endl;
		cout << gpu << endl;
	}
};

class ComputerBuilder	//Abstract builder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{
		delete this->computer;
	}
	Computer* getComputer()
	{
		return computer;
	}
	void createNewComputer()
	{
		computer = new Computer;
	}
	virtual void setType() = 0;
	virtual void setCPU() = 0;
	virtual void setRAM() = 0;
	virtual void setDisk() = 0;
	virtual void setGPU() = 0;
};

class CheapComputerBuilder:public ComputerBuilder
{
public:
	~CheapComputerBuilder(){}

	void setType()
	{
		computer->set_type("Ѕюджетный компьютер");
	}
	void setCPU()
	{
		computer->set_cpu("Pentuim");
	}
	void setRAM()
	{
		computer->set_ram(4);
	}
	void setDisk()
	{
		computer->set_disk("Toshiba HDD 500 GB");
	}
	void setGPU()
	{
		computer->set_video("Integrated GPU");
	}
};
class OfficeComputerBuilder:public ComputerBuilder
{
public:
	~OfficeComputerBuilder(){}

	void setType()
	{
		computer->set_type("ќфисный компьютер");
	}
	void setCPU()
	{
		computer->set_cpu("Core i3");
	}
	void setRAM()
	{
		computer->set_ram(8);
	}
	void setDisk()
	{
		computer->set_disk("Kingston SSD 240 GB");
	}
	void setGPU()
	{
		computer->set_video("Integrated GPU");
	}
};
class GameComputerBuilder:public ComputerBuilder
{
public:
	~GameComputerBuilder(){}

	void setType()
	{
		computer->set_type("»гровой компьютер");
	}
	void setCPU()
	{
		computer->set_cpu("Core i7");
	}
	void setRAM()
	{
		computer->set_ram(16);
	}
	void setDisk()
	{
		computer->set_disk("Samsung SSD 500 GB");
	}
	void setGPU()
	{
		computer->set_video("nVidia GeForce 2050 Ti");
	}
};
class Assembler	//Director
{
	ComputerBuilder* computer;
public:
	void assemblyComputer(ComputerBuilder* computer)
	{
		this->computer = computer;
		this->computer->setType();
		this->computer->setCPU();
		this->computer->setRAM();
		this->computer->setDisk();
		this->computer->setGPU();
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	CheapComputerBuilder cheap_comp;
	OfficeComputerBuilder office;
	GameComputerBuilder for_crysis;

	Assembler sysadmin;
	sysadmin.assemblyComputer(&cheap_comp);
	cheap_comp.getComputer()->info();

	sysadmin.assemblyComputer(&office);
	office.getComputer()->info();

	sysadmin.assemblyComputer(&for_crysis);
	for_crysis.getComputer()->info();
}