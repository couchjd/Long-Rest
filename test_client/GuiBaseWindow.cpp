#include "GuiBaseWindow.h"

GuiBaseWindow::GuiBaseWindow() :
	m_show(true)
{
}

GuiBaseWindow::~GuiBaseWindow()
{
}

bool GuiBaseWindow::begin(std::string name)
{
	return ImGui::Begin(name.c_str(), &m_show);
}

void GuiBaseWindow::end()
{
	ImGui::End();
}