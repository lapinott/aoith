#include "Includes.h"
#include "Globals.h"
#include "Stats.struct.h"
#include "Setup.struct.h"
#include "Equippable.struct.h"
#include "SmartImplant.struct.h"

Stats::Stats(unsigned int base_str, unsigned int base_sta, unsigned int base_agi, unsigned int base_sen, unsigned int base_int, unsigned int base_psy, unsigned int base_treat)
	: base_str{ base_str }, base_sta{ base_sta }, base_agi{ base_agi }, base_sen{ base_sen }, base_int{ base_int }, base_psy{ base_psy }, base_treat{ base_treat } {

	// Calculate base treatment trickle
	this->treat_trickle = 0.25f * (0.5f * this->base_int + 0.3f * this->base_agi + 0.2f * this->base_sen);
	this->base_treat = (int)std::round((float)this->base_treat - this->treat_trickle);

	// Init values
	this->str_buff = 0;
	this->sta_buff = 0;
	this->agi_buff = 0;
	this->sen_buff = 0;
	this->int_buff = 0;
	this->psy_buff = 0;
	this->treat_buff = 0;
}

unsigned int Stats::getMax(STAT s) const {
	switch (s) {
	case STR: return this->base_str + this->str_buff; break;
	case STA: return this->base_sta + this->sta_buff; break;
	case AGI: return this->base_agi + this->agi_buff; break;
	case SEN: return this->base_sen + this->sen_buff; break;
	case INT: return this->base_int + this->int_buff; break;
	case PSY: return this->base_psy + this->psy_buff; break;
	case TREAT: return this->base_treat + this->treat_buff + (int)std::round(this->treat_trickle); break;
	default: return 0;
	}
}

float Stats::getTreatmentTrickle() const {
	return 0.25f * (0.5f * this->getMax(INT) + 0.3f * this->getMax(AGI) + 0.2f * this->getMax(SEN));
}

STAT Stats::getHighestAbility(std::vector<STAT> stats) {
	unsigned int max_value = 0;
	for (unsigned int i = 0; i < NUM_ABILITY; i++) {
		for (unsigned int j = 0; j < stats.size(); j++) {
			if (stats[j] == STAT(j)) max_value = std::max(max_value, this->getMax(stats[j]));
		}
	}
	if (max_value == getMax(STR)) return STR;
	if (max_value == getMax(STA)) return STA;
	if (max_value == getMax(AGI)) return AGI;
	if (max_value == getMax(SEN)) return SEN;
	if (max_value == getMax(INT)) return INT;
	if (max_value == getMax(PSY)) return PSY;
	return NUM_ABILITY;
}

unsigned int Stats::getHighestAbilityValue(std::vector<STAT> stats) {
	unsigned int max_value = 0;
	for (unsigned int i = 0; i < NUM_ABILITY; i++) {
		for (unsigned int j = 0; j < stats.size(); j++) {
			if (stats[j] == STAT(j)) max_value = std::max(max_value, this->getMax(stats[j]));
		}
	}
	return max_value;
}

void Stats::addToStatEquippable(Equippable* e) {
	if (e->buff_str > 0) this->str_buff += e->buff_str;
	if (e->buff_sta > 0) this->sta_buff += e->buff_sta;
	if (e->buff_agi > 0) {
		this->agi_buff += e->buff_agi;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_sen > 0) {
		this->sen_buff += e->buff_sen;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_int > 0) {
		this->int_buff += e->buff_int;
		this->treat_trickle = this->getTreatmentTrickle();
	}
	if (e->buff_psy > 0) this->psy_buff += e->buff_psy;
	if (e->buff_treat > 0) this->treat_buff += e->buff_treat;
}

void Stats::removeFromStatEquippable(Equippable* e) {
	if (e->buff_str > 0) this->str_buff -= e->buff_str;
	if (e->buff_sta > 0) this->sta_buff -= e->buff_sta;
	if (e->buff_agi > 0) this->agi_buff -= e->buff_agi;
	if (e->buff_sen > 0) this->sen_buff -= e->buff_sen;
	if (e->buff_int > 0) this->int_buff -= e->buff_int;
	if (e->buff_psy > 0) this->psy_buff -= e->buff_psy;
	if (e->buff_treat > 0) this->treat_buff -= e->buff_treat;
}

void Stats::addToStatImplant(SmartImplant* i) {
	for (std::pair<POTENCY, STAT> ps : i->buffed_stat) {
		switch (ps.second) {
		case STR:
			this->str_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case STA:
			this->sta_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case AGI:
			this->agi_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case SEN:
			this->sen_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case INT:
			this->int_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql);
			this->treat_trickle = this->getTreatmentTrickle();
			break;
		case PSY:
			this->psy_buff += get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case TREAT:
			this->treat_buff += get_treatment_buff_amount_from_ql(ps.first, i->current_ql); break;
		default: break;
		}
	}
}

void Stats::removeFromStatImplant(SmartImplant* i) {
	for (std::pair<POTENCY, STAT> ps : i->buffed_stat) {
		switch (ps.second) {
		case STR:
			this->str_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case STA:
			this->sta_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case AGI:
			this->agi_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case SEN:
			this->sen_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case INT:
			this->int_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case PSY:
			this->psy_buff -= get_ability_buff_amount_from_ql(ps.first, i->current_ql); break;
		case TREAT:
			this->treat_buff -= get_treatment_buff_amount_from_ql(ps.first, i->current_ql); break;
		default: break;
		}
	}
}

void Stats::displayStat() const {
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
	std::cout << "|" << s << "|";
}