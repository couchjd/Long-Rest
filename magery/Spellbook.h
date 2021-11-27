#pragma once
#include "Spell.h"

typedef __declspec(dllexport) std::vector<Spell*> SpellVector;

class Spellbook
{
public:

private:
	SpellVector m_spells;
};