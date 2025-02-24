#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include "Monk.h"

	using namespace std;

class Room {
protected:
	string type;
	vector<Room*> connectedRooms;

public:
	Room(string type) : type(type) {}
	virtual ~Room() {}

	string getType() {
		return type;
	}


	void addConnection(Room* room) {
		connectedRooms.push_back(room);
	}

	vector<Room*>& getConnections() {
		return connectedRooms;
	}

	virtual void enterRoom(Monk* monk) = 0;
};

class EmptyRoom : public Room {
public:
	EmptyRoom() : Room("Empty Room") {}
	void enterRoom(Monk* monk) override;
};

class MonsterRoom : public Room {
public:
	MonsterRoom() : Room("Monster Room") {}
	void enterRoom(Monk* monk) override;
};

class UpgradeRoom : public Room {
public:
	UpgradeRoom() : Room("Upgrade Room") {}
	void enterRoom(Monk* monk) override;
};

class TreasureRoom : public Room {
public:
	TreasureRoom() : Room("Treasure Room") {}
	void enterRoom(Monk* monk) override;
};

#endif
