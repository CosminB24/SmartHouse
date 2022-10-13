#pragma once
#include "ISensor.h"
class Humidity :
    public ISensor
{
	double generateHumidity()
	{
		double hi = 99.9;
		double lo = 0;

		double random = ((double)rand()) / (double)RAND_MAX;
		double diff = hi - lo;
		double r = random * diff;
		sensorValue = lo + r;

		return sensorValue;

	}
	double readSensor()
	{
		return generateHumidity();
	}

};

