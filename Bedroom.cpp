#pragma once
#include <fstream>
#include <string>
#include "IRoom.h"
#include "Bedroom.h"
#include "ISensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Pressure.h"

using namespace std;

void Bedroom::createRoom()
{
	cout << "Creating bedroom" << endl;

	ofstream roomFile("bedroom.txt");
	roomFile.close();

	sensors.push_back(new Temperature());
	sensors.push_back(new Humidity());
	sensors.push_back(new Pressure());

}


void Bedroom::readRoom()
{

	string line;
	ifstream roomFile("bedroom.txt");
	if (roomFile.is_open())
	{
		cout << "Bedroom:" << endl;
		while (getline(roomFile, line))
		{
			cout << line << '\n';
		}
		roomFile.close();
	}
}



void Bedroom::updateRoom()
{

	ofstream roomFile;
	roomFile.open("bedroom.txt", std::ios_base::app);

	for (int i = 0; i < sensors.size(); i++)
	{
		double value = (*(sensors.at(i))).readSensor();
		roomFile << "Sensor" << i << "=" << value << " ";
	}
	roomFile << endl;

	roomFile.close();
}
void Bedroom::deleteRoom()
{
	remove("bedroom.txt");
}