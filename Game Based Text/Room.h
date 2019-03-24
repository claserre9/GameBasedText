#pragma once

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Room {
public:
	Room(string description);
	Room(string description, bool lockstatus);
	Room(string description, bool lockstatus, vector<string> listItems);
	~Room();

	string getDescription();
	void setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom);

	Room* getRoom(string direction);
	
	void removeItem(string element);

	void showItems();

	vector<string> getListItems();

	bool getRoomLockStatus();
	void setRoomLockStatus(bool b);

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
