#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include "GameController.h"

//Cat cats[2];
//Enemy enemies[5];
//ManaFtn fountain;
//Scroll scrolls[10] = {0,1,2,3,4,5,6,7,8,9};
//
//Object room00[MAX_ITEM_COUNT];
//Object room01[MAX_ITEM_COUNT];
//Object room02[MAX_ITEM_COUNT];
//Object room10[MAX_ITEM_COUNT];
//Object room11[MAX_ITEM_COUNT];
//Object room12[MAX_ITEM_COUNT];
//Object room20[MAX_ITEM_COUNT];
//Object room21[MAX_ITEM_COUNT] = { cats[0], enemies[0], scrolls[3] };
//Object room22[MAX_ITEM_COUNT];
//
//GameController ctrl(room00,room01,room02,room10,room11,room12,room20,room21,room22);

int main() {

	String text;
	
	char END_OF_LINE = '#';
	char singleCharacter;

	fstream file;
	file.open("Room Descriptions.txt", std::ios::in);
	if (!file.is_open()) {
		return 1;
	}

	file.get(singleCharacter);
	
	while (singleCharacter != END_OF_LINE)
	{
		cout << singleCharacter;
		file.get(singleCharacter);
	}

	file.close();

	return 0;

}
