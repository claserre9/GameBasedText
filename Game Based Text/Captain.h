#pragma once
#include "Enemy.h"
class Captain: public Enemy {

	using Enemy::Enemy;

	void attack();
	void defend();
};