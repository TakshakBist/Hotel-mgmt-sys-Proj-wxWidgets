#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	h1 = new hotel;
	h1->loadData();
	m_frame1 = new mainWindow();
	m_frame1->SetBackgroundColour(*wxWHITE);
	m_frame1->Show();
	return true;

}