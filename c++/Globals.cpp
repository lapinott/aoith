#include "Includes.h"
#include "Globals.h"
#include "Setup.struct.h"
#include "Stats.struct.h"
#include "SmartImplant.struct.h"
#include "Equippable.struct.h"

// Implants mapped by ID
std::vector<SmartImplant*>* g_implants = new std::vector<SmartImplant*>();

// Equippables mapped by ID
std::vector<Equippable*>* g_equippables = new std::vector<Equippable*>();

// Setup
Setup* g_setup = new Setup();

// Stat
Stats* g_stats = new Stats(1, 2, 3, 4, 5, 6, 7);

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
	case W_HUD1: return "HUD1"; break;
	case W_HUD2: return "HUD2"; break;
	case W_HUD3: return "HUD3"; break;
	case W_UTILS1: return "UTILS1"; break;
	case W_UTILS2: return "UTILS2"; break;
	case W_UTILS3: return "UTILS3"; break;
	case W_RHAND: return "RHAND"; break;
	case W_DECK: return "DECK"; break;
	case W_LHAND: return "LHAND"; break;
	case W_DECK1: return "DECK1"; break;
	case W_DECK2: return "DECK2"; break;
	case W_DECK3: return "DECK3"; break;
	case W_DECK4: return "DECK4"; break;
	case W_DECK5: return "DECK5"; break;
	case W_DECK6: return "DECK6"; break;
	case A_NECK: return "NECK"; break;
	case A_HEAD: return "HEAD"; break;
	case A_BACK: return "BACK"; break;
	case A_RSHOULDER: return "RSHOULDER"; break;
	case A_CHEST: return "CHEST"; break;
	case A_LSHOULDER: return "LSHOULDER"; break;
	case A_RARM: return "RARM"; break;
	case A_HANDS: return "HANDS"; break;
	case A_LARM: return "LARM"; break;
	case A_RWRIST: return "RWRIST"; break;
	case A_LEGS: return "LEGS"; break;
	case A_LWRIST: return "LWRIST"; break;
	case A_RFINGER: return "RFINGER"; break;
	case A_FEET: return "FEET"; break;
	case A_LFINGER: return "LFINGER"; break;
	case I_EYES: return "EYES"; break;
	case I_HEAD: return "HEAD"; break;
	case I_EAR: return "EAR"; break;
	case I_RARM: return "RARM"; break;
	case I_CHEST: return "CHEST"; break;
	case I_LARM: return "LARM"; break;
	case I_RWRIST: return "RWRIST"; break;
	case I_WAIST: return "WAIST"; break;
	case I_LWRIST: return "LWRIST"; break;
	case I_RHAND: return "RHAND"; break;
	case I_LEGS: return "LEGS"; break;
	case I_LHAND: return "LHAND"; break;
	case I_FEET: return "FEET"; break;
	default: return "???"; break;
	}
}

unsigned int get_ability_buff_amount_from_ql(POTENCY p, unsigned int ql) {
	switch (p) {
	case SHINING:
		return (int)std::round(50 / 199 * ql + 945 / 199); break;
	case BRIGHT:
		return (int)std::round(30 / 199 * ql + 567 / 199);  break;
	case FADED:
		return (int)std::round(20 / 199 * ql + 378 / 199);  break;
	default: return 0;
	}
}

unsigned int get_treatment_buff_amount_from_ql(POTENCY p, unsigned int ql) {
	switch (p) {
	case SHINING:
		return (int)std::round(99 / 199 * ql + 1095 / 199); break;
	case BRIGHT:
		return (int)std::round(60 / 199 * ql + 537 / 199);  break;
	case FADED:
		return (int)std::round(40 / 199 * ql + 358 / 199);  break;
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

bool handleCommand(std::string cmd) {
	if (cmd == "help") {
		std::cout << "  commands list :" << std::endl;
		std::cout << "   'help' - displays this" << std::endl;
		std::cout << "   'exit' - exits program" << std::endl;
		std::cout << "   'ilist' - displays available implants" << std::endl;
		std::cout << "   'wlist' - displays available weapons" << std::endl;
		std::cout << "   'alist' - displays available armor" << std::endl;
		std::cout << "   'stats' - displays current stats" << std::endl;
		std::cout << "   'setup' - displays current setup" << std::endl;
		std::cout << "   'slots' - displays slot names" << std::endl;
		std::cout << "   'add [slot] [str buff] [sta buff] [agi buff] [sense buff] [int buff] [psy buff] [name]' - adds a weapon or armor piece" << std::endl;
		return true;
	}
	else if (cmd == "ilist") {
		std::cout << "  Available implants [SLOT] [BUFFS] [REQUIRES] Name :" << std::endl;
		for (SmartImplant* i : *g_implants) {
			std::string buffs = get_stat_string(i->buffed_stat[0].second);
			if (i->buffed_stat.size() > 1) {
				for (unsigned int j = 1; j < i->buffed_stat.size(); j++) buffs += (std::string("|") + get_stat_string(i->buffed_stat[j].second));
			}
			std::cout << "   [" << get_slot_string(i->slot) << "] [" << buffs << "] " << i->name << std::endl;
		}
		return true;
	}
	else if (cmd == "wlist") {
		std::cout << "  Available weapons [SLOT] [BUFFS] Name :" << std::endl;
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
				std::cout << "   [" << get_slot_string(e->slot) << "] [" << buffs << "] " << e->name << std::endl;
			}
		}
		return true;
	}
	else if (cmd == "alist") {
		std::cout << "  Available armor [SLOT] [BUFFS] Name :" << std::endl;
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
				std::cout << "   [" << get_slot_string(e->slot) << "] [" << buffs << "] " << e->name << std::endl;
			}
		}
		return true;
	}
	else if (cmd == "stats") {
		g_stats->displayStat();
	}
	else if (cmd == "setup") {
		g_setup->displaySetup();
	}
	else if (cmd == "slots") {

	}
	else if (cmd == "add") {

	}
	else {
		// Invalid command
	}
	return false;
}