#include "SpellComponent.h"

SpellComponent::SpellComponent() 
{

}

const ComponentTypeEnum& SpellComponent::getComponentType() 
{
	return m_component_type;
}
