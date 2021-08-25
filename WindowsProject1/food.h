#pragma once


#include "mainWindow.h"

class food : public wxFrame
{
public:

	food();
	~food();

public:
	wxMenuBar* menubar = nullptr;
	wxMenu* about = nullptr;
	wxMenu* help = nullptr;
	wxBitmapButton* back = nullptr;
	wxButton* MasuBhat = nullptr;
	wxButton* Momo = nullptr;
	wxButton* Chiso = nullptr;
	wxButton* FriedRice = nullptr;
	wxListBox* Output = nullptr;
	wxTextCtrl* forMasuBhat = nullptr;
	wxTextCtrl* forMomo = nullptr;
	wxTextCtrl* forFriedRice = nullptr;
	wxTextCtrl* forChiso = nullptr;
	wxButton* done = nullptr;

public:
	void OnBack(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnHelp(wxCommandEvent& evt);
	void OnOK(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();

};

