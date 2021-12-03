#pragma once
#include "GuiBaseWindow.h"
#include <Spellbook.h>

class SpellCreator;

class SpellbookWindow : public GuiBaseWindow
{
public:
	SpellbookWindow();
	SpellbookWindow(SpellCreator* spell_creator);
	void update() override;

private:
	SpellCreator* m_spell_creator;
};