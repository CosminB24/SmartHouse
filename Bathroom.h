#pragma once
#include "IRoom.h"
#include "ISensor.h"
#include <vector>


class Bathroom :
    public IRoom
{
private:
	vector <ISensor*> sensors;


public:
	void createRoom();
	void readRoom();
	void updateRoom();
	void deleteRoom();
	
};



