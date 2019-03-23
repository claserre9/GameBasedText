#pragma once
#include "Enemy.h"
class Captain: public Enemy {

	using Enemy::Enemy;
public:
	void attack();
	void defend();
};