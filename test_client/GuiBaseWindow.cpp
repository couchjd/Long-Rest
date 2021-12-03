#include "GuiBaseWindow.h"

GuiBaseWindow::GuiBaseWindow() :
	m_show(true)
{
}

GuiBaseWindow::~GuiBaseWindow()
{
}

void 
GuiBaseWindow::setWindowName(const std::string& window_name)
{
	m_window_name = window_name;
}

bool GuiBaseWindow::begin(std::string name)
{
	return ImGui::Begin(name.c_str(), &m_show);
}

void GuiBaseWindow::end()
{
	ImGui::End();
}