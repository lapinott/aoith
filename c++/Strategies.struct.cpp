#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"
#include "SmartImplant.struct.h"
#include "Setup.struct.h"
#include "Stats.struct.h"
#include "Strategies.struct.h"

void Strategies::strategy_0() {

	// Organize equippables by slots
	std::map<SLOTS, std::vector<Equippable*>> equippables_by_slots{};
	for (Equippable* e : (*g_equippables)) {
		equippables_by_slots[e->slot].push_back(e);
	}

	// Print possible equippables combinations
	int combinations = 1;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) combinations *= ebs.second.size();
	std::cout << "Number of possible equippables combinations : " << combinations << "!" << std::endl;

	// Organize implants by slots
	std::map<SLOTS, std::vector<SmartImplant*>> implants_by_slots{};
	for (SmartImplant* i : (*g_implants)) {
		implants_by_slots[i->slot].push_back(i);
	}

	// Print possible implants combinations
	combinations = 1;
	for (std::pair<SLOTS, std::vector<SmartImplant*>> ibs : implants_by_slots) combinations *= ibs.second.size();
	std::cout << "Number of possible implants combinations : " << combinations << "!" << std::endl;

	//freopen_s("cout.txt", "w+", stdout);

	// ..
}