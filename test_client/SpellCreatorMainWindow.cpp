#include "SpellCreatorMainWindow.h"
#include "SpellbookWindow.h"

SpellCreatorMainWindow::SpellCreatorMainWindow()
{
}

SpellCreatorMainWindow::SpellCreatorMainWindow(const std::string& window_title, Spellbook* spellbook) :
	ImGuiWindow(window_title)
{
	m_spellbook_window = new SpellbookWindow("Spellbook", spellbook);
}

void SpellCreatorMainWindow::showWindow()
{
}

void SpellCreatorMainWindow::addSpell()
{
	Spell* new_spell = new Spell();

	struct Elements elementality(m_earth, m_air, m_fire, m_water, m_nature, m_arcane);

	MaterialComponent test_mat_comp(elementality);
	SomaticComponent test_som_comp; // Default for testing.

	new_spell->addComponent(test_mat_comp);
	new_spell->addComponent(test_som_comp); // Default for testing.
	new_spell->setSpellName(m_spell_name);

	m_spellbook_window->getSpellbook()->addSpell(*new_spell);

	m_earth = m_air = m_fire = m_water = m_nature = m_arcane = 0;
	memset(m_spell_name, 0, SPELL_NAME_SIZE);
}

void SpellCreatorMainWindow::drawWidgets()
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
			m_spellbook_window->setShowWindow(true);
		}
	}
	else
	{
		if (ImGui::Button("Close Spellbook"))
		{
			m_spellbook_window->setShowWindow(false);
		}
	}
}
