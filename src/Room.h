#pragma once
#include "Object.h"
#include "String.h"
#include "Cat.h"

#define MAX_ITEM_COUNT 10

class Room
{
public:

	Room();
	Room(Object* items, int x, int y);
	~Room();

public:

	void GetCoords();

	void ShowContents(bool fStoneActive);

	int FindFirstEmpty();

	void AppendItem(Object& obj);
	void RemoveItem(Object& obj);

	void SetContents(Object* items);


public:

	Object itemsInRoom[MAX_ITEM_COUNT];

private:

	int posX = -1;
	int posY = -1;
};

