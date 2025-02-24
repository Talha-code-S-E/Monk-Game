#ifndef ROOMFACTORY_H
#define ROOMFACTORY_H

#include "Room.h"

class RoomFactory {
public:
	static Room* createRoom(const std::string& type) {
		if (type == "Empty") return new EmptyRoom();
		if (type == "Monster") return new MonsterRoom();
		if (type == "Upgrade") return new UpgradeRoom();
		if (type == "Treasure") return new TreasureRoom();
		return nullptr; // Unknown room type
	}
};

#endif
