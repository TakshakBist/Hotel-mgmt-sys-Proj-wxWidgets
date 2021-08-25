
#pragma once


#include "wx/wx.h"
#include "mainWindow.h"
#include "Check_in.h"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();

private:
	mainWindow* m_frame1 = nullptr;
	
public:
	virtual bool OnInit();

};
