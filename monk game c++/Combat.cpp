#include "Combat.h"
#include <iostream>
#include <cstdlib>
	using namespace std;

bool Combat::fight(Monk& player, Monster& enemy) {
	cout << enemy.getName() << " appears! Prepare to fight.\n";

	while (player.getHealth() > 0 && !enemy.isDefeated()) {
		int action;
		cout << "Your Health: " << player.getHealth() << " | "
			<< enemy.getName() << "'s Health: " << enemy.getHealth() << "\n";
		cout << "Choose an action:\n1. Attack\n2. Guard\n";
		cin >> action;

		if (action == 1) { // Attack
			if (rand() % 2 == 0) {
				cout << "You hit the " << enemy.getName() << " for " << player.getAttack() << " damage!\n";
				enemy.takeDamage(player.getAttack());

				if (player.hasShieldPoison()) {
					cout << enemy.getName() << " is poisoned! It takes **7** extra damage.\n";
					enemy.takeDamage(7);
					player.useShieldPoison();
				}
			}
			else {
				cout << "Your attack missed!\n";
			}
		}
		else { // Guard
			player.recoverHealth(1);
		}

		if (!enemy.isDefeated()) {
			enemy.attack(player);
		}
	}

	if (player.getHealth() > 0) {
		cout << "You defeated the " << enemy.getName() << "!\n";
		return true;
	}
	else {
		cout << "You were defeated!\n";
		return false;
	}
}