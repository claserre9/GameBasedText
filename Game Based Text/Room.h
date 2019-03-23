#pragma once

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Room {
public:
	Room(string description);
	~Room();

	string getDescription();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);

	Room* getRoom(string direction);


private:
	// List of items
	string description;
	vector<string> listOfitems;
	bool roomlocked;

	Room* northRoom;
	Room* eastRoom;
	Room* southRoom;
	Room* westRoom;
};
