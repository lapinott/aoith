#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"
#include "Implant.struct.h"
#include "Setup.struct.h"

Setup::Setup() : Setup(0, 0, 0, 0, 0, 0, 0) {}

Setup::Setup(unsigned int base_str, unsigned int base_sta, unsigned int base_agi, unsigned int base_sen, unsigned int base_int, unsigned int base_psy, unsigned int base_treat)
	: base_str{ base_str }, base_sta{ base_sta }, base_agi{ base_agi }, base_sen{ base_sen }, base_int{ base_int }, base_psy{ base_psy }, base_treat{ base_treat } {

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

	// Calculate base treatment trickle
	this->treat_trickle = 0.25f * (0.5f * this->base_int + 0.3f * this->base_agi + 0.2f * this->base_sen);
	this->base_treat = (int)std::round((float)this->base_treat - this->treat_trickle);

	// Init values
	this->e_str_buff = 0;
	this->e_sta_buff = 0;
	this->e_agi_buff = 0;
	this->e_sen_buff = 0;
	this->e_int_buff = 0;
	this->e_psy_buff = 0;
	this->e_treat_buff = 0;
	this->i_str_buff = 0;
	this->i_sta_buff = 0;
	this->i_agi_buff = 0;
	this->i_sen_buff = 0;
	this->i_int_buff = 0;
	this->i_psy_buff = 0;
	this->i_treat_buff = 0;
}

void Setup::initStats(std::vector<unsigned int> init_stats) {

	this->base_str = init_stats[0];
	this->base_sta = init_stats[1];
	this->base_agi = init_stats[2];
	this->base_sen = init_stats[3];
	this->base_int = init_stats[4];
	this->base_psy = init_stats[5];
	this->base_treat = init_stats[6];

	this->treat_trickle = 0.25f * (0.5f * this->base_int + 0.3f * this->base_agi + 0.2f * this->base_sen);
	this->base_treat = (int)std::round((float)this->base_treat - this->treat_trickle);
}

unsigned int Setup::getMax(STAT s) const {
	switch (s) {
	case STR: return this->base_str + this->e_str_buff + this->i_str_buff; break;
	case STA: return this->base_sta + this->e_sta_buff + this->i_sta_buff; break;
	case AGI: return this->base_agi + this->e_agi_buff + this->i_agi_buff; break;
	case SEN: return this->base_sen + this->e_sen_buff + this->i_sen_buff; break;
	case INT: return this->base_int + this->e_int_buff + this->i_int_buff; break;
	case PSY: return this->base_psy + this->e_psy_buff + this->i_psy_buff; break;
	case TREAT: return this->base_treat + this->e_treat_buff + this->i_treat_buff + (int)std::round(this->treat_trickle); break;
	default: return 0;
	}
}

unsigned int Setup::getImplantsMax(STAT s) const {
	switch (s) {
	case STR: return this->i_str_buff; break;
	case STA: return this->i_sta_buff; break;
	case AGI: return this->i_agi_buff; break;
	case SEN: return this->i_sen_buff; break;
	case INT: return this->i_int_buff; break;
	case PSY: return this->i_psy_buff; break;
	case TREAT: return this->i_treat_buff; break;
	default: return 0;
	}
}

float Setup::getTreatmentTrickle() const {
	return 0.25f * (0.5f * this->getMax(INT) + 0.3f * this->getMax(AGI) + 0.2f * this->getMax(SEN));
}

STAT Setup::getHighestAbility(std::vector<STAT> stats) {
	unsigned int max_value = 0;
	for (unsigned int i = 0; i < NUM_STAT; i++) {
		for (unsigned int j = 0; j < stats.size(); j++) {
			if (stats[j] == STAT(i)) max_value = std::max(max_value, this->getMax(stats[j]));
		}
	}
	if (max_value == getMax(STR)) return STR;
	else if (max_value == getMax(STA)) return STA;
	else if (max_value == getMax(AGI)) return AGI;
	else if (max_value == getMax(SEN)) return SEN;
	else if (max_value == getMax(INT)) return INT;
	else if (max_value == getMax(PSY)) return PSY;
	else return NUM_STAT;
}

unsigned int Setup::getHighestAbilityValue(std::vector<STAT> stats) {
	unsigned int max_value = 0;
	for (unsigned int i = 0; i < NUM_STAT; i++) {
		for (STAT s : stats) if (s == STAT(i)) max_value = std::max(max_value, this->getMax(s));
	}
	return max_value;
}

void Setup::addToStatEquippable(Equippable* e) {
	if (e->buff_str > 0) this->e_str_buff += e->buff_str;
	if (e->buff_sta > 0) this->e_sta_buff += e->buff_sta;
	if (e->buff_agi > 0) {
		this->e_agi_buff += e->buff_agi;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_sen > 0) {
		this->e_sen_buff += e->buff_sen;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_int > 0) {
		this->e_int_buff += e->buff_int;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_psy > 0) this->e_psy_buff += e->buff_psy;
	if (e->buff_treat > 0) this->e_treat_buff += e->buff_treat;
}

void Setup::removeFromStatEquippable(Equippable* e) {
	if (e->buff_str > 0) this->e_str_buff -= e->buff_str;
	if (e->buff_sta > 0) this->e_sta_buff -= e->buff_sta;
	if (e->buff_agi > 0) {
		this->e_agi_buff -= e->buff_agi;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_sen > 0) {
		this->e_sen_buff -= e->buff_sen;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_int > 0) {
		this->e_int_buff -= e->buff_int;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_psy > 0) this->e_psy_buff -= e->buff_psy;
	if (e->buff_treat > 0) this->e_treat_buff -= e->buff_treat;
}

void Setup::addToStatImplant(Implant* i) {
	for (std::pair<POTENCY, STAT> ps : i->buffed_stat) {
		switch (ps.second) {
		case STR:
			this->i_str_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case STA:
			this->i_sta_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case AGI:
			this->i_agi_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case SEN:
			this->i_sen_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case INT:
			this->i_int_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case PSY:
			this->i_psy_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case TREAT:
			this->i_treat_buff += get_treatment_buff_amount_from_ql(ps.first, i->current_ql); break;
		default: break;
		}
	}
}

void Setup::removeFromStatImplant(Implant* i) {
	for (std::pair<POTENCY, STAT> ps : i->buffed_stat) {
		switch (ps.second) {
		case STR:
			this->i_str_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case STA:
			this->i_sta_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case AGI:
			this->i_agi_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case SEN:
			this->i_sen_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case INT:
			this->i_int_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case PSY:
			this->i_psy_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case TREAT:
			this->i_treat_buff -= get_treatment_buff_amount_from_ql(ps.first, i->current_ql); break;
		default: break;
		}
	}
}

void Setup::displayStats() const {
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::cout << "|   STR   |   STA   |   AGI   |   SEN   |   INT   |   PSY   |   TREAT   |" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
	std::string s = std::to_string(this->getMax(STR));
	unsigned int from = s.length() / 2;
	for (unsigned int i = 0; i < 4 - from; i++) s = std::string(" ") + s;
	unsigned int to = s.length();
	for (unsigned int i = 0; i < 9 - to; i++) s += " ";
	std::cout << "|" << s;
	s = std::to_string(this->getMax(STA));
	from = s.length() / 2;
	for (unsigned int i = 0; i < 4 - from; i++) s = std::string(" ") + s;
	to = s.length();
	for (unsigned int i = 0; i < 9 - to; i++) s += " ";
	std::cout << "|" << s;
	s = std::to_string(this->getMax(AGI));
	from = s.length() / 2;
	for (unsigned int i = 0; i < 4 - from; i++) s = std::string(" ") + s;
	to = s.length();
	for (unsigned int i = 0; i < 9 - to; i++) s += " ";
	std::cout << "|" << s;
	s = std::to_string(this->getMax(SEN));
	from = s.length() / 2;
	for (unsigned int i = 0; i < 4 - from; i++) s = std::string(" ") + s;
	to = s.length();
	for (unsigned int i = 0; i < 9 - to; i++) s += " ";
	std::cout << "|" << s;
	s = std::to_string(this->getMax(INT));
	from = s.length() / 2;
	for (unsigned int i = 0; i < 4 - from; i++) s = std::string(" ") + s;
	to = s.length();
	for (unsigned int i = 0; i < 9 - to; i++) s += " ";
	std::cout << "|" << s;
	s = std::to_string(this->getMax(PSY));
	from = s.length() / 2;
	for (unsigned int i = 0; i < 4 - from; i++) s = std::string(" ") + s;
	to = s.length();
	for (unsigned int i = 0; i < 9 - to; i++) s += " ";
	std::cout << "|" << s;
	s = std::to_string(this->getMax(TREAT));
	from = s.length() / 2;
	for (unsigned int i = 0; i < 5 - from; i++) s = std::string(" ") + s;
	to = s.length();
	for (unsigned int i = 0; i < 11 - to; i++) s += " ";
	std::cout << "|" << s << "|" << std::endl;
	std::cout << "-------------------------------------------------------------------------" << std::endl;
}

void Setup::equipEquippable(Equippable* e) {

	// Return if e null
	if (e == nullptr) return;

	// Return if already equipped
	for (std::pair<SLOTS, Equippable*> se : this->e_slots) {
		if (se.second == e) {
			std::cout << "[x] [" << get_slot_string(e->slot) << "] " << e->name << " is already equipped." << std::endl;
			return;
		}
	}

	// Remove item if slot not empty
	if (this->e_slots[e->slot] != nullptr) {
		this->removeFromStatEquippable(e);
		std::cout << "[-] [" << get_slot_string(e->slot) << "] " << this->e_slots[e->slot]->name << " removed." << std::endl;
	}

	// Equip
	this->e_slots[e->slot] = e;
	this->addToStatEquippable(e);
	std::cout << "[+] [" << get_slot_string(e->slot) << "] " << e->name << " equipped." << std::endl;
}

void Setup::removeEquippable(SLOTS s) {
	if (this->e_slots[s] != nullptr) {
		this->removeFromStatEquippable(this->e_slots[s]);
		std::cout << "[-] [" << get_slot_string(s) << "] " << this->e_slots[s]->name << " removed." << std::endl;
		this->e_slots[s] = nullptr;
	}
}

void Setup::removeEquippable(Equippable* e) {
	if (this->e_slots[e->slot] == e) {
		this->removeFromStatEquippable(this->e_slots[e->slot]);
		std::cout << "[-] [" << get_slot_string(e->slot) << "] " << e->name << " removed." << std::endl;
		this->e_slots[e->slot] = nullptr;
	}
}

// Add std::cout
void Setup::equipImplant(Implant* i) {
	
	// Remove item if slot not empty
	if (this->i_slots[i->slot] != nullptr) {
		std::cout << "[-] [" << get_slot_string(i->slot) << "|QL" << this->i_slots[i->slot]->current_ql << "|" << get_stat_string(this->i_slots[i->slot]->current_abi_req) << "-BASED] " << this->i_slots[i->slot]->name << " removed." << std::endl;
		this->removeFromStatImplant(this->i_slots[i->slot]);
	}

	// Get best QL
	unsigned int highest_ability_value = this->getHighestAbilityValue(i->requires_ability);
	unsigned int ql_abi = (int)std::floor(((float)highest_ability_value - 4.0f) / 2.0f);
	unsigned int ql_treat = (int)std::floor(((float)this->getMax(TREAT) - 1249.0f / 199.0f) / (940.0f / 199.0f));
	unsigned int ql_best = std::min(ql_abi, ql_treat);

	// Upload values
	i->current_ql = ql_best;
	i->current_abi_req = this->getHighestAbility(i->requires_ability);

	// Equip
	this->i_slots[i->slot] = i;
	this->addToStatImplant(i);
	std::cout << "[+] [" << get_slot_string(i->slot) << "|QL" << i->current_ql << "|" << get_stat_string(i->current_abi_req) << "-BASED] " << i->name << " equipped." << std::endl;
}

void Setup::removeImplant(SLOTS s) {
	if (this->i_slots[s] != nullptr) {
		this->removeFromStatImplant(this->i_slots[s]);
		std::cout << "[-]  [" << get_slot_string(s) << "|QL" << this->i_slots[s]->current_ql << "|" << get_stat_string(this->i_slots[s]->current_abi_req) << "-BASED] " << this->i_slots[s]->name << " removed." << std::endl;
		this->i_slots[s] = nullptr;
	}
}

void Setup::removeImplant(Implant* i) {
	if (this->i_slots[i->slot] == i) {
		this->removeFromStatImplant(this->i_slots[i->slot]);
		std::cout << "[-] [" << get_slot_string(i->slot) << "|QL" << i->current_ql << "|" << get_stat_string(i->current_abi_req) << "-BASED] " << i->name << " removed." << std::endl;
		this->i_slots[i->slot] = nullptr;
	}
}

void Setup::displaySetup() const {
	for (std::pair<SLOTS, Implant*> si : this->i_slots) {
		if (si.second != nullptr) std::cout << "[" << get_slot_string(si.second->slot) << "|QL" << si.second->current_ql << "|" << get_stat_string(si.second->current_abi_req) << "-BASED] " << si.second->name << std::endl;
		//else std::cout << "[" << get_slot_string(si.first) << "] empty." << std::endl;
		if (si.second != nullptr && si.second->name == "") {
			int what = 123;
		}
	}
	for (std::pair<SLOTS, Equippable*> se : this->e_slots) {
		if (se.second != nullptr) std::cout << "[" << get_slot_string(se.first) << "] " << se.second->name << std::endl;
		//else std::cout << "[" << get_slot_string(se.first) << "] empty." << std::endl;
	}
}

void Setup::swapGear(Setup* setup) {
	for (std::pair<SLOTS, Equippable*> se : setup->e_slots) {
		if (se.second != nullptr) this->equipEquippable(se.second);
	}
}