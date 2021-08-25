#pragma once


#include "mainWindow.h"

class Check_in: public wxFrame
{
public:

	Check_in();
	~Check_in();

public:
	wxMenuBar* menubar = nullptr;
	wxMenu* about = nullptr;
	wxMenu* help = nullptr;
	wxBitmapButton* back = nullptr;
	wxTextCtrl* name = nullptr;
	wxTextCtrl* phone = nullptr;
	wxTextCtrl* room_no = nullptr;
	wxButton* done = nullptr;
	wxTextCtrl* address = nullptr;
	wxTextCtrl* days = nullptr;
	
public:

	void OnBack(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnHelp(wxCommandEvent& evt);
	void OnOK(wxCommandEvent& evt);
	
	wxDECLARE_EVENT_TABLE();
};

