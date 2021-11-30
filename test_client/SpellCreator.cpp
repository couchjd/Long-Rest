#include "SpellCreator.h"

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>

SpellCreator::SpellCreator() : m_show_main_window(true)
{
	
}

void
SpellCreator::showWindows()
{

}

Spellbook* SpellCreator::getSpellbook()
{
	return &m_spellbook;
}

SpellCreatorMainWindow* SpellCreator::getMainWindow()
{
	return &m_main_window;
}

