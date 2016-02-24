Item = function(_html, _id, _type, _slots, _name, _img, _str, _sta, _agi, _sen, _int, _psy, _treat) {
	var instance = this;
	this.html = _html;
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
	this.treat = _treat;
	this.equipped_count = 0;
	this.overlay = null;
	this.has_overlay = false;
	for (var i = 0; i < _slots.length; i++) this.slots.push(_slots[i]);
	this.text_node = document.createElement('span');
	
	this.mouse_click = function () {
		if (!this.has_overlay) {
			this.overlay = document.createElement('div');
			this.overlay.className = 'equippable_overlay';
			if (parseInt(this.str) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Str +" + this.str;
				this.overlay.appendChild(span);
			}
			if (parseInt(this.sta) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Sta +" + this.sta;
				this.overlay.appendChild(span);
			}
			if (parseInt(this.agi) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Agi +" + this.agi;
				this.overlay.appendChild(span);
			}
			if (parseInt(this.sen) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Sense +" + this.sen;
				this.overlay.appendChild(span);
			}
			if (parseInt(this.intel) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Int +" + this.intel;
				this.overlay.appendChild(span);
			}
			if (parseInt(this.psy) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Psy +" + this.psy;
				this.overlay.appendChild(span);
			}
			if (parseInt(this.treat) > 0) {
				var span = document.createElement('span');
				span.innerHTML = "Treat +" + this.treat;
				this.overlay.appendChild(span);
			}
			
			this.html.appendChild(this.overlay);
			this.has_overlay = true;
		}
		else {
			this.html.removeChild(this.overlay);
			this.has_overlay = false;
		}
	}
}