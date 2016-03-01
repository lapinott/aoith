#include "Includes.h"
#include "Globals.h"
#include "Equippable.struct.h"

int main() {
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [agi/sense]", W_LHAND, 0, 0, 10, 10, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [agi/sense]", W_RHAND, 0, 0, 10, 10, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [str/sta]", W_LHAND, 10, 10, 0, 0, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [str/sta]", W_RHAND, 10, 10, 0, 0, 0, 0, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [int/psy]", W_LHAND, 0, 0, 0, 0, 10, 10, 0));
	g_equippables->push_back(new Equippable("Explosif's Polychromatic Pillows [int/psy]", W_RHAND, 0, 0, 0, 0, 10, 10, 0));
	g_equippables->push_back(new Equippable("Shades of Lucubration", A_HEAD, 0, 0, 0, 0, 30, 30, 0));

	// ++ trickle update on abilites update
	// stategies
	// console UI loop commands
	system("PAUSE");
}