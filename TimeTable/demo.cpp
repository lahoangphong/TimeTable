#include "timeTable.h"

int main() {
	HELPER::fullscreen_mode();
	SchoolTimeTable Tool;
	Tool.ShowList();
	Tool.ShowTimeTable();
	cin.get();
	cin.get();
	return 0;
}