#include "SpellbookWindow.h"

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>

const char* SPELLBOOK_WINDOW = "Spellbook";

SpellbookWindow::SpellbookWindow() : 
	m_spellbook(nullptr),
	m_show_window(true)
{
}

SpellbookWindow::SpellbookWindow(Spellbook* spellbook) :
	m_show_window(true)
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
			int count = 1;
			for (auto& spell : m_spellbook->getSpells())
			{
				std::string spell_name = "Spell " + std::to_string(count);

				ImGui::Button(spell_name.c_str());
				++count;
			}

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
