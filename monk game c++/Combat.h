#ifndef COMBAT_H
#define COMBAT_H
#include "Monk.h"
#include "Monster.h"

	class Combat {
	public:
		static bool fight(Monk& player, Monster& enemy);
};

#endif