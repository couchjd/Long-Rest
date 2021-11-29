#include "Spellbook.h"
#include <iostream>

void Spellbook::addSpell(Spell& new_spell)
{
	bool spell_exists = false;
	for (auto& spell : m_spells)
	{
		if (*spell == new_spell)
		{
			spell_exists = true;
		}
	}

	if (!spell_exists)
	{
		m_spells.push_back(&new_spell);
	}
	else
	{
		std::cout << "Spell already exists!" << std::endl;
	}
}
