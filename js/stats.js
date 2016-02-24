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
	
	this.base_str = parseInt(this.html_base_str.innerHTML);
	this.base_sta = parseInt(this.html_base_sta.innerHTML);
	this.base_agi = parseInt(this.html_base_agi.innerHTML);
	this.base_sen = parseInt(this.html_base_sen.innerHTML);
	this.base_int = parseInt(this.html_base_int.innerHTML);
	this.base_psy = parseInt(this.html_base_psy.innerHTML);
	this.base_treat = parseInt(this.html_base_treat.innerHTML);
	
	this.buff_str = 0;
	this.buff_sta = 0;
	this.buff_agi = 0;
	this.buff_sen = 0;
	this.buff_int = 0;
	this.buff_psy = 0;
	this.buff_treat = 0;
	
	this.refresh_stats_twinked_values = function () {
		this.html_twinked_str.innerHTML = this.base_str + this.buff_str;
		this.html_twinked_sta.innerHTML = this.base_sta + this.buff_sta;
		this.html_twinked_agi.innerHTML = this.base_agi + this.buff_agi;
		this.html_twinked_sen.innerHTML = this.base_sen + this.buff_sen;
		this.html_twinked_int.innerHTML = this.base_int + this.buff_int;
		this.html_twinked_psy.innerHTML = this.base_psy + this.buff_psy;
		this.html_twinked_treat.innerHTML = this.base_treat + this.buff_treat;
	}
	
	this.change_base_stats_cell = function (el) {
		switch (el.id) {
			case 'base_str' : this.base_str = parseInt(this.html_base_str.innerHTML); break;
			case 'base_sta' : this.base_sta = parseInt(this.html_base_sta.innerHTML); break;
			case 'base_agi' : this.base_agi = parseInt(this.html_base_agi.innerHTML); break;
			case 'base_sen' : this.base_sen = parseInt(this.html_base_sen.innerHTML); break;
			case 'base_int' : this.base_int = parseInt(this.html_base_int.innerHTML); break;
			case 'base_psy' : this.base_psy = parseInt(this.html_base_psy.innerHTML); break;
			case 'base_treat' : this.base_treat = parseInt(this.html_base_treat.innerHTML); break;
			default : break;
		}
		this.refresh_stats_twinked_values();
	}
}