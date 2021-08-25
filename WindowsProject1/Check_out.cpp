#include "Check_out.h"

#include "mainWindow.h"

#include "mainCode.h"




Check_out::Check_out() : wxFrame(nullptr, 1002, "Apna Sapna Money Money ", wxPoint(30, 30), wxSize(800, 600)) {


	//menubar
	menubar = new wxMenuBar;


	about = new wxMenu;
	about->Append(wxID_ABOUT, wxT(" & About..."),
		wxT("Show about dialog"));


	help = new wxMenu;
	help->Append(wxID_HELP, wxT(" & Help..."),
		wxT("Show help dialog"));


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
	back = new wxBitmapButton(this, 2, bitmap, wxPoint(10, 10), wxSize(100, 67), wxBORDER_NONE);
	back->SetBackgroundColour(*wxCYAN);



	//font size for static text
	wxFont textFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//this is static text
	wxStaticText* text = new wxStaticText(this, wxID_ANY, "Check-Out", wxPoint(120, 10), wxSize(300, 40), wxALIGN_CENTER_HORIZONTAL);
	text->SetFont(textFont);
	text->SetForegroundColour(*wxBLACK);




	//font size for other static texts
	wxFont othFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);


	//Static text for name
	//wxStaticText* nameTxt = new wxStaticText(this, wxID_ANY, "Name:", wxPoint(130, 170), wxSize(60, 40));
	//nameTxt->SetFont(othFont);
	//nameTxt->SetForegroundColour(*wxBLACK);


	//input box for name
	//nameCO = new wxTextCtrl(this, 1003, "", wxPoint(240, 150), wxSize(300, 40), wxFILTER_EMPTY);
	//nameCO->SetBackgroundColour(*wxLIGHT_GREY);
	//nameCO->SetFont(othFont);



	//static text for phone no.
	//wxStaticText* phoneTxt = new wxStaticText(this, wxID_ANY, "Phone no:", wxPoint(130, 220), wxSize(60, 40));
	//phoneTxt->SetFont(othFont);



	//input box for phone no.
	//phoneCO = new wxTextCtrl(this, 1004, "", wxPoint(240, 210), wxSize(300, 40), wxFILTER_EMPTY);
	//phoneCO->SetFont(othFont);
	//phoneCO->SetBackgroundColour(*wxLIGHT_GREY);



	//static text for room no.
	wxStaticText* roomTxt = new wxStaticText(this, wxID_ANY, "Room no. :", wxPoint(130, 160), wxSize(60, 40));
	roomTxt->SetFont(othFont);



	//input box for room no.
	room_noCO = new wxTextCtrl(this, 1005, "", wxPoint(240, 150), wxSize(300, 40), wxFILTER_EMPTY);
	room_noCO->SetFont(othFont);
	//room_noCO->SetBackgroundColour(*wxLIGHT_GREY);



	//wxStaticText* addressTxt = new wxStaticText(this, wxID_ANY, "Address :", wxPoint(130, 320), wxSize(60, 40));
	//addressTxt->SetFont(othFont);


	/*addressCO = new wxTextCtrl(this, 1006, "", wxPoint(240, 320), wxSize(300, 40), wxFILTER_EMPTY);
	addressCO->SetFont(othFont);
	addressCO->SetBackgroundColour(*wxLIGHT_GREY);*/



	/*wxStaticText* daysTxt = new wxStaticText(this, wxID_ANY, "Duration:", wxPoint(130, 370), wxSize(60, 40));
	daysTxt->SetFont(othFont);



	daysCO = new wxTextCtrl(this, 1009, "", wxPoint(240, 370), wxSize(300, 40), wxFILTER_EMPTY);
	daysCO->SetFont(othFont);
	daysCO->SetBackgroundColour(*wxLIGHT_GREY);*/



	//font size for button
	wxFont btnFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//Button for Done
	done = new wxButton(this, 1007, wxT("Done"), wxPoint(240, 210), wxSize(300, 40));
	done->SetFont(btnFont);
	done->SetBackgroundColour(*wxGREEN);

	wxStaticText* billstr = new wxStaticText(this, wxID_ANY, "Bill:", wxPoint(180, 280), wxSize(60, 40));
	billstr->SetFont(othFont);


	Showbill = new wxListBox(this, 1008, wxPoint(240, 260), wxSize(300, 60));
	Showbill->SetFont(othFont);
	//Showbill->SetBackgroundColour(*wxLIGHT_GREY);


	wxStaticText* fbstr = new wxStaticText(this, wxID_ANY, "Feedback:", wxPoint(130, 380), wxSize(60, 40));
	fbstr->SetFont(othFont);
	fbstr->SetForegroundColour(*wxBLACK);


	Feedback = new wxTextCtrl(this, 2, "", wxPoint(240, 380), wxSize(300, 100), wxTE_MULTILINE);
	Feedback->SetFont(othFont);

	feedbackButton = new wxButton(this, 1234, wxT("Send Feeedback"), wxPoint(240, 490), wxSize(300, 40));
	feedbackButton->SetFont(btnFont);
	feedbackButton->SetBackgroundColour(*wxGREEN);

}


Check_out::~Check_out() {}




wxBEGIN_EVENT_TABLE(Check_out, wxFrame)
	EVT_BUTTON(2, OnBack)
	EVT_MENU(wxID_ABOUT, OnAbout)
	EVT_MENU(wxID_HELP, OnHelp)
	EVT_BUTTON(1007,OnOK)
	EVT_BUTTON(1234,OnFeedback)
wxEND_EVENT_TABLE()





void Check_out::OnBack(wxCommandEvent& evt) {
	
	mainWindow* m_frame1 = new mainWindow();
	m_frame1->SetBackgroundColour(*wxWHITE);
	m_frame1->Show();
	Close(TRUE);
	

}



void Check_out::OnAbout(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("C++ minor project by noName"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"),
		wxOK | wxICON_INFORMATION, this);
}



void Check_out::OnHelp(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("We cannot provide any help. Sorry"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("Help"),
		wxOK | wxICON_INFORMATION, this);

}





void Check_out::OnOK(wxCommandEvent& evt) {

	/*wxString naame = nameCO->GetValue();
	wxString addresss = addressCO->GetValue();
	wxString phoone = phoneCO->GetValue();*/
	wxString room = room_noCO->GetValue();
	/*wxString day = daysCO->GetValue();*/


	/*std::string name1 = std::string(naame.mb_str());
	std::string address1 = std::string(addresss.mb_str());*/

	/*int phone1 = wxAtoi(phoone);*/
	int room1 = wxAtoi(room);
	/*int day1 = wxAtoi(day);*/
	std::string string = std::string(room.mb_str());
	if (string == "") {
		wxMessageBox("Please Enter Your room no.", "Okay thats enough",
			wxOK | wxICON_INFORMATION);
		return;
	}

	if (room1 >= 50 || room1 < 0) {
		wxMessageBox("Please Enter Valid Room no", "Invalid room no", wxOK | wxICON_INFORMATION, this);
	}
	else {
		Guest g;
		if (h1->check_out_function(g, room1)) {

			int bill = g.days_0 * 2500;
			wxString mystring = wxString::Format(wxT("%i"), bill);

			wxString text;

			text.Printf(wxT("Ypur bill in rupees is:"),
				wxVERSION_STRING);
			Showbill->AppendString(text);
			Showbill->AppendString(mystring);
		}
		

		
	}
	/*nameCO->Clear();
	addressCO->Clear();
	phoneCO->Clear();*/
	room_noCO->Clear();
	/*daysCO->Clear();*/
}

void Check_out::OnFeedback(wxCommandEvent& evt)
{
	
	wxString feedbackStr = Feedback->GetValue();

	
	std::string feedback2 = std::string(feedbackStr.mb_str());

	if (feedback2 == "") {
		wxMessageBox("Please Enter Feedback ", "You are one hell of a naughty person",
			wxOK | wxICON_INFORMATION);
		return;
	}

	h1->FeedbackINFO(feedback2);
	Feedback->Clear();
}
