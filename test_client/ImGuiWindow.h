#pragma once

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include <vector>

#define WINDOW_TITLE_SIZE 100


class ImGuiWindow
{
public:
	ImGuiWindow();

	ImGuiWindow(const std::string& window_title);

	virtual void showWindow();

	virtual bool getShowWindow();

	virtual void setShowWindow(const bool show_window);

	virtual void setWindowTitle(const std::string& window_title);

protected:
	std::vector<ImGuiWindow*> m_child_windows;

private:
	virtual void drawWidgets() = 0;

	char m_window_title[WINDOW_TITLE_SIZE];
	bool m_show_window;

};
