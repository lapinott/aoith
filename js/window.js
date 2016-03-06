// Equippables container
var g_Equippables = [];

// Slots container
var g_Slots = [];

// Potential equip slots
var g_SlotsEquipPotential = [];

translate_location_to_slot_id = function (type, slot) {
	switch (type) {
		case 'w' :
			switch (slot) {
				case 0 : return "w_hud_1"; break;
				case 1 : return "w_hud_2"; break;
				case 2 : return "w_hud_3"; break;
				case 3 : return "w_utils_1"; break;
				case 4 : return "w_utils_2"; break;
				case 5 : return "w_utils_3"; break;
				case 6 : return "w_right_hand"; break;
				case 7 : return "w_deck"; break;
				case 8 : return "w_left_hand"; break;
				case 9 : return "w_deck_1"; break;
				case 10 : return "w_deck_2"; break;
				case 11 : return "w_deck_3"; break;
				case 12 : return "w_deck_4"; break;
				case 13 : return "w_deck_5"; break;
				case 14 : return "w_deck_6"; break;
				default : alert("Slot '" + slot + "' not found!!"); break;
			}
		break;
		case 'a' :
			switch (slot) {
				case 0 : return "a_neck"; break;
				case 1 : return "a_head"; break;
				case 2 : return "a_back"; break;
				case 3 : return "a_right_shoulder"; break;
				case 4 : return "a_chest"; break;
				case 5 : return "a_left_shoulder"; break;
				case 6 : return "a_right_arm"; break;
				case 7 : return "a_hands"; break;
				case 8 : return "a_left_arm"; break;
				case 9 : return "a_right_wrist"; break;
				case 10 : return "a_legs"; break;
				case 11 : return "a_left_wrist"; break;
				case 12 : return "a_right_finger"; break;
				case 13 : return "a_feet"; break;
				case 14 : return "a_left_finger"; break;
				default : alert("Slot '" + slot + "' not found!!"); break;
			}
		break;
		case 'i' :
			switch (slot) {
				case 0 : return "i_eyes"; break;
				case 1 : return "i_head"; break;
				case 2 : return "i_ears"; break;
				case 3 : return "i_right_arm"; break;
				case 4 : return "i_chest"; break;
				case 5 : return "i_left_arm"; break;
				case 6 : return "i_right_wrist"; break;
				case 7 : return "i_waist"; break;
				case 8 : return "i_left_wrist"; break;
				case 9 : return "i_right_hand"; break;
				case 10 : return "i_legs"; break;
				case 11 : return "i_left_hand"; break;
				case 13 : return "i_feet"; break;
				default : alert("Slot '" + slot + "' not found!!"); break;
			}
		break;
		default :
			alert("Type '" + type + "' not found!!");
		break;
	}
}

addEventListeners = function () {
	var weapon_slots = document.getElementById('weapons_table').getElementsByTagName('td');
	for (var i = 0; i < weapon_slots.length; i++) {
		weapon_slots[i].addEventListener('click', function() {
			//weapon_mouse_click(this.id);
		});
		weapon_slots[i].addEventListener('contextmenu', function(event) {
			weapon_mouse_right_click(this.id);
			event.preventDefault();
		});
		weapon_slots[i].addEventListener('mouseover', function() {
			//weapon_mouse_over(this.id);
		});
		weapon_slots[i].addEventListener('mouseout', function() {
			//weapon_mouse_out(this.id);
		});
	}
	var armor_slots = document.getElementById('armor_table').getElementsByTagName('td');
	for (var i = 0; i < armor_slots.length; i++) {
		armor_slots[i].addEventListener('click', function() {
			//armor_mouse_click(this);
		});
		armor_slots[i].addEventListener('contextmenu', function(event) {
			armor_mouse_right_click(this.id);
			event.preventDefault();
		});
		armor_slots[i].addEventListener('mouseover', function() {
			//armor_mouse_over(this);
		});
		armor_slots[i].addEventListener('mouseout', function() {
			//armor_mouse_out(this);
		});
	}
	var implant_slots = document.getElementById('implants_table').getElementsByTagName('td');
	for (var i = 0; i < implant_slots.length; i++) {
		implant_slots[i].addEventListener('click', function() {
			//implant_mouse_click(this);
		});
		implant_slots[i].addEventListener('contextmenu', function(event) {
			implant_mouse_right_click(this.id);
			event.preventDefault();
		});
		implant_slots[i].addEventListener('mouseover', function() {
			//implant_mouse_over(this);
		});
		implant_slots[i].addEventListener('mouseout', function() {
			//implant_mouse_out(this);
		});
	}
}