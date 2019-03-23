#pragma once
#include "Enemy.h"
class Colonel : public Enemy {

	using Enemy::Enemy;
public:
	void attack();
	void defend();
};

