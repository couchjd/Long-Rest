#pragma once

#include "SpellCreatorMainWindow.h"
#include "SpellbookWindow.h"

#include <MagerySpell.h>
#include <Spellbook.h>

#include <vector>

class SpellCreator
{
public:
	SpellCreatorMainWindow* getMainWindow();
	SpellbookWindow* getSpellbookWindow();

private:
	SpellCreatorMainWindow m_main_window;
	SpellbookWindow m_spellbook_window;
};
