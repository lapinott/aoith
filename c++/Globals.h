#pragma once

struct SmartImplant;
struct Equippable;
struct Setup;
struct Stats;
struct Strategies;

enum STAT {
	STR,
	STA,
	AGI,
	SEN,
	INT,
	PSY,
	TREAT,
	NUM_ABILITY
};

enum POTENCY {
	FADED,
	BRIGHT,
	SHINING,
	NUM_POTENCY
};

std::string get_stat_string(STAT s);

std::string get_potency_string(POTENCY p);

unsigned int get_ability_buff_amount_from_ql(POTENCY p, unsigned int ql);

unsigned int get_treatment_buff_amount_from_ql(POTENCY p, unsigned int ql);

unsigned int get_equippable_id(Equippable* e);

unsigned int get_implant_id(SmartImplant* i);

bool equip_item_id(unsigned int item_id);

enum SLOTS {

	// Weapons
	W_HUD1, W_HUD2, W_HUD3, W_UTILS1, W_UTILS2,
	W_UTILS3, W_RHAND, W_DECK, W_LHAND, W_DECK1,
	W_DECK2, W_DECK3, W_DECK4, W_DECK5, W_DECK6,

	// Armor
	A_NECK, A_HEAD, A_BACK, A_RSHOULDER, A_CHEST,
	A_LSHOULDER, A_RARM, A_HANDS, A_LARM, A_RWRIST,
	A_LEGS, A_LWRIST, A_RFINGER, A_FEET, A_LFINGER,

	// Implants
	I_EYES, I_HEAD, I_EAR, I_RARM, I_CHEST,
	I_LARM, I_RWRIST, I_WAIST, I_LWRIST, I_RHAND,
	I_LEGS, I_LHAND, I_FEET,
	NUM_SLOTS
};

bool is_weapon(Equippable* e);

bool is_armor(Equippable* e);

std::string get_slot_string(SLOTS s);

bool handleCommand(std::string cmd);

// Implants mapped by ID
extern std::vector<SmartImplant*>* g_implants;

// Equippables mapped by ID
extern std::vector<Equippable*>* g_equippables;

// Setup
extern Setup* g_setup;

// Stat
extern Stats* g_stats;

// Strategies
extern Strategies* g_strategies;
