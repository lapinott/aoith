#include "Includes.h"
#include "Globals.h"
#include "Setup.struct.h"
#include "Stats.struct.h"
#include "SmartImplant.struct.h"
#include "Equippable.struct.h"
#include "Strategies.struct.h"

// Implants mapped by ID
std::vector<SmartImplant*>* g_implants = new std::vector<SmartImplant*>();

// Equippables mapped by ID
std::vector<Equippable*>* g_equippables = new std::vector<Equippable*>();

// Setup
Setup* g_setup = new Setup();

// Stat
Stats* g_stats = new Stats(0, 0, 0, 0, 0, 0, 0);

// Strategies
Strategies* g_strategies = new Strategies();

// Init stats
std::vector<unsigned int> g_init_stats = { 0,0,0,0,0,0,0 };

std::string get_stat_string(STAT s) {
	switch (s) {
	case STR: return "STR"; break;
	case STA: return "STA"; break;
	case AGI: return "AGI"; break;
	case SEN: return "SEN"; break;
	case INT: return "INT"; break;
	case PSY: return "PSY"; break;
	case TREAT: return "TREAT"; break;
	default: return "???"; break;
	}
}

std::string get_potency_string(POTENCY p) {
	switch (p) {
	case SHINING: return "Shining"; break;
	case BRIGHT: return "Bright"; break;
	case FADED: return "Faded"; break;
	default: return "???"; break;
	}
}

std::string get_slot_string(SLOTS s) {
	switch (s) {
	case W_HUD1: return "W_HUD1"; break;
	case W_HUD2: return "W_HUD2"; break;
	case W_HUD3: return "W_HUD3"; break;
	case W_UTILS1: return "W_UTILS1"; break;
	case W_UTILS2: return "W_UTILS2"; break;
	case W_UTILS3: return "W_UTILS3"; break;
	case W_RHAND: return "W_RHAND"; break;
	case W_DECK: return "W_DECK"; break;
	case W_LHAND: return "W_LHAND"; break;
	case W_DECK1: return "W_DECK1"; break;
	case W_DECK2: return "W_DECK2"; break;
	case W_DECK3: return "W_DECK3"; break;
	case W_DECK4: return "W_DECK4"; break;
	case W_DECK5: return "W_DECK5"; break;
	case W_DECK6: return "W_DECK6"; break;
	case A_NECK: return "A_NECK"; break;
	case A_HEAD: return "A_HEAD"; break;
	case A_BACK: return "A_BACK"; break;
	case A_RSHOULDER: return "A_RSHOULDER"; break;
	case A_CHEST: return "A_CHEST"; break;
	case A_LSHOULDER: return "A_LSHOULDER"; break;
	case A_RARM: return "A_RARM"; break;
	case A_HANDS: return "A_HANDS"; break;
	case A_LARM: return "A_LARM"; break;
	case A_RWRIST: return "A_RWRIST"; break;
	case A_LEGS: return "A_LEGS"; break;
	case A_LWRIST: return "A_LWRIST"; break;
	case A_RFINGER: return "A_RFINGER"; break;
	case A_FEET: return "A_FEET"; break;
	case A_LFINGER: return "A_LFINGER"; break;
	case I_EYES: return "I_EYES"; break;
	case I_HEAD: return "I_HEAD"; break;
	case I_EAR: return "I_EAR"; break;
	case I_RARM: return "I_RARM"; break;
	case I_CHEST: return "I_CHEST"; break;
	case I_LARM: return "I_LARM"; break;
	case I_RWRIST: return "I_RWRIST"; break;
	case I_WAIST: return "I_WAIST"; break;
	case I_LWRIST: return "I_LWRIST"; break;
	case I_RHAND: return "I_RHAND"; break;
	case I_LEGS: return "I_LEGS"; break;
	case I_LHAND: return "I_LHAND"; break;
	case I_FEET: return "I_FEET"; break;
	default: return "???"; break;
	}
}

unsigned int get_ability_buff_amount_from_ql(POTENCY p, unsigned int ql) {
	switch (p) {
	case SHINING:
		return (int)std::round(50.0f / 199 * ql + 945.0f / 199); break;
	case BRIGHT:
		return (int)std::round(30.0f / 199 * ql + 567.0f / 199); break;
	case FADED:
		return (int)std::round(20.0f / 199 * ql + 378.0f / 199); break;
	default: return 0;
	}
}

unsigned int get_treatment_buff_amount_from_ql(POTENCY p, unsigned int ql) {
	switch (p) {
	case SHINING:
		return (int)std::round(99.0f / 199 * ql + 1095.0f / 199); break;
	case BRIGHT:
		return (int)std::round(60.0f / 199 * ql + 537.0f / 199); break;
	case FADED:
		return (int)std::round(40.0f / 199 * ql + 358.0f / 199); break;
	default: return 0;
	}
}

bool is_weapon(Equippable* e) {
	if (e->slot < 15) return true;
	else return false;
}

bool is_armor(Equippable* e) {
	return !is_weapon(e) && e->slot < 30;
}

unsigned int get_equippable_id(Equippable* e) {
	for (unsigned int i = 0; i < g_equippables->size(); i++) {
		if ((*g_equippables)[i] == e) return i + g_implants->size();
	}
	return -1;
}

unsigned int get_implant_id(SmartImplant* i) {
	for (unsigned int j = 0; j < g_equippables->size(); j++) {
		if ((*g_implants)[j] == i) return j;
	}
	return -1;
}

bool equip_item_id(unsigned int item_id) {
	if (item_id < g_implants->size()) g_setup->equipImplant(g_stats, (*g_implants)[item_id]);
	else g_setup->equipEquippable(g_stats, (*g_equippables)[item_id - g_implants->size()]);
	return false;
}

bool handleCommand(std::string cmd) {

	std::stringstream ss(cmd);
	std::string sub;
	std::vector<std::string> sub_commands;
	while (ss >> sub) sub_commands.push_back(sub);

	if (cmd == "help") {
		std::cout << "  commands list :" << std::endl;
		std::cout << "   'help' - displays this" << std::endl;
		std::cout << "   'exit' - exits program" << std::endl;
		std::cout << "   'ilist' - displays available implants" << std::endl;
		std::cout << "   'wlist' - displays available weapons" << std::endl;
		std::cout << "   'alist' - displays available armor" << std::endl;
		std::cout << "   'init [STR] [STA] [AGI] [SEN] [INT] [PSY] [TREAT]' - inits stats values" << std::endl;
		std::cout << "   'equip [ITEM_ID] [[...]]' - equips item[s] with id [ITEM_ID] [[ITEM_ID]] [[...]]" << std::endl;
		std::cout << "   'stats' - displays current stats" << std::endl;
		std::cout << "   'setup' - displays current setup" << std::endl;
		std::cout << "   'slots' - displays slot names" << std::endl;
		std::cout << "   'add [slot] [str buff] [sta buff] [agi buff] [sense buff] [int buff] [psy buff] [name]' - adds a weapon or armor piece" << std::endl;
		std::cout << "   'run [STRATEGY_ID]' - run strategy" << std::endl;
	}
	else if (cmd == "ilist") {
		std::cout << "  Available implants [ID] [SLOT] [BUFFS] [REQUIRES] Name :" << std::endl;
		for (SmartImplant* i : *g_implants) {
			std::string buffs = get_stat_string(i->buffed_stat[0].second);
			if (i->buffed_stat.size() > 1) for (unsigned int j = 1; j < i->buffed_stat.size(); j++) buffs += (std::string("|") + get_stat_string(i->buffed_stat[j].second));
			std::string requires = get_stat_string(i->requires_ability[0]);
			if (i->requires_ability.size() > 1) for (unsigned int j = 1; j < i->requires_ability.size(); j++) requires += (std::string("|") + get_stat_string(i->requires_ability[j]));
			std::cout << "   [" << get_implant_id(i) << "] [" << get_slot_string(i->slot) << "] [" << buffs << "] [" << requires << "] " << i->name << std::endl;
		}
	}
	else if (cmd == "wlist") {
		std::cout << "  Available weapons [ID] [SLOT] [BUFFS] Name :" << std::endl;
		for (Equippable* e : *g_equippables) {
			if (is_weapon(e)) {
				std::string buffs = "";
				if (e->buff_str > 0) buffs += get_stat_string(STR) + "+" + std::to_string(e->buff_str);
				if (e->buff_sta > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(STA) + "+" + std::to_string(e->buff_sta);
				if (e->buff_agi > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(AGI) + "+" + std::to_string(e->buff_agi);
				if (e->buff_sen > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(SEN) + "+" + std::to_string(e->buff_sen);
				if (e->buff_int > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(INT) + "+" + std::to_string(e->buff_int);
				if (e->buff_psy > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(PSY) + "+" + std::to_string(e->buff_psy);
				if (e->buff_treat > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(TREAT) + "+" + std::to_string(e->buff_treat);
				std::cout << "   [" << get_equippable_id(e) << "] [" << get_slot_string(e->slot) << "] [" << buffs << "] " << e->name << std::endl;
			}
		}
	}
	else if (cmd == "alist") {
		std::cout << "  Available armor [ID] [SLOT] [BUFFS] Name :" << std::endl;
		for (Equippable* e : *g_equippables) {
			if (is_armor(e)) {
				std::string buffs = "";
				if (e->buff_str > 0) buffs += get_stat_string(STR) + "+" + std::to_string(e->buff_str);
				if (e->buff_sta > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(STA) + "+" + std::to_string(e->buff_sta);
				if (e->buff_agi > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(AGI) + "+" + std::to_string(e->buff_agi);
				if (e->buff_sen > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(SEN) + "+" + std::to_string(e->buff_sen);
				if (e->buff_int > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(INT) + "+" + std::to_string(e->buff_int);
				if (e->buff_psy > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(PSY) + "+" + std::to_string(e->buff_psy);
				if (e->buff_treat > 0) buffs += (buffs.size() > 0 ? "|" : "") + get_stat_string(TREAT) + "+" + std::to_string(e->buff_treat);
				std::cout << "   [" << get_equippable_id(e) << "] [" << get_slot_string(e->slot) << "] [" << buffs << "] " << e->name << std::endl;
			}
		}
	}
	else if (cmd == "stats") {
		g_stats->displayStats();
	}
	else if (cmd == "setup") {
		g_setup->displaySetup();
	}
	else if (cmd == "slots") {

	}
	else if (sub_commands[0] == "init" && std::regex_match(cmd, std::regex("init\\s+\\d+\\s+\\d+\\s+\\d+\\s+\\d+\\s+\\d+\\s+\\d+\\s+\\d+\\s*"))) {
		g_init_stats = {
			std::stoul(sub_commands[1]),
			std::stoul(sub_commands[2]),
			std::stoul(sub_commands[3]),
			std::stoul(sub_commands[4]),
			std::stoul(sub_commands[5]),
			std::stoul(sub_commands[6]),
			std::stoul(sub_commands[7])
		};
		g_stats->initStats(g_init_stats);
		g_stats->displayStats();
	}
	else if (sub_commands[0] == "equip" && std::regex_match(cmd, std::regex("equip\\s+\\d+.*"))) {
		for (unsigned int i = 1; i < sub_commands.size(); i++) equip_item_id(std::stoi(sub_commands[i]));
	}
	else if (cmd == "unequip all") {
		for (std::pair<SLOTS, Equippable*> se : g_setup->e_slots) if (se.second != nullptr) g_setup->removeEquippable(g_stats, se.second);
		for (std::pair<SLOTS, SmartImplant*> si : g_setup->i_slots) if (si.second != nullptr) g_setup->removeImplant(g_stats, si.second);
	}
	else if (sub_commands[0] == "unequip" && std::regex_match(cmd, std::regex("unequip\\s+\\d+.*"))) {
		//for (unsigned int i = 1; i < sub_commands.size(); i++) equip_item_id(std::stoi(sub_commands[i]));
	}
	else if (cmd == "add") {

	}
	else if (cmd == "run 0") {
		std::cout << "Now running Strategy 0" << std::endl << std::endl;
		g_strategies->strategy_0();
	}
	else {
		std::cout << "Unknown or badly formatted command." << std::endl;
		return false;
	}
	return true;
}