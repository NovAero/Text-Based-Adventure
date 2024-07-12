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

void Room::ShowContents(bool fStoneActive, bool LOrbActive)
{
	String contents = "In the room you can see ";
	String find;
	String replace;

	if (posX == 2 && posY == 0 && LOrbActive == true) {
		for (Object v : itemsInRoom) {
			if (v.GetID() == -1 || v.NameObj() == "Exit Gate") {
				continue;
			}
			else {
				contents.Suffix("a ");
				contents.Suffix(v.Name());
				contents.Suffix(", ");
				find = v.NameObj();
				break;
			}
		}
	} else {
		for (Object v : itemsInRoom) {

			if (v.GetID() == -1 || v.NameObj() == "Exit Gate") {
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
	}
	int len = contents.len();
	int lastWord = FindFirstEmpty() - 1;

	if (lastWord == 1) {
		contents.Replace(",", ".");
		cout << contents.GetData();
	}
	else {

		find.Prefix("a ");
		replace = find.GetData();
		replace.Prefix("and ");
		replace.Suffix(".");

		contents.Replace(find, replace);
		contents.Replace(".,", ".");

		cout << contents.GetData();
	}
}

int Room::AnyHiddenItems()
{
	int i = 0;
	for(Object h : itemsInRoom) {
		if (h.GetID() != -1 && h.isInvisible() == true) {
			return i;
		}
		++i;
	}
	return -1;
}

int Room::HasItemID(int ID)
{
	int iterator = 0;
	for (Object h : itemsInRoom) {
		if (h.GetID() == ID) {
			return iterator;
		}
		++ iterator;
	}
	return -1;
}

int Room::HasItem(String& item)
{
	int iterator = 0;
	for (Object h : itemsInRoom) {
		if (h.NameObj().ToLower() == item.GetData()) {
			return iterator;
		}
		++iterator;
	}
	return -1;
}

Object& Room::GetItemAtIndex(int index)
{
	if (index != -1) {
		return itemsInRoom[index];
	}
}

const char* Room::Name()
{
	return roomName.GetData();
}

void Room::Description(int roomX, int roomY, bool LOrbActive)
{
	
	int descToSeek = (roomX*10) + roomY; //Sets descToSeek to 10*X + Y, giving a 2 digit number
	if (descToSeek >= 10 && descToSeek < 20) { //if it's >= 10, value is either 10,11,or 12, -7 gives 3,4,5
		descToSeek -= 7;
	}
	else if (descToSeek >= 20) { //Same again but for 20,21,22 remove 14 to give 6,7,8
		descToSeek -= 14;
	}

	if (LOrbActive == true) {
		descToSeek = 9;
	}

	char END_OF_LINE = '#'; //End of Line char in .txt file
	char singleCharacter; //Temp char for iteration
	String retDesc; //string to set and return, clears up temp and new[] keyword

	if (descToSeek < 0 || descToSeek > 9) { //if the seek is out of range 0-8, exits (No descriptions have been included for those)
		cout << "Failure: description doesnt exist, out of range";
		return;
	}

	fstream file; //Opens file for reading
	file.open("Room Descriptions.txt", std::ios::in);

	if (!file.is_open()) { //If its not open, its open by something else, exits
		cout << "Failure to open file";
		return;
	}
	
	int iterator = 0; // iterator is multipurpose, gets number of # chars passed, also used later for storing location in file to read from
	int charsDeep = 0; // to read how many bytes into a file the seekg needs to go, also for setting size of char[]
	int length = 0;

	if (descToSeek > 0){ //If iterator is 0 it doesnt need iterator, thus skips a step, otherwise keep going
		
		while (iterator != descToSeek) {
			file.get(singleCharacter) >> noskipws;
			if (singleCharacter == END_OF_LINE) { //if found end char (#) add to iterator
				iterator++;
			}
			else {
				charsDeep++;
			}
		}

		char temp[500]; //Makes new char[] == length of description
		
		while (iterator != descToSeek+1)	{
			file.get(singleCharacter) >> noskipws;
			if (singleCharacter == END_OF_LINE) {
				iterator++;
			}
			else {
				temp[length] = singleCharacter;
				length++;
			}
		}

		file.close(); //close file !!!

		if (temp[length] != '\0') { //Check for null terminator, adds if it doesnt exist
			temp[length] = '\0';
		}

		retDesc.SetData(temp);

		cout << retDesc.GetData(); //Prints the contents to the console with a \n
		cout << "\n\n";
		
	}
	else { //Does same as above, just skips Step 1: find how deep, since it's starting at the 0 index of file
		
		file.get(singleCharacter) >> noskipws;
		while (singleCharacter != END_OF_LINE) {
			file.get(singleCharacter) >> noskipws;
			length++;
		}

		retDesc = new char[length + 1]; //Makes new char[] == length of description
		file.seekg(0);
		charsDeep = 0; //Sets charsDeep back to 0 again, to iterate over temp[] to set it's contents

		while (charsDeep < length) //Sets contents of temp until end of Description
		{
			file.get(singleCharacter) >> noskipws;

			if (singleCharacter != END_OF_LINE) {
				retDesc[charsDeep] = singleCharacter;
				cout << retDesc[charsDeep];
				charsDeep++;
			}
			else {
				break;
			}
		}

		file.close(); //close file !!!
		length = retDesc.unsafeLen();

		if (retDesc[length] != '\0') { //Check for null terminator, adds if it doesnt exist
			retDesc[length] = '\0';
		}

		retDesc.Print('n'); //returns the contents of retDesc, which is then deleted when out of funtion YAY no memory leaks!!! (hopefully)
		cout << "\n\n";
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
