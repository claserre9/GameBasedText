#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Utilities.h"
#include "Player.h"

using namespace std;


int main() {

	Player usmarine("Clifford", 10);

	vector<Room*> rooms;
	Room* currentRoom;
	currentRoom = NULL;
	string userInput;

	rooms.push_back(new Room("Barracks", false, {"Map","Knife"}));
	rooms.push_back(new Room("Messhall"));
	rooms.push_back(new Room("SchoolHouse"));
	rooms.push_back(new Room("RunningField"));
	rooms.push_back(new Room("Tunnel"));
	rooms.push_back(new Room("Desert"));

	//Room order to set direction : Northside, eastside, soutside, westside (clockwise)

	rooms[0]->setRooms(nullptr, rooms[1], nullptr, nullptr);
	rooms[1]->setRooms(nullptr, nullptr, rooms[2], rooms[0]);
	rooms[2]->setRooms(rooms[1], nullptr, nullptr, rooms[3]);
	rooms[3]->setRooms(nullptr, rooms[2], rooms[4], nullptr);
	rooms[4]->setRooms(rooms[3], rooms[5], nullptr, nullptr);
	rooms[5]->setRooms(nullptr, nullptr, nullptr, rooms[4]);

	currentRoom = rooms[0];
	usmarine.accessRoom(currentRoom); //This is the way USMARINE access a room by the method "accessRoom()"

	while (userInput != "QUIT") {
		if (currentRoom != nullptr) {
			cout <<"You are in the "<< currentRoom->getDescription() << endl;
		}

		Menu(usmarine, currentRoom);

		cout << "\nWhere do you want to go now? " << endl;
		cin >> userInput;

		currentRoom = currentRoom->getRoom(userInput);
		usmarine.accessRoom(currentRoom); //The ma
		if (currentRoom->getDescription() == "Desert") {
			cout << "You're free from camp, you can escape now !!!" << endl;
			break;
		}
	}
	return 0;
}