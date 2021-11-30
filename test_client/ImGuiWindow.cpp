#include "ImGuiWindow.h"

ImGuiWindow::ImGuiWindow(const std::string& window_title) : 
	m_show_window(false)
{
	strncpy_s(m_window_title, window_title.c_str(), WINDOW_TITLE_SIZE);
}

void ImGuiWindow::showWindow()
{
	if (!ImGui::Begin(m_window_title, &m_show_window)) // begin window
	{
		ImGui::End();
	}
	else
	{
		drawWidgets();
		ImGui::End(); // end window
	}
}

bool ImGuiWindow::getShowWindow()
{
	return m_show_window;
}

void ImGuiWindow::setShowWindow(const bool show_window)
{
	m_show_window = show_window;
}

void
ImGuiWindow::setWindowTitle(const std::string& window_title)
{
	strncpy_s(m_window_title, window_title.c_str(), WINDOW_TITLE_SIZE);
}
