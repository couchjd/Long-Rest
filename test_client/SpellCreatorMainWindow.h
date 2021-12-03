#pragma once

#include "GuiBaseWindow.h"

#define SPELL_NAME_SIZE 100

class SpellCreatorMainWindow : public GuiBaseWindow
{
public:
	SpellCreatorMainWindow();
	void update() override;
	void addSpell();

private:
	int counter = 0;

	char m_spell_name[SPELL_NAME_SIZE];

	int m_earth;
	int m_air;
	int m_fire;
	int m_water;
	int m_nature;
	int m_arcane;
};