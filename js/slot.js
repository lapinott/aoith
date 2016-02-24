Slot = function (el) {
	var instance = this;
	this.html = el;
	this.has_equippable = false;
	this.has_equippable_id = "";
	this.hovered = false;
	this.background_empty = el.style.background;
	this.text_bkp = el.innerHTML;
	
	this.equip_equippable = function (item_id) {
		if (this.has_equippable) {
			// Unequip item...
		}
		instance.has_equippable = true;
		instance.has_equippable_id = item_id;
		g_Equippables[item_id].equipped_count++;
		this.html.style.background = 'url(items/img/' + g_Equippables[item_id].img + ') no-repeat center center, rgba(55, 255, 55, 0.85)';
		this.html.innerHTML = "";
	}
	
	this.equippable_mouse_over = function () {
		if (!this.has_equippable) this.html.style.background = 'rgba(255, 55, 55, 0.85)';
	}
	
	this.equippable_mouse_out = function () {
		if (!this.has_equippable) this.html.style.background = this.background_empty;
	}
	
	this.slot_right_click = function () {
		if (this.has_equippable) {
			this.html.style.background = this.background_empty;
			this.html.innerHTML = this.text_bkp;
			this.has_equippable = false;
			this.has_equippable_id = "";
		}
	}
}

createSlots = function () {
	var weapon_slots = document.getElementById('weapons_table').getElementsByTagName('td');
	for (var i = 0; i < weapon_slots.length; i++) {
		g_Slots[weapon_slots[i].id] = new Slot(weapon_slots[i]);
	}
	
	var armor_slots = document.getElementById('armor_table').getElementsByTagName('td');
	for (var i = 0; i < armor_slots.length; i++) {
		g_Slots[armor_slots[i].id] = new Slot(armor_slots[i]);
	}
	
	var implants_slots = document.getElementById('implants_table').getElementsByTagName('td');
	for (var i = 0; i < implants_slots.length; i++) {
		g_Slots[implants_slots[i].id] = new Slot(implants_slots[i]);
	}
}