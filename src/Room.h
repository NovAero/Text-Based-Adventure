#pragma once
#include "Object.h"
#include "String.h"
#include "Cat.h"

class Room
{
public:

	Room();
	~Room();

public:

	void GetCoords();

	void ShowContents(bool fStoneActive);

	void AppendItem(Object& obj);
	void RemoveItem(Object& obj);

public:

	Object itemsInRoom[3];

private:

	int posX = -1;
	int posY = -1;

	int numOfItems = 0;


};

