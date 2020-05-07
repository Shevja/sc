#ifndef ESC_H
#define ESC_H
#include <sys/ioctl.h>
#include <unistd.h>

enum color { 
	BLACK, 
	RED, 
	GREEN, 
	YELLOW, 
	NAVY, 
	PURPLE, 
	BLUE, 
	WHITE,
	DEFAULT = 9
};

void mt_clrscr();
bool mt_gotoXY(int x, int y, int rows, int cols);
bool mt_setbgcolor(enum color);
bool mt_setfgcolor(enum color);
void cursor_invis();
void cursor_vis();
void mt_getScreen(int* rows, int* cols);

#endif
