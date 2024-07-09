#include "Room.h"

Room::Room()
{
	posX = 10;
	posY = 7;
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
			cout << v.Name() << " " << v.isInvisible() << endl;
		}
		else if (v.isInvisible() == true && fStoneActive != true) {
			continue;
		}
		else if (v.isInvisible() != true) {
			cout << v.Name() << endl;
		}
	}
}

void Room::AppendItem(Object& obj)
{
	for (Object& i : itemsInRoom) {

		if (i.GetID() == -1) {
			i.CopyData(obj);
			cout << "Added " << obj.Name() << " to room " << endl;
			return;
		}

	}
	cout << "Room is full" << endl;
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
