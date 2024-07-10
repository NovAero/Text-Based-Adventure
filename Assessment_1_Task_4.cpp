#include <iostream>
#include "String.h"
#include "GameController.h"

int main() {

	Object room00[MAX_ITEM_COUNT];
	Object room01[MAX_ITEM_COUNT];
	Object room02[MAX_ITEM_COUNT];
	Object room10[MAX_ITEM_COUNT];
	Object room11[MAX_ITEM_COUNT];
	Object room12[MAX_ITEM_COUNT];
	Object room20[MAX_ITEM_COUNT];
	Object room21[MAX_ITEM_COUNT];
	Object room22[MAX_ITEM_COUNT];
	
	GameController ctrl(room00,room01,room02,room10,room11,room12,room20,room21,room22);

	ctrl.RunGame();
}