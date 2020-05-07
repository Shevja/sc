#include <iostream>

using namespace std;

#include "myTerm.cpp"
#include "myTerm.h"

int main(){
	mt_clrscr();

	int x = 5, y = 10, cols = 0, rows = 0;
	mt_getScreen(&rows, &cols);
	mt_gotoXY(x, y, rows, cols);

	mt_setbgcolor(BLACK);
	mt_setfgcolor(RED);
	cout << "Kashirin Vladislav" << endl;

	x = 6, y = 8;
	mt_gotoXY(x, y, rows, cols);

	mt_setbgcolor(GREEN);
	mt_setfgcolor(WHITE);
	cout << "IV822" << endl;

	mt_gotoXY(10, 1, rows, cols);
	mt_setbgcolor(DEFAULT);
	mt_setfgcolor(DEFAULT);

	cursor_invis();
	cursor_vis();
	return 0;
}
