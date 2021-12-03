#include "SpellCreator.h"

#include <iostream>

SpellCreator::SpellCreator() :
	m_main_window(this),
	m_spellbook_window(this)
{

}

SpellCreatorMainWindow* 
SpellCreator::getMainWindow()
{
	return &m_main_window;
}

SpellbookWindow* 
SpellCreator::getSpellbookWindow()
{
	return &m_spellbook_window;
}

void SpellCreator::onAddSpell(Spell* spell)
{
	m_spellbook.addSpell(*spell);
}

SpellVector SpellCreator::getSpells()
{
	return m_spellbook.getSpells();
}

