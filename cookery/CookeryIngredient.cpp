#include "CookeryIngredient.h"

CookeryIngredient::CookeryIngredient()
{
}

CookeryIngredient::CookeryIngredient(const Flavors& flavor_profile) :
	m_flavor_profile(flavor_profile)
{
}

const Flavors&
CookeryIngredient::getFlavorProfile()
{
	return m_flavor_profile;
}
