#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <nlohmann/json.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <Actor.h>
#include <DrawableActor.h>
#include <MagerySpell.h>
#include "SpellCreator.h"
#include "SpellbookWindow.h"

#include <iostream>

void testActor();
void testImgui();

using json = nlohmann::json;

int main() 
{
	testImgui();
	testActor();

	return 0;
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
	sf::RenderWindow window(sf::VideoMode(1024, 768), "");
	window.setVerticalSyncEnabled(true);
	ImGui::SFML::Init(window);
	SpellCreator spell_creator;

	sf::Color bgColor;

	// let's use char array as buffer, see next part
	// for instructions on using std::string with ImGui
	char windowTitle[255] = "Long Rest";

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				spell_creator.setShowWindow(true);
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		if (spell_creator.getShowWindow())
		{
			spell_creator.showWindows();
		}
		
		window.clear(bgColor); // fill background with color
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
}
