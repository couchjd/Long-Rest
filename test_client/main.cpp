#include <MagerySpell.h>

int main() 
{
	Spell* test_spell = new MagerySpell();
	MaterialComponent test_mat_comp;
	SomaticComponent test_som_comp;
	test_spell->addComponent(test_mat_comp);
	test_spell->addComponent(test_som_comp);

	return 0;
}