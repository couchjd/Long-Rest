#pragma once

#include "SpellCreatorMainWindow.h"

#include <MagerySpell.h>
#include <Spellbook.h>

class SpellCreatorMainWindow;

class SpellCreator
{
public:
	SpellCreator();

	void showWindows();

	Spellbook* getSpellbook();

	void setShowWindows(bool show_windows);
	bool getShowWindows();

private:
	Spellbook m_spellbook;
	bool m_show_windows;
	SpellCreatorMainWindow* m_main_window;
};
