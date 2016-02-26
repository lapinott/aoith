Slot = function (el) {
	var instance = this;
	this.html = el;
	this.has_equippable = false;
	this.has_equippable_id = "";
	this.hovered = false;
	this.background_empty = el.style.background;
	this.text_bkp = el.innerHTML;
	this.overlay = null;
	this.has_overlay = false;
	
	this.equip_equippable = function (equippable) {
		switch (equippable.type) {
			case 'w' :
			case 'a' :
			
				// Bkp
				var old_item = this.has_equippable ? g_Equippables[this.has_equippable_id] : null;
				var new_item = g_Equippables[equippable.id];
				
				if (this.has_equippable) g_Stats.remove_wa_from_twink(g_Equippables[this.has_equippable_id]);
				g_Stats.add_wa_to_twink(equippable);
				this.has_equippable = true;
				this.has_equippable_id = equippable.id;
				equippable.equipped_count++;
				this.html.style.background = 'url(items/img/' + equippable.img + ') no-repeat center center, rgba(55, 255, 55, 0.85)';
				this.html.innerHTML = "";
				this.html.title = g_Equippables[this.has_equippable_id].name;
				
				// Log action
				g_Logger.log_item(old_item, new_item);
			break;
			case 'i' :
				
				// Bkp
				var old_imp = this.has_equippable ? g_Equippables[this.has_equippable_id] : null;
				var new_imp = equippable;
				
				// Empty slot if not empty
				if (this.has_equippable) {
					g_Stats.remove_i_from_twink(g_Equippables[this.has_equippable_id]);
					//g_Equippables[this.has_equippable_id].slotted_with_ql = 0;
					//g_Equippables[this.has_equippable_id].slotted_with_req = "";
				}
				
				// Bla notify
				this.has_equippable = true;
				this.has_equippable_id = equippable.id;
				equippable.equipped_count++;
				this.html.style.background = 'url(items/img/' + equippable.img + ') no-repeat center center, rgba(55, 255, 55, 0.85)';
				
				// Calculate best possible ql and relative stats
				var best_req_abi;
				var best_req_amount_abi = 0;
				for (var i = 0; i < equippable.reqs.length;  i++) {
					if (g_Stats.get_stat(equippable.reqs[i]) > best_req_amount_abi) {
						best_req_abi = equippable.reqs[i];
						best_req_amount_abi = g_Stats.get_stat(equippable.reqs[i]);
					}
				}
				
				// Reverse get correponding ql's
				var ql_abi = Math.floor((best_req_amount_abi - 4) / 2);
				var ql_treat = Math.floor((g_Stats.get_stat("treat") - 1249/199) / (940/199));
				
				// Take smaller of two
				var ql_best = ql_abi > ql_treat ? ql_treat : ql_abi;
				var req_abi = Math.round(2 * ql_best + 4);
				var req_treat = Math.round(940/199 * ql_best + 1249/199);
				
				// Compute buffing values
				if (equippable.buff == "str" || equippable.buff == "sta" || equippable.buff == "agi" || equippable.buff == "sen" || equippable.buff == "int" || equippable.buff == "psy") {
					if (equippable.potency == "s") equippable.buff_amount = Math.round(50/199 * ql_best + 945/199);
					if (equippable.potency == "b") equippable.buff_amount = Math.round(30/199 * ql_best + 567/199);
					if (equippable.potency == "f") equippable.buff_amount = Math.round(20/199 * ql_best + 378/199);
				}
				else if (equippable.buff == "treat") {
					if (equippable.potency == "s") equippable.buff_amount = Math.round(99/199 * ql_best + 1095/199);
					if (equippable.potency == "b") equippable.buff_amount = Math.round(60/199 * ql_best + 537/199);
					if (equippable.potency == "f") equippable.buff_amount = Math.round(40/199 * ql_best + 358/199);
				}
				
				// Save some values
				equippable.slotted_with_ql = ql_best;
				equippable.slotted_with_req = best_req_abi;
				
				// Display implant info
				this.html.innerHTML = "";
				this.html.title = equippable.name
				this.overlay = document.createElement('div');
				this.overlay.className = 'slot_overlay';
				var span1 = document.createElement('span');
				span1.innerHTML = "QL " + ql_best;
				this.overlay.appendChild(span1);
				var span2 = document.createElement('span');
				span2.innerHTML = "+" + equippable.buff_amount + " " + equippable.buff;
				this.overlay.appendChild(span2);
				var span3 = document.createElement('span');
				span3.innerHTML = best_req_abi + "-based";
				this.overlay.appendChild(span3);
				var span4 = document.createElement('span');
				span4.innerHTML = "Reqs: " + req_abi + "/" + req_treat;
				this.overlay.appendChild(span4);
				this.html.appendChild(this.overlay);
				
				// Add implant to twink stats
				g_Stats.add_i_to_twink(equippable);
				
				// Log action
				g_Logger.log_implant(old_imp, new_imp);
			break;
			default : break;
		}
	}
	
	this.equippable_mouse_over = function () {
		if (!this.has_equippable) this.html.style.background = 'rgba(255, 55, 55, 0.85)';
	}
	
	this.equippable_mouse_out = function () {
		if (!this.has_equippable) this.html.style.background = this.background_empty;
	}
	
	this.slot_right_click = function () {
		if (this.has_equippable) {
			switch (g_Equippables[this.has_equippable_id].type) {
				case 'w' :
				case 'a' :
					g_Stats.remove_wa_from_twink(g_Equippables[this.has_equippable_id]);
					g_Logger.log_item(g_Equippables[this.has_equippable_id], null);
				break;
				case 'i' :
					g_Stats.remove_i_from_twink(g_Equippables[this.has_equippable_id]);
					g_Logger.log_item(g_Equippables[this.has_equippable_id], null);
				break;
				default : break;
			}
			this.html.style.background = this.background_empty;
			this.html.innerHTML = this.text_bkp;
			this.html.title = "";
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