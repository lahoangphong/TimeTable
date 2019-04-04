#include "SchoolTimeTable.h"
	


void SchoolTimeTable::DEBUGList(){
	cout << "\n#FOR DEBUGER [LIST OF SEMESTER]\n";
	for (int i = 0; i < List.size(); i++) {
		cout << List[i] << "\n";
	}
}

void SchoolTimeTable::DEBUGTimeTable(){
	cout << "\n#FOR DEBUGER [TIMETABLE DATA]\n";
	for (int i = 0; i < TimeTable.size(); i++) {
		cout << TimeTable[i].CourseID << " " << TimeTable[i].Day << " " << TimeTable[i].Shift << " " << TimeTable[i].RoomName << "\n";
	}
}

void SchoolTimeTable::DEBUGLecturer(){
	cout << "\n#FOR DEBUGER [LECTURER DATA]\n";
	for (int i = 0; i < Lecturer.size(); i++) {
		cout << Lecturer[i].CourseID << " " << Lecturer[i].CourseFull << " " << Lecturer[i].TheoryLec << " ";
		for (int j = 0; j < Lecturer[i].TALec.size(); j++)
			cout << Lecturer[i].TALec[j] << " ";
		cout << Lecturer[i].OfficeHour << " ";
		for (int j = 0; j < Lecturer[i].Email.size(); j++)
			cout << Lecturer[i].Email[j] << " ";
		cout << "\n";
	}
}

void SchoolTimeTable::GetList(){ //return
	string path = PATH::SchoolTimeTable + "ListTimeTable.txt";
	string read;
	vector <string> Res;
	ifstream in;
	in.open(path);
	while (in >> read) {
		Res.push_back(read);
	}
	in.close();
	List = Res;
	return ;
}

void SchoolTimeTable::GetTimeTable(){
	string path = PATH::SchoolTimeTable + ID + "/TimeTable.txt";
	vector <SchTimeTab> Res;
	SchTimeTab Tmp;
	
	ifstream in;
	in.open(path);
	while (in >> Tmp.Day >> Tmp.Shift >> Tmp.CourseID >> Tmp.RoomName) {
		Res.push_back(Tmp);
	}
	in.close();
	TimeTable = Res;
	return ;
}

void SchoolTimeTable::GetLecturer(){
	string path = PATH::SchoolTimeTable + ID + "/Lecturer.txt";
	vector <SchLect> Res;
	SchLect Tmp;

	ifstream in;
	in.open(path);
	while (in >> Tmp.CourseID >> Tmp.CourseFull >> Tmp.TheoryLec >> Tmp.TALec_Tmp >> Tmp.OfficeHour >> Tmp.Email_Tmp) {
		Tmp.convert(Tmp.TALec_Tmp, Tmp.TALec);
		Tmp.convert(Tmp.Email_Tmp, Tmp.Email);
		Res.push_back(Tmp);
	}
	in.close();
	Lecturer = Res;
	return ;
}

void SchoolTimeTable::ShowList(){
	GetList();
	int number;
	for (int i = 0; i < List.size(); i++) {
		cout << i + 1 << ". " << List[i] << "\n";
	}
	cout << "\n";
	cout << "Your selection: ";
	cin >> number;
	ID = List[number - 1];
	system("cls");
	return;
}

void SchoolTimeTable::ShowTimeTable(){
	// cell :  x 3
	// shift : 7
	// hour/dow : 
	GetTimeTable();

	int ULCx = 5; // Upper left conner
	int ULCy = 12;
	// show shift
	HELPER::gotoxy(ULCx + 1, ULCy + 0);
	cout << "SHIFT"; // finish : 6x0
	for (int i = 1; i <= 4; i ++) {
		HELPER::gotoxy(ULCx + 3,ULCy + 3 + (i-1) * 5);
		cout << i;
	}
	// show hour/dow
	// TH h:mm-h:mm , theory
	// TA h:mm-h:mm , TA
	HELPER::gotoxy(ULCx + 15, ULCy + 0);
	cout << "HOUR/DoW"; // finish 18x0
	// Hour
	for (int i = 1; i <= 4; i++) {
		HELPER::gotoxy(ULCx + 13, ULCy + 2 + (i - 1) * 5);
		switch (i) {
			case 1: {
				cout << "TH 7:30-9:10";
				break;
			}
			case 2: {
				cout << "TH 9:30-11:10";
				break;
			}
			case 3: {
				cout << "TH 13:30-15:10";
				break;
			}
			case 4: {
				cout << "TH 15:30-17:10";
				break;
			}
			default:
				break;
		}
		HELPER::gotoxy(ULCx + 13, ULCy + 4 + (i - 1) * 5);
		switch (i) {
			case 1: {
				cout << "TA 7:30-9:30";
				break;
			}
			case 2: {
				cout << "TA 9:30-11:30";
				break;
			}
			case 3: {
				cout << "TA 13:30-15:30";
				break;
			}
			case 4: {
				cout << "TA 15:30-17:30";
				break;
			}
			default:
				break;
		}
	}
	// DoW 18 x
	for (int i = 2; i <= 7; i++) {
		HELPER::gotoxy(ULCx + 25 * (i), ULCy + 0);
		cout << i;
	}
	// Timetable full
	for (int i = 0; i < TimeTable.size(); i++) {
		HELPER::gotoxy(ULCx + 25 * TimeTable[i].Day - 5, ULCy + 3 + (TimeTable[i].Shift-1) * 5);
		cout << TimeTable[i].CourseID << " - " << TimeTable[i].RoomName;
	}
	return;
}
