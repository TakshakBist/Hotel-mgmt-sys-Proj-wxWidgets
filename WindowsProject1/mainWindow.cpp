

#include "mainWindow.h"

#include "Check_in.h"

#include "Check_out.h"

#include "Search.h"

#include "food.h"

hotel* h1;

mainWindow::mainWindow() :wxFrame(nullptr, wxID_ANY, "Apna Sapna Money Money", wxPoint(30, 30), wxSize(800, 600))
{


	enum { WX_ID = 1 };


	//We make menu bar
	menubar = new wxMenuBar;

	about = new wxMenu;
	about->  Append(wxID_ABOUT, wxT(" & About...\tF1"),
		wxT("Show about dialog"));

	help = new wxMenu;
	help->Append(wxID_HELP, wxT(" & Help...\tF1"),
		wxT("Show about dialog"));

	menubar->Append(about, wxT("&About"));
	menubar->Append(help, wxT("&Help"));
	SetMenuBar(menubar);



	//using sizers
	//wxBoxSizer* box = new wxBoxSizer(wxVERTICAL);



	//Setting the font size for static text
	wxFont txtFont(40, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_THIN, false);



	//Adding static text
	wxStaticText* mainTxt = new wxStaticText(this, 1001, "The Grand Zero Hotel", wxPoint(30, 20), wxSize(300, 40), wxALIGN_LEFT);
	mainTxt->SetFont(txtFont);
	mainTxt->SetForegroundColour(*wxBLACK);
	//box->Add(mainTxt);



	/*we make button.it takes parent class which is this->wxFrame, id which is needed for event - handling,
		its co-ordinates and its size as arguments.
	*/


	//this is image handler
	wxPNGHandler* handler = new wxPNGHandler;
	wxImage::AddHandler(handler);
	wxStaticBitmap* image;
	image = new wxStaticBitmap(this, 93, wxBitmap("22.png", wxBITMAP_TYPE_PNG), wxPoint(600, 10), wxSize(172, 158));



	//Setting font size for Buttons
	wxFont font(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	btn_check_in = new wxButton(this, WX_ID + 1, "Check-in", wxPoint(30, 120), wxSize(500, 70));
	btn_check_in->SetFont(font);
	btn_check_in->SetBackgroundColour(*wxBLUE);
	//btn_check_in->SetForegroundColour(*wxWHITE);
	//box->Add(btn_check_in);


	btn_search = new wxButton(this, WX_ID + 2, "Search Guests", wxPoint(30, 200), wxSize(500, 70));
	btn_search->SetFont(font);
	btn_search->SetBackgroundColour(*wxLIGHT_GREY);
	//btn_search->SetForegroundColour(*wxWHITE);
	//box->Add(btn_search);


	btn_food = new wxButton(this, WX_ID + 3, "Order food", wxPoint(30, 280), wxSize(500, 70));
	btn_food->SetFont(font);
	btn_food->SetBackgroundColour(*wxLIGHT_GREY);
	//btn_food->SetForegroundColour(*wxWHITE);
	//box->Add(btn_food);


	btn_check_out = new wxButton(this, WX_ID + 4, "Check-out", wxPoint(30, 360), wxSize(500, 70));
	btn_check_out->SetFont(font);
	btn_check_out->SetBackgroundColour(*wxLIGHT_GREY);
	//btn_check_out->SetForegroundColour(*wxWHITE);
	//box->Add(btn_check_out);


	btn_exit = new wxButton(this, WX_ID + 5, "Exit", wxPoint(30, 440), wxSize(500, 70));
	btn_exit->SetFont(font);
	btn_exit->SetBackgroundColour(*wxRED);
	//btn_exit->SetForegroundColour(*wxWHITE);
	//box->Add(btn_exit);

	//this->SetSizer(box);



}


//Takes name of the class its producing events for and the base class
wxBEGIN_EVENT_TABLE(mainWindow, wxFrame)
EVT_BUTTON(6, OnQuit)
EVT_BUTTON(2, OnCheckIn)
EVT_BUTTON(3, OnSearch)
EVT_BUTTON(5, OnCheckOut)
EVT_BUTTON(4, OnFood)
EVT_MENU(wxID_ABOUT, OnAbout)
EVT_MENU(wxID_HELP, OnHelp)
wxEND_EVENT_TABLE()


mainWindow::~mainWindow() { }

//when you press About button from menubar

void mainWindow::OnAbout(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("C++ minor project by noName"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"),
		wxOK | wxICON_INFORMATION, this);
}

//When you press help from menubar

void mainWindow::OnHelp(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("We cannot provide any help. Sorry"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("Help"),
		wxOK | wxICON_INFORMATION, this);

}

//WHen you press check-in button this window appears

void mainWindow::OnCheckIn(wxCommandEvent& evt) {
	
	Check_in *m_frame2 = new Check_in();
	m_frame2->SetBackgroundColour(*wxCYAN);
	m_frame2->Show();
	Close(TRUE);
}


//When you press check-out button

void mainWindow::OnCheckOut(wxCommandEvent& evt) { 
	Check_out* m_frame3 = new Check_out();
	m_frame3->SetBackgroundColour(*wxCYAN);
	m_frame3->Show();
	Close(TRUE);
}


//When you press Search Button

void mainWindow::OnSearch(wxCommandEvent& evt) {

	Search* m_frame4 = new Search();
	m_frame4->SetBackgroundColour(*wxCYAN);
	m_frame4->Show();
	Close(TRUE);
}


//When you press Food button

void mainWindow::OnFood(wxCommandEvent& evt) { 
	food* m_frame5 = new food();
	m_frame5->SetBackgroundColour(*wxWHITE);
	m_frame5->Show();
	Close(TRUE);
}


//When you press quit button

void mainWindow::OnQuit(wxCommandEvent& evt) {

	//Close the program
	h1->saveData();
	Close(TRUE);

}

