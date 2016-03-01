#include "Includes.h"
#include "Globals.h"

// Implants mapped by ID
std::map<std::string, SmartImplant*>* g_implants{};

// Equippables mapped by ID
std::map<std::string, Equippable*>* g_equippables{};

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