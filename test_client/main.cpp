#include <MagerySpell.h>
#include <SFML/Graphics.hpp>

int main() 
{
	Spell* test_spell = new MagerySpell();

	sf::CircleShape shape(100.f);

	struct Elements elemantality(100, 99, 98, 97, 96, 95);

	MaterialComponent test_mat_comp(elemantality);
	SomaticComponent test_som_comp;
	test_spell->addComponent(test_mat_comp);
	test_spell->addComponent(test_som_comp);

	return 0;
}