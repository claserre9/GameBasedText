#include "Room.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

Room::Room(string description) {
	this->description = description;
	this->roomlocked = false;
}

Room::Room(string description, bool lockstatus) {
	this->description = description;
	this->roomlocked = lockstatus;
}

Room::Room(string description, bool lockstatus, vector<string> listItems) {
	this->description = description;
	this->roomlocked = lockstatus;
	this->listOfitems = listItems;
}

Room::~Room() {
}

string Room::getDescription() {
	return this->description;
}

void Room::setRooms(Room* northRoom, Room* eastRoom, Room* southRoom, Room* westRoom) {
	this->northRoom = northRoom;
	this->southRoom = southRoom;
	this->eastRoom = eastRoom;
	this->westRoom = westRoom;
}
vector<string> Room::getListItems() {
	return this->listOfitems;
}

bool Room::getRoomLockStatus(){
	return this->roomlocked;
}

void Room::setRoomLockStatus(bool b){
	this->roomlocked = b;
}

Room* Room::getRoom(std::string direction) {
	if (direction == "North" && this->northRoom != nullptr) {
		return this->northRoom;
	}
	else if (direction == "East" && this->eastRoom != nullptr) {
		return this->eastRoom;
	}
	else if (direction == "South" && this->southRoom != nullptr) {
		return this->southRoom;
	}
	else if (direction == "West" && this->westRoom != nullptr) {
		return this->westRoom;
	}
	else {
		return this;
	}
}

void Room::removeItem(string element) {
	if (find(this->listOfitems.begin(), this->listOfitems.end(), element) != this->listOfitems.end())
		this->listOfitems.erase(remove(this->listOfitems.begin(), this->listOfitems.end(), element), this->listOfitems.end());
}
	
void Room::showItems() {
	cout << "There are : \n" << endl;
	for (auto i = this->listOfitems.begin(); i != this->listOfitems.end(); ++i) {
		cout << *i << endl;
	}

		
}


