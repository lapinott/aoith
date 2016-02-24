equippable_mouse_over = function (equippable_id) {
	var equippable = g_Equippables[equippable_id];
	for (var i = 0; i < equippable.slots.length; i++) {
		var slot_id = translate_location_to_slot_id(equippable.type, parseInt(equippable.slots[i]));
		g_Slots[slot_id].equippable_mouse_over();
	}
}

equippable_mouse_out = function (equippable_id) {
	var equippable = g_Equippables[equippable_id];
	for (var i = 0; i < equippable.slots.length; i++) {
		var slot_id = translate_location_to_slot_id(equippable.type, parseInt(equippable.slots[i]));
		g_Slots[slot_id].equippable_mouse_out();
	}
}

equippabble_mouse_click = function (equippable_id) {
	var equippable = g_Equippables[equippable_id];
	equippable.mouse_click();
}

equippable_mouse_right_click = function (equippable_id) {
	var equippable = g_Equippables[equippable_id];
	var slots = equippable.slots;
	var type = equippable.type;
	if (slots.length == 1) {
		g_Slots[translate_location_to_slot_id(type, parseInt(slots[0]))].equip_equippable(equippable_id);
	}
	else if (slots.length > 1) {
		// First equip where there is room, else overwrite
		for (var i = 0; i < slots.length; i++) {
			if (!g_Slots[translate_location_to_slot_id(type, parseInt(slots[i]))].has_equippable) {
				g_Slots[translate_location_to_slot_id(type, parseInt(slots[i]))].equip_equippable(equippable_id);
				return false;
			}
		}
		for (var i = 0; i < slots.length; i++) {
			if (g_Slots[translate_location_to_slot_id(type, parseInt(slots[i]))].has_equippable_id != equippable_id) {
				g_Slots[translate_location_to_slot_id(type, parseInt(slots[i]))].equip_equippable(equippable_id);
				return false;
			}
		}
	}
	return false;
}

weapon_mouse_right_click = function (slot_id) {
	return g_Slots[slot_id].slot_right_click();
}

armor_mouse_right_click = function (slot_id) {
	return g_Slots[slot_id].slot_right_click();
}

implant_mouse_right_click = function (slot_id) {
	return g_Slots[slot_id].slot_right_click();
}