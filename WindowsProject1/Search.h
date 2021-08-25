#pragma once



#include "mainWindow.h"

class Search : public wxFrame
{
public:
	Search();
	~Search();

public:
	wxMenuBar* menubar = nullptr;
	wxMenu* about = nullptr;
	wxMenu* help = nullptr;
	wxBitmapButton* back = nullptr;
	wxTextCtrl* box = nullptr;
	wxListBox* list_box = nullptr;
	wxBitmapButton* search_btn = nullptr;

public:
	void OnBack(wxCommandEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnHelp(wxCommandEvent& evt);
	void OnSearch(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

