#include <fstream>
#include <string>
#include "IRoom.h"
#include "Kitchen.h"
#include "ISensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Pressure.h"

using namespace std;

void Kitchen::createRoom()
{
	cout << "Creating kitchen" << endl;

	ofstream roomFile("kitchen.txt");
	roomFile.close();

	sensors.push_back(new Temperature());
	sensors.push_back(new Humidity());
	sensors.push_back(new Pressure());

}

void Kitchen::readRoom()
{

	string line;
	ifstream roomFile("kitchen.txt");
	if (roomFile.is_open())
	{
		cout << "Kitchen:" << endl;
		while (getline(roomFile, line))
		{
			cout << line << '\n';
		}
		roomFile.close();
	}
}

void Kitchen::updateRoom()
{

	ofstream roomFile;
	roomFile.open("kitchen.txt", std::ios_base::app);

	for (int i = 0; i < sensors.size(); i++)
	{
		double value = (*(sensors.at(i))).readSensor();
		roomFile << "Sensor" << i << "=" << value << " ";
	}
	roomFile << endl;

	roomFile.close();
}
void Kitchen::deleteRoom()
{
	remove("kitchen.txt");
}
