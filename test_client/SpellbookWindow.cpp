#include "SpellbookWindow.h"

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>

const char* SPELLBOOK_WINDOW = "Spellbook";

SpellbookWindow::SpellbookWindow() : 
	m_spellbook(nullptr),
	m_show_window(false)
{
}

SpellbookWindow::SpellbookWindow(Spellbook* spellbook) :
	m_show_window(false)
{
	m_spellbook = spellbook;
}

void 
SpellbookWindow::showWindow()
{
	if (m_spellbook)
	{
		if (!ImGui::Begin(SPELLBOOK_WINDOW, &m_show_window)) // begin window
		{
			ImGui::End();
		}
		else
		{
			drawWidgets();
			ImGui::End(); // end window
		}
	}
}

bool 
SpellbookWindow::getShowWindow()
{
	return m_show_window;
}

void 
SpellbookWindow::setShowWindow(const bool display_window)
{
	m_show_window = display_window;
}

void 
SpellbookWindow::drawWidgets()
{
	int count = 1;
	for (auto& spell : m_spellbook->getSpells())
	{
		ImGui::Button(spell->getSpellName().c_str());
		++count;
	}
}


