#pragma once
#ifndef _DATA_TIMETABLE_H
#define _DATA_TIMETABLE_H

#include "template.h";

 struct SchTimeTab {
	int Day, Shift;
	string CourseID;
	string RoomName;
};

 struct SchLect {
	 string CourseID;
	 string CourseFull;
	 string TheoryLec;
	 string TALec_Tmp; // for get from file
	 vector<string> TALec;
	 string OfficeHour;
	 string Email_Tmp; // for get from file
	 vector<string> Email;
	 void convert(string Tmp, vector <string> &Use);

 };

#endif