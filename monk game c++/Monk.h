#ifndef MONK_H
#define MONK_H

#include <string>

	class Room; // Forward declaration

class Monk {
private:
	std::string name;
	std::string description;
	int health;
	int attack;
	Room* currentRoom;
	bool shieldPoison; // ✅ Poison effect variable

public:
	Monk(std::string name, std::string desc);

	void setRoom(Room* room);
	Room* getCurrentRoom();

	void takeDamage(int dmg);
	void recoverHealth(int amount);
	void meditate();
	void upgradeHealth();
	void upgradeAttack(); // Default +2 upgrade
	void upgradeAttack(int amount); // ✅ Overloaded for +10 upgrade

	int getHealth();
	int getAttack();

	// ✅ Poison Mechanics
	bool hasShieldPoison();
	void drinkShieldPoison();
	void useShieldPoison();
};

#endif
