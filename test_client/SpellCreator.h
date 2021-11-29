#pragma once
#include <MagerySpell.h>
#include <Spellbook.h>

class SpellCreator
{
public:
	SpellCreator();

	void showWindow();

	bool getShowWindow();

	void setShowWindow(const bool show_window);

private:
	Spellbook m_spellbook;

	bool m_show_window;

	int m_earth;
	int m_air;
	int m_fire;
	int m_water;
	int m_nature;
	int m_arcane;
};
