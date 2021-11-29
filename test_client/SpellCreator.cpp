#include "SpellCreator.h"

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <iostream>

SpellCreator::SpellCreator() : m_show_window(true)
{
}

void
SpellCreator::showWindow()
{
	if (!ImGui::Begin("Spell Creation", &m_show_window)) // begin window
	{
		ImGui::End();
	}
	else
	{
		ImGui::InputInt("Earth", &m_earth);
			ImGui::InputInt("Air", &m_air);
			ImGui::InputInt("Fire", &m_fire);
			ImGui::InputInt("Water", &m_water);
			ImGui::InputInt("Nature", &m_nature);
			ImGui::InputInt("Arcane", &m_arcane);

		//if (ImGui::ColorEdit3("Background color", color)) {
		//	// this code gets called if color value changes, so
		//	// the background color is upgraded automatically!
		//	bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
		//	bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
		//	bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
		//}

		//// Window title text edit
		//ImGui::InputText("Window title", windowTitle, 255);

		//if (ImGui::Button("Update window title")) {
		//	// this code gets if user clicks on the button
		//	// yes, you could have written if(ImGui::InputText(...))
		//	// but I do this to show how buttons work :)
		//	window.setTitle(windowTitle);
		//}

		if (ImGui::Button("Add Spell"))
		{
			Spell* new_spell = new Spell();

			struct Elements elementality(m_earth, m_air, m_fire, m_water, m_nature, m_arcane);

			MaterialComponent test_mat_comp(elementality);
			SomaticComponent test_som_comp;

			new_spell->addComponent(test_mat_comp);
			new_spell->addComponent(test_som_comp);

			m_spellbook.addSpell(*new_spell);

			m_earth = m_air = m_fire = m_water = m_nature = m_arcane = 0;
		}

		ImGui::End(); // end window
	}
}

bool 
SpellCreator::getShowWindow()
{
	return m_show_window;
}

void 
SpellCreator::setShowWindow(const bool show_window)
{
	m_show_window = show_window;
}
