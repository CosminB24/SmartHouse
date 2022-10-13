#pragma once
#pragma once
#include <iostream>


using namespace std;

class ISensor
{

protected:
	double sensorValue;

public:
	virtual double readSensor()=0;
};