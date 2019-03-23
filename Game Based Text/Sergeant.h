#pragma once
#include "Enemy.h"
class Sergeant : public Enemy {

	using Enemy::Enemy;
public:
	void attack();
	void defend();
};
