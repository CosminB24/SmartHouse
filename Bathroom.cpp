#pragma once
#include <fstream>
#include <string>
#include "IRoom.h"
#include "Bathroom.h"
#include "ISensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Pressure.h"

using namespace std;

void Bathroom::createRoom()
{
	
	cout << "Creating bathroom " << endl;

	ofstream roomFile("bathroom.txt");
	roomFile.close();

	sensors.push_back(new Temperature());
	sensors.push_back(new Humidity());
	sensors.push_back(new Pressure());

}
	

void Bathroom::readRoom()
{

	string line;
	ifstream roomFile("bathroom.txt");
	if (roomFile.is_open())
	{
		cout << "Bathroom:" << endl;
		while (getline(roomFile, line))
		{
			cout << line << '\n';
		}
		roomFile.close();
	}
}


void Bathroom::updateRoom()
{

	ofstream roomFile;
	roomFile.open("bathroom.txt", std::ios_base::app);

	for (int i = 0; i < sensors.size(); i++)
	{
		double value = (*(sensors.at(i))).readSensor();
		roomFile << "Sensor" << i << "=" << value << " ";
	}
	roomFile << endl;

	roomFile.close();
}
void Bathroom::deleteRoom()
{
	remove("bathroom.txt");
}