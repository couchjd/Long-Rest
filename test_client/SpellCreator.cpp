#include "SpellCreator.h"

#include <iostream>

SpellCreator::SpellCreator()
{
}

Spellbook* SpellCreator::getSpellbook()
{
	return &m_spellbook;
}

void 
SpellCreator::setShowWindows(bool show_windows)
{
	m_show_windows = show_windows;
}

bool SpellCreator::getShowWindows()
{
	return m_show_windows;
}
