#include "SpellbookWindow.h"
#include "SpellCreator.h"

#include <iostream>

SpellbookWindow::SpellbookWindow()
{
	m_window_name = "Spellbook";
}

SpellbookWindow::SpellbookWindow(SpellCreator* spell_creator) :
	m_spell_creator(spell_creator)
{
	m_window_name = "Spellbook";
}

void SpellbookWindow::update()
{
	if (m_show)
	{
		if (begin(m_window_name))
		{
			SpellVector spells = m_spell_creator->getSpells();
			for (Spell* spell : spells)
			{
				ImGui::Button(spell->getSpellName().c_str());
			}
		}
		end();
	}
}


