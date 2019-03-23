/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include <iostream>
#include "Enemy.h"


class Lieutenant :public Enemy {

	Lieutenant(string grade, string name, int health) :
		Enemy(grade, name, health) {
	}

	void attack() {
		cout << "Attack as Lieutenant" << endl;
	}

	void defend() {
		cout << "Defend as Lieutenant" << endl;
	}


};