#pragma once
#include <Spellbook.h>

class SpellbookWindow
{
public:
	SpellbookWindow();
	
	SpellbookWindow(Spellbook* spellbook);

	void showWindow();

	bool getShowWindow();

	void setShowWindow(const bool display_window);

private:
	bool m_show_window;
	Spellbook* m_spellbook;

};