#include <iostream>

using namespace std;

#include "myTerm.cpp"
#include "myTerm.h"

int main(){
	mt_clrscr();

	int x = 20, y = 20, cols = 0, rows = 0;
	mt_getScreen(&rows, &cols);
	mt_gotoXY(x, y, rows, cols);

	color b(NAVY);
	mt_setbgcolor(b);
	color f(GREEN);
	mt_setfgcolor(f);
	cout << "gg" << endl;

	cursor_invis();
	cursor_vis();
	return 0;
}