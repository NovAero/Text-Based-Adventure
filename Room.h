#pragma once
#include "Object.h"
#include "String.h"

#define MAX_ITEM_COUNT 10

class Room
{
public:

	Room();
	Room(Object* items, const char* name, const char* description, int x, int y);
	~Room();

public:

	void SetAllData(Object* contents, const char* name, const char* desc, int x, int y);

	void SetCoords(int x, int y);
	int GetX();
	int GetY();

	void ShowContents(bool fStoneActive);
	bool HasItemID(int ID);
	const char* Name();
	const char* Description();

	int FindFirstEmpty();

	void AppendItem(Object& obj);
	void RemoveItem(Object& obj);

	void SetContents(Object* items);
	void SetName(const char* name);
	void SetDesc(const char* desc);


public:

	String roomName;
	String roomDesc;
	Object itemsInRoom[MAX_ITEM_COUNT];

	int posX = -1;
	int posY = -1;
};

