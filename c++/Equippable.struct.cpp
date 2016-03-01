#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"

// Constructor
Equippable::Equippable(std::string name,
	SLOTS slot,
	unsigned int buff_str,
	unsigned int buff_sta,
	unsigned int buff_agi,
	unsigned int buff_sen,
	unsigned int buff_int,
	unsigned int buff_psy,
	unsigned int buff_treat
	) : name{ name }, slot{ slot }, buff_str{ buff_str }, buff_agi{ buff_agi }, buff_sen{ buff_sen }, buff_int{ buff_int }, buff_psy{ buff_psy }, buff_treat{ buff_treat } {

	// Give an instance ID
	srand((unsigned)time(0));
	while (id.length() < 10) this->id.push_back(char(std::rand() % 60) + 65);
}