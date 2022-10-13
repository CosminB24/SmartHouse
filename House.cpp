#include <iostream>
#include "House.h"
#include "IRoom.h"

void House::addRoom(IRoom* newRoom)
{
	(*newRoom).createRoom();
	rooms.push_back(newRoom);

}
void House::removeRoom(int index)
{
	
	rooms.erase(rooms.begin() + index);
}

void House::collectData()
{
	for (int i = 0; i < rooms.size() ; i++)
	{
		
		(*(rooms.at(i))).updateRoom();

	}

}

void House::viewRoomData()
{
	for (int i = 0; i < rooms.size() ; i++)
	{
		cout << "Room" << i << endl;
		(*(rooms.at(i))).readRoom();
		
	}
}