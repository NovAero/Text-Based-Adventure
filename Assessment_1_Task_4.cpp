#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include "GameController.h"
#include "Object.h"

	Cat cats[2];
	Enemy enemy;

	Faerie faerie;

	ManaFtn fountain;

	Scroll dm(SCROLL_ID_DM, false);
	Scroll l(SCROLL_ID_L, true);
	Scroll fb(SCROLL_ID_FB, true);
	Scroll fd(SCROLL_ID_FD, false);
	Scroll swa(SCROLL_ID_SWA, false);
	Scroll j(SCROLL_ID_J, false);
	Scroll lo(SCROLL_ID_LO, false);
	Scroll hs(SCROLL_ID_H, false);

	Door exitGates[4] = { DOOR_ID_N,DOOR_ID_E,DOOR_ID_S,DOOR_ID_W };

	Door boatDoor(DOOR_ID_W, "Boat Shed Door", "Run down wooden double doors, locked.");
	Door ossuaryDoor(DOOR_ID_W, "Ossuary Door", "A heavy mahogany door with a single skull in the centre, magically sealed");
	Door cemetaryDoor(DOOR_ID_E, "Cemetery Gates", "Large cast iron gates to the cemetary, locked with a special key.");
	Door tombstone(DOOR_ID_E, "Your Tombstone", "ENDGAME Y/N");

	Key rustedKey("Rusted Key", "A rusty key with a handle shaped like a boat", false, RUSTED_KEY_ID);
	Key cemeteryKey("Cemetery Key", "A glittering silver key", true, CEMETERY_KEY_ID);
	Key flowerKey("Magic Flower", "An incandescent white flower", false, FAERIE_KEY_ID);

	Object room00[MAX_ITEM_COUNT] = { cats[0], exitGates[1], fb};
	Object room01[MAX_ITEM_COUNT] = { exitGates[2], ossuaryDoor, cemetaryDoor, fountain, cemeteryKey};
	Object room02[MAX_ITEM_COUNT] = { exitGates[3], tombstone, fd };
	Object room10[MAX_ITEM_COUNT] = { exitGates[1], swa , flowerKey, enemy };
	Object room11[MAX_ITEM_COUNT] = { cats[1], exitGates[0], exitGates[1], exitGates[2], exitGates[3], l, faerie};
	Object room12[MAX_ITEM_COUNT] = { exitGates[3], dm, j };
	Object room20[MAX_ITEM_COUNT] = { exitGates[1], hs };
	Object room21[MAX_ITEM_COUNT] = { boatDoor, exitGates[0], exitGates[1]};
	Object room22[MAX_ITEM_COUNT] = { exitGates[3] , rustedKey };
	
int main() {

	String nameSet;
	cout << "What is your character's name?\n";
	nameSet.Input();

	system("CLS");

	GameController ctrl(nameSet,room00,room01,room02,room10,room11,room12,room20,room21,room22);
	
	cout << "As your eyes struggle to open, you take in your surroundings and realise you are on a beach, you do \nnot know who you are.\nAll that you can remember is falling into the sea...\n\nAs you gather yourself, you check your belongings and find an empty spellbook, you might have been a mage?.\n\n";
	cout << "Type \"help\" for a list of commands\n\n";

	ctrl.RunGame(2,1, true);
}


//TODO Add faerie, key object "magic flower", enemy types, combat module