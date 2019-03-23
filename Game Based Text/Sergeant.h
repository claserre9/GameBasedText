#pragma once
#include "Enemy.h"
class Sergeant : public Enemy {

	using Enemy::Enemy;

	void attack();
	void defend();
};
