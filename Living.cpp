#pragma once
#include <fstream>
#include <string>
#include <stdio.h>
#include "IRoom.h"
#include "Living.h"
#include "ISensor.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Pressure.h"

using namespace std;

void Living::createRoom()
{
	cout << "Creating living" << endl;

	ofstream roomFile("living.txt");
	roomFile.close();

	sensors.push_back(new Temperature());

	sensors.push_back( new Humidity());

	sensors.push_back(new Pressure());

}
void Living::readRoom()
{

	string line;
	ifstream roomFile("living.txt");
	if (roomFile.is_open())
	{
		cout << "Living:" << endl;
		while (getline(roomFile, line))
		{
			cout << line << '\n';
		}
		roomFile.close();
	}
}

void Living::updateRoom()
{
	
	ofstream roomFile;
	roomFile.open("living.txt", std::ios_base::app);

	for (int i = 0; i < sensors.size(); i++)
	{
		double value = (*(sensors.at(i))).readSensor();
		roomFile << "Sensor" << i << "=" << value << " ";
	}
	roomFile << endl;
   
	roomFile.close();
}
void Living::deleteRoom()
{
	remove("living.txt");
}
