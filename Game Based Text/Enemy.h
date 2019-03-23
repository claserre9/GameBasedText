#pragma once

using namespace std;

class Enemy {
private:
	string grade;
	string name;
	int health;

public:
	Enemy();
	Enemy(string grade, string name, int health);
	virtual ~Enemy();
	string getGrade();
	string getName();
	int getHealth();
	int setHealth(int h);
	virtual void attack() = 0;
	virtual void defend() = 0;
};
