#include <Actor.h>
#include <DrawableActor.h>
#include <MagerySpell.h>
#include <iostream>

void testMagery();
void testActor();

int main() 
{
	testMagery();
	testActor();

	std::getchar();
	return 0;
}

void testMagery()
{
	std::cout << "TESTING MAGIC SYSTEM" << std::endl;
	Spell* test_spell = new MagerySpell();

	struct Elements elemantality(100, 99, 98, 97, 96, 95);

	MaterialComponent test_mat_comp(elemantality);
	SomaticComponent test_som_comp;

	test_spell->addComponent(test_mat_comp);
	test_spell->addComponent(test_som_comp);

	MaterialComponentVector test_get_mat_comp = test_spell->getMaterialComponents();
	
	for (auto& mat_component : test_get_mat_comp)
	{
		Elements elements = mat_component.getElementatlity();
		std::cout << "Component type: " << mat_component.getComponentType() << ": " <<
			elements.m_air << " " << elements.m_arcane << " " << elements.m_earth << " " <<
			elements.m_fire << " " << elements.m_nature << " " << elements.m_water << std::endl;
	}
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