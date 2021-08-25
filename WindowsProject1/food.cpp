

#include "food.h"

#include "mainWindow.h"

#include "mainCode.h"

food::food() : wxFrame(nullptr, 5000, "Apna Sapna Money Money ", wxPoint(30, 30), wxSize(800, 600)) 
{
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

	// bitmap for back button
		wxBitmap bitmap;
	bitmap.LoadFile("Back_2.png", wxBITMAP_TYPE_PNG);
	back = new wxBitmapButton(this, 5001, bitmap, wxPoint(10, 10), wxSize(100, 67), wxBORDER_NONE);
	back->SetBackgroundColour(*wxWHITE);


	//font size for static text
	wxFont textFontBig(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);



	//this is static text
	wxStaticText* text = new wxStaticText(this, wxID_ANY, "Order Food", wxPoint(120, 10), wxSize(300, 40), wxALIGN_CENTER_HORIZONTAL);
	text->SetFont(textFontBig);
	text->SetForegroundColour(*wxBLACK);


	//font for button text
	wxFont btnFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
		wxFONTWEIGHT_NORMAL, false);


	//Button for Masu Bhat
	MasuBhat = new wxButton(this, 5002, wxT("MASU BHAT   (Rs. 400)"), wxPoint(130, 120), wxSize(300, 40));
	MasuBhat->SetBackgroundColour(*wxCYAN);
	MasuBhat->SetFont(btnFont);

	forMasuBhat = new wxTextCtrl(this, 5009, "", wxPoint(440, 120), wxSize(50, 40));
	forMasuBhat->SetBackgroundColour(*wxCYAN);
	forMasuBhat->SetFont(btnFont);

	


	//Button for Momo
	Momo = new wxButton(this, 5003, wxT("MOMO   (Rs. 100)"), wxPoint(130, 170), wxSize(300, 40));
	Momo->SetBackgroundColour(*wxCYAN);
	Momo->SetFont(btnFont);

	forMomo = new wxTextCtrl(this, 5009, "", wxPoint(440, 170), wxSize(50, 40));
	forMomo->SetBackgroundColour(*wxCYAN);
	forMomo->SetFont(btnFont);

	
	//Button for Chiso
	Chiso = new wxButton(this, 5004, wxT("CHISO   (Rs.50)"), wxPoint(130, 220), wxSize(300, 40));
	Chiso->SetBackgroundColour(*wxCYAN);
	Chiso->SetFont(btnFont);


	//List Box for Chiso
	forChiso = new wxTextCtrl(this, 5009,"", wxPoint(440, 220), wxSize(50, 40));
	forChiso->SetBackgroundColour(*wxCYAN);
	forChiso->SetFont(btnFont);


	//Button for Fried Rice
	FriedRice = new wxButton(this, 5005, "FRIED RICE   (Rs.100)", wxPoint(130, 270), wxSize(300, 40));
	FriedRice->SetBackgroundColour(*wxCYAN);
	FriedRice->SetFont(btnFont);


	//List Box for Fried Rice
	forFriedRice = new wxTextCtrl(this, 5010,"", wxPoint(440, 270), wxSize(50, 40));
	forFriedRice->SetBackgroundColour(*wxCYAN);
	forFriedRice->SetFont(btnFont);

	done = new wxButton(this, 5011, "Done", wxPoint(130, 320), wxSize(300, 40));
	done->SetBackgroundColour(*wxGREEN);
	done->SetFont(btnFont);


	//Output shows what you have ordered
	Output = new wxListBox(this, 5006, wxPoint(130, 370), wxSize(300, 160));
	Output->SetBackgroundColour(*wxCYAN);
	Output->SetFont(btnFont);

	



}


food::~food(){}

wxBEGIN_EVENT_TABLE(food, wxFrame)
	EVT_BUTTON(5001,OnBack)
	EVT_MENU(wxID_ABOUT, OnAbout)
	EVT_MENU(wxID_HELP, OnHelp)
	EVT_BUTTON(5011,OnOK)
wxEND_EVENT_TABLE()



void food::OnBack(wxCommandEvent& evt) {
	mainWindow* m_frame1 = new mainWindow();
	m_frame1->SetBackgroundColour(*wxWHITE);
	m_frame1->Show();
	Close(TRUE);

}
void food::OnAbout(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("C++ minor project by noName"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("About"),
		wxOK | wxICON_INFORMATION, this);
}

void food::OnHelp(wxCommandEvent& evt) {

	wxString msg;
	msg.Printf(wxT("We cannot provide any help. Sorry"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("Help"),
		wxOK | wxICON_INFORMATION, this);

}

void food::OnOK(wxCommandEvent& evt) {

	Output->Clear();

	wxString MomoStr = forMomo->GetValue() ;
	int momoNum;
	momoNum = wxAtoi(MomoStr);

	wxString MasuBhatStr = forMasuBhat->GetValue();
	int MasuBhatNum;
	MasuBhatNum = wxAtoi(MasuBhatStr);

	wxString ChisoStr = forChiso->GetValue();
	int chisoNum;
	chisoNum = wxAtoi(ChisoStr);

	wxString friedRiceStr = forFriedRice->GetValue();
	int friedRiceNum;
	friedRiceNum = wxAtoi(friedRiceStr);

	if (momoNum < 1 && MasuBhatNum < 1 && chisoNum < 1 && friedRiceNum < 1) {
		wxMessageBox("Enter a number of item you want to order. You know its not a witchCraft","Oye vai hero naban hai",
			wxOK | wxICON_INFORMATION);
		return;
	}

	if (momoNum < 1) {
		momoNum = 0;
	}

	if (MasuBhatNum < 1) {
		MasuBhatNum = 0;
	}

	if (chisoNum < 1) {
		chisoNum = 0;
	}

	if (friedRiceNum < 1) {
		friedRiceNum = 0;
	}


	h1->food_function(MasuBhatNum, momoNum, chisoNum, friedRiceNum);

	int tot = h1->food_function(MasuBhatNum, momoNum, chisoNum, friedRiceNum);

	wxString total = wxString::Format(wxT("%i"), tot);

	wxString text;
	text.Printf(wxT("Your total is:"),
		wxVERSION_STRING);

	Output->AppendString(text);

	Output->AppendString(total);

	forMasuBhat->Clear();
	forMomo->Clear();
	forChiso->Clear();
	forFriedRice->Clear();

}