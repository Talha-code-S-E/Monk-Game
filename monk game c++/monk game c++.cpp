#include <iostream>
#include "Dungeon.h"
#include <string>
#include "Monk.h"
#include "Room.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	cout << "Welcome to the Dungeon Exploration Game!\n";

	string name, description;
	cout << "Enter your Monk's name: ";
	getline(cin, name);
	cout << "Describe your Monk: ";
	getline(cin, description);

	Monk* monk = new Monk(name, description);
	Dungeon dungeon(monk);

	dungeon.startExploration();

	delete monk; // Clean up memory
	return 0;
}