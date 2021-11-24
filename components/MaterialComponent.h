#ifndef MATERIAL_COMPONENT_H
#define MATERIAL_COMPONENT_H

#include "SpellComponent.h"

struct __declspec(dllexport) Elements
{
	int m_earth;
	int m_air;
	int m_fire;
	int m_water;
	int m_nature;
	int m_arcane;

	Elements() :
		m_earth(0),
		m_air(0),
		m_fire(0),
		m_water(0),
		m_nature(0),
		m_arcane(0)
	{}

	Elements(
		int earth,
		int air,
		int fire,
		int water,
		int nature,
		int arcane) :
		m_earth(earth),
		m_air(air),
		m_fire(fire),
		m_water(water),
		m_nature(nature),
		m_arcane(arcane)
	{}
};

class __declspec(dllexport) MaterialComponent : public SpellComponent
{
public:
	MaterialComponent();
	MaterialComponent(const struct Elements& elementality);
	
private:
	struct Elements m_elementality;
};


#endif // !MATERIAL_COMPONENT_H

