#pragma once

#include "SpellCreatorMainWindow.h"
#include "SpellbookWindow.h"

#include <MagerySpell.h>
#include <Spellbook.h>

#include <vector>

class SpellCreator
{
public:
	SpellCreator();
	SpellCreatorMainWindow* getMainWindow();
	SpellbookWindow* getSpellbookWindow();
	void onAddSpell(Spell* spell);
	SpellVector getSpells();

private:
	SpellCreatorMainWindow m_main_window;
	SpellbookWindow m_spellbook_window;
	Spellbook m_spellbook;
};
