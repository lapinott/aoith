#include "Includes.h"
#include "Globals.h"
#include "Setup.struct.h"
#include "Stats.struct.h"
#include "Equippable.struct.h"
#include "SmartImplant.struct.h"

Stats::Stats(unsigned int base_str, unsigned int base_sta, unsigned int base_agi, unsigned int base_sen, unsigned int base_int, unsigned int base_psy, float base_treat)
	: base_str{ base_str }, base_sta{ base_sta }, base_agi{ base_agi }, base_sen{ base_sen }, base_int{ base_int }, base_psy{ base_psy }, base_treat{ base_treat } {

	// Calculate base treatment trickle
	this->treat_trickle = 0.25f * (0.5f * this->base_int + 0.3f * this->base_agi + 0.2f * this->base_sen);
	this->base_treat -= this->treat_trickle;
}

void Stats::addToStatEquippable(Equippable* e) {
	if (e->buff_str > 0) this->str_buff += e->buff_str;
	if (e->buff_sta > 0) this->sta_buff += e->buff_sta;
	if (e->buff_agi > 0) this->agi_buff += e->buff_agi;
	if (e->buff_sen > 0) this->sen_buff += e->buff_sen;
	if (e->buff_int > 0) this->int_buff += e->buff_int;
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
}

void Stats::removeFromStatImplant(SmartImplant* i) {
}

void Stats::updateStats(Setup* setup) {
	this->str_buff = 0;
	this->sta_buff = 0;
	this->agi_buff = 0;
	this->sen_buff = 0;
	this->int_buff = 0;
	this->psy_buff = 0;
	this->treat_buff = 0;

	for (int i = 0; i < I_EYES; i++) {
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_str > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_str;
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_sta > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_sta;
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_agi > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_agi;
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_sen > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_sen;
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_int > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_int;
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_psy > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_psy;
		if (g_setup->e_slots[SLOTS(i)] != nullptr && g_setup->e_slots[SLOTS(i)]->buff_treat > 0) this->str_buff += g_setup->e_slots[SLOTS(i)]->buff_treat;
	}

	for (int i = I_EYES + 1; i < NUM_SLOTS; i++) {
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == STR) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_str;
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == STA) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_sta;
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == AGI) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_agi;
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == SEN) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_sen;
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == INT) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_int;
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == PSY) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_psy;
		if (g_setup->i_slots[SLOTS(i)] != nullptr && g_setup->i_slots[SLOTS(i)]->buffed_stat == TREAT) this->str_buff += g_setup->i_slots[SLOTS(i)]->buff_treat;
	}
}