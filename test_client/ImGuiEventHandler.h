#pragma once

#include "EventHandler.h"

class ImGuiEventHandler : public EventHandler
{
	void handleEvent(const sf::Event& event) override;
};