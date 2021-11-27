#pragma once
#include "Actor.h"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>

class __declspec(dllexport) DrawableActor : public Actor, public sf::Drawable
{
public:
	virtual void
	draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};