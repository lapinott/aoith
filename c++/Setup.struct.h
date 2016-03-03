#pragma once

struct Setup {

	// Equippables slots
	std::map<SLOTS, Equippable*> e_slots;

	// Implants slots
	std::map<SLOTS, SmartImplant*> i_slots;

	Setup();


	void equipEquippable(Stats* stat, Equippable* e);

	void removeEquippable(Stats* stat, SLOTS s);

	void removeEquippable(Stats* stat, Equippable* e);


	void equipImplant(Stats* stat, SmartImplant* i);

	void removeImplant(Stats* stat, SLOTS s);

	void removeImplant(Stats* stat, SmartImplant* i);

	void displaySetup() const;
};