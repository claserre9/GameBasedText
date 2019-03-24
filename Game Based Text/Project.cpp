#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Utilities.h"
#include "Player.h"
#include "Caporal.h"

using namespace std;


int main() {

	displayStory();
	system("pause");
	cout << endl;

	Player usmarine("Clifford", 10);
	Caporal caporalYun("Caporal", "Yun", 2);

	vector<Room*> rooms;
	Room* currentRoom;
	currentRoom = NULL;
	string userInput;

	rooms.push_back(new Room("Barracks", false, {"Map","Knife"}));
	rooms.push_back(new Room("Messhall", false, {"Food","Books","Ammo"}));
	rooms.push_back(new Room("SchoolHouse", true, {"Gun"}));
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
			cout <<"\n\nYou are in the "<< currentRoom->getDescription() << endl;
		}
		
		if (currentRoom->getDescription() == "Messhall" && caporalYun.getHealth() != 0) {
			cout << "\n\nHEY!!! You were spot by korean soldier" << endl;
			cout << "YOU HAVE TO FIGHT WITH HIM BEFORE HE RINGS THE ALARM" << endl;
			figthscene_1(usmarine, caporalYun,currentRoom);
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