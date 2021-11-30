#include "SpellbookWindow.h"

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>

SpellbookWindow::SpellbookWindow() : 
	m_spellbook(nullptr)
{
}

SpellbookWindow::SpellbookWindow(
	const std::string& window_title,
	Spellbook* spellbook) :
	ImGuiWindow(window_title)
{
	m_spellbook = spellbook;
}

Spellbook* SpellbookWindow::getSpellbook()
{
	return m_spellbook;
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


