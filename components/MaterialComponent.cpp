#include "MaterialComponent.h"

MaterialComponent::MaterialComponent()
{
	m_component_type = MATERIAL;
	m_elementality = Elements();
}

MaterialComponent::MaterialComponent(const struct Elements& elementality)
{
	m_component_type = MATERIAL;
	m_elementality = elementality;
}

