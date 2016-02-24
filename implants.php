<!DOCTYPE html>
<html>
	<head>
		<title>AO Implant Twink Helper</title>
		<link rel="shortcut icon" href="img/ao.png" type="image/x-icon">
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<script type="text/javascript" src="js/scripts.js"></script>
		<script type="text/javascript" src="js/window.js"></script>
		<script type="text/javascript" src="js/item.js"></script>
		<script type="text/javascript" src="js/events.js"></script>
		<script type="text/javascript" src="js/slots.js"></script>
	</head>
	<body>
		<div id="main_frame">
			<div id="base_stats_container" class="stats_table_container">
				<table id="base_stats" class="stats_table">
					<thead>
						<tr><td colspan="2">Base buffed stats</td></tr>
					</thead>
					<tbody>
						<tr class="str">
							<td>Strength</td>
							<td id="base_str" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
						<tr class="sta">
							<td>Stamina</td>
							<td id="base_sta" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
						<tr class="agi">
							<td>Agility</td>
							<td id="base_agi" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
						<tr class="sen">
							<td>Sense</td>
							<td id="base_sen" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
						<tr class="int">
							<td>Intelligence</td>
							<td id="base_int" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
						<tr class="psy">
							<td>Psychic</td>
							<td id="base_psy" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
						<tr class="treat">
							<td>Treatment</td>
							<td id="base_treat" class="ce" contenteditable="true" onclick="click_base_stats_cell_ce(this);">0</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div id="updated_stats_container" class="stats_table_container">
				<table id="updated_stats" class="stats_table">
					<thead>
						<tr><td colspan="2">Twinked stats</td></tr>
					</thead>
					<tbody>
						<tr class="str">
							<td>Strength</td>
							<td id="updated_str" class="nce" contenteditable="false">0</td>
						</tr>
						<tr class="sta">
							<td>Stamina</td>
							<td id="updated_sta" class="nce" contenteditable="false">0</td>
						</tr>
						<tr class="agi">
							<td>Agility</td>
							<td id="updated_agi" class="nce" contenteditable="false">0</td>
						</tr>
						<tr class="sen">
							<td>Sense</td>
							<td id="updated_sen" class="nce" contenteditable="false">0</td>
						</tr>
						<tr class="int">
							<td>Intelligence</td>
							<td id="updated_int" class="nce" contenteditable="false">0</td>
						</tr>
						<tr class="psy">
							<td>Psychic</td>
							<td id="updated_psy" class="nce" contenteditable="false">0</td>
						</tr>
						<tr class="treat">
							<td>Treatment</td>
							<td id="updated_treat" class="nce" contenteditable="false">0</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div id="weapons_table_container" class="equip_table_container">
				<table id="weapons_table" class="equip_table">
					<tbody>
						<tr>
							<td id="w_hud_1">Hud-1</td>
							<td id="w_hud_2">Hud-2</td>
							<td id="w_hud_3">Hud-3</td>
						</tr>
						<tr>
							<td id="w_utils_1">Utils-1</td>
							<td id="w_utils_2">Utils-2</td>
							<td id="w_utils_3">Utils-3</td>
						</tr>
						<tr>
							<td id="w_right_hand">Right hand</td>
							<td id="w_deck">Deck</td>
							<td id="w_left_hand">Left hand</td>
						</tr>
						<tr>
							<td id="w_deck_1">Deck-1</td>
							<td id="w_deck_2">Deck-2</td>
							<td id="w_deck_3">Deck-3</td>
						</tr>
						<tr>
							<td id="w_deck_4">Deck-4</td>
							<td id="w_deck_5">Deck-5</td>
							<td id="w_deck_6">Deck-6</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div id="armor_table_container" class="equip_table_container">
				<table id="armor_table" class="equip_table">
					<tbody>
						<tr>
							<td id="a_neck">Neck</td>
							<td id="a_head">Head</td>
							<td id="a_back">Back</td>
						</tr>
						<tr>
							<td id="a_right_shoulder">Right shoulder</td>
							<td id="a_chest">Chest</td>
							<td id="a_left_shoulder">Left shoulder</td>
						</tr>
						<tr>
							<td id="a_right_arm">Right arm</td>
							<td id="a_hands">Hands</td>
							<td id="a_left_arm">Left arm</td>
						</tr>
						<tr>
							<td id="a_right_wrist">Right wrist</td>
							<td id="a_legs">Legs</td>
							<td id="a_left_wrist">Left wrist</td>
						</tr>
						<tr>
							<td id="a_right_finger">Right finger</td>
							<td id="a_feet">Feet</td>
							<td id="a_left_finger">Left finger</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div id="implants_table_container" class="equip_table_container">
				<table id="implants_table" class="equip_table">
					<tbody>
						<tr>
							<td id="i_eyes">Eyes</td>
							<td id="i_head">Head</td>
							<td id="i_ears">Ears</td>
						</tr>
						<tr>
							<td id="i_right_arm">Right arm</td>
							<td id="i_chest">Chest</td>
							<td id="i_left_arm">Left arm</td>
						</tr>
						<tr>
							<td id="i_right_wrist">Right wrist</td>
							<td id="i_waist">Waist</td>
							<td id="i_left_wrist">Left wrist</td>
						</tr>
						<tr>
							<td id="i_right_hand">Right hand</td>
							<td id="i_legs">Legs</td>
							<td id="i_left_hand">Left hand</td>
						</tr>
						<tr>
							<td id="i_empty_right">&nbsp;</td>
							<td id="i_feet">Feet</td>
							<td id="i_empty_left">&nbsp;</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div class="cb"></div>
			<fieldset id="items_container">
				<legend>Items</legend>
				<div><?php
				
				// Get items from file
				$items = Array();
				$fhandle = fopen("items/item_list.csv", "r");
				$i = 0;
				while (($line = fgets($fhandle)) !== false) {
					if ($line[0] !== "#") {
						$values = explode(",", $line);
						$data = Array($i);
						$data['id'] = md5($i);
						$data['type'] = $values[0];
						$data['slots'] = explode("|", $values[1]);
						$data['name'] = $values[2];
						$data['img'] = $values[3];
						$data['str'] = $values[4];
						$data['sta'] = $values[5];
						$data['agi'] = $values[6];
						$data['sen'] = $values[7];
						$data['int'] = $values[8];
						$data['psy'] = $values[9];
						$data['treat'] = $values[10];
						$items[] = $data;
						++$i;
					}
				}
				
				// Print items
				foreach ($items as $item) {
					echo "\r\n\t\t\t\t\t<div id=\"".$item['id']."\" class=\"list_item\" oncontextmenu=\"return item_list_mouse_right_click('".$item['id']."');\" onclick=\"item_list_mouse_click('".$item['id']."');\" onmouseover=\"item_list_mouse_over('".$item['id']."');\" onmouseout=\"item_list_mouse_out('".$item['id']."');\">\r\n\t\t\t\t\t\t<div class=\"list_item_img\">\r\n\t\t\t\t\t\t\t<img src=\"items/img/".$item['img']."\" alt=\"".$item['name']."\"/></div>\r\n\t\t\t\t\t\t\t<div class=\"list_item_name\">".$item['name']."\r\n\t\t\t\t\t\t</div>\r\n\t\t\t\t\t</div>";
				}
				echo "\r\n";
?>
				</div>
			</fieldset>
			<fieldset id="ability_implants_container">
				<legend>Implants</legend>
				<ul>
					<li>Str buffing implants
					<li>Agi buffing implants
					<li>For each req. type etc...
				</ul>
			</fieldset>
			<fieldset id="treatment_implants_container">
				<legend>Treatment</legend>
				<ul>
					<li>Head/Eye/Hand per req.
				</ul>
			</fieldset>
			<script type="text/javascript">
<?php
				// Create JS items
				foreach ($items as $item) {
					$jsSlots = "[";
					foreach ($item['slots'] as $slot) $jsSlots .= ($slot.",");
					$jsSlots[strlen($jsSlots) - 1] = "]";
					echo "\t\t\t\tg_Items[\"".$item['id']."\"] = new Item(document.getElementById('".$item['id']."'), '".$item['id']."', '".$item['type']."', $jsSlots, '".addslashes($item['name'])."', '".$item['img']."', ".$item['str'].", ".$item['sta'].", ".$item['agi'].", ".$item['sen'].", ".$item['int'].", ".$item['psy'].", ".$item['treat'].");" . PHP_EOL;
				}
?>				createSlots();
				addEventListeners();
			</script>
		</div>
	</body>
</html>