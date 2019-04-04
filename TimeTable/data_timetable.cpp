#include "data_timetable.h"

void SchLect::convert(string Tmp, vector<string>& Use){
	Use.clear();
	string use_element = "";
	for (int i = 0; i < Tmp.length(); i++) {
		if (Tmp[i] != ',')
			use_element += Tmp[i];
		else {
			Use.push_back(use_element);
			use_element = "";
		}
	}
}

