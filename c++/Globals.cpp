#include "Includes.h"
#include "Globals.h"
#include "Setup.struct.h"
#include "Stats.struct.h"

// Implants mapped by ID
std::vector<SmartImplant*>* g_implants = new std::vector<SmartImplant*>();

// Equippables mapped by ID
std::vector<Equippable*>* g_equippables = new std::vector<Equippable*>();

// Setup
Setup* g_setup = new Setup();

// Stat
Stats* g_stats = new Stats(1, 2, 3, 4, 5, 6, 7);

std::string get_ability_string(STAT s) {
	switch (s) {
	case STR: return "STR"; break;
	case STA: return "STA"; break;
	case AGI: return "AGI"; break;
	case SEN: return "SEN"; break;
	case INT: return "INT"; break;
	case PSY: return "PSY"; break;
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