#include "SpellbookWindow.h"

#include <iostream>

SpellbookWindow::SpellbookWindow()
{
	m_window_name = "Spellbook";
}

void SpellbookWindow::update()
{
	if (m_show)
	{
		if (begin(m_window_name))
		{
			ImGui::Button("TEST");
		}
		end();
	}
}


