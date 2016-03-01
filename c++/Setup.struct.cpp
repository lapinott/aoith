#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"
#include "SmartImplant.struct.h"
#include "Stats.struct.h"
#include "Setup.struct.h"

Setup::Setup() {
	this->e_slots[W_HUD1] = nullptr;
	this->e_slots[W_HUD2] = nullptr;
	this->e_slots[W_HUD3] = nullptr;
	this->e_slots[W_UTILS1] = nullptr;
	this->e_slots[W_UTILS2] = nullptr;
	this->e_slots[W_UTILS3] = nullptr;
	this->e_slots[W_RHAND] = nullptr;
	this->e_slots[W_DECK] = nullptr;
	this->e_slots[W_LHAND] = nullptr;
	this->e_slots[W_DECK1] = nullptr;
	this->e_slots[W_DECK2] = nullptr;
	this->e_slots[W_DECK3] = nullptr;
	this->e_slots[W_DECK4] = nullptr;
	this->e_slots[W_DECK5] = nullptr;
	this->e_slots[W_DECK6] = nullptr;

	this->e_slots[A_NECK] = nullptr;
	this->e_slots[A_HEAD] = nullptr;
	this->e_slots[A_BACK] = nullptr;
	this->e_slots[A_RSHOULDER] = nullptr;
	this->e_slots[A_CHEST] = nullptr;
	this->e_slots[A_LSHOULDER] = nullptr;
	this->e_slots[A_RARM] = nullptr;
	this->e_slots[A_HANDS] = nullptr;
	this->e_slots[A_LARM] = nullptr;
	this->e_slots[A_RWRIST] = nullptr;
	this->e_slots[A_LEGS] = nullptr;
	this->e_slots[A_LWRIST] = nullptr;
	this->e_slots[A_RFINGER] = nullptr;
	this->e_slots[A_FEET] = nullptr;
	this->e_slots[A_LFINGER] = nullptr;

	this->i_slots[I_EYES] = nullptr;
	this->i_slots[I_HEAD] = nullptr;
	this->i_slots[I_EAR] = nullptr;
	this->i_slots[I_RARM] = nullptr;
	this->i_slots[I_CHEST] = nullptr;
	this->i_slots[I_LARM] = nullptr;
	this->i_slots[I_RWRIST] = nullptr;
	this->i_slots[I_WAIST] = nullptr;
	this->i_slots[I_LWRIST] = nullptr;
	this->i_slots[I_RHAND] = nullptr;
	this->i_slots[I_LEGS] = nullptr;
	this->i_slots[I_LHAND] = nullptr;
	this->i_slots[I_FEET] = nullptr;
}

// Add std::cout
void Setup::equipEquippable(Stats* stat, Equippable* e) {

	// Return if already equipped
	for (std::pair<SLOTS, Equippable*> se : this->e_slots) if (se.second == e) return;

	// Remove item if slot not empty
	if (this->e_slots[e->slot] != nullptr) stat->removeFromStatEquippable(e);

	// Equip
	this->e_slots[e->slot] = e;
	stat->addToStatEquippable(e);
}

// Add std::cout
void Setup::removeEquippable(Stats* stat, SLOTS s) {
	if (this->e_slots[s] != nullptr) {
		stat->removeFromStatEquippable(this->e_slots[s]);
		this->e_slots[s] = nullptr;
	}
}

// Add std::cout
void Setup::removeEquippable(Stats* stat, Equippable* e) {
	if (this->e_slots[e->slot] == e) {
		stat->removeFromStatEquippable(this->e_slots[e->slot]);
		this->e_slots[e->slot] = nullptr;
	}
}

// Add std::cout
void Setup::equipImplant(Stats* stat, SLOTS s, SmartImplant* i) {
	// compute best ql
}

// Add std::cout
void Setup::removeImplant(Stats* stat, SLOTS s) {
	// ...
}

// Add std::cout
void Setup::removeImplant(Stats* stat, SmartImplant* i) {
	// ...
}