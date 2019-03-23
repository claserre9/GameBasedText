
#include <string>

#include "Enemy.h"


Enemy::Enemy() {
	this->grade = "";
	this->name = "";
	this->health = 1;
}

Enemy::Enemy(string grade, string name, int health) {
	this->grade = grade;
	this->name = name;
	this->health = health;
}

Enemy::~Enemy() {
};

void Enemy::attack() {
};

void Enemy::defend() {
};

string Enemy::getGrade() {
	return grade;
};

string Enemy::getName() {
	return name;
}

int Enemy::getHealth() {
	return health;
};

int Enemy::setHealth(int h) {
	this->health = h;
}