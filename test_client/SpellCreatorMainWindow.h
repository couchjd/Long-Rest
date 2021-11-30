#pragma once

#include "ImGuiWindow.h"
#include "SpellbookWindow.h"

#define SPELL_NAME_SIZE 100

class SpellCreatorMainWindow : public ImGuiWindow
{
public:
	SpellCreatorMainWindow();

	SpellCreatorMainWindow(const std::string& window_title, Spellbook* spellbook);

	void showWindow() override;

	void addSpell();

private:
	void drawWidgets() override;

	SpellbookWindow* m_spellbook_window;

	char m_spell_name[SPELL_NAME_SIZE];

	int m_earth;
	int m_air;
	int m_fire;
	int m_water;
	int m_nature;
	int m_arcane;
};