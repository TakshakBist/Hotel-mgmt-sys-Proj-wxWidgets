

#include "Check_in.h"

#include "mainWindow.h"

#include "mainCode.h"

#include <string>


Check_in::Check_in() : wxFrame(nullptr, 2000, "Apna Sapna Money Money ", wxPoint(30, 30), wxSize(800, 600)) {

	//menubar
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


	//Image handler
	/*wxJPEGHandler* handler = new wxJPEGHandler;
	wxImage::AddHandler(handler);
	wxStaticBitmap* image;
	image = new wxStaticBitmap(this, 93, wxBitmap("hotel_2.jpg", wxBITMAP_TYPE_JPEG), wxPoint(0, 0), wxSize(800, 600));*/



	//bitmap for back button
	wxBitmap bitmap;
	bitmap.LoadFile("Back_2.png", wxBITMAP_TYPE_PNG);
	back = new wxBitmapButton(this, 2001, bitmap, wxPoint(10, 10), wxSize(100, 67), wxBORDER_NONE);
	back->SetBackgroundColour(*wxCYAN);



	//font size for static text
	wxFont textFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//this is static text
	wxStaticText* text = new wxStaticText(this, wxID_ANY, "Check-In", wxPoint(120, 10), wxSize(300, 40), wxALIGN_CENTER_HORIZONTAL);
	text->SetFont(textFont);
	text->SetForegroundColour(*wxBLACK);



	//font size for other static texts
	wxFont othFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	wxStaticText* nameTxt = new wxStaticText(this, wxID_ANY, "Name:", wxPoint(130, 170), wxSize(60, 40));
	nameTxt->SetFont(othFont);
	//nameTxt->SetForegroundColour(*wxBLACK);
	


	//input box for name
	name = new wxTextCtrl(this, 2002, "", wxPoint(240, 150), wxSize(300, 40), wxFILTER_EMPTY);
	//name->SetBackgroundColour(*wxLIGHT_GREY);
	name->SetFont(othFont);



	//static text for phone no.
	wxStaticText* phoneTxt = new wxStaticText(this, wxID_ANY, "Phone no:", wxPoint(130, 220), wxSize(60, 40));
	phoneTxt->SetFont(othFont);
	


	//input box for phone no.
	phone = new wxTextCtrl(this, 2003, "", wxPoint(240, 210), wxSize(300, 40), wxFILTER_EMPTY);
	phone->SetFont(othFont);
	//phone->SetBackgroundColour(*wxLIGHT_GREY);
	


	//static text for room no.
	wxStaticText* roomTxt = new wxStaticText(this, wxID_ANY, "Room no. :", wxPoint(130, 270), wxSize(60, 40));
	roomTxt->SetFont(othFont);



	//input box for room no.
	room_no = new wxTextCtrl(this, 2004, "", wxPoint(240, 270), wxSize(300, 40), wxFILTER_EMPTY);
	room_no->SetFont(othFont);
	//room_no->SetBackgroundColour(*wxLIGHT_GREY);



	wxStaticText* addressTxt = new wxStaticText(this, wxID_ANY, "Address :", wxPoint(130, 320),wxSize(60,40));
	addressTxt->SetFont(othFont);



	address = new wxTextCtrl(this, 2005, "", wxPoint(240, 320), wxSize(300, 40),wxFILTER_EMPTY);
	address->SetFont(othFont);
	//address->SetBackgroundColour(*wxLIGHT_GREY);



	wxStaticText* stay_duration=new wxStaticText(this, wxID_ANY, "Duration:", wxPoint(130, 370), wxSize(60, 40));
	stay_duration->SetFont(othFont);



	days = new wxTextCtrl(this, 2006, "", wxPoint(240, 370), wxSize(300, 40), wxFILTER_EMPTY);
	days->SetFont(othFont);
	//days->SetBackgroundColour(*wxLIGHT_GREY);



	//font size for button
	wxFont btnFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//Button for Done
	done = new wxButton(this, 2007, wxT("Done"), wxPoint(240, 420), wxSize(300, 40));
	done->SetFont(btnFont);
	done->SetBackgroundColour(*wxGREEN);




	
}


Check_in::~Check_in() {}



wxBEGIN_EVENT_TABLE(Check_in, wxFrame)
	EVT_BUTTON(2001,OnBack)
	EVT_BUTTON(2007,OnOK)
	EVT_MENU(wxID_ABOUT, OnAbout)
	EVT_MENU(wxID_HELP, OnHelp)
wxEND_EVENT_TABLE()




void Check_in::OnBack(wxCommandEvent& evt) {

	mainWindow* m_frame1 = new mainWindow();
	m_frame1->SetBackgroundColour(*wxWHITE);
	m_frame1->Show();
	Close(TRUE);
	

}

void Check_in::OnAbout(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("C++ minor project by noName"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"),
		wxOK | wxICON_INFORMATION, this);
}

void Check_in::OnHelp(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("We cannot provide any help. Sorry"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("Help"),
		wxOK | wxICON_INFORMATION, this);

}



void Check_in::OnOK(wxCommandEvent& evt) {

	wxString naame =  name->GetValue();
	wxString addresss = address->GetValue();
	wxString phoone = phone->GetValue();
	wxString room = room_no->GetValue();
	wxString day = days->GetValue();


	std::string name1 = std::string(naame.mb_str());
	std::string phone2 = std::string(phoone.mb_str());
	std::string room2 = std::string(room.mb_str());
	std::string day2 = std::string(day.mb_str());
	std::string address1 = std::string(addresss.mb_str());

	if (name1 == "" || phone2 == "" || room2 == "" || day2 == "" || address1 == "") {
		wxMessageBox("Please enter everything", "Why are you doing this",
			wxOK | wxICON_INFORMATION);
		name->Clear();
		address->Clear();
		phone->Clear();
		room_no->Clear();
		days->Clear();
		return;
	}
	int phone1 = wxAtoi(phoone);
	int room1 = wxAtoi(room);
	int day1 = wxAtoi(day);

	if (room1 > 50 || room1 < 1) {
		wxMessageBox("Please Enter Valid Room no", "Invalid room no", wxOK | wxICON_INFORMATION, this);
	}
	else {
		
		h1->check_in_function(name1,address1,phone1,room1,day1);

	}

	name->Clear();
	address->Clear();
	phone->Clear();
	room_no->Clear();
	days->Clear();

}