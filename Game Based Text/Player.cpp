
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

Room * Player::getCurrentRoom(){
	return this->CurrentRoom;
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
		cout << "You have : " << endl;
		for (auto i = this->inventory.begin(); i != this->inventory.end(); ++i) {
			cout << *i << endl;
		}
			
	}
	else {
		cout << "Your inventory is empty" << endl;
	}

}

void Player::setHealth(int h){
	this->health = h;
}

int Player::getHealth(){
	return this->health;
}

vector<string> Player::get_items_taken(){
	return this->inventory;
}

bool Player::keyExist(){
	if (find(this->inventory.begin(), this->inventory.end(), "Key") != this->inventory.end()) {
		return true;
	}
	else {
		return false;
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

