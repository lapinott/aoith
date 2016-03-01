#pragma once

struct SmartImplant {

	// Props
	std::string id;
	std::string name;
	SLOTS slot;

	// Buff
	std::vector<std::pair<POTENCY, STAT>> buffed_stat;

	// Req
	std::vector<STAT> requires_ability;

	// Slotted values
	unsigned int current_ql;
	STAT current_abi_req;

	SmartImplant(std::string name, SLOTS slot, std::vector<std::pair<POTENCY, STAT>> buffed_stat, std::vector<STAT> requires_ability);
};