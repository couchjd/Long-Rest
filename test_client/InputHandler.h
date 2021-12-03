#pragma once

#include "EventHandler.h"

class InputHandler : public EventHandler
{
	void handleEvent(const sf::Event& event);
};