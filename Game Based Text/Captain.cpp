
#include <string>
#include <iostream>
#include "Enemy.h"


class Captain :public Enemy {

	Captain(string grade, string name, int health) :
		Enemy(grade, name, health) {
	}

	void attack() {
		cout << "Attack as Captain" << endl;
	}

	void defend() {
		cout << "Defend as Captain" << endl;
	}


};