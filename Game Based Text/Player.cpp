/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Player.h"
#include <string>
#include <vector>

using namespace std;

Player::Player(string playername, int health) {
	this->playername = playername;
	this->health = health;
}

Player::~Player() {
}

void Player::search() {
}

void Player::drop() {
}

void Player::take() {
}

void Player::open() {
}