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

void Setup::equipEquippable(Stats* stat, Equippable* e) {

	// Return if already equipped
	for (std::pair<SLOTS, Equippable*> se : this->e_slots) {
		if (se.second == e) {
			std::cout << e->name << " (" << get_slot_string(e->slot) << ") is already equipped." << std::endl;
			return;
		}
	}

	// Remove item if slot not empty
	if (this->e_slots[e->slot] != nullptr) {
		stat->removeFromStatEquippable(e);
		std::cout << e->name << " (" << get_slot_string(e->slot) << ") removed." << std::endl;
	}

	// Equip
	this->e_slots[e->slot] = e;
	stat->addToStatEquippable(e);
	std::cout << e->name << " (" << get_slot_string(e->slot) << ") equipped." << std::endl;
}

void Setup::removeEquippable(Stats* stat, SLOTS s) {
	if (this->e_slots[s] != nullptr) {
		stat->removeFromStatEquippable(this->e_slots[s]);
		std::cout << this->e_slots[s]->name << " (" << get_slot_string(s) << ") removed." << std::endl;
		this->e_slots[s] = nullptr;
	}
}

void Setup::removeEquippable(Stats* stat, Equippable* e) {
	if (this->e_slots[e->slot] == e) {
		stat->removeFromStatEquippable(this->e_slots[e->slot]);
		std::cout << e->name << " (" << get_slot_string(e->slot) << ") removed." << std::endl;
		this->e_slots[e->slot] = nullptr;
	}
}

// Add std::cout
void Setup::equipImplant(Stats* stat, SmartImplant* i) {
	
	// Get best QL
	unsigned int highest_ability_value = stat->getHighestAbilityValue(i->requires_ability);
	unsigned int ql_abi = (int)std::floor((highest_ability_value - 4) / 2);
	unsigned int ql_treat = (int)std::floor((stat->getMax(TREAT) - 1249 / 199) / (940 / 199));
	unsigned int ql_best = std::min(ql_abi, ql_treat);

	// Send unequip if slot not empty
	if (this->i_slots[i->slot] != nullptr) {
		unsigned int buff_amount = 0;
		std::cout << i->name << " (" << get_slot_string(i->slot) << " - QL" << i->current_ql << ") removed." << std::endl;
		stat->removeFromStatImplant(i);
	}

	// up
	i->current_ql = ql_best;
	i->current_abi_req = stat->getHighestAbility(i->requires_ability);

	// add to stat
	stat->addToStatImplant(i);
}

// Add std::cout
void Setup::removeImplant(Stats* stat, SLOTS s) {
	if (this->i_slots[s] != nullptr) {
		stat->removeFromStatImplant(this->i_slots[s]);
		this->i_slots[s] = nullptr;
	}
}

// Add std::cout
void Setup::removeImplant(Stats* stat, SmartImplant* i) {
	if (this->i_slots[i->slot] == i) {
		stat->removeFromStatImplant(this->i_slots[i->slot]);
		this->i_slots[i->slot] = nullptr;
	}
}