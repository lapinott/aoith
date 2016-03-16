#pragma once

struct Setup {

	unsigned int base_str;
	unsigned int base_sta;
	unsigned int base_agi;
	unsigned int base_sen;
	unsigned int base_int;
	unsigned int base_psy;
	unsigned int base_treat; // subscract trickle on init

	unsigned int e_str_buff;
	unsigned int e_sta_buff;
	unsigned int e_agi_buff;
	unsigned int e_sen_buff;
	unsigned int e_int_buff;
	unsigned int e_psy_buff;
	unsigned int e_treat_buff;

	unsigned int i_str_buff;
	unsigned int i_sta_buff;
	unsigned int i_agi_buff;
	unsigned int i_sen_buff;
	unsigned int i_int_buff;
	unsigned int i_psy_buff;
	unsigned int i_treat_buff;

	float treat_trickle;

	void initStats(std::vector<unsigned int> init_stats);


	unsigned int getMax(STAT s) const;

	unsigned int getImplantsMax(STAT s) const;

	STAT getHighestAbility(std::vector<STAT> stats);

	unsigned int getHighestAbilityValue(std::vector<STAT> stats);


	float getTreatmentTrickle() const;


	void addToStatEquippable(Equippable* e);

	void removeFromStatEquippable(Equippable* e);


	void addToStatImplant(Implant* i);

	void removeFromStatImplant(Implant* i);


	void displayStats() const;

	Setup();

	Setup(
		unsigned int base_str,
		unsigned int base_sta,
		unsigned int base_agi,
		unsigned int base_sen,
		unsigned int base_int,
		unsigned int base_psy,
		unsigned int base_treat
		);

	std::map<SLOTS, Equippable*> e_slots;

	std::map<SLOTS, Implant*> i_slots;


	void equipEquippable(Equippable* e);

	void removeEquippable(SLOTS s);

	void removeEquippable(Equippable* e);


	void equipImplant(Implant* i);

	void removeImplant(SLOTS s);

	void removeImplant(Implant* i);


	void swapGear(Setup* setup);


	void displaySetup() const;
};