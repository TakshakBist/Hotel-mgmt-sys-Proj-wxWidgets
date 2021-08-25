#pragma once

#include "wx/wx.h"

#include <iostream>

#include "Check_out.h"

#include "food.h"

#include <cstdlib>

#include <string>

#include <cstring>

#include <fstream>

#include <vector>

#include <algorithm>

using namespace std;


class Guest{
public:
	string name_0;
	string address_0;
	int room_0;
	int phone_0;
	int days_0;
	
	
};

class Room {
public: 
	int price = 500;
	int rooms[50] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	
	
};

class Food {
public:
	int mbp;
	int mmp;
	int chp;
	int frp;

	Food():mbp(400),mmp(100),chp(50),frp(100){}
};

class hotel :public Room,public Food {


public:
	
	vector <Guest> guest;

public:

	void check_in_function(string name_0, string address_0, int phone_0, int room_0, int days_0);
	int  check_out_function(Guest &g1, int room_0);
	int search_function( string name, Guest &g);
	int food_function(int mb,int mm,int ch,int fr);
	void loadData();
	void saveData();
	void FeedbackINFO(string feedback);
};

inline void hotel::loadData() {
	guest.clear();
	ifstream f;
	f.open("Guest.txt", ios::binary);
	if (f.is_open()) {
		while (!f.eof()) {
			Guest g;
			if (!(f >> g.name_0)) 
				break;
			
			if (!(f >> g.address_0))
				break;
			
			if (!(f >> g.room_0))
				break;
			
			if (!(f >> g.phone_0))
				break;
			
			if (!(f >> g.days_0))
				break;
			
			guest.push_back(g);
		}
		f.close();
	}
	memset(rooms, 0, sizeof(rooms));
	for (auto &g : guest) {
		rooms[g.room_0] = 1;
	}


}

inline void hotel::saveData() {

	ofstream f;
	f.open("Guest.txt", ios::binary);
	for (auto &g : guest) {
		f << g.name_0 << " ";
		f << g.address_0 <<" ";
		f << g.room_0 << " ";
		f << g.phone_0 << " ";
		f << g.days_0 << "\n";
	}
	f.close();
}

inline void hotel::FeedbackINFO(string feedback)
{
	string fb = feedback;
	ofstream f3;
	f3.open("feedback.txt", ios::binary | ios::app);
	if (!f3.is_open()) {
		wxMessageBox("File cannot be opened ", "problem Detected",
			wxOK | wxICON_INFORMATION);
		return;
	}
	f3 << fb << "\n";
	wxMessageBox("Your Feedback  is  Recorded", "Success",
		wxOK | wxICON_INFORMATION);
	f3.close();
}

inline void hotel::check_in_function(string name_0,string address_0,int phone_0,int room_0, int days_0) {
		
	if (rooms[room_0] == 1) {
		wxMessageBox("This room is already taken",
			"Problem appeared ", wxOK | wxICON_INFORMATION);
		return;
	}

	Guest g1;
	g1.days_0 = days_0;
	g1.name_0 = name_0;
	g1.address_0 = address_0;
	g1.room_0 = room_0;
	g1.phone_0 = phone_0;

	guest.push_back(g1);
	rooms[room_0] = 1;

	wxMessageBox("You have Checked in",
						"	Checked in", wxOK | wxICON_INFORMATION);


	/*f1.open("GuestInfo.txt", ios::in | ios::binary);
	while (!f1.eof()) {

		f1.read()
		if (rooms[room_0]==1) {
			wxMessageBox("This room is already taken",
				"Problem appeared ", wxOK | wxICON_INFORMATION);
			f1.close();
			break;
		}
		
	
		else {*/


	//		rooms[room_0] = 1;
	//		/*string room_str = to_string(room_0);
	//		string phone_str = to_string(phone_0);
	//		string days_str = to_string(days_0);*/


	//		if (!f1.is_open()) {
	//			wxMessageBox("Failed to open the file",
	//				"Failed", wxOK | wxICON_INFORMATION);
	//		}
	//		else {

	//			f1 << name_0;
	//			f1 << address_0;
	//			f1 << room_0;
	//			f1 << phone_0;
	//			f1 << days_0;
	//			/*f1.write((char*)&address1, sizeof(address1));
	//			f1.write((char*)&address_0, sizeof(address_0));
	//			f1.write((char*)&room1, sizeof(room1));
	//			f1.write((char*)&rooms[room_0], sizeof(rooms[room_0]));
	//			f1.write((char*)&room_str, sizeof(room_str));
	//			f1.write((char*)&phone1, sizeof(phone1));
	//			f1.write((char*)&phone_str, sizeof(phone_str));
	//			f1.write((char*)&days1, sizeof(days1));
	//			f1.write((char*)&days_str, sizeof(days_str));*/
	//			wxMessageBox("You have Checked in",
	//				"	Checked in", wxOK | wxICON_INFORMATION);
	//			f1.close();
	//			
	//		}
	//		break;
	//	}
	//	
	//}
}

inline int hotel::check_out_function(Guest& g1,int room_0) {
	
	//size_t pos;

	//string line;
	//int bill = 0;
	//bill = price * days_0;
	
	

	/*f (room_0 < 50 || room_0 == 0) {
		wxMessageBox("Please Enter valid Room no",
			"Invalid Room Number", wxOK | wxICON_INFORMATION);
		return 0;
	}*/
	if (rooms[room_0] == 0) {
				wxMessageBox("This room is empty, please enter your room no.",
					"Invalid room", wxOK | wxICON_INFORMATION);
				return 0;
		}
	int found = -1;
	for (int i = 0; i < guest.size(); ++i) {
		if (guest[i].room_0 == room_0) {
			found = i;
			break;
		}
	}
	if (found == -1) {
		wxMessageBox("Your record is not found in our database",
									"Record not found", wxOK | wxICON_INFORMATION);
		return 0;
	}
	rooms[room_0] = 0;
	g1 = guest[found];

	guest.erase(guest.begin()+found);

	return 1;



	//find_if(guest.begin(), guest.end(),);




	//else {
	//	//rooms[room_0] = 0;
	//	string room_str = to_string(room_0);
	//	string phone_str = to_string(phone_0);
	//	string days_str = to_string(days_0);

	//	f1.open("GuestInfo.dat", ios::in | ios::binary | ios::app);
	//	if (!f1.is_open()) {
	//		wxMessageBox("Failed to open the file",
	//			"Failed", wxOK | wxICON_INFORMATION);
	//	}
	//	else {
	//		
	//		if (rooms[room_0] == 0) {
	//			wxMessageBox("This room is empty, please enter your room no.",
	//				"Invalid room", wxOK | wxICON_INFORMATION);
	//		}
	//		/*else if (f1.is_open()) {
	//			
	//				while (getline(f1, line))
	//				{
	//					pos = f1.find(name_0);
	//					if (pos != string::npos) // string::npos is returned if string is not found
	//					{
	//						break;
	//					}
	//					else {
	//						wxMessageBox("Your record is not found in our database",
	//							"Record not found", wxOK | wxICON_INFORMATION);
	//						break;
	//					}
	//				
	//				}
	//		}*/
	//		else {

	//			rooms[room_0] = 0;

	//			return bill;


	//		}
	//	}
	//}
}



inline int hotel:: search_function ( string name, Guest &g ) {
	
	int found = -1;
	for (int i = 0; i < guest.size(); ++i) {
		if (guest[i].name_0 == name) {
			found = i;
			break;
		}

	}
	if (found == -1) {
		return 0;
	}
	g = guest[found];
	return 1;
	

}

inline int hotel :: food_function(int mb,int mm,int ch,int fr) {


	string masubhat = "MasuBhat: ";
	string Momo = "Momo: ";
	string Chiso = "Chiso: ";
	string FriedRice = "Fried Rice: ";

	int total = mb * mbp + mm * mmp + ch * chp + fr * frp;

	ofstream food;
	food.open("food.txt", ios::binary );
	if (!food.is_open()) {
		wxMessageBox("Failed to open the file",
			"Failed", wxOK | wxICON_INFORMATION);
	}
	else {
		food << masubhat;
		//food.write((char*)&masubhat, sizeof(masubhat));
		food << mb <<"  ";
		//food.write((char*)&mb, sizeof(mb));
		food << Momo;
		//food.write((char*)&Momo, sizeof(Momo));
		food << mm <<"  ";
		//food.write((char*)&mm, sizeof(mm));
		food << Chiso;
		//food.write((char*)&Chiso, sizeof(Chiso));
		food << ch <<"  ";
		//food.write((char*)&ch, sizeof(ch));
		food << FriedRice;
		//food.write((char*)&FriedRice, sizeof(FriedRice));
		food << fr << "\n";
		//food.write((char*)&fr, sizeof(fr));

	}
	return total;
}
