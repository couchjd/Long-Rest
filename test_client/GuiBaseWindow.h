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

protected:
	virtual bool begin(std::string name);
	void end();
	bool m_show;

private:
	
};
