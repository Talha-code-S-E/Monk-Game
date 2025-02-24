#include "Monster.h"
#include "Monk.h"
	using namespace std;

void Monster::takeDamage(int dmg) {
	health -= dmg;
	cout << name << " took " << dmg << " damage! Remaining health: " << health << "\n";
}

void Goblin::attack(Monk& player) {
	if (rand() % 2 == 0) { // 50% chance to hit
		cout << "Goblin slashes you for " << attackPower << " damage!\n";
		player.takeDamage(attackPower);
	}
	else {
		cout << "Goblin missed!\n";
	}
}

void Gorilla::attack(Monk& player) {
	if (rand() % 2 == 0) {
		cout << "Gorilla smashes you for " << attackPower << " damage!\n";
		player.takeDamage(attackPower);
	}
	else {
		cout << "Gorilla swings wildly but misses!\n";
	}
}