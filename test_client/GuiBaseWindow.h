#pragma once

#include "imgui/imgui.h"
#include "imgui-sfml/imgui-SFML.h"

class GuiBaseWindow
{
public:
	GuiBaseWindow();
	~GuiBaseWindow();

	virtual void update() = 0;
	void show();
	void setWindowName(const std::string& window_name);

protected:
	virtual bool begin(std::string name);
	void end();
	bool m_show;
	std::string m_window_name;

private:
	
};
