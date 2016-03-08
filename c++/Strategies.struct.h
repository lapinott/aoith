#pragma once

struct Strategies {

	Strategies() {}

	static SmartImplant* get_max_stat_with_potentials(STAT s, std::vector<SmartImplant*> imps);

	static Equippable* get_max_stat_with_potentials(STAT s, std::vector<Equippable*> imps);

	Setup max_str_setup = Setup();
	Stats max_str_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_sta_setup = Setup();
	Stats max_sta_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_agi_setup = Setup();
	Stats max_agi_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_sen_setup = Setup();
	Stats max_sen_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_int_setup = Setup();
	Stats max_int_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_psy_setup = Setup();
	Stats max_psy_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_treat_setup = Setup();
	Stats max_treat_stats = Stats(0, 0, 0, 0, 0, 0, 0);

	void create_max_stat_setups(std::vector<Equippable*>* equippables);

	// Blind swap ?
	void strategy_0();
};