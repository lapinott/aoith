#pragma once

struct Stats {

	unsigned int base_str;
	unsigned int base_sta;
	unsigned int base_agi;
	unsigned int base_sen;
	unsigned int base_int;
	unsigned int base_psy;
	float base_treat; // subscract trickle on init

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
		float base_treat
	);

	void addToStatEquippable(Equippable* e);

	void removeFromStatEquippable(Equippable* e);

	void addToStatImplant(SmartImplant* i); // pass this

	void removeFromStatImplant(SmartImplant* i);

	void updateStats(Setup* setup);
};