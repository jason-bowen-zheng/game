#include <ncurse.h>
#include <stdio.h>
#include <stdlib.h>
#include "support.h"

int main(){
	initsrc();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	if (has_colors == FALSE){
		endwin();
		printf("Your terminal does not support color!");
		exit(1);
	} else {
		clear();
		start_color();
		init_pair(LAND, COLOR_GREEN, COLOR_GREEN);
		init_pair(HERO, COLOR_RED, COLOR_GREEN);
		init_pair(MONS_1, COLOR_BLACK, COLOR_GREEN);
	}
