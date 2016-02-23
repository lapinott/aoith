// Items container
var g_Items = [];

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
				default : alert("Slot not found!!"); break;
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
				default : alert("Slot not found!!"); break;
			}
		break;
		case 'i' :
			switch (slot) {
				case 0 : return "i_hud_1"; break;
				case 1 : return "i_hud_2"; break;
				case 2 : return "i_hud_3"; break;
				case 3 : return "i_utils_1"; break;
				case 4 : return "i_utils_2"; break;
				case 5 : return "i_utils_3"; break;
				case 6 : return "i_right_hand"; break;
				case 7 : return "i_deck"; break;
				case 8 : return "i_left_hand"; break;
				case 9 : return "i_deck_1"; break;
				case 10 : return "i_deck_2"; break;
				case 11 : return "i_deck_3"; break;
				case 12 : return "i_deck_4"; break;
				case 13 : return "i_deck_5"; break;
				case 14 : return "i_deck_6"; break;
				default : alert("Slot not found!!"); break;
			}
		break;
		default :
			alert("Type not found!!");
		break;
	}
}