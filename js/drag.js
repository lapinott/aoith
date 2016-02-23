item_list_mouse_over = function (id) {
	var item = g_Items[id];
	for (var i = 0; i < item.slots.length; i++) {
		var slot_id = translate_location_to_slot_id(item.type, parseInt(item.slots[i]));
		g_Slots[slot_id].item_list_mouse_over();
	}
}

item_list_mouse_out = function (id) {
	var item = g_Items[id];
	for (var i = 0; i < item.slots.length; i++) {
		var slot_id = translate_location_to_slot_id(item.type, parseInt(item.slots[i]));
		g_Slots[slot_id].item_list_mouse_out();
	}
}

item_list_mouse_click = function (id) {
	var item = g_Items[id];
	for (var i = 0; i < item.slots.length; i++) {
		
	}
}

item_list_mouse_right_click = function (item_id) {
	var item = g_Items[item_id];
	var slots = item.slots;
	var type = item.type;
	if (slots.length == 1) {
		g_Slots[translate_location_to_slot_id(type, parseInt(slots[0]))].equip_item(item_id);
	}
	else if (slots.length > 1) {
		// First equip where there is room, else overwrite
		for (var i = 0; i < slots.length; i++) {
			if (!g_Slots[translate_location_to_slot_id(type, parseInt(slots[i]))].has_item) {
				g_Slots[translate_location_to_slot_id(type, parseInt(slots[i]))].equip_item(item_id);
				return false;
			}
		}
		// ...
		/*
		for () {
			
		}
		*/
	}
	return false;
}