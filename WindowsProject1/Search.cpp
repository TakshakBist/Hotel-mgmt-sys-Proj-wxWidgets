

#include "Search.h"

#include "mainWindow.h"

#include "mainCode.h"




Search::Search() : wxFrame(nullptr, wxID_ANY, "Apna Sapna Money Money", wxPoint(30, 30), wxSize(800, 600)) 
{


	//menubar creation
	menubar = new wxMenuBar;
	about = new wxMenu;
	about->Append(wxID_ABOUT, wxT(" & About...\tF1"),
		wxT("Show about dialog"));

	help = new wxMenu;
	help->Append(wxID_HELP, wxT(" & Help...\tF1"),
		wxT("Show about dialog"));

	menubar->Append(about, wxT("&About"));
	menubar->Append(help, wxT("&Help"));
	SetMenuBar(menubar);



	//bitmap for back button
	wxBitmap bitmap;
	bitmap.LoadFile("Back_2.png", wxBITMAP_TYPE_PNG);
	back = new wxBitmapButton(this, 3000, bitmap, wxPoint(10, 10), wxSize(100, 67), wxBORDER_NONE);
	back->SetBackgroundColour(*wxCYAN);



	//font size for static text
	wxFont textFontBig(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//this is static text
	wxStaticText* text = new wxStaticText(this, wxID_ANY, "Search", wxPoint(120, 10), wxSize(300, 40), wxALIGN_CENTER_HORIZONTAL);
	text->SetFont(textFontBig);
	text->SetForegroundColour(*wxBLACK);



	//font size for name text
	wxFont textFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//Enter name text
	wxStaticText* nameTxt = new wxStaticText(this, wxID_ANY, "Enter Name:", wxPoint(130, 140), wxSize(60, 40), wxFILTER_EMPTY);
	nameTxt->SetFont(textFont);

	

	//This is input field
	box = new wxTextCtrl(this, 3001, "", wxPoint(240, 150), wxSize(300, 40));
	//box->SetBackgroundColour(*wxLIGHT_GREY);
	box->SetFont(textFont);


	//Bitmap for search Button
	wxBitmap bitmap_1;
	bitmap_1.LoadFile("search_3.png", wxBITMAP_TYPE_PNG);
	search_btn = new wxBitmapButton(this, 3002, bitmap_1, wxPoint(560, 150), wxSize(42, 50), wxBORDER_NONE);
	search_btn->SetBackgroundColour(*wxCYAN);

	//Static Text for output box
	wxStaticText* Output = new wxStaticText(this, wxID_ANY, "Output Box:", wxPoint(130, 200), wxSize(60, 40));
	Output->SetFont(textFont);


	//for a field to show dynamic output
	list_box = new wxListBox(this, 3003, wxPoint(240, 200), wxSize(300, 300));
	//list_box->SetBackgroundColour(*wxLIGHT_GREY);
	list_box->SetFont(textFont);
}



Search::~Search(){}



wxBEGIN_EVENT_TABLE(Search, wxFrame)
EVT_BUTTON(3000, OnBack)
EVT_MENU(wxID_ABOUT, OnAbout)
EVT_MENU(wxID_HELP, OnHelp)
EVT_BUTTON(3002, OnSearch)
wxEND_EVENT_TABLE()



void Search::OnBack(wxCommandEvent& evt) {
	mainWindow* m_frame1 = new mainWindow();
	m_frame1->SetBackgroundColour(*wxWHITE);
	m_frame1->Show();
	Close(TRUE);

}

void Search::OnAbout(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("C++ minor project by noName"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"),
		wxOK | wxICON_INFORMATION, this);
}

void Search::OnHelp(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("We cannot provide any help. Sorry"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("Help"),
		wxOK | wxICON_INFORMATION, this);

}

void Search::OnSearch(wxCommandEvent& evt) {

	wxString str = box->GetValue();

	std::string Name = std::string(str.mb_str());

	if (Name == "") {
		wxMessageBox("Enter a name to search. Havent you ever searched  ","Dont be a basic bitch",
			wxOK|wxICON_INFORMATION);
		return;
	}

	Guest g3;
	list_box->Clear();

	if (h1->search_function(Name,g3)) {
		
		list_box->AppendString(wxString("Name: " + g3.name_0));
		list_box->AppendString(wxString("Address: " + g3.address_0));
		list_box->AppendString(wxString("Phone: " + to_string(g3.phone_0)));
		list_box->AppendString(wxString("Room no.: " + to_string(g3.room_0)));
		list_box->AppendString(wxString("Duration: " + to_string(g3.days_0)));
		box->Clear();
		
			return;
	}

	wxString str3;

	str3.Printf(wxT("Not found"),
		wxVERSION_STRING);

	list_box->AppendString(str3);

	box->Clear();

}
