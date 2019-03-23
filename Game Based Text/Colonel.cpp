#include <string>
#include <iostream>
#include "Enemy.h"


class Colonel :public Enemy {

	Colonel(string grade, string name, int health) :
		Enemy(grade, name, health) {
	}

	void attack() {
		cout << "Attack as Colonel" << endl;
	}

	void defend() {
		cout << "Defend as Colonel" << endl;
	}


};