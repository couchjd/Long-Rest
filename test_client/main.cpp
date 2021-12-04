#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include "ImGuiUiManager.h"
#include "InputHandler.h"
#include "EventHandlerManager.h"
#include "FileOpenWindow.h"

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
	
	EventHandlerManager event_handler_manager;
	SpellCreator spell_creator;

	ImGuiUIManager ui_manager(&window);
	event_handler_manager.addHandler(ui_manager.getEventHandler());

	InputHandler input_handler;
	event_handler_manager.addHandler(&input_handler);

	ui_manager.addWindow(spell_creator.getMainWindow());
	ui_manager.addWindow(spell_creator.getSpellbookWindow());

	FileOpenWindow file_open_window;
	ui_manager.addWindow(&file_open_window);

	sf::Color bgColor;

	char windowTitle[255] = "Long Rest";

	window.setTitle(windowTitle);
	window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
	sf::Clock deltaClock;
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			event_handler_manager.callHandlers(event);

			if (event.type == sf::Event::Closed) 
			{
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
