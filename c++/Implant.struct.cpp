#include "Includes.h"
#include "Globals.h"
#include "Implant.struct.h"

Implant::Implant(std::string name, SLOTS slot, std::vector<std::pair<POTENCY, STAT>> buffed_stat, std::vector<STAT> requires_ability)
	: name{ name }, slot{ slot }, buffed_stat{ buffed_stat }, requires_ability{ requires_ability }, current_ql{ 0 }, current_abi_req{ STAT(-1) } {

	// Give an instance ID
	srand((unsigned)time(0));
	while (id.length() < 10) this->id.push_back(char(std::rand() % 60) + 65);
}