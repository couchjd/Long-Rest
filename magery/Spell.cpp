#include "Spell.h"

Spell::Spell()
{
	m_material_components = {};
	m_verbal_components = {};
	m_somatic_components = {};
}

Spell::Spell(std::vector<SpellComponent>& components) 
{
	Spell();
	for (SpellComponent& component : components)
	{
		addComponent(component);
	}
}

Spell::~Spell() 
{
}

void Spell::addComponent(SpellComponent& component) 
{
	ComponentTypeEnum component_type = component.getComponentType();
	MaterialComponent* mat_component = nullptr;
	VerbalComponent* verbal_component = nullptr;
	SomaticComponent* somatic_component = nullptr;

	switch(component_type) 
	{
		case(MATERIAL):
			mat_component = static_cast<MaterialComponent*>(&component);
			m_material_components.push_back(*mat_component);
			break;
		case(VERBAL):
			verbal_component = static_cast<VerbalComponent*>(&component);
			m_verbal_components.push_back(*verbal_component);
			break;
		case(SOMATIC):
			somatic_component = static_cast<SomaticComponent*>(&component);
			m_somatic_components.push_back(*somatic_component);
			break;
	}
}

const MaterialComponentVector& 
Spell::getMaterialComponents()
{
	return m_material_components;
}

const VerbalComponentVector& 
Spell::getVerbalComponents()
{
	return m_verbal_components;
}

const SomaticComponentVector& 
Spell::getSomaticComponents()
{
	return m_somatic_components;
}

bool Spell::operator==(const Spell& other)
{
	// TODO: Implement this:
	// If all material components are equal, return true.
	// We'll also need to check verbal and somatic components as well
	// eventually. But, for testing, we'll just worry about material components
	// since the other component types haven't been fleshed-out yet.
	bool equal = true;
	for (auto& material_component : m_material_components)
	{
		bool found = false;
		for (auto& other_material_component : other.m_material_components)
		{
			if (material_component == other_material_component)
			{
				found = true;
			}
			break;
		}
		if (false == found)
		{
			equal = false;
			break;
		}
	}
	return equal;
}