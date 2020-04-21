#ifndef SPELL_H
#define SPELL_H

#include <vector>

#include <MaterialComponent.h>
#include <VerbalComponent.h>
#include <SomaticComponent.h>

typedef __declspec(dllexport) std::vector<MaterialComponent> MaterialComponentVector;
typedef __declspec(dllexport) std::vector<VerbalComponent> VerbalComponentVector;
typedef __declspec(dllexport) std::vector<SomaticComponent> SomaticComponentVector;

class __declspec(dllexport) Spell
{
public:
	Spell();
	
	Spell(const std::vector<SpellComponent>& components);

	~Spell();

	void addComponent(SpellComponent& component);

private:
	MaterialComponentVector m_material_components;
	VerbalComponentVector m_verbal_components;
	SomaticComponentVector m_somatic_components;

};

#endif // !SPELL_H

