<!DOCTYPE html>
<html>
	<head>
		<title>AO Implant Twink Helper</title>
		<link rel="stylesheet" type="text/css" href="styles.css"/>
		<script type="text/javascript" src="js/scripts.js"></script>
		<script type="text/javascript" src="js/window.js"></script>
		<script type="text/javascript" src="js/item.js"></script>
		<script type="text/javascript" src="js/drag.js"></script>
	</head>
	<body>
		<div id="base_stats_container" class="stats_table_container">
			<table id="base_stats" class="stats_table">
				<thead>
					<tr><td colspan="2">Base stats</td></tr>
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
					<tr><td colspan="2">Updated stats</td></tr>
				</thead>
				<tbody>
					<tr class="str">
						<td>Strength</td>
						<td id="updated_str" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
					<tr class="sta">
						<td>Stamina</td>
						<td id="updated_sta" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
					<tr class="agi">
						<td>Agility</td>
						<td id="updated_agi" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
					<tr class="sen">
						<td>Sense</td>
						<td id="updated_sen" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
					<tr class="int">
						<td>Intelligence</td>
						<td id="updated_int" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
					<tr class="psy">
						<td>Psychic</td>
						<td id="updated_psy" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
					<tr class="treat">
						<td>Treatment</td>
						<td id="updated_treat" class="nce" contenteditable="false" onclick="click_updated_stats_cell_ce(this);">0</td>
					</tr>
				</tbody>
			</table>
		</div>
		<div id="weapons_table_container" class="equip_table_container">
			<table id="weapons_table" class="equip_table">
				<tbody>
					<tr>
						<td id="hud_1">Hud-1</td>
						<td id="hud_2">Hud-2</td>
						<td id="hud_3">Hud-3</td>
					</tr>
					<tr>
						<td id="utils_1">Utils-1</td>
						<td id="utils_2">Utils-2</td>
						<td id="utils_3">Utils-3</td>
					</tr>
					<tr>
						<td id="right_hand">Right hand</td>
						<td id="deck">Deck</td>
						<td id="left_hand">Left hand</td>
					</tr>
					<tr>
						<td id="deck_1">Deck-1</td>
						<td id="deck_2">Deck-2</td>
						<td id="deck_3">Deck-3</td>
					</tr>
					<tr>
						<td id="deck_4">Deck-4</td>
						<td id="deck_5">Deck-5</td>
						<td id="deck_6">Deck-6</td>
					</tr>
				</tbody>
			</table>
		</div>
		<div id="armor_table_container" class="equip_table_container">
			<table id="armor_table" class="equip_table">
				<tbody>
					<tr>
						<td id="neck">Neck</td>
						<td id="head">Head</td>
						<td id="back">Back</td>
					</tr>
					<tr>
						<td id="right_shoulder">Right shoulder</td>
						<td id="chest">Chest</td>
						<td id="left_shoulder">Left shoulder</td>
					</tr>
					<tr>
						<td id="right_arm">Right arm</td>
						<td id="hands">Hands</td>
						<td id="left_arm">Left arm</td>
					</tr>
					<tr>
						<td id="right_wrist">Right wrist</td>
						<td id="legs">Legs</td>
						<td id="left_wrist">Left wrist</td>
					</tr>
					<tr>
						<td id="right_finger">Right finger</td>
						<td id="feet">Feet</td>
						<td id="left_finger">Left finger</td>
					</tr>
				</tbody>
			</table>
		</div>
		<div id="implants_table_container" class="equip_table_container">
			<table id="implants_table" class="equip_table">
				<tbody>
					<tr>
						<td id="eyes">Eyes</td>
						<td id="head">Head</td>
						<td id="ears">Ears</td>
					</tr>
					<tr>
						<td id="right_arm">Right arm</td>
						<td id="chest">Chest</td>
						<td id="left_arm">Left arm</td>
					</tr>
					<tr>
						<td id="right_wrist">Right wrist</td>
						<td id="waist">Waist</td>
						<td id="left_wrist">Left wrist</td>
					</tr>
					<tr>
						<td id="right_hand">Right hand</td>
						<td id="legs">Legs</td>
						<td id="left_hand">Left hand</td>
					</tr>
					<tr>
						<td id="empty_right">&nbsp;</td>
						<td id="feet">Feet</td>
						<td id="empty_left">&nbsp;</td>
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
					$items[] = $data;
					++$i;
				}
			}
			
			// Print items
			foreach ($items as $item) {
				echo "<div class=\"list_item\" onclick=\"item_list_mouse_click('".$item['id']."');\" onmouseover=\"item_list_mouse_over('".$item['id']."');\" onmouseout=\"item_list_mouse_out('".$item['id']."');\"><div class=\"list_item_img\"><img src=\"items/img/".$item['img']."\" alt=\"".$item['name']."\"/></div><div class=\"list_item_name\">".$item['name']."</div></div>";
			}
		?></div>
		</fieldset>
		<script type="text/javascript">
<?php
			// Create JS items
			foreach ($items as $item) {
				$jsSlots = "[";
				foreach ($item['slots'] as $slot) $jsSlots .= $slot;
				$jsSlots .= "]";
				echo "\t\t\tg_items[\"".$item['id']."\"] = new Item('".$item['id']."', '".$item['type']."', $jsSlots, '".addslashes($item['name'])."', '".$item['img']."', ".$item['str'].", ".$item['sta'].", ".$item['agi'].", ".$item['sen'].", ".$item['int'].", ".$item['psy'].");" . PHP_EOL;
			}
?>		</script>
	</body>
</html>