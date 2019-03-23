#pragma once
#include "Enemy.h"
class Caporal : public Enemy {

	using Enemy::Enemy;
public:
	void attack();
	void defend();
};
