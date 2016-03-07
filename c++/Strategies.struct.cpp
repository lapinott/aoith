#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"
#include "SmartImplant.struct.h"
#include "Setup.struct.h"
#include "Stats.struct.h"
#include "Strategies.struct.h"

void Strategies::create_max_stat_setups(std::vector<Equippable*>* equippables) {

	// Organize equippables by slots
	std::map<SLOTS, std::vector<Equippable*>> equippables_by_slots{};
	for (Equippable* e : (*equippables)) {
		equippables_by_slots[e->slot].push_back(e);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_str > e_max.second) e_max = { es, es->buff_str };
		}
		if (e_max.first != nullptr) this->max_str_setup.equipEquippable(&this->max_str_stats, e_max.first);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_sta > e_max.second) e_max = { es, es->buff_sta };
		}
		if (e_max.first != nullptr) this->max_sta_setup.equipEquippable(&this->max_sta_stats, e_max.first);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_agi > e_max.second) e_max = { es, es->buff_agi };
		}
		if (e_max.first != nullptr) this->max_agi_setup.equipEquippable(&this->max_agi_stats, e_max.first);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_sen > e_max.second) e_max = { es, es->buff_sen };
		}
		if (e_max.first != nullptr) this->max_sen_setup.equipEquippable(&this->max_sen_stats, e_max.first);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_int > e_max.second) e_max = { es, es->buff_int };
		}
		if (e_max.first != nullptr) this->max_int_setup.equipEquippable(&this->max_int_stats, e_max.first);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_psy > e_max.second) e_max = { es, es->buff_psy };
		}
		if (e_max.first != nullptr) this->max_psy_setup.equipEquippable(&this->max_psy_stats, e_max.first);
	}

	for (std::pair<SLOTS, std::vector<Equippable*>> ebs : equippables_by_slots) {
		std::pair<Equippable*, unsigned int> e_max{ nullptr, 0 };
		for (Equippable* es : ebs.second) {
			if (es->buff_treat > e_max.second) e_max = { es, es->buff_treat };
		}
		if (e_max.first != nullptr) this->max_treat_setup.equipEquippable(&this->max_treat_stats, e_max.first);
	}
}

void Strategies::strategy_0() {

	// Redirect cout to file
	FILE *conin, *conout;
	freopen_s(&conout, "cout.txt", "w+t", stdout);

	// Disable cout
	std::cout.setstate(std::ios_base::failbit);

	// Organize equippables by slots
	std::map<SLOTS, std::vector<Equippable*>> equippables_by_slots{};
	for (Equippable* e : (*g_equippables)) {
		equippables_by_slots[e->slot].push_back(e);
	}

	// Organize fine tuning
	// treatment[/3 ?] / ability ratio by ABI
	/*std::map<SLOTS, std::vector<std::pair<float, Equippable*>>> sre{};
	for (Equippable* e : *g_equippables) {

	}*/

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

	// Create max setups
	this->create_max_stat_setups(g_equippables);

	// Blindly put implants
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	long duration = 0;
	int max_sense = 0;
	Stats max_sense_stats = Stats(0, 0, 0, 0, 0, 0, 0);
	Setup max_sense_setup = Setup();
	long long counter = 0;
	std::vector<SmartImplant*> ignore_list{};

	// Seed rand
	std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());

	while ((duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count()) < 5000) {

		// Simulate
		Setup sim_setup = *g_setup;
		Stats sim_stats = *g_stats;
		
		// Pick a random implant
		SmartImplant* i = (*g_implants)[std::rand() % g_implants->size()];

		// Remove slotted implant
		sim_setup.removeImplant(&sim_stats, i->slot);

		// Remove gear
		for (std::pair<SLOTS, Equippable*> se : sim_setup.e_slots) sim_setup.removeEquippable(&sim_stats, se.second);

		// Checks which best ability to use
		STAT highest_ability = (STAT)-1;
		unsigned int highest_ability_value = 0;
		for (STAT s : i->requires_ability) {
			if (this->max_str_stats.getMax(s) + sim_stats.getMax(s) > highest_ability_value) {
				highest_ability_value = this->max_str_stats.getMax(s) + sim_stats.getMax(s);
				highest_ability = s;
			}
		}

		// Put ability gear on
		switch (highest_ability) {
		case STR: for (std::pair<SLOTS, Equippable*> se : this->max_str_setup.e_slots) sim_setup.equipEquippable(&sim_stats, se.second); break;
		case STA: for (std::pair<SLOTS, Equippable*> se : this->max_sta_setup.e_slots) sim_setup.equipEquippable(&sim_stats, se.second); break;
		case AGI: for (std::pair<SLOTS, Equippable*> se : this->max_agi_setup.e_slots) sim_setup.equipEquippable(&sim_stats, se.second); break;
		case SEN: for (std::pair<SLOTS, Equippable*> se : this->max_sen_setup.e_slots) sim_setup.equipEquippable(&sim_stats, se.second); break;
		case INT: for (std::pair<SLOTS, Equippable*> se : this->max_int_setup.e_slots) sim_setup.equipEquippable(&sim_stats, se.second); break;
		case PSY: for (std::pair<SLOTS, Equippable*> se : this->max_psy_setup.e_slots) sim_setup.equipEquippable(&sim_stats, se.second); break;
		default: break;
		}

		// Put treatment gear in empty slots
		for (std::pair<SLOTS, Equippable*> se : this->max_treat_setup.e_slots) {
			if (sim_setup.e_slots[se.first] == nullptr && se.second != nullptr) {
				sim_setup.equipEquippable(&sim_stats, se.second);
			}
		}

		// Weight treatment swaps
		std::map<float, Equippable*> swaps{};
		for (Equippable* e : *g_equippables) {
			if (sim_setup.e_slots[e->slot] != e && e->buff_treat > sim_setup.e_slots[e->slot]->buff_treat) {
				float weight = 0.0f;
				switch (highest_ability) {
				case STR: weight = (float)e->buff_treat / sim_setup.e_slots[e->slot]->buff_str;  break;
				case STA: weight = (float)e->buff_treat / sim_setup.e_slots[e->slot]->buff_sta;  break;
				case AGI: weight = (float)e->buff_treat / sim_setup.e_slots[e->slot]->buff_agi;  break;
				case SEN: weight = (float)e->buff_treat / sim_setup.e_slots[e->slot]->buff_sen;  break;
				case INT: weight = (float)e->buff_treat / sim_setup.e_slots[e->slot]->buff_int;  break;
				case PSY: weight = (float)e->buff_treat / sim_setup.e_slots[e->slot]->buff_psy;  break;
				default: weight = 0;
				}
				swaps[weight] = e;
			}
		}

		// Fine tune
		unsigned int ql_abi = (int)std::floor(((float)sim_stats.getMax(highest_ability) - 4.0f) / 2.0f);
		unsigned int ql_treat = (int)std::floor(((float)sim_stats.getMax(TREAT) - 1249.0f / 199.0f) / (940.0f / 199.0f));
		for (std::pair<float, Equippable*> we : swaps) {
			if (ql_abi > ql_treat) {
				sim_setup.removeEquippable(&sim_stats, we.second->slot);
				sim_setup.equipEquippable(&sim_stats, we.second);
			}
		}

		// Put
		// ...

		// Compare setups
		// ...

		// PASS/FAIL
		// ... -> taking account for : less x ability / more y ability ?
		// ... -> ignore list
		// std::cout > fail

		// IF i NOT IN ignore_list (if implant equip. discarded add to ignore list; when any implant slotted, clear ignore list

		// SIMULATE -> Remove implant in i->slot

		// FOR EACH IMP. ABI. REQ. : PUT MAX ABI

		// Simulate 

		// ROLL RANDOM + CHECK IF ABILITIES/TREATMENT GO HIGHER IF EQUIPPING IMPLANT - ELSE DISCARD
		// -> potentials

		// CHECK -> uneqip on copy of setup/stats then compare

		// Unequip implant if slotted
		if (g_setup->i_slots[i->slot] != nullptr) g_setup->removeImplant(g_stats, i->slot);

		// Equip
		g_setup->equipImplant(g_stats, i);

		if (g_stats->getMax(SEN) > max_sense) {
			max_sense = g_stats->getMax(SEN);
			max_sense_setup = *g_setup;
			max_sense_stats = *g_stats;
		}

		++counter;
	}

	// Reset cout
	std::cout.clear();
	freopen_s(&conout, "conout$", "w+t", stdout);

	// End
	std::cout << "Elapsed time : " << duration << "ms" << std::endl;
	std::cout << "Number of loops : " << counter << std::endl;
	std::cout << "Max sense : " << max_sense << std::endl;
	max_sense_stats.displayStats();
	max_sense_setup.displaySetup();

	return;
}