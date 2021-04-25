#pragma once

#include "wx/wx.h"
#include "Main.hpp"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();

private:
	Main* m_frame = nullptr;

public:
	virtual bool OnInit();
};