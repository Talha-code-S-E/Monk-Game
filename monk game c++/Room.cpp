#include "Room.h"
#include "Combat.h"
#include <cstdlib>
	using namespace std;

void EmptyRoom::enterRoom(Monk* monk) {
	cout << "This room is empty. You can meditate to restore health.\n";
	monk->meditate();
}

void UpgradeRoom::enterRoom(Monk* monk) {
	cout << "You found an upgrade! Choose to increase Health or Attack.\n";
	cout << "1. Increase Health (+5) \n2. Increase Attack (+2)\n";

	int choice;
	cin >> choice;

	if (choice == 1) {
		monk->upgradeHealth();
	}
	else {
		monk->upgradeAttack();
	}
}

void TreasureRoom::enterRoom(Monk* monk) {
	cout << "Congratulations! You found the treasure and won the game.\n";
	exit(0);
}

void MonsterRoom::enterRoom(Monk* monk) {
	cout << "You have entered a Monster Room.\n";
	cout << "You see two enemies: A Goblin and a Gorilla.\n";

	int choice;
	Monster* enemy = nullptr;
	bool hasPrepared = false; // Track if the player has already prepared

	while (true) {
		cout << "Choose an option:\n";
		cout << "1. Fight the Goblin\n";
		cout << "2. Fight the Gorilla\n";

		if (!hasPrepared) { // Show "Run to Prepare" only if not used before
			cout << "3. Run to prepare\n";
		}

		cin >> choice;

		if (choice == 1) {
			enemy = new Goblin();
			break; // Proceed to combat
		}
		else if (choice == 2) {
			enemy = new Gorilla();
			break; // Proceed to combat
		}
		else if (choice == 3 && !hasPrepared) {
			cout << "You decided to run and prepare before fighting.\n";
			cout << "Choose your preparation option:\n";
			cout << "1. Increase Attack (+10)\n";
			cout << "2. Drink Shield Poison (Monsters get poisoned when attacked)\n";

			int prepChoice;
			cin >> prepChoice;

			if (prepChoice == 1) {
				monk->upgradeAttack(10);
				cout << "Your attack increased by 10! You feel stronger for the battle.\n";
			}
			else if (prepChoice == 2) {
				monk->drinkShieldPoison();
				cout << "You drank the Shield Poison! Now, enemies will take poison damage when attacked.\n";
			}

			hasPrepared = true; // Mark preparation as done
		}
		else {
			cout << "❌ Invalid choice, try again.\n";
		}
	}

	if (enemy) {
		Combat::fight(*monk, *enemy);
		delete enemy;
	}
}