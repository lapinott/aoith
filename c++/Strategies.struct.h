#pragma once

struct Strategies {

	Strategies() {}

	//static Implant* get_max_stat_with_potentials(STAT s, std::vector<Implant*> imps);

	//static Equippable* get_max_stat_with_potentials(STAT s, std::vector<Equippable*> imps);

	std::map<STAT, Setup> max_stat_setup;

	void create_max_stat_setups(std::vector<Equippable*>* equippables);

	// Strategies
	void strategy_0();
	void strategy_1();
};