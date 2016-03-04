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


	//////////////////////////////////////////////////// SETUPS /////////////////////////////////////////////////////////////////////////////////////

	//freopen_s("cout.txt", "w+", stdout);

	// Max strength setup
	Setup max_str_setup = Setup();
	Stats max_str_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{nullptr, 0};
		for (Equippable* es : ebs.second) {
			if (es->buff_str > e_max.second) e_max = { es, es->buff_str };
		}
		if (e_max.first != nullptr) max_str_setup.equipEquippable(&max_str_stats, e_max.first);
	}

	// Check stat :>
	//max_str_stats.displayStats();

	// Max stamina setup
	Setup max_sta_setup = Setup();
	Stats max_sta_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_sta > e_max.second) e_max = { es, es->buff_sta };
		}
		if (e_max.first != nullptr) max_sta_setup.equipEquippable(&max_sta_stats, e_max.first);
	}

	// Check stat :>
	//max_sta_stats.displayStats();

	// Max agility setup
	Setup max_agi_setup = Setup();
	Stats max_agi_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_agi > e_max.second) e_max = { es, es->buff_agi };
		}
		if (e_max.first != nullptr) max_agi_setup.equipEquippable(&max_agi_stats, e_max.first);
	}

	// Check stat :>
	//max_agi_stats.displayStats();

	// Max sense setup
	Setup max_sen_setup = Setup();
	Stats max_sen_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_sen > e_max.second) e_max = { es, es->buff_sen };
		}
		if (e_max.first != nullptr) max_sen_setup.equipEquippable(&max_sen_stats, e_max.first);
	}

	// Check stat :>
	//max_sen_stats.displayStats();

	// Max intelligence setup
	Setup max_int_setup = Setup();
	Stats max_int_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_int > e_max.second) e_max = { es, es->buff_int };
		}
		if (e_max.first != nullptr) max_int_setup.equipEquippable(&max_int_stats, e_max.first);
	}

	// Check stat :>
	//max_int_stats.displayStats();

	// Max psychic setup
	Setup max_psy_setup = Setup();
	Stats max_psy_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_psy > e_max.second) e_max = { es, es->buff_psy };
		}
		if (e_max.first != nullptr) max_psy_setup.equipEquippable(&max_psy_stats, e_max.first);
	}

	// Check stat :>
	//max_psy_stats.displayStats();

	// Max treatment setup
	Setup max_treat_setup = Setup();
	Stats max_treat_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_treat > e_max.second) e_max = { es, es->buff_treat };
		}
		if (e_max.first != nullptr) max_treat_setup.equipEquippable(&max_treat_stats, e_max.first);
	}

	// Check stat :>
	//max_treat_stats.displayStats();


	//////////////////////////////////////////////////// MASH /////////////////////////////////////////////////////////////////////////////////////
	// Try all possible combinations ?
	// 10 slots
	Setup mash_setup = *g_setup;
	Stats mash_stats = *g_stats;
	for (std::pair<SLOTS, std::vector<SmartImplant*>> ss : implants_by_slots) {
		for (SmartImplant* i : ss.second) {
			mash_setup.
			mash_setup.equipImplant(&mash_stats, i);
		}
	}
}