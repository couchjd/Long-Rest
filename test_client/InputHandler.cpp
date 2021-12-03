#include "InputHandler.h"
#include <iostream>


void 
InputHandler::handleEvent(const sf::Event& event)
{
	if (sf::Event::KeyPressed == event.type)
	{
		switch (event.key.code)
		{
			case(sf::Keyboard::Escape):
			{
				std::cout << "Escape key pressed" << std::endl;
				break;
			}
		}
	}
}
