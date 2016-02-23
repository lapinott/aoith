Item = function(_id, _type, _slots, _name, _img, _str, _sta, _agi, _sen, _int, _psy) {
	this.instance = this;
	this.id = _id;
	this.type = _type;
	this.slots = [];
	this.name = _name;
	this.img = _img;
	this.str = _str;
	this.sta = _sta;
	this.agi = _agi;
	this.sen = _sen;
	this.intel = _int;
	this.psy = _psy;
	this.equipped_count = 0;
	
	// Push slots..
	for (var i = 0; i < _slots.length; i++) this.slots.push(_slots[i]);
}