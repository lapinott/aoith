<!DOCTYPE html>
<html>
	<head>
		<title>AO Implant Twink Helper</title>
		<link rel="shortcut icon" href="img/ao.png" type="image/x-icon">
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<script type="text/javascript" src="js/scripts.js"></script>
		<script type="text/javascript" src="js/window.js"></script>
		<script type="text/javascript" src="js/item.js"></script>
		<script type="text/javascript" src="js/implant.js"></script>
		<script type="text/javascript" src="js/slot.js"></script>
		<script type="text/javascript" src="js/stats.js"></script>
		<script type="text/javascript" src="js/events.js"></script>
	</head>
	<body>
		<div id="main_frame">
			<div id="twinked_stats_container" class="stats_table_container">
				<table id="twinked_stats" class="stats_table">
					<thead>
						<tr><td colspan="2">Twinked stats</td></tr>
					</thead>
					<tbody>
						<tr class="str">
							<td>Strength</td>
							<td id="twinked_str" class="nce" contenteditable="false">100</td>
						</tr>
						<tr class="sta">
							<td>Stamina</td>
							<td id="twinked_sta" class="nce" contenteditable="false">100</td>
						</tr>
						<tr class="agi">
							<td>Agility</td>
							<td id="twinked_agi" class="nce" contenteditable="false">100</td>
						</tr>
						<tr class="sen">
							<td>Sense</td>
							<td id="twinked_sen" class="nce" contenteditable="false">100</td>
						</tr>
						<tr class="int">
							<td>Intelligence</td>
							<td id="twinked_int" class="nce" contenteditable="false">100</td>
						</tr>
						<tr class="psy">
							<td>Psychic</td>
							<td id="twinked_psy" class="nce" contenteditable="false">100</td>
						</tr>
						<tr class="treat">
							<td>Treatment</td>
							<td id="twinked_treat" class="nce" contenteditable="false">300</td>
						</tr>
					</tbody>
				</table>
			</div>
			<div id="base_stats_container" class="stats_table_container">
				<table id="base_stats" class="stats_table">
					<thead>
						<tr><td colspan="2">Base buffed stats</td></tr>
					</thead>
					<tbody>
						<tr class="str">
							<td>Strength</td>
							<td><input id="base_str" class="ce" type="text" value="100" oninput="g_Stats.change_base_stats_cell(this);"/></td>
						</tr>
						<tr class="sta">
							<td>Stamina</td>
							<td><input id="base_sta" class="ce" type="text" value="100" oninput="g_Stats.change_base_stats_cell(this);"/></td>
						</tr>
						<tr class="agi">
							<td>Agility</td>
							<td><input id="base_agi" class="ce" type="text" value="100" oninput="g_Stats.change_base_stats_cell(this);"/></td>
						</tr>
						<tr class="sen">
							<td>Sense</td>
							<td><input id="base_sen" class="ce" type="text" value="100" oninput="g_Stats.change_base_stats_cell(this);"/></td>
						</tr>
						<tr class="int">
							<td>Intelligence</td>
							<td><input id="base_int" class="ce" type="text" value="100" oninput="g_Stats.change_base_stats_cell(this);"/></td>
						</tr>
						<tr class="psy">
							<td>Psychic</td>
							<td><input id="base_psy" class="ce" type="text" value="100" oninput="g_Stats.change_base_stats_cell(this);"/></td>
						</tr>
						<tr class="treat">
							<td>Treatment</td>
							<td><input id="base_treat" class="ce" type="text" value="300" oninput="g_Stats.change_base_stats_cell(this);"/></td>
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
					if ($line[0] !== "#" && trim($line) != "") {
						$values = explode(",", $line);
						$data = Array($i);
						$data['id'] = md5("item".$i);
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
						$data['treat'] = trim($values[10]);
						$items[] = $data;
						++$i;
					}
				}
				
				// Print items
				foreach ($items as $item) {
					echo "\r\n\t\t\t\t\t<div id=\"".$item['id']."\" class=\"list_equippable\" oncontextmenu=\"return equippable_mouse_right_click('".$item['id']."');\" onclick=\"equippabble_mouse_click('".$item['id']."');\" onmouseover=\"equippable_mouse_over('".$item['id']."');\" onmouseout=\"equippable_mouse_out('".$item['id']."');\">\r\n\t\t\t\t\t\t<div class=\"list_equippable_img\">\r\n\t\t\t\t\t\t\t<img src=\"items/img/".$item['img']."\" alt=\"".$item['name']."\"/></div>\r\n\t\t\t\t\t\t\t<div class=\"list_equippable_name\">".$item['name']."\r\n\t\t\t\t\t\t</div>\r\n\t\t\t\t\t</div>";
				}
				echo "\r\n";
?>
				</div>
			</fieldset>
			<fieldset id="ability_implants_container">
				<legend>Ability implants</legend>
				<div><?php
				
				// Get items from file
				$ability_implants = Array();
				$ability_implants['str'] = Array();
				$ability_implants['sta'] = Array();
				$ability_implants['agi'] = Array();
				$ability_implants['sen'] = Array();
				$ability_implants['int'] = Array();
				$ability_implants['psy'] = Array();
				$fhandle = fopen("items/ability_implant_list.csv", "r");
				$i = 0;
				while (($line = fgets($fhandle)) !== false) {
					if ($line[0] !== "#" && trim($line) != "") {
						$values = explode(",", $line);
						$data = Array($i);
						$data['id'] = md5("ability".$i);
						$data['type'] = $values[0];
						$data['slot'] = $values[1];
						$data['potency'] = $values[2];
						$data['name'] = $values[3];
						$data['img'] = $values[4];
						$data['buff'] = $values[5];
						$data['reqs'] = explode("|", trim($values[6]));
						$ability_implants[$data['buff']][] = $data;
						++$i;
					}
				}
				
				// Print items
				foreach ($ability_implants as $buff => $implants) {
					echo "\t\t\t\t\t<fieldset>\r\n";
					if ($buff == 'str') $ability = "Strength";
					else if ($buff == 'sta') $ability = "Stamina";
					else if ($buff == 'agi') $ability = "Agility";
					else if ($buff == 'sen') $ability = "Sense";
					else if ($buff == 'int') $ability = "Intelligence";
					else if ($buff == 'psy') $ability = "Psychic";
					echo "\t\t\t\t\t\t<legend>$ability</legend>\r\n";
					foreach ($implants as $implant) {
						echo "\r\n\t\t\t\t\t\t<div id=\"".$implant['id']."\" class=\"list_equippable\" oncontextmenu=\"return equippable_mouse_right_click('".$implant['id']."');\" onclick=\"equippabble_mouse_click('".$implant['id']."');\" onmouseover=\"equippable_mouse_over('".$implant['id']."');\" onmouseout=\"equippable_mouse_out('".$implant['id']."');\">\r\n\t\t\t\t\t\t<div class=\"list_equippable_img\">\r\n\t\t\t\t\t\t\t<img src=\"items/img/".$implant['img']."\" alt=\"".$implant['name']."\"/></div>\r\n\t\t\t\t\t\t\t<div class=\"list_equippable_name\">".$implant['name']."\r\n\t\t\t\t\t\t</div>\r\n\t\t\t\t\t</div>";
					}
					echo "\t\t\t\t\t</fieldset>\r\n"; 
				}
				echo "\r\n";
?>
				</div>
			</fieldset>
			<fieldset id="treatment_implants_container">
				<legend>Treatment implants</legend>
				<div><?php
				
				// Get items from file
				$treatment_implants = Array();
				$fhandle = fopen("items/treatment_implant_list.csv", "r");
				$i = 0;
				while (($line = fgets($fhandle)) !== false) {
					if ($line[0] !== "#" && trim($line) != "") {
						$values = explode(",", $line);
						$data = Array($i);
						$data['id'] = md5("treatment".$i);
						$data['type'] = $values[0];
						$data['slot'] = $values[1];
						$data['potency'] = $values[2];
						$data['name'] = $values[3];
						$data['img'] = $values[4];
						$data['buff'] = $values[5];
						$data['reqs'] = explode("|", trim($values[6]));
						$treatment_implants[] = $data;
						++$i;
					}
				}
				
				// Print items
				foreach ($treatment_implants as $implant) {
					echo "\r\n\t\t\t\t\t<div id=\"".$implant['id']."\" class=\"list_equippable\" oncontextmenu=\"return equippable_mouse_right_click('".$implant['id']."');\" onclick=\"equippabble_mouse_click('".$implant['id']."');\" onmouseover=\"equippable_mouse_over('".$implant['id']."');\" onmouseout=\"equippable_mouse_out('".$implant['id']."');\">\r\n\t\t\t\t\t\t<div class=\"list_equippable_img\">\r\n\t\t\t\t\t\t\t<img src=\"items/img/".$implant['img']."\" alt=\"".$implant['name']."\"/></div>\r\n\t\t\t\t\t\t\t<div class=\"list_equippable_name\">".$implant['name']."\r\n\t\t\t\t\t\t</div>\r\n\t\t\t\t\t</div>";
				}
				echo "\r\n";
?>
				</div>
			</fieldset>
			<script type="text/javascript">
<?php
				// Create JS items
				foreach ($items as $item) {
					$jsSlots = "[";
					foreach ($item['slots'] as $slot) $jsSlots .= ($slot.",");
					$jsSlots[strlen($jsSlots) - 1] = "]";
					echo "\t\t\t\tg_Equippables[\"".$item['id']."\"] = new Item(document.getElementById('".$item['id']."'), '".$item['id']."', '".$item['type']."', $jsSlots, '".addslashes($item['name'])."', '".$item['img']."', ".$item['str'].", ".$item['sta'].", ".$item['agi'].", ".$item['sen'].", ".$item['int'].", ".$item['psy'].", ".$item['treat'].");".PHP_EOL;
				}
				
				// Create JS treatment implants
				foreach ($treatment_implants as $implant) {
					$jsReqs = "[";
					foreach ($implant['reqs'] as $req) $jsReqs .= ("'".$req."',");
					$jsReqs[strlen($jsReqs) - 1] = "]";
					echo "\t\t\t\tg_Equippables[\"".$implant['id']."\"] = new Implant(document.getElementById('".$implant['id']."'), '".$implant['id']."', '".$implant['type']."', '".$implant['slot']."', '".$implant['potency']."', '".addslashes($implant['name'])."', '".$implant['img']."', '".$implant['buff']."', $jsReqs);" . PHP_EOL;
				}
				
				// Create JS ability implants
				foreach ($ability_implants as $buff => $implants) {
					foreach ($implants as $implant) {
						$jsReqs = "[";
						foreach ($implant['reqs'] as $req) $jsReqs .= ("'".$req."',");
						$jsReqs[strlen($jsReqs) - 1] = "]";
						echo "\t\t\t\tg_Equippables[\"".$implant['id']."\"] = new Implant(document.getElementById('".$implant['id']."'), '".$implant['id']."', '".$implant['type']."', '".$implant['slot']."', '".$implant['potency']."', '".addslashes($implant['name'])."', '".$implant['img']."', '".$implant['buff']."', $jsReqs);" . PHP_EOL;
					}
				}
?>				g_Stats = new Stats();
				createSlots();
				addEventListeners();
			</script>
		</div>
	</body>
</html>