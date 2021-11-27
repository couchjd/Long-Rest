#include <Actor.h>
#include <DrawableActor.h>
#include <MagerySpell.h>

//Testing branching

int main() 
{
	Spell* test_spell = new MagerySpell();

	Actor* actor = new DrawableActor();

	sf::Vector2f actor_pos = actor->getPosition();

	struct Elements elemantality(100, 99, 98, 97, 96, 95);

	MaterialComponent test_mat_comp(elemantality);
	SomaticComponent test_som_comp;
	test_spell->addComponent(test_mat_comp);
	test_spell->addComponent(test_som_comp);

	return 0;
}