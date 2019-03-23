#pragma once
#include "Enemy.h"
class Lieutenant : public Enemy {

	using Enemy::Enemy;
public:
	void attack();
	void defend();
};
