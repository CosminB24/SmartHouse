#pragma once
#include <vector>
#include <iostream>
#include "IRoom.h"

using namespace std;

class House
{
private:
	vector <IRoom*> rooms;

public:
	void addRoom(IRoom*);
	void removeRoom(int);
	void collectData();
	void viewRoomData();

};

