#pragma once

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

#include "GuiBaseWindow.h"
#include <vector>

class ImGuiUIManager 
{
public:
	ImGuiUIManager(sf::RenderWindow* window);
	~ImGuiUIManager();
	void processEvent(const sf::Event& event);
	void update(sf::Time dt);
	void render();
	void shutdown();
	void addWindow(GuiBaseWindow* new_window);

private:
	void updateWindows();
	void deleteWindows();

	sf::RenderWindow* m_render_window;
	std::vector<GuiBaseWindow*> m_windows;
};