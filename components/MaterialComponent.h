#ifndef MATERIAL_COMPONENT_H
#define MATERIAL_COMPONENT_H

#include "SpellComponent.h"

struct Elements 
{
	int earth;
	int air;
	int fire;
	int water;
	int nature;
	int arcane;
};

class __declspec(dllexport) MaterialComponent : public SpellComponent
{
public:
	MaterialComponent();
	
};


#endif // !MATERIAL_COMPONENT_H

