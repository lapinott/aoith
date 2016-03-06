#pragma once

struct Equippable {

	// Props
	std::string id;
	std::string name;
	SLOTS slot;

	// Buffs
	unsigned int buff_str;
	unsigned int buff_sta;
	unsigned int buff_agi;
	unsigned int buff_sen;
	unsigned int buff_int;
	unsigned int buff_psy;
	unsigned int buff_treat;

	// Constructor
	Equippable(
		std::string name,
		SLOTS slot,
		unsigned int buff_str,
		unsigned int buff_sta,
		unsigned int buff_agi,
		unsigned int buff_sen,
		unsigned int buff_int,
		unsigned int buff_psy,
		unsigned int buff_treat
	);
};