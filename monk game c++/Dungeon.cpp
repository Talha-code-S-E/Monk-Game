#include "Dungeon.h"
#include "RoomFactory.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For std::shuffle
#include <random> // For std::random_device and std::mt19937

	using namespace std;

	Dungeon::Dungeon(Monk* monk): monk(monk), lockedTreasureRoom(nullptr) {
	srand(time(0));
	generateRooms();
}

Dungeon::~Dungeon() {
	for (Room* room : rooms) {
		delete room;
	}
	rooms.clear(); // Prevent accidental reuse or double deletion
}

void Dungeon::generateRooms() {
	std::random_device rd;
	std::mt19937 g(rd()); // ✅ Random generator

	// ✅ Use Factory Pattern Instead of Manually Creating Rooms
	rooms.push_back(RoomFactory::createRoom("Empty"));
	rooms.push_back(RoomFactory::createRoom("Empty"));
	rooms.push_back(RoomFactory::createRoom("Monster"));
	rooms.push_back(RoomFactory::createRoom("Monster"));
	rooms.push_back(RoomFactory::createRoom("Upgrade"));
	rooms.push_back(RoomFactory::createRoom("Upgrade"));

	// ✅ Create Treasure Room separately because it should be locked
	lockedTreasureRoom = RoomFactory::createRoom("Treasure");

	// ✅ Shuffle rooms properly
	std::shuffle(rooms.begin(), rooms.end(), g);

	// ✅ Ensure at least 2 connections per room
	for (size_t i = 0; i < rooms.size(); i++) {
		if (i < rooms.size() - 1) {
			rooms[i]->addConnection(rooms[i + 1]); // Ensure at least one forward path
		}
		int randIndex = rand() % rooms.size();
		if (randIndex != i) { // Prevent self-connection
			rooms[i]->addConnection(rooms[randIndex]);
		}
	}

	// ✅ Lock the Treasure Room (no path initially)
	rooms[rand() % rooms.size()]->addConnection(lockedTreasureRoom);

	// ✅ Monk starts in the first room
	monk->setRoom(rooms[0]);

	cout << "Dungeon generated with " << rooms.size() << " rooms. The Treasure Room is locked!\n";
}

void Dungeon::startExploration() {
	cout << "Starting dungeon exploration!\n";

	while (true) {
		Room* currentRoom = monk->getCurrentRoom();
		cout << "You are in a " << currentRoom->getType() << ".\n";

		// Mark the room as visited only if it's the first time
		if (find(visitedRooms.begin(), visitedRooms.end(), currentRoom) == visitedRooms.end()) {
			visitedRooms.push_back(currentRoom);
		}

		// Update room type visit status
		if (currentRoom->getType() == "Empty Room" && !visitedEmpty) {
			visitedEmpty = true;
			cout << "✅ You have visited your first Empty Room!\n";
		}
		if (currentRoom->getType() == "Monster Room" && !visitedMonster) {
			visitedMonster = true;
			cout << "✅ You have visited your first Monster Room!\n";
		}
		if (currentRoom->getType() == "Upgrade Room" && !visitedUpgrade) {
			visitedUpgrade = true;
			cout << "✅ You have visited your first Upgrade Room!\n";
		}

		// Ensure Treasure Room unlocks **only after visiting at least one of each type**
		if (lockedTreasureRoom && visitedEmpty && visitedMonster && visitedUpgrade) {
			cout << "🔓 You have explored at least one of each room type! The Treasure Room is now unlocked!\n";
			for (Room* room : rooms) {
				room->addConnection(lockedTreasureRoom); // Connect the Treasure Room to all rooms
			}
			lockedTreasureRoom = nullptr; // Remove lock
		}

		// Check Win Condition
		if (currentRoom->getType() == "Treasure Room") {
			cout << "🎉 Congratulations! You found the Treasure Room and won the game! 🎉\n";
			break;
		}

		// Check Lose Condition
		if (monk->getHealth() <= 0) {
			cout << "💀 You have been defeated... Game Over! 💀\n";
			break;
		}

		// Let the Monk interact with the room
		currentRoom->enterRoom(monk);

		// Display available paths
		vector<Room*> connections = currentRoom->getConnections();

		// Prevent locked Treasure Room from appearing before it's unlocked
		if (lockedTreasureRoom) {
			connections.erase(remove_if(connections.begin(), connections.end(),
				[](Room* room) { return room->getType() == "Treasure Room"; }), connections.end());
		}

		cout << "Available paths:\n";
		for (size_t i = 0; i < connections.size(); i++) {
			cout << i + 1 << ". " << connections[i]->getType() << "\n";
		}

		// Get Player Choice
		int choice;
		cout << "Choose a room to explore: ";
		cin >> choice;

		if (choice > 0 && choice <= connections.size()) {
			monk->setRoom(connections[choice - 1]);
		}
		else {
			cout << "❌ Invalid choice, try again.\n";
			continue;
		}
	}

	cout << "🏆 Game Over. Thanks for playing! 🏆\n";
}
Room* Dungeon::getTreasureRoom() {
	return lockedTreasureRoom;
}

vector<Room*> Dungeon::getRooms() {
	return rooms;
}