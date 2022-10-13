#pragma once
#include "ISensor.h"
class Temperature :
    public ISensor
{

	double generateTemperature()
	{
		double hi = 80;
		double lo = -40;

		double random = ((double)rand()) / (double)RAND_MAX;
		double diff = hi - lo;
		double r = random * diff;
		sensorValue = lo + r;

		return sensorValue;
		
	}
	double readSensor()
	{
		return generateTemperature();
	}


};

