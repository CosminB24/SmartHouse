#pragma once
#include "ISensor.h"
class Pressure :
    public ISensor
{
	double generatePressure()
	{
		double hi = 1100;
		double lo = 300;

		double random = ((double)rand()) / (double)RAND_MAX;
		double diff = hi - lo;
		double r = random * diff;
		sensorValue = lo + r;

		return sensorValue;

	}
	double readSensor()
	{
		return generatePressure();
	}
};

