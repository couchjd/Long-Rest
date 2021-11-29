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

const Elements& 
MaterialComponent::getElementatlity()
{
	return m_elementality;
}

bool 
MaterialComponent::operator==(const MaterialComponent& other)
{
	return m_elementality.m_earth == other.m_elementality.m_earth &&
		   m_elementality.m_air == other.m_elementality.m_air &&
		   m_elementality.m_fire == other.m_elementality.m_fire &&
		   m_elementality.m_water == other.m_elementality.m_water &&
		   m_elementality.m_nature == other.m_elementality.m_nature &&
		   m_elementality.m_arcane == other.m_elementality.m_arcane;
}

