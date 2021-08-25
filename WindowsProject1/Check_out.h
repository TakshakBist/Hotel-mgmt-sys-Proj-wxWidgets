#pragma once

#pragma once


#include "mainWindow.h"

class Check_out : public wxFrame
{
public:

	Check_out();
	~Check_out();

public:
	wxMenuBar* menubar = nullptr;
	wxMenu* about = nullptr;
	wxMenu* help = nullptr;
	wxBitmapButton* back = nullptr;
	//wxTextCtrl* nameCO = nullptr;
	//wxTextCtrl* phoneCO = nullptr;
	wxTextCtrl* room_noCO = nullptr;
	wxButton* done = nullptr;
	//wxTextCtrl* addressCO = nullptr;
	//wxTextCtrl* daysCO = nullptr;
	wxListBox* Showbill = nullptr;
	wxTextCtrl* Feedback = nullptr;
	wxButton* feedbackButton = nullptr;

public:

	void OnBack(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnHelp(wxCommandEvent& evt);
	void OnOK(wxCommandEvent& evt);
	void OnFeedback(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};
