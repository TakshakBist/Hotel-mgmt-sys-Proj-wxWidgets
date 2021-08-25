#pragma once

#include <wx/wx.h>
#include "mainCode.h"

extern hotel* h1;

class mainWindow :public wxFrame
{
public:
	mainWindow();
	~mainWindow();

public:
	wxMenuBar* menubar = nullptr;
	wxMenu* about = nullptr;
	wxMenu* help = nullptr;
	wxButton* btn_check_in = nullptr;
	wxButton* btn_check_out = nullptr;
	wxButton* btn_search = nullptr;
	wxButton* btn_food = nullptr;
	wxButton* btn_exit = nullptr;

	//This is Event for button being clicked i.e. Command Event type
	void OnQuit(wxCommandEvent& evt);
	void OnCheckIn(wxCommandEvent& evt);
	void OnCheckOut(wxCommandEvent& evt);
	void OnSearch(wxCommandEvent& evt);
	void OnFood(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnHelp(wxCommandEvent& evt);



	wxDECLARE_EVENT_TABLE();

};