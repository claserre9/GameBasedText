#pragma once
#include "Enemy.h"
class Lieutenant : public Enemy {

	using Enemy::Enemy;

	void attack();
	void defend();
};
