#ifndef _SCHOOLTIMETABLE_H
#define _SCHOOLTIMETABLE_H

#include "template.h"
#include "path.h"
#include "data_TimeTable.h"
#include "helper.h"

class SchoolTimeTable {
private:
	vector <string> List;
	vector <SchTimeTab> TimeTable;
	vector <SchLect> Lecturer;
	string ID = ""; // semester_id.
public:
	// Debug - Run BackEnd before debug
	void DEBUGList();
	void DEBUGTimeTable();
	void DEBUGLecturer();
	// BackEnd
	void GetList();
	void GetTimeTable();
	void GetLecturer();
	// FrontEnd
	void ShowList(); // For Get ID;
	void ShowTimeTable();
};
#endif