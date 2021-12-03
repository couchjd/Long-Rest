#include "SpellCreator.h"

#include <iostream>

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

