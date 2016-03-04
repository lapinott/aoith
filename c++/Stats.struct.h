#pragma once

struct Stats {

	unsigned int base_str;
	unsigned int base_sta;
	unsigned int base_agi;
	unsigned int base_sen;
	unsigned int base_int;
	unsigned int base_psy;
	unsigned int base_treat; // subscract trickle on init

	unsigned int str_buff;
	unsigned int sta_buff;
	unsigned int agi_buff;
	unsigned int sen_buff;
	unsigned int int_buff;
	unsigned int psy_buff;
	unsigned int treat_buff;

	float treat_trickle;

	Stats(
		unsigned int base_str,
		unsigned int base_sta,
		unsigned int base_agi,
		unsigned int base_sen,
		unsigned int base_int,
		unsigned int base_psy,
		unsigned int base_treat
	);

	void initStats(
		unsigned int base_str,
		unsigned int base_sta,
		unsigned int base_agi,
		unsigned int base_sen,
		unsigned int base_int,
		unsigned int base_psy,
		unsigned int base_treat
	);


	unsigned int getMax(STAT s) const;

	STAT getHighestAbility(std::vector<STAT> stats);

	unsigned int getHighestAbilityValue(std::vector<STAT> stats);


	float getTreatmentTrickle() const;


	void addToStatEquippable(Equippable* e);

	void removeFromStatEquippable(Equippable* e);


	void addToStatImplant(SmartImplant* i);

	void removeFromStatImplant(SmartImplant* i);


	void displayStats() const;
};