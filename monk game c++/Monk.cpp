#include "Monk.h"
#include <iostream>
#include <vector>
#include "Room.h"
	using namespace std;

Monk::Monk(std::string name, std::string desc)
	: name(name), description(desc), health(15), attack(3), currentRoom(nullptr), shieldPoison(false) {
}

void Monk::setRoom(Room* room) {
	currentRoom = room;
	cout << "You have entered a " << room->getType() << ".\n";
}

Room* Monk::getCurrentRoom() {
	return currentRoom;
}

void Monk::takeDamage(int dmg) {
	health -= dmg;
	if (health <= 0) {
		cout << "You have been defeated! Game over.\n";
		exit(0);
	}
}

void Monk::recoverHealth(int amount) {
	health += amount;
	cout << "You recovered " << amount << " health. Current Health: " << health << "\n";
}

void Monk::meditate() {
	health += 3;
	cout << "You meditate and recover 3 health points. Current Health: " << health << "\n";
}

void Monk::upgradeHealth() {
	health += 5;
	cout << "Your health increased! Current Health: " << health << "\n";
}

void Monk::upgradeAttack() {
	attack += 2;
	cout << "Your attack power increased! Current Attack: " << attack << "\n";
}

void Monk::upgradeAttack(int amount) {
	attack += amount;
	cout << "Your attack power increased by " << amount << "! Current Attack: " << attack << "\n";
}

int Monk::getHealth() {
	return health;
}

int Monk::getAttack() {
	return attack;
}

// ✅ Poison Functions
bool Monk::hasShieldPoison() {
	return shieldPoison;
}

void Monk::drinkShieldPoison() {
	shieldPoison = true;
	cout << "You drank the Shield Poison! Your next attack will poison the enemy.\n";
}

void Monk::useShieldPoison() {
	if (shieldPoison) {
		cout << "Your attack poisons the enemy!\n";
		shieldPoison = false; // ✅ Poison is consumed
	}
}