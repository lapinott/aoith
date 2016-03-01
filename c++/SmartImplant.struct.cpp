#include "Includes.h"
#include "Globals.h"
#include "SmartImplant.struct.h"

SmartImplant::SmartImplant(std::string name, SLOTS slot, std::vector<STAT> buffed_stat, std::vector<STAT> requires_ability)
	: name{ name }, slot{ slot }, current_ql{ 0 }, buffed_stat{ buffed_stat }, requires_ability{ requires_ability } {

	// Give an instance ID
	srand((unsigned)time(0));
	while (id.length() < 10) this->id.push_back(char(std::rand() % 60) + 65);
}