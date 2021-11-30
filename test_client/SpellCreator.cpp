#include "SpellCreator.h"

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>

const char* MAIN_WINDOW = "Spell Creation";

SpellCreator::SpellCreator() : m_show_main_window(true)
{
	m_spellbook_window = new SpellbookWindow(&m_spellbook);
}

void
SpellCreator::showWindows()
{
	if (!ImGui::Begin(MAIN_WINDOW, &m_show_main_window)) // begin window
	{
		ImGui::End();
	}
	else
	{
		drawWidgets();
		ImGui::End(); // end window
	}

	if (m_spellbook_window->getShowWindow())
	{
		m_spellbook_window->showWindow();
	}
}

bool 
SpellCreator::getShowWindow()
{

	return m_show_main_window;
}

void 
SpellCreator::setShowWindow(const bool show_window)
{
	m_show_main_window = show_window;
}

void 
SpellCreator::addSpell()
{
	Spell* new_spell = new Spell();

	struct Elements elementality(m_earth, m_air, m_fire, m_water, m_nature, m_arcane);

	MaterialComponent test_mat_comp(elementality);
	SomaticComponent test_som_comp; // Default for testing.
	
	new_spell->addComponent(test_mat_comp);
	new_spell->addComponent(test_som_comp); // Default for testing.
	new_spell->setSpellName(m_spell_name);

	m_spellbook.addSpell(*new_spell);

	m_earth = m_air = m_fire = m_water = m_nature = m_arcane = 0;
	memset(m_spell_name, 0, SPELL_NAME_SIZE);
}

void SpellCreator::openSpellbook()
{
	m_spellbook_window->setShowWindow(true);
}

void SpellCreator::closeSpellbook()
{
	m_spellbook_window->setShowWindow(false);
}

Spellbook* SpellCreator::getSpellbook()
{
	return &m_spellbook;
}

void 
SpellCreator::drawWidgets()
{
	ImGui::InputText("Spell Name", m_spell_name, SPELL_NAME_SIZE);
	ImGui::InputInt("Earth", &m_earth);
	ImGui::InputInt("Air", &m_air);
	ImGui::InputInt("Fire", &m_fire);
	ImGui::InputInt("Water", &m_water);
	ImGui::InputInt("Nature", &m_nature);
	ImGui::InputInt("Arcane", &m_arcane);

	if (ImGui::Button("Add Spell"))
	{
		if (strcmp(m_spell_name, "") != 0)
		{
			addSpell();
		}
	}

	if (!m_spellbook_window->getShowWindow())
	{
		if (ImGui::Button("Open Spellbook"))
		{
			openSpellbook();
		}
	}
	else
	{
		if (ImGui::Button("Close Spellbook"))
		{
			closeSpellbook();
		}
	}
}
