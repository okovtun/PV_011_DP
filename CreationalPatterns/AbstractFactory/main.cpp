


#include"stdafx.h"
#include"Client.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	SportFactory sf;
	TruckFactory tf;
	Client client1(&sf);
	Client client2(&tf);
	/*client.info();
	client.setFactory(&tf);
	client.info();
	Engine* sport_engine = sf.createEngine();
	sport_engine->info();*/
	Car* sportcar = client1.assembly();
	sportcar->info();
	Car* truck = client2.assembly();
	truck->info();
}