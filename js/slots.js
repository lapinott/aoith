Slot = function (el) {
	var instance = this;
	this.html = el;
	this.has_item = false;
	this.has_item_id = "";
	this.background_bkp = el.style.background;
	this.text_bkp = el.innerHTML;
	this.hovered = false;
	this.has_potential_equip_item = false;
	
	this.equip_item = function (item_id) {
		if (this.has_item) {
			// Unequip item...
		}
		instance.has_item = true;
		instance.has_item_id = item_id;
		g_Items[item_id].equipped_count++;
		this.html.style.background = 'url(items/img/' + g_Items[item_id].img + ') no-repeat center center, rgba(55, 255, 55, 0.85)';
		this.html.innerHTML = "";
	}
	
	this.item_list_mouse_over = function () {
		if (!this.has_item && !this.has_potential_equip_item) this.html.style.background = 'rgba(255, 55, 55, 0.85)';
	}
	
	this.item_list_mouse_out = function () {
		if (!this.has_item && !this.has_potential_equip_item) this.html.style.background = this.background_bkp;
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