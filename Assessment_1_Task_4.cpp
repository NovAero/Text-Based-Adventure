#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include "GameController.h"


	Cat cats[2];
	Enemy enemies[5];
	ManaFtn fountain;
	Scroll scrolls[10] = {0,1,2,3,4,5,6,7,8,9};
	Door exitGates[4] = { DOOR_ID_N,DOOR_ID_E,DOOR_ID_S,DOOR_ID_W };
	Door keyDoors[3] = { 
			(DOOR_ID_W, "Boat Shed Door", "Run down wooden double doors, locked.") ,
			(DOOR_ID_W, "Ossuary Door", "A heavy mahogany door with a single skull in the centre, magically sealed"),
			(DOOR_ID_E, "Cemetery Gates", "Large cast iron gates to the cemetary, locked with a special key.") 
	};
	
	Object room00[MAX_ITEM_COUNT];
	Object room01[MAX_ITEM_COUNT];
	Object room02[MAX_ITEM_COUNT];
	Object room10[MAX_ITEM_COUNT];
	Object room11[MAX_ITEM_COUNT];
	Object room12[MAX_ITEM_COUNT];
	Object room20[MAX_ITEM_COUNT];
	Object room21[3] = { keyDoors[0], exitGates[0], exitGates[1]};
	Object room22[MAX_ITEM_COUNT];
	
int main() {

	GameController ctrl(room00,room01,room02,room10,room11,room12,room20,room21,room22);

	ctrl.LoadRoom(0, 0);
	ctrl.LoadRoom(0, 1);
	ctrl.LoadRoom(0, 2);
	ctrl.LoadRoom(1, 0);
	ctrl.LoadRoom(1, 1);
	ctrl.LoadRoom(1, 2);
	ctrl.LoadRoom(2, 0);
	ctrl.LoadRoom(2, 1);
	ctrl.LoadRoom(2, 2);

}
