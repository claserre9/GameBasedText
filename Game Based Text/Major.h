#pragma once
#include "Enemy.h"
class Major : public Enemy {

	using Enemy::Enemy;

	void attack();
	void defend();
};
