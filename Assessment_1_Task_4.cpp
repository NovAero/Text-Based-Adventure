#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include "GameController.h"
#include "Object.h"

	Cat cats[2];
	Enemy enemies[5];
	ManaFtn fountain;
	Scroll scrolls[10] = {SCROLL_ID_DM,SCROLL_ID_L,SCROLL_ID_FB,SCROLL_ID_FD,SCROLL_ID_FS,SCROLL_ID_SWA,SCROLL_ID_J,SCROLL_ID_LO,SCROLL_ID_MM,SCROLL_ID_H};
	Door exitGates[4] = { DOOR_ID_N,DOOR_ID_E,DOOR_ID_S,DOOR_ID_W };

	Door boatDoor(DOOR_ID_W, "Boat Shed Door", "Run down wooden double doors, locked.");
	Door ossuaryDoor(DOOR_ID_W, "Ossuary Door", "A heavy mahogany door with a single skull in the centre, magically sealed");
	Door cemetaryDoor(DOOR_ID_E, "Cemetery Gates", "Large cast iron gates to the cemetary, locked with a special key.");
	Door tombstone(DOOR_ID_E, "Your Tombstone", "ENDGAME Y/N");

	Key rustedKey("Rusted Key", "A rusty key with a handle shaped like a boat", false, RUSTED_KEY_ID);
	Key cemeteryKey("Cemetery Key", "A glittering silver key", true, CEMETERY_KEY_ID);

	Object room00[MAX_ITEM_COUNT] = { cats[0], exitGates[1], scrolls[2]};
	Object room01[MAX_ITEM_COUNT] = { exitGates[2], ossuaryDoor, cemetaryDoor, fountain, cemeteryKey, scrolls[7]};
	Object room02[MAX_ITEM_COUNT] = { exitGates[3], tombstone, scrolls[3] };
	Object room10[MAX_ITEM_COUNT] = { exitGates[1], scrolls[5] };
	Object room11[MAX_ITEM_COUNT] = { cats[1], exitGates[0], exitGates[1], exitGates[2], exitGates[3]};
	Object room12[MAX_ITEM_COUNT] = { exitGates[3], scrolls[0], scrolls[6] };
	Object room20[MAX_ITEM_COUNT] = { exitGates[1], scrolls[9] };
	Object room21[MAX_ITEM_COUNT] = { boatDoor, exitGates[0], exitGates[1]};
	Object room22[MAX_ITEM_COUNT] = { exitGates[3] , rustedKey };
	
int main() {

	String nameSet;
	cout << "What is your character's name?\n";
	nameSet.Input();

	system("CLS");

	GameController ctrl(nameSet,room00,room01,room02,room10,room11,room12,room20,room21,room22);
	
	ctrl.RunGame(1,2, true);
}


//TODO Add faerie, key object "magic flower", enemy types, combat module