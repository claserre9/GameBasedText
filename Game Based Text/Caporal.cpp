#include <string>
#include <iostream>
#include "Enemy.h"

using namespace std;

class Caporal : public Enemy {
public:

	Caporal(string grade, string name, int health) :
		Enemy(grade, name, health) {
	}

	void attack() {
		cout << "Attack as Caporal" << endl;
	}

	void defend() {
		cout << "Defend as Caporal" << endl;
	}

};
