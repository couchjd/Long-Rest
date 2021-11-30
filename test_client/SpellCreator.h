#pragma once
#include <MagerySpell.h>
#include <Spellbook.h>
#include "SpellCreatorMainWindow.h"

class SpellCreator
{
public:
	SpellCreator();

	void showWindows();

	void addSpell();

	Spellbook* getSpellbook();

	SpellCreatorMainWindow*
	getMainWindow();

private:
	Spellbook m_spellbook;
	SpellCreatorMainWindow m_main_window;
	bool m_show_main_window;
};
