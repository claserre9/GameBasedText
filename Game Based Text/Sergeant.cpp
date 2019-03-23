#include <string>
#include <iostream>
#include "Enemy.h"


class Sergeant :public Enemy {

	Sergeant(string grade, string name, int health) :
		Enemy(grade, name, health) {
	}

	void attack() {
		cout << "Attack as Sergeant" << endl;
	}

	void defend() {
		cout << "Defend as Sergeant" << endl;
	}


};