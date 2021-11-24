#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

namespace MathLib
{
	class Transform : public sf::Transformable
	{
		sf::Vector3<float> position;
		
	};
}