#ifndef SPELL_COMPONENT_H
#define SPELL_COMPONENT_H

enum __declspec(dllexport) ComponentTypeEnum
{
	MATERIAL,
	VERBAL,
	SOMATIC
};

class __declspec(dllexport) SpellComponent
{
public:
	SpellComponent();
	
	const ComponentTypeEnum& 
	getComponentType();

protected:
	ComponentTypeEnum m_component_type;
};

#endif // !SPELL_COMPONENT_H

