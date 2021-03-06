#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"
#include "Implant.struct.h"
#include "Setup.struct.h"
#include "Strategies.struct.h"

int main() {

	// Weapons
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [agi/sense]", W_LHAND, 0, 0, 10, 10, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [agi/sense]", W_RHAND, 0, 0, 10, 10, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [str/sta]", W_LHAND, 10, 10, 0, 0, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [str/sta]", W_RHAND, 10, 10, 0, 0, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [int/psy]", W_LHAND, 0, 0, 0, 0, 10, 10, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [int/psy]", W_RHAND, 0, 0, 0, 0, 10, 10, 0));
	g_equippables->push_back(new Equippable("Advanced Scent Sensor", W_HUD2, 0, 0, 0, 22, 0, 0, 0));
	g_equippables->push_back(new Equippable("Treatment Library", W_UTILS2, 0, 0, 0, 0, 0, 0, 6));

	// Armor
	g_equippables->push_back(new Equippable("Shades of Lucubration", A_HEAD, 0, 0, 0, 0, 30, 30, 0));
	g_equippables->push_back(new Equippable("Lya's Sangi Patch", A_LSHOULDER, 0, 0, 4, 4, 0, 0, 0));
	//g_equippables->push_back(new Equippable("Lya's Sangi Patch", A_RSHOULDER, 0, 0, 4, 4, 0, 0, 0));
	g_equippables->push_back(new Equippable("Overheated Shoulderpad", A_RSHOULDER, 1, 1, 1, 1, 1, 1, 3));
	g_equippables->push_back(new Equippable("Overheated Light Tank Armor", A_BACK, 1, 1, 1, 1, 1, 1, 0));
	g_equippables->push_back(new Equippable("Pure Novictum Ring for the Control Unit", A_RFINGER, 0, 0, 0, 0, 8, 0, 0));
	g_equippables->push_back(new Equippable("Platinum Filigree Ring set with a Perfectly Cut Ruby Pearl", A_RFINGER, 0, 0, 0, 4, 4, 0, 0));
	g_equippables->push_back(new Equippable("Platinum Filigree Ring set with a Perfectly Cut Ruby Pearl", A_LFINGER, 0, 0, 0, 4, 4, 0, 0));
	g_equippables->push_back(new Equippable("Platinum Filigree Ring set with a Perfectly Cut Ruby Pearl", A_RFINGER, 0, 0, 0, 5, 5, 0, 0));
	g_equippables->push_back(new Equippable("Platinum Filigree Ring set with a Perfectly Cut Ruby Pearl", A_LFINGER, 0, 0, 0, 5, 5, 0, 0));
	g_equippables->push_back(new Equippable("Platinum Filigree Ring set with a Perfectly Cut Almandine", A_RFINGER, 4, 0, 4, 0, 0, 0, 0));
	g_equippables->push_back(new Equippable("Platinum Filigree Ring set with a Perfectly Cut Almandine", A_LFINGER, 4, 0, 4, 0, 0, 0, 0));
	g_equippables->push_back(new Equippable("Omni-Med Suit Sleeves", A_RARM, 0, 0, 0, 0, 0, 0, 14));
	g_equippables->push_back(new Equippable("Omni-Med Suit Sleeves", A_LARM, 0, 0, 0, 0, 0, 0, 14));
	g_equippables->push_back(new Equippable("Omni-Med Suit Shirt", A_CHEST, 0, 0, 0, 0, 0, 0, 20));
	g_equippables->push_back(new Equippable("Omni-Med Suit Boots", A_FEET, 0, 0, 0, 0, 0, 0, 6));
	g_equippables->push_back(new Equippable("Omni-Med Suit Gloves", A_HANDS, 0, 0, 0, 0, 0, 0, 10));
	g_equippables->push_back(new Equippable("Omni-Med Suit Trousers", A_LEGS, 0, 0, 0, 0, 0, 0, 14));
	g_equippables->push_back(new Equippable("Docaholic's Ring", A_RFINGER, 0, 0, 0, 0, 0, 0, 14));
	g_equippables->push_back(new Equippable("Docaholic's Ring", A_LFINGER, 0, 0, 0, 0, 0, 0, 14));
	g_equippables->push_back(new Equippable("Nova Dillon Body Armor", A_CHEST, 2, 2, 2, 2, 2, 2, 0));
	g_equippables->push_back(new Equippable("Nova Dillon Armor Sleeves", A_LARM, 2, 2, 2, 2, 2, 2, 0));
	g_equippables->push_back(new Equippable("Nova Dillon Armor Sleeves", A_RARM, 2, 2, 2, 2, 2, 2, 0));
	g_equippables->push_back(new Equippable("Nova Dillon Armor Gloves", A_HANDS, 2, 2, 2, 2, 2, 2, 0));
	g_equippables->push_back(new Equippable("Nova Dillon Armor Pants", A_LEGS, 2, 2, 2, 2, 2, 2, 0));
	g_equippables->push_back(new Equippable("Nova Nova Dillon Armor Boots", A_FEET, 2, 2, 2, 2, 2, 2, 0));

	// Treatment implants
	std::vector<std::pair<POTENCY, STAT>> buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, TREAT), std::make_pair(FADED, SEN) };
	std::vector<STAT> requires_ability = std::vector<STAT>{ AGI, SEN, INT, PSY };
	g_implants->push_back(new Implant("Head Implant: Treatment Shiny", I_HEAD, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, TREAT) };
	requires_ability = std::vector<STAT>{ AGI, SEN, INT };
	g_implants->push_back(new Implant("Eye Implant: Treatment Bright", I_EYES, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, TREAT) };
	requires_ability = std::vector<STAT>{ STA, AGI, SEN, INT };
	g_implants->push_back(new Implant("Right-Hand Implant: Treatment Faded", I_RHAND, buffed_stat, requires_ability));

	// Str implants
	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, STR) };
	requires_ability = std::vector<STAT>{ STR, STA, AGI, SEN };
	g_implants->push_back(new Implant("Right-Arm Implant: Strength Shining", I_RARM, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, STR) };
	requires_ability = std::vector<STAT>{ STR, STA, SEN };
	g_implants->push_back(new Implant("Left-Arm Implant: Strength Bright", I_LARM, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, STR) };
	requires_ability = std::vector<STAT>{ STA, AGI, INT, PSY };
	g_implants->push_back(new Implant("Chest Implant: Strength Faded", I_CHEST, buffed_stat, requires_ability));

	// Sta implants
	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, STA) };
	requires_ability = std::vector<STAT>{ STR, STA, AGI };
	g_implants->push_back(new Implant("Chest Implant: Stamina Shining", I_CHEST, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, STA) };
	requires_ability = std::vector<STAT>{ STA, AGI };
	g_implants->push_back(new Implant("Leg Implant: Stamina Bright", I_LEGS, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, STA) };
	requires_ability = std::vector<STAT>{ STA, AGI, SEN, PSY };
	g_implants->push_back(new Implant("Waist Implant: Stamina Faded", I_WAIST, buffed_stat, requires_ability));

	// Agi implants
	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, AGI) };
	requires_ability = std::vector<STAT>{ STA, AGI };
	g_implants->push_back(new Implant("Leg Implant: Agility Shining", I_LEGS, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, AGI) };
	requires_ability = std::vector<STAT>{ STA, AGI };
	g_implants->push_back(new Implant("Feet Implant: Agility Bright", I_FEET, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, AGI) };
	requires_ability = std::vector<STAT>{ STA, AGI, SEN, PSY };
	g_implants->push_back(new Implant("Waist Implant: Agility Faded", I_WAIST, buffed_stat, requires_ability));

	// Sense implants
	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, SEN) };
	requires_ability = std::vector<STAT>{ STR, AGI, INT, PSY };
	g_implants->push_back(new Implant("Chest Implant: Sense Shining", I_CHEST, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, SEN) };
	requires_ability = std::vector<STAT>{ STA, AGI, SEN, PSY };
	g_implants->push_back(new Implant("Waist Implant: Sense Bright", I_WAIST, buffed_stat, requires_ability));

	/*buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, SEN) };
	requires_ability = std::vector<STAT>{ STA, AGI, SEN, INT, PSY };
	g_implants->push_back(new Implant("Head Implant: Sense Faded", I_HEAD, buffed_stat, requires_ability));*/

	// Int implants
	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, INT), std::make_pair(FADED, SEN) };
	requires_ability = std::vector<STAT>{ AGI, SEN, INT, PSY };
	g_implants->push_back(new Implant("Head Implant: Intelligence Shining / Sense faded", I_HEAD, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, INT) };
	requires_ability = std::vector<STAT>{ AGI, SEN, INT, PSY };
	g_implants->push_back(new Implant("Eye Implant: Intelligence Bright", I_EYES, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, INT) };
	requires_ability = std::vector<STAT>{ AGI, SEN, INT, PSY };
	g_implants->push_back(new Implant("Ear Implant: Intelligence Faded", I_EAR, buffed_stat, requires_ability));

	// Psy implants
	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(SHINING, PSY) };
	requires_ability = std::vector<STAT>{ AGI, SEN, INT, PSY };
	g_implants->push_back(new Implant("Head Implant: Psychic Shining", I_HEAD, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(BRIGHT, PSY) };
	requires_ability = std::vector<STAT>{ STR, STA, INT, PSY };
	g_implants->push_back(new Implant("Chest Implant: Psychic Bright", I_CHEST, buffed_stat, requires_ability));

	buffed_stat = std::vector<std::pair<POTENCY, STAT>>{ std::make_pair(FADED, PSY) };
	requires_ability = std::vector<STAT>{ AGI, SEN, INT };
	g_implants->push_back(new Implant("Ear Implant: Psychic Faded", I_EAR, buffed_stat, requires_ability));

	// Init stats
	g_init_stats = { 95, 55, 58, 46, 68, 58, 224 };
	g_setup->initStats(g_init_stats);

	// Welcome
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
	std::cout << "- -  AO IMPLANT TWINK HELPER -- type 'help' for a list of commands  - -" << std::endl;
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl << std::endl;

	// Display help
	handleCommand("help");

	/*Strategies test_strat = Strategies();
	test_strat.create_max_stat_setups(g_equippables);
	test_strat.max_str_setup.displaySetup();
	test_strat.max_sta_setup.displaySetup();
	test_strat.max_agi_setup.displaySetup();
	test_strat.max_sen_setup.displaySetup();
	test_strat.max_int_setup.displaySetup();
	test_strat.max_psy_setup.displaySetup();
	test_strat.max_treat_setup.displaySetup();*/

	// Loop commands
	char command[100];
	while (std::cout << std::endl << "> " && std::cin.getline(command, sizeof(command))) {

		// Handle command
		if (std::string(command) == "exit") break;
		else if (std::string(command) != "") {
			std::cout << std::endl;
			handleCommand(command);
		}
	}

	// Out
	std::cout << "bye";
	return 0;
}