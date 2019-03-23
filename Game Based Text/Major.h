#pragma once
#include "Enemy.h"
class Major : public Enemy {

	using Enemy::Enemy;
public:
	void attack();
	void defend();
};
