#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include "Room.h"

using namespace std;

class Player {
private:
	string playername;
	int health;
	vector<string> inventory;
	Room* CurrentRoom;


public:
	Player(string playername, int health);
	~Player();

	//void attack();
	//void defend();

	void search();
	void open();
	void take(string element);
	void drop(string element);
	void accessRoom(Room* room);
	void getInventory();

};