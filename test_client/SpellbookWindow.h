#pragma once
#include "ImGuiWindow.h"
#include <Spellbook.h>

class SpellbookWindow : public ImGuiWindow
{
public:
	SpellbookWindow();
	
	SpellbookWindow(
		const std::string& window_title,
		Spellbook* spellbook);

	Spellbook*
	getSpellbook();

private:
	void drawWidgets();

	Spellbook* m_spellbook;
};