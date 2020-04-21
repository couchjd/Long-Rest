#include "Spell.h"

Spell::Spell()
{
	m_material_components = {};
	m_verbal_components = {};
	m_somatic_components = {};
}

Spell::Spell(const std::vector<SpellComponent>& components) 
{
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
