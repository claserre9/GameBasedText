#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Utilities.h"
#include "Player.h"
#include "Caporal.h"
#include <algorithm>

using namespace std;


int main() {

	displayStory();
	system("pause");
	cout << endl;

	Player usmarine("Clifford", 10);
	Caporal caporalYun("Caporal", "Yun", 2);
	Captain captainSong("Captain", "Song", 3);
	Colonel colonelKim("Colonel", "kim", 5);
	Lieutenant lieutenantHun("Lieutenant", "Hun", 5);

	vector<Room*> rooms;
	Room* currentRoom;
	currentRoom = NULL;
	string userInput;

	rooms.push_back(new Room("Barracks", false, {"Map","Knife"}));
	rooms.push_back(new Room("Messhall", false, {"Food","Books","Gun"}));
	rooms.push_back(new Room("SchoolHouse", true, {"Money","Laptop",}));
	rooms.push_back(new Room("RunningField", false, {"Grenade","Sword"}));
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
	bool keyfound;

	while (userInput != "QUIT") {
		if (currentRoom != nullptr) {
			cout <<"\n\nYou are in the "<< currentRoom->getDescription() << endl;
		}
		
		//First fight scene
		if (currentRoom->getDescription() == "Messhall" && caporalYun.getHealth() != 0) {
			cout << "\n\nHEY!!! You were spot by korean soldier, it's a caporal!!" << endl;
			cout << "YOU HAVE TO FIGHT WITH HIM BEFORE HE RINGS THE ALARM!!!" << endl;
			figthscene_1(usmarine, caporalYun,currentRoom);
		}

		//Second fight scene
		if (currentRoom->getDescription() == "SchoolHouse" && captainSong.getHealth() != 0) {
			cout << "\n\nWARNING!!!!!! This time, you meet the captain of the Korean Army" << endl;
			cout << "YOU MUST ABSOLUTELY KILL HIM!!!!!" << endl;
			figthscene_2(usmarine, captainSong, currentRoom);
		}


		

		Menu(usmarine, currentRoom);

		
		cout << "\nWhere do you want to go now? " << endl;
		cin >> userInput;

		
		currentRoom = currentRoom->getRoom(userInput);
		usmarine.accessRoom(currentRoom);

		keyfound = usmarine.keyExist();
		if (currentRoom->getDescription()== "SchoolHouse" && currentRoom->getRoomLockStatus() == true && keyfound == false) {
			cout << "\n\nUnfortunately," <<currentRoom->getDescription() << " is locked !!!" << endl;
			cout << "You have to find a key" << endl;
			cout << "Maybe you should check in the corporal's pocket that you killed in the previous room." << endl;
			cout << "Press any key to return to the MessHall ... \n\n" << endl;
			currentRoom = currentRoom->getRoom("North");
			usmarine.accessRoom(currentRoom);
			system("pause > nul");
		}

		if (currentRoom->getDescription() == "Tunnel"  && colonelKim.getHealth() != 0 && lieutenantHun.getHealth() != 0) {
			cout << "\n\nOMG!!!!!! They are two now waiting for you at the end of the tunnel" << endl;
			cout << "YOU MUST FINISH THEM IN ORDER TO ESCAPE!!!!!" << endl;
			userInput = finalfight(usmarine, colonelKim, lieutenantHun, currentRoom);

		}

		if (currentRoom->getDescription() == "Desert") {
			cout << "You're free from camp, you can escape now !!!" << endl;
			break;
		}
	}
	return 0;
}