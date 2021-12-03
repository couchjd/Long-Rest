#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include "ImGuiUiManager.h"

#include <nlohmann/json.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <Actor.h>
#include <DrawableActor.h>
#include <MagerySpell.h>
#include "SpellCreator.h"

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

	ImGuiUIManager ui_manager(&window);
	SpellCreatorMainWindow main_window;
	ui_manager.addWindow(&main_window);

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
			ui_manager.processEvent(event);

			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		ui_manager.update(deltaClock.restart());
		
		window.clear(bgColor); // fill background with color
		ui_manager.render();
		window.display();
	}
	ui_manager.shutdown();
}
