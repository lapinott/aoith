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

	// Set naked
	for (std::pair<SLOTS, Equippable*> se : g_setup->e_slots) {
		if (se.second != nullptr) g_setup->removeEquippable(g_stats, se.second);
	}
	for (std::pair<SLOTS, SmartImplant*> si : g_setup->i_slots) {
		if (si.second != nullptr) {
			g_setup->removeImplant(g_stats, si.second);
			si.second->current_ql = 0;
			si.second->current_abi_req = (STAT)-1;
		}
	}

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

	// Ignore list
	std::vector<SmartImplant*> i_ignore_list{};

	// Max stats
	unsigned int max_str = 0;
	unsigned int max_sta = 0;
	unsigned int max_agi = 0;
	unsigned int max_sen = 0;
	unsigned int max_int = 0;
	unsigned int max_psy = 0;
	unsigned int max_treat = 0;

	while ((duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count()) < 5000) {

		// Simulate
		Setup sim_setup = *g_setup;
		Stats sim_stats = *g_stats;
		
		// Pick a random implant
		SmartImplant* i = (*g_implants)[std::rand() % g_implants->size()];

		// Remove slotted implant
		sim_setup.removeImplant(&sim_stats, i->slot);

		// Remove gear
		for (std::pair<SLOTS, Equippable*> se : sim_setup.e_slots) {
			if (se.second != nullptr) sim_setup.removeEquippable(&sim_stats, se.second);
		}

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

		// Put other gear in empty slots (Advanced Scent Sensor...)
		for (Equippable* e : *g_equippables) {
			if (sim_setup.e_slots[e->slot] == nullptr) {
				sim_setup.equipEquippable(&sim_stats, e);
			}
		}

		// Weight treatment swaps
		std::multimap<float, Equippable*> swaps{};
		for (std::pair<SLOTS, Equippable*> se : this->max_treat_setup.e_slots) {
			if (
				se.second != nullptr &&
				sim_setup.e_slots[se.first] != se.second &&
				se.second->buff_treat > sim_setup.e_slots[se.first]->buff_treat
			) {
				float weight = 0.0f;
				switch (highest_ability) {
				case STR: weight = (float)sim_setup.e_slots[se.first]->buff_str / se.second->buff_treat;  break;
				case STA: weight = (float)sim_setup.e_slots[se.first]->buff_sta / se.second->buff_treat;  break;
				case AGI: weight = (float)sim_setup.e_slots[se.first]->buff_agi / se.second->buff_treat;  break;
				case SEN: weight = (float)sim_setup.e_slots[se.first]->buff_sen / se.second->buff_treat;  break;
				case INT: weight = (float)sim_setup.e_slots[se.first]->buff_int / se.second->buff_treat;  break;
				case PSY: weight = (float)sim_setup.e_slots[se.first]->buff_psy / se.second->buff_treat;  break;
				default: weight = 0;
				}
				swaps.insert(std::make_pair(weight, se.second));
			}
		}

		// Fine tune
		unsigned int ql_abi = (int)std::floor(((float)sim_stats.getMax(highest_ability) - 4.0f) / 2.0f);
		unsigned int ql_treat = (int)std::floor(((float)sim_stats.getMax(TREAT) - 1249.0f / 199.0f) / (940.0f / 199.0f));
		for (std::pair<float, Equippable*> we : swaps) {
			if (ql_abi > ql_treat) {
				sim_setup.equipEquippable(&sim_stats, we.second);
				ql_abi = (int)std::floor(((float)sim_stats.getMax(highest_ability) - 4.0f) / 2.0f);
				ql_treat = (int)std::floor(((float)sim_stats.getMax(TREAT) - 1249.0f / 199.0f) / (940.0f / 199.0f));
			}
		}

		// Implant simulate
		SmartImplant i_sim = *i;

		// Simulate implant equip
		sim_setup.equipImplant(&sim_stats, &i_sim);

		/* Compare
		if (i_sim.current_ql > i->current_ql) {
			g_setup->swapGear(g_stats, &sim_setup);
			g_setup->equipImplant(g_stats, i);
			ignore_list.clear();
		}
		//*/

		//*
		if (
			sim_stats.getMax(STR) > g_stats->getMax(STR) ||
			sim_stats.getMax(STA) > g_stats->getMax(STA) ||
			sim_stats.getMax(AGI) > g_stats->getMax(AGI) ||
			sim_stats.getMax(SEN) > g_stats->getMax(SEN) ||
			sim_stats.getMax(INT) > g_stats->getMax(INT) ||
			sim_stats.getMax(PSY) > g_stats->getMax(PSY) ||
			sim_stats.getMax(TREAT) > g_stats->getMax(TREAT)
		) {
			if (sim_stats.getImplantsMax(STR) > max_str) max_str = sim_stats.getImplantsMax(STR);
			if (sim_stats.getImplantsMax(STA) > max_sta) max_sta = sim_stats.getImplantsMax(STA);
			if (sim_stats.getImplantsMax(AGI) > max_agi) max_agi = sim_stats.getImplantsMax(AGI);
			if (sim_stats.getImplantsMax(SEN) > max_sen) max_sen = sim_stats.getImplantsMax(SEN);
			if (sim_stats.getImplantsMax(INT) > max_int) max_int = sim_stats.getImplantsMax(INT);
			if (sim_stats.getImplantsMax(PSY) > max_psy) max_psy = sim_stats.getImplantsMax(PSY);
			if (sim_stats.getImplantsMax(TREAT) > max_treat) max_treat = sim_stats.getImplantsMax(TREAT);
			max_str = std::max(max_str, sim_stats.getImplantsMax(STR));
			max_sta = std::max(max_sta, sim_stats.getImplantsMax(STA));
			max_agi = std::max(max_agi, sim_stats.getImplantsMax(AGI));
			max_sen = std::max(max_sen, sim_stats.getImplantsMax(SEN));
			max_int = std::max(max_int, sim_stats.getImplantsMax(INT));
			max_psy = std::max(max_psy, sim_stats.getImplantsMax(PSY));
			max_treat = std::max(max_treat, sim_stats.getImplantsMax(TREAT));
			g_setup->swapGear(g_stats, &sim_setup);
			g_setup->equipImplant(g_stats, i);
			ignore_list.clear();
		}
		//*/

		// Add current implant to ignore list
		ignore_list.push_back(i);
		if (ignore_list.size() == g_implants->size()) {
			std::cout.clear();
			freopen_s(&conout, "conout$", "w+t", stdout);
			std::cout << "No more implant swaps available..." << std::endl;
			break;
		}

		// ++
		++counter;
		//if (counter == 3) break;
	}

	// Reset cout
	std::cout.clear();
	freopen_s(&conout, "conout$", "w+t", stdout);

	std::cout << "Max str. (implants) : " << max_str << std::endl;
	std::cout << "Max sta. (implants) : " << max_sta << std::endl;
	std::cout << "Max agi. (implants) : " << max_agi << std::endl;
	std::cout << "Max sen. (implants) : " << max_sen << std::endl;
	std::cout << "Max int. (implants) : " << max_int << std::endl;
	std::cout << "Max psy. (implants) : " << max_psy << std::endl;
	std::cout << "Max treat. (implants) : " << max_treat << std::endl;

	// End
	std::cout << "Elapsed time : (implants) : " << duration << "ms" << std::endl;
	std::cout << "Number of loops : (implants) : " << counter << std::endl;
	//g_stats->displayStats();
	//g_setup->displaySetup();

	return;
}