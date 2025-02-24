#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

	class Monk; // Forward declaration

class Monster {
protected:
	std::string name;
	int health;
	int attackPower;

public:
	Monster(std::string n, int h, int a) : name(n), health(h), attackPower(a) {}

	virtual void attack(Monk& player) = 0; // Each monster has a different attack strategy
	virtual void takeDamage(int dmg);
	bool isDefeated() {
		return health <= 0;
	}
	std::string getName() {
		return name;
	}
	int getHealth() {
		return health;
	}
};

class Goblin : public Monster {
public:
	Goblin() : Monster("Goblin", 10, 2) {}
	void attack(Monk& player) override;
};

class Gorilla : public Monster {
public:
	Gorilla() : Monster("Gorilla", 20, 4) {}
	void attack(Monk& player) override;
};

#endif),
