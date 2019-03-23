#pragma once
#include "Enemy.h"
class Caporal : public Enemy {

	using Enemy::Enemy;

	void attack();
	void defend();
};
