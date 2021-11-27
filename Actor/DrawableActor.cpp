#include "DrawableActor.h"

void 
DrawableActor::draw(
	sf::RenderTarget& target, 
	sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
