Stats = function () {
	this.html_base_str = document.getElementById('base_str');
	this.html_base_sta = document.getElementById('base_sta');
	this.html_base_agi = document.getElementById('base_agi');
	this.html_base_sen = document.getElementById('base_sen');
	this.html_base_int = document.getElementById('base_int');
	this.html_base_psy = document.getElementById('base_psy');
	this.html_base_treat = document.getElementById('base_treat');
	
	this.html_twinked_str = document.getElementById('twinked_str');
	this.html_twinked_sta = document.getElementById('twinked_sta');
	this.html_twinked_agi = document.getElementById('twinked_agi');
	this.html_twinked_sen = document.getElementById('twinked_sen');
	this.html_twinked_int = document.getElementById('twinked_int');
	this.html_twinked_psy = document.getElementById('twinked_psy');
	this.html_twinked_treat = document.getElementById('twinked_treat');
	
	this.base_str = parseInt(this.html_base_str.value);
	this.base_sta = parseInt(this.html_base_sta.value);
	this.base_agi = parseInt(this.html_base_agi.value);
	this.base_sen = parseInt(this.html_base_sen.value);
	this.base_int = parseInt(this.html_base_int.value);
	this.base_psy = parseInt(this.html_base_psy.value);
	this.base_treat = parseInt(this.html_base_treat.value);
	
	this.twinked_str = 0;
	this.twinked_sta = 0;
	this.twinked_agi = 0;
	this.twinked_sen = 0;
	this.twinked_int = 0;
	this.twinked_psy = 0;
	this.twinked_treat = 0;
	
	this.trickle_treat_init = 0.25 * (0.5 * this.base_int + 0.3 * this.base_agi + 0.2 * this.base_sen);
	
	this.get_stat = function (stat) {
		switch (stat) {
			case 'str' : return this.base_str + this.twinked_str;
			case 'sta' : return this.base_sta + this.twinked_sta;
			case 'agi' : return this.base_agi + this.twinked_agi;
			case 'sen' : return this.base_sen + this.twinked_sen;
			case 'int' : return this.base_int + this.twinked_int;
			case 'psy' : return this.base_psy + this.twinked_psy;
			case 'treat' : return Math.round(this.base_treat + this.twinked_treat - this.trickle_treat_init + this.get_treatment_trickle());
			default : return 0;
		}
	}
	
	this.get_treatment_trickle = function () {
		return 0.25 * (0.5 * this.get_stat('int') + 0.3 * this.get_stat('agi') + 0.2 * this.get_stat('sen'));
	}
	
	this.refresh_stats_twinked_values = function () {
		var str = this.base_str + this.twinked_str;
		var sta = this.base_sta + this.twinked_sta;
		var agi = this.base_agi + this.twinked_agi;
		var sen = this.base_sen + this.twinked_sen;
		var intel = this.base_int + this.twinked_int;
		var psy = this.base_psy + this.twinked_psy;
		var treat = Math.round(this.base_treat + this.twinked_treat - this.trickle_treat_init + this.get_treatment_trickle());
		var ql_str = Math.floor((str - 4) / 2);
		var ql_sta = Math.floor((sta - 4) / 2);
		var ql_agi = Math.floor((agi - 4) / 2);
		var ql_sen = Math.floor((sen - 4) / 2);
		var ql_int = Math.floor((intel - 4) / 2);
		var ql_psy = Math.floor((psy - 4) / 2);
		var ql_treat = Math.floor((treat - 1249/199) / (940/199));
		
		this.html_twinked_str.innerHTML = str + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_str + "]</span>";
		this.html_twinked_sta.innerHTML = sta + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_sta + "]</span>";
		this.html_twinked_agi.innerHTML = agi + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_agi + "]</span>";
		this.html_twinked_sen.innerHTML = sen + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_sen + "]</span>";
		this.html_twinked_int.innerHTML = intel + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_int + "]</span>";
		this.html_twinked_psy.innerHTML = psy + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_psy + "]</span>";
		this.html_twinked_treat.innerHTML = treat + " <span class=\"stat_rel_ql\" title=\"Relative best QL\">[ql" + ql_treat + "]</span> <span class=\"stat_treat_trickle\" title=\"Trickle\">[&uarr;" + Math.round(this.get_treatment_trickle()) + "]</span>";
	}
	
	this.change_base_stats_cell = function (el) {
		switch (el.id) {
			case 'base_str' : this.base_str = parseInt(this.html_base_str.value); break;
			case 'base_sta' : this.base_sta = parseInt(this.html_base_sta.value); break;
			case 'base_agi' : this.base_agi = parseInt(this.html_base_agi.value); break;
			case 'base_sen' : this.base_sen = parseInt(this.html_base_sen.value); break;
			case 'base_int' : this.base_int = parseInt(this.html_base_int.value); break;
			case 'base_psy' : this.base_psy = parseInt(this.html_base_psy.value); break;
			case 'base_treat' : this.base_treat = parseInt(this.html_base_treat.value); break;
			default : break;
		}
		this.refresh_stats_twinked_values();
	}
	
	this.add_wa_to_twink = function (equippable) {
		if (equippable.str > 0) this.twinked_str += equippable.str;
		if (equippable.sta > 0) this.twinked_sta += equippable.sta;
		if (equippable.agi > 0) this.twinked_agi += equippable.agi;
		if (equippable.sen > 0) this.twinked_sen += equippable.sen;
		if (equippable.intel > 0) this.twinked_int += equippable.intel;
		if (equippable.psy > 0) this.twinked_psy += equippable.psy;
		if (equippable.treat > 0) this.twinked_treat += equippable.treat;
		this.refresh_stats_twinked_values();
	}
	
	this.remove_wa_from_twink = function (equippable) {
		if (equippable.str > 0) this.twinked_str -= equippable.str;
		if (equippable.sta > 0) this.twinked_sta -= equippable.sta;
		if (equippable.agi > 0) this.twinked_agi -= equippable.agi;
		if (equippable.sen > 0) this.twinked_sen -= equippable.sen;
		if (equippable.intel > 0) this.twinked_int -= equippable.intel;
		if (equippable.psy > 0) this.twinked_psy -= equippable.psy;
		if (equippable.treat > 0) this.twinked_treat -= equippable.treat;
		this.refresh_stats_twinked_values();
	}
	
	this.add_i_to_twink = function (equippable) {
		switch (equippable.buff) {
			case 'str' : this.twinked_str += equippable.buff_amount; break;
			case 'sta' : this.twinked_sta += equippable.buff_amount; break;
			case 'agi' : this.twinked_agi += equippable.buff_amount; break;
			case 'sen' : this.twinked_sen += equippable.buff_amount; break;
			case 'int' : this.twinked_int += equippable.buff_amount; break;
			case 'psy' : this.twinked_psy += equippable.buff_amount; break;
			case 'treat' : this.twinked_treat += equippable.buff_amount; break;
			default : break;
		}
		this.refresh_stats_twinked_values();
	}
	
	this.remove_i_from_twink = function (equippable) {
		switch (equippable.buff) {
			case 'str' : this.twinked_str -= equippable.buff_amount; break;
			case 'sta' : this.twinked_sta -= equippable.buff_amount; break;
			case 'agi' : this.twinked_agi -= equippable.buff_amount; break;
			case 'sen' : this.twinked_sen -= equippable.buff_amount; break;
			case 'int' : this.twinked_int -= equippable.buff_amount; break;
			case 'psy' : this.twinked_psy -= equippable.buff_amount; break;
			case 'treat' : this.twinked_treat -= equippable.buff_amount; break;
			default : break;
		}
		this.refresh_stats_twinked_values();
	}
}