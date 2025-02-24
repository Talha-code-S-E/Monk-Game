#ifndef DUNGEON_H
#define DUNGEON_H

#include "Room.h"
#include "Monk.h"
#include <vector>

	class Dungeon {
	private:
		Monk* monk;
		std::vector<Room*> rooms;
		Room* lockedTreasureRoom;
		std::vector<Room*> visitedRooms;
		bool visitedEmpty = false;
		bool visitedMonster = false;
		bool visitedUpgrade = false;

	public:
		Dungeon(Monk* monk);
		~Dungeon();
		void generateRooms();
		void startExploration();
		Room* getTreasureRoom();
		std::vector<Room*> getRooms();
};

#endif
