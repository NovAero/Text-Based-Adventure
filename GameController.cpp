#include "GameController.h"

GameController::GameController(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	GenerateRooms(room00,room01,room02,room10,room11,room12,room20,room21,room22);
}

GameController::~GameController()
{
}

void GameController::RunGame()
{	
	int pos[2] = { 0, 0 };

	command.Input();
	command.ToLower();

	if (command.Find("move ")) {

		char direction = command.CharAt(5);

		switch (direction) {

		case 'n':
			try {
				if (rooms[pos[0]][pos[1]].HasItemID(DOOR_ID_N)) {
					pos[1]--;
					LoadRoom(pos[0], pos[1]);
				}
				else {
					throw(rooms[pos[0]][pos[1]].Name());
				}
			}
			catch(const char* name) {
				cout << "You cant go that way";
			}
			break;

		case 'e':

			break;
		case's':

			break;
		case'w':

			break;
		default:

			break;
		}
	}

}

void GameController::LoadRoom(Room& toLoad)
{
	system("CLS");
	cout << "You enter the " << toLoad.Name() << "\n\n";
	cout << toLoad.Description();
	toLoad.ShowContents(false);
}

void GameController::LoadRoom(int x, int y)
{
	LoadRoom(rooms[x][y]);
}

void GameController::GenerateRooms(Object* room00, Object* room01, Object* room02, Object* room10, Object* room11, Object* room12, Object* room20, Object* room21, Object* room22)
{
	rooms[0][0].SetAllData(room00, "The Ossuary", "This room is constructed from bone, walls laden with skulls of many races, and is dimly lit with candles scattered throughout. As you cross the threshold you feel a deep chill set in to your bones, and are met with an impending sense of doom...", 0, 0);
	rooms[0][1].SetAllData(room01, "The Cathedral", "Exiting the Gardens, you heave open the thick oaken doors of the Cathedral, and are greeted by a bright room with rows of pews and an altar in the centre, colourful lights dance through the room as the sun passes through the stained glass windows.", 0, 1);
	rooms[0][2].SetAllData(room02, "The Cemetery", "Opening the gates to the cemetery you see many weathered headstones with faded names, covered in lichen and moss, beyond which is an expansive chasm with a single mausoleum on the other side. You also notice two figures hiding behind gravestones which appear to zombies, they do not notice you.", 0, 2);
	rooms[1][0].SetAllData(room10, "The Forest", "Walking further into the trees, the light from the sun fades out to a dim flicker, with spots of light dancing here and there along the undergrowth, as you near a clearing you see two goblins wielding spears both perched on log stools around a small campfire, one has a scroll attached to his waist. Beyond them you see a magnificent flower, of which they seem to be protecting.", 1, 0);
	rooms[1][1].SetAllData(room11, "The Gardens", "As you enter the garden, a warm breeze blows towards you, thick with the scent of many flowers and fresh dew, there is a Cat asleep on the grass and a small Faerie resting near a large Oak tree in the centre. To the west is a thick forest, to the east is a small library, and directly north is a magnificent cathedral.", 1, 1);
	rooms[1][2].SetAllData(room12, "The Library", "As you enter the library you hear the welcoming jingle of a bell. You note the entire place smells like fresh parchment. You walk further in and there is a shelf of scrolls, only two of which are in a language you can understand. Their tags read \"Dispel Magic\" and \"Jolt\". On the counter is a thick book whose cover reads \"World history\". As you look around, you also notice there is nobody else inside...", 1, 2);
	rooms[2][0].SetAllData(room20, "The Boat Shed", "After opening the door with the rusted key, you look around the dark boat shed, you can't see much other than a table, it's a bit too dark to make out anything clearly.", 2, 0);
	rooms[2][1].SetAllData(room21, "The Coast", "A very empty coast with nothing but sand. There are rockpools to the west and what seems to be a Boat Shed to the east.", 2, 1);
	rooms[2][2].SetAllData(room22, "The Rock Pools", "You come up to some rock pools, each with some tiny fish and a crab or two which quickly scurry away, in one pool you notice a rusted key which seems to have a handle shaped like a boat.", 2, 2);

}