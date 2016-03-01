#pragma once

struct SmartImplant {

	// Props
	std::string id;
	std::string name;
	SLOTS slot;

	// Buff
	std::vector<STAT> buffed_stat;

	// Req
	std::vector<STAT> requires_ability;

	// Quality level
	unsigned int current_ql;

	SmartImplant(std::string name, SLOTS slot, std::vector<STAT> buffed_stat, std::vector<STAT> requires_ability);
};