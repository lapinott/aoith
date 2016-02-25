Implant = function(_html, _id, _type, _slots, _potency, _name, _img, _buff, _reqs) {
	var instance = this;
	this.html = _html;
	this.id = _id;
	this.type = _type;
	this.slots = [];
	this.slots.push(_slots);
	this.potency = _potency;
	this.name = _name;
	this.img = _img;
	this.buff = _buff;
	this.buff_amount = 0;
	this.reqs = [];
	this.equipped_count = 0;
	this.overlay = null;
	this.has_overlay = false;
	this.quality_level = 0;
	for (var i = 0; i < _reqs.length; i++) this.reqs.push(_reqs[i]);
	this.text_node = document.createElement('span');
	
	this.mouse_click = function () {
		if (!this.has_overlay) {
			this.overlay = document.createElement('div');
			this.overlay.className = 'equippable_overlay';
			
			var span = document.createElement('span');
			span.className = 'ul bigger';
			span.innerHTML = "Requirement";
			this.overlay.appendChild(span);
			
			for (var i = 0; i < this.reqs.length; i++) {
				var span = document.createElement('span');
				switch (this.reqs[i]) {
					case 'str' : span.innerHTML = "Strength"; break;
					case 'sta' : span.innerHTML = "Stamina"; break;
					case 'agi' : span.innerHTML = "Agility"; break;
					case 'sen' : span.innerHTML = "Sense"; break;
					case 'int' : span.innerHTML = "Intelligence"; break;
					case 'psy' : span.innerHTML = "Psychic"; break;
					default : break;
				}
				if (i != this.reqs.length - 1) span.innerHTML += " or";
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