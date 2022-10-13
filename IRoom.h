#pragma once
#include <iostream>


using namespace std;

class IRoom
{
public:
	virtual void createRoom()=0;
	virtual void readRoom()=0 ;
	virtual void updateRoom()=0;
	virtual void deleteRoom()=0;


};