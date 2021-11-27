#pragma once
#include "Actor.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class __declspec(dllexport) DrawableActor : public Actor, public sf::Drawable
{
public:
	virtual void
	draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};