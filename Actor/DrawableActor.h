#pragma once
#include "Actor.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class DrawableActor : public Actor, public sf::Drawable
{
	virtual void 
	draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};