#pragma once

struct __declspec(dllexport) Flavors
{
	int m_sweet;
	int m_salty;
	int m_spicy;
	int m_sour;
	int m_umami;

	Flavors() :
		m_sweet(0),
		m_salty(0),
		m_spicy(0),
		m_sour(0),
		m_umami(0) {}

	Flavors(
		int sweet,
		int salty,
		int spicy,
		int sour,
		int umami) :
		m_sweet(sweet),
		m_salty(salty),
		m_spicy(spicy),
		m_sour(sour),
		m_umami(umami) {}
};

class __declspec(dllexport) CookeryIngredient
{
public:
	CookeryIngredient();
	CookeryIngredient(const struct Flavors& flavor_profile);

	const Flavors&
	getFlavorProfile();

	bool
	operator==(const CookeryIngredient& other);

private:
	struct Flavors m_flavor_profile;
};