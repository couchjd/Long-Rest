#pragma once
#include "Spell.h"

typedef __declspec(dllexport) std::vector<Spell*> SpellVector;

class __declspec(dllexport) Spellbook
{
public:
	void addSpell(Spell& spell);
	
	const SpellVector&
	getSpells();

private:
	SpellVector m_spells;
};