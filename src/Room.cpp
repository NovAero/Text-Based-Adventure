#include "Room.h"

Room::Room()
{
	posX = 10;
	posY = 7;
}

Room::Room(Object* items, int x, int y)
{
	SetContents(items);
	posX = x;
	posY = y;
}

Room::~Room()
{

}


void Room::GetCoords()
{
	String strX = posX;
	String strY = posY;

	String phrase = "X: [x], Y: [y]";
	phrase.Replace("[x]", strX);
	phrase.Replace("[y]", strY);

	cout << phrase.GetData() << endl;
}

void Room::ShowContents(bool fStoneActive)
{
	for (Object v : itemsInRoom) {

		if (v.GetID() == -1) {
			continue;
		}

		if (v.isInvisible() == true && fStoneActive == true) {
			cout << v.Name() << " " << "(invisible)" << endl;
		}
		else if (v.isInvisible() == true && fStoneActive != true) {
			continue;
		}
		else if (v.isInvisible() != true) {
			cout << v.Name() << endl;
		}
	}
}

int Room::FindFirstEmpty()
{
	int i = 0;
	for (Object& o : itemsInRoom) {

		if (o.GetID() == -1) {
			return i;
		}
		++i;
	}
	return -1;
}

void Room::AppendItem(Object& obj)
{
	if (FindFirstEmpty() != -1) {
		itemsInRoom[FindFirstEmpty()].CopyData(obj);
		return;
	}
	cout << "No Empty Slots";
}

void Room::RemoveItem(Object& obj)
{
	for (Object& i : itemsInRoom) {

		if (i.GetID() == obj.GetID()) {
			i.SetData("N/A", "Empty", -1, false);
			cout << "Removed " << obj.Name() << " from room " << endl;
			return;
		}

	}
	cout << "Item is not in room" << endl;
}

void Room::SetContents(Object* items)
{
	for (int i = 0; i < MAX_ITEM_COUNT; i++) {
		AppendItem(items[i]);
	}
}
