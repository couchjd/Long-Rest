#pragma once

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
	
	Spell(std::vector<SpellComponent>& components);

	~Spell();

	void addComponent(SpellComponent& component);

	const MaterialComponentVector&
	getMaterialComponents();
	
	const VerbalComponentVector&
	getVerbalComponents();
	
	const SomaticComponentVector&
	getSomaticComponents();

	void
	setSpellName(const std::string& spell_name);

	const std::string&
	getSpellName();

	bool
	operator==(const Spell& other);

private:
#pragma warning(push)
#pragma warning(disable:4251)
	std::string m_spell_name;
	MaterialComponentVector m_material_components;
	VerbalComponentVector m_verbal_components;
	SomaticComponentVector m_somatic_components;
#pragma warning(pop)
};
