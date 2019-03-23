#pragma once
#include "Enemy.h"
class Colonel : public Enemy {

	using Enemy::Enemy;

	void attack();
	void defend();
};

