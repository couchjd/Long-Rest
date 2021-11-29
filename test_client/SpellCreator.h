#pragma once
#include <MagerySpell.h>
#include <Spellbook.h>
#include "SpellbookWindow.h"

class SpellCreator
{
public:
	SpellCreator();

	void showWindows();

	bool getShowWindow();

	void setShowWindow(const bool show_window);

	void addSpell();

	void openSpellbook();

	void closeSpellbook();

	Spellbook* getSpellbook();

private:
	Spellbook m_spellbook;
	SpellbookWindow* m_spellbook_window;

	bool m_show_main_window;
	bool m_show_spellbook_window;

	int m_earth;
	int m_air;
	int m_fire;
	int m_water;
	int m_nature;
	int m_arcane;
};
