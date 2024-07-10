#include "Room.h"

Room::Room()
{
	posX = 0;
	posY = 0;
}

Room::Room(Object* items, const char* name, int x, int y)
{
	SetAllData(items, name, x, y);
}

Room::~Room()
{

}


void Room::SetAllData(Object* contents, const char* name, int x, int y)
{
	SetName(name);
	SetContents(contents);
	SetCoords(x, y);
}

void Room::SetCoords(int x, int y)
{
	posX = x;
	posY = y;
}

int Room::GetX()
{
	return posX;
}

int Room::GetY()
{
	return posY;
}

void Room::ShowContents(bool fStoneActive)
{
	String contents = "In the room you can see ";
	String find;
	String replace;

	for (Object v : itemsInRoom) {

		if (v.GetID() == -1 || v.Name() == "Exit Gate") {
			continue;
		}
		if (v.isInvisible() == true && fStoneActive == true) {
			contents.Suffix("a ");
			contents.Suffix(v.Name());
			contents.Suffix(", ");
			find = v.NameObj();
		}
		else if (v.isInvisible() == true && fStoneActive != true) {
			continue;
		}
		else if (v.isInvisible() != true) {
			contents.Suffix("a ");
			contents.Suffix(v.Name());
			contents.Suffix(", ");
			find = v.NameObj();
		}
	}
	int len = contents.len();
	int lastWord = FindFirstEmpty() - 1;
	int lastWordLen = itemsInRoom[lastWord].NameObj().len();

	find.Prefix("a ");
	replace = find.GetData();
	replace.Prefix("and ");
	replace.Suffix(".");

	contents.Replace(find, replace);
	contents.Replace(".,", ".");

	cout << contents.GetData();
}

bool Room::HasItemID(int ID)
{
	for (Object h : itemsInRoom) {
		if (h.GetID() == ID) {
			return true;
		}
	}
	return false;
}

const char* Room::Name()
{
	return roomName.GetData();
}

const char* Room::Description()
{
	return roomDesc.GetData();
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

void Room::SetName(const char* name)
{
	roomName = name;
}

void Room::SetDesc(const char* desc)
{
	roomDesc = desc;
}
