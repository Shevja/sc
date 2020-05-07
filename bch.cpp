#include <iostream>

using namespace std;

#include "myTerm.h"
#include "myTerm.cpp"

int bc_printA (char ch){
	cout << "\E(0" << ch << "\E(B";
	return 0;
}

int bc_box(int x1, int y1, int x2, int y2) {

	if(mt_gotoXY(x1, y1, 0, 0) != 0 || mt_gotoXY(x2, y2, 0, 0) != 0){
		return -1;
	}else {
		mt_gotoXY(x1, y1, 0, 0);
		bc_printA('l');
		mt_gotoXY(x2, y1, 0, 0);
		bc_printA('m');
		mt_gotoXY(x1, y2, 0, 0);
		bc_printA('k');
		mt_gotoXY(x2, y2, 0, 0);
		bc_printA('j');
	}

	for (int i = x1+1; i <= x2-1; i++)
	{
		mt_gotoXY(i, y1, 0, 0);
		bc_printA('x');
	}
	for (int i = y1+1; i <= y2-1; i++)
	{
		mt_gotoXY(x1, i, 0, 0);
		bc_printA('q');
	}
	for (int i = y1+1; i <= y2-1; i++)
	{
		mt_gotoXY(x2, i, 0, 0);
		bc_printA('q');
	}

	for (int i = x1+1; i <= x2-1; i++)
	{
		mt_gotoXY(i, y2, 0, 0);
		bc_printA('x');
	}

	return 0;
}

int bc_printbigchar (int *big, int x, int y, color backg, color foreg){
	int bit;

	if (mt_gotoXY(x, y, 0, 0) != 0)
	{
		return -1;
	}
	mt_setbgcolor(backg);
	mt_setfgcolor(foreg);

	mt_gotoXY(x, y, 0, 0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			bit = (big[i >> 2] >> ((i % 4) * 8 + j)) & 0x1;
            if(bit == 0)
            {
                bc_printA(' ');
            }
            else if(bit == 1)
            {
                bc_printA('a'); 
            }
		}
		mt_gotoXY(x + (i + 1), y, 0, 0);
	}

	mt_setbgcolor(BLACK);
	mt_setfgcolor(WHITE);
	return 0;
}

int main(){
	mt_clrscr();
	bc_box(10, 10, 40, 120);

	int bch[2] = {01001111, 10000001};
	bc_printbigchar (bch, 20, 20, RED, GREEN);

	mt_gotoXY(0,0,0,0);
	return 0;
}