#include "myTerm.h"

void mt_clrscr(){
	cout << "\E[H\E[J";
}

bool mt_gotoXY(int x, int y, int rows, int cols){
	if(rows == 0 || cols == 0){
		mt_getScreen(&rows, &cols);
	}
	if (x >= 0 && y >= 0 && x <= rows && y <= cols){
		cout << "\E[" << x << ";" << y << "H";
		return 0;
	}else {
		cout << "achieved beyond screen size" << endl;
		return -1;
	}
}

bool mt_setbgcolor(color c){
	if(c >= 0 && c <= 7){		
		cout << "\E[4" << c << "m";
		return 0;
	}
	return -1;
}

bool mt_setfgcolor(color c){
	if(c >= 0 && c <= 7){
		cout << "\E[3" << c << "m";
		return 0;
	}
	return -1;
}

void cursor_invis(){
	cout << "\E[?25l\E[?1c";
}

void cursor_vis(){
	cout << "\E[?25h\E[?8c";
}

void mt_getScreen(int* rows, int* cols){
	struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    *rows = w.ws_row;
	*cols = w.ws_col;
}