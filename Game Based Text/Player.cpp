
#include "Player.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

Player::Player(string playername, int health) {
	this->playername = playername;
	this->health = health;
	this->CurrentRoom = NULL;
}

Player::~Player() {
}

void Player::search() {
	this->CurrentRoom->showItems();
}

void Player::drop(string element) {
	if (find(this->inventory.begin(), this->inventory.end(), element) != this->inventory.end()) {
		this->inventory.erase(remove(this->inventory.begin(), this->inventory.end(), element), this->inventory.end());
	}

}

void Player::accessRoom(Room* room) {
	this->CurrentRoom = room;
}

void Player::getInventory(){
	if (this->inventory.size() != 0) {
		for (auto i = this->inventory.begin(); i != this->inventory.end(); ++i)
			cout << *i << '--';
	}
	else {
		cout << "Your inventory is empty" << endl;
	}

}

void Player::take(string element) {
		this->inventory.push_back(element);
}
	

void Player::open() {
	if (find(this->inventory.begin(), this->inventory.end(), "Key") != this->inventory.end()) {
		if (this->CurrentRoom->getRoomLockStatus()) {
			this->CurrentRoom->setRoomLockStatus(true);
		}
	}
}

