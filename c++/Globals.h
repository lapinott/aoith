#pragma once

struct SmartImplant;
struct Equippable;
struct Setup;

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

std::string get_ability_string(STAT a);

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

// Implants mapped by ID
extern std::map<std::string, SmartImplant*>* g_implants;

// Equippables mapped by ID
extern std::map<std::string, Equippable*>* g_equippables;

// Setup
extern Setup* g_setup;

// BASE function -> display base stats
// LIST functions -> equippables + implants
// STAT function -> display stat
// SETUP function -> display setup
