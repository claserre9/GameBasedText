#include <string>
#include <iostream>
#include "Enemy.h"


class Major :public Enemy {

	Major(string grade, string name, int health) :
		Enemy(grade, name, health) {
	}

	void attack() {
		cout << "Attack as Major" << endl;
	}

	void defend() {
		cout << "Defend as Major" << endl;
	}


};