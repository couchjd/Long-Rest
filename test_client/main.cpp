#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <nlohmann/json.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <Actor.h>
#include <DrawableActor.h>
#include <MagerySpell.h>
#include <iostream>

void testMagery();
void testActor();
void testImgui();
void addSpell(Spell* new_spell, std::vector<Spell*>& spells_vector);

using json = nlohmann::json;

int main() 
{
	testImgui();
	testMagery();
	testActor();

	std::getchar();
	return 0;
}

void testMagery()
{
	std::cout << "TESTING MAGIC SYSTEM" << std::endl;
	Spell* test_spell = new MagerySpell();

	struct Elements elementality(100, 99, 98, 97, 96, 95);

	MaterialComponent test_mat_comp(elementality);
	SomaticComponent test_som_comp;

	test_spell->addComponent(test_mat_comp);
	test_spell->addComponent(test_som_comp);

	MaterialComponentVector test_get_mat_comp = test_spell->getMaterialComponents();
	
	for (auto& mat_component : test_get_mat_comp)
	{
		Elements elements = mat_component.getElementatlity();
		std::cout << "Component type: " << mat_component.getComponentType() << ": " <<
			elements.m_air << " " << elements.m_arcane << " " << elements.m_earth << " " <<
			elements.m_fire << " " << elements.m_nature << " " << elements.m_water << std::endl;
	}
}

void testActor()
{
	std::cout << std::endl << "TESTING ACTOR" << std::endl;
	Actor* actor = new DrawableActor();

	sf::Vector2f actor_pos = actor->getPosition();
	std::cout << "Actor pos X: " << actor_pos.x << " Y:" << actor_pos.y << std::endl;
	
	actor->move(sf::Vector2f(32.0f, 32.0f));
	
	actor_pos = actor->getPosition();
	std::cout << "Actor pos X: " << actor_pos.x << " Y:" << actor_pos.y << std::endl;
}

void testImgui()
{
	std::vector<Spell*> spells_vector;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);

	sf::Color bgColor;

	float color[3] = { 0.f, 0.f, 0.f };

	// let's use char array as buffer, see next part
	// for instructions on using std::string with ImGui
	char windowTitle[255] = "Long Rest";

	int earth = 0;
	int air = 0;
	int fire = 0;
	int water = 0;
	int nature = 0;
	int arcane = 0;

	window.setTitle(windowTitle);
	window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
	sf::Clock deltaClock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());


		ImGui::Begin("Spell Creation"); // begin window
									   // Background color edit

		ImGui::InputInt("Earth", &earth);
		ImGui::InputInt("Air", &air);
		ImGui::InputInt("Fire", &fire);
		ImGui::InputInt("Water", &water);
		ImGui::InputInt("Nature", &nature);
		ImGui::InputInt("Arcane", &arcane);

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

			struct Elements elementality(earth, air, fire, water, nature, arcane);

			MaterialComponent test_mat_comp(elementality);
			SomaticComponent test_som_comp;

			new_spell->addComponent(test_mat_comp);
			new_spell->addComponent(test_som_comp);

			addSpell(new_spell, spells_vector);

			earth = air = fire = water = nature = arcane = 0;
		}

		ImGui::End(); // end window

		window.clear(bgColor); // fill background with color
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
}

void addSpell(
	Spell* new_spell, 
	std::vector<Spell*>& spells_vector)
{
	bool spell_exists = false;
	for (auto& spell : spells_vector)
	{
		if (*spell == *new_spell)
		{
			spell_exists = true;
		}
	}

	if (!spell_exists)
	{
		spells_vector.push_back(new_spell);
	}
	else
	{
		std::cout << "Spell already exists!" << std::endl;
	}
}