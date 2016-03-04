#pragma once

struct Strategies {

	static SmartImplant* get_max_stat_with_potentials(STAT s, std::vector<SmartImplant*> imps);

	static Equippable* get_max_stat_with_potentials(STAT s, std::vector<Equippable*> imps);

	// Blind swap ?
	static void strategy_0();
};