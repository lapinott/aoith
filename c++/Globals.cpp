#include "Includes.h"
#include "Globals.h"

// Implants mapped by ID
std::vector<SmartImplant*>* g_implants{};

// Equippables mapped by ID
std::vector<Equippable*>* g_equippables{};

// Setup
Setup* g_setup{};

std::string get_ability_string(STAT a) {
	switch (a) {
	case STR: return "STR"; break;
	case STA: return "STA"; break;
	case AGI: return "AGI"; break;
	case SEN: return "SEN"; break;
	case INT: return "INT"; break;
	case PSY: return "PSY"; break;
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