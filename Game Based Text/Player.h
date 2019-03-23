#pragma once

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
private:
	string playername;
	int health;
	vector<string> inventory;

public:
	Player(string playername, int health);
	~Player();
	//void attack();
	//void defend();
	void search();
	void look();
	void open();
	void take();
	void drop();

};