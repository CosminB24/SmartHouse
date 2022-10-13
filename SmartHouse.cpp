#pragma once
#include <iostream>
#include "House.h"
#include "Living.h"
#include "Bathroom.h"
#include "Bedroom.h"
#include "Kitchen.h"
using namespace std;

int main()
{
    cout << "My House:\n";


    House myHouse;
    Living myLiving;
    Bedroom myBedroom;
    Kitchen myKitchen;
    Bathroom myBathroom;

    myHouse.addRoom(&myLiving);
    myHouse.addRoom(&myBedroom);
    myHouse.addRoom(&myKitchen);
    myHouse.addRoom(&myBathroom);

    myHouse.collectData();
    myHouse.collectData();
    myHouse.collectData();


    myHouse.viewRoomData();
    
    
}

