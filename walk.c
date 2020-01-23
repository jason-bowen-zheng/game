#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GROUND ' '
#define PERSON '*'
#define WORD 1
#define TITLE "Walk"

void draw(void){
	attron(COLOR_PAIR(GROUND));
	for (int y = 0; y < LINES; y++){
		mvhline(y, 0, GROUND, COLS);
	}
	attroff(COLOR_PAIR(GROUND));
	refresh();
}

void addmidstr(char str[]){
	mvaddstr((LINES / 2), (COLS - strlen(str)) / 2, str);
}

int main(){
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	if (has_colors() == FALSE){
		endwin();
		printf("Your terminal dose not support color!");
		exit(1);
	} else {
		clear();
		start_color();
		init_pair(GROUND, COLOR_CYAN, COLOR_CYAN);
		init_pair(PERSON, COLOR_RED, COLOR_CYAN);
		init_pair(WORD, COLOR_WHITE, COLOR_CYAN);
	}
	int y = 0;
	int x = 0;
	do{
		draw();
		attron(COLOR_PAIR(WORD));
		addmidstr(TITLE);
		attroff(COLOR_PAIR(WORD));
		attron(COLOR_PAIR(PERSON));
		mvaddch(y, x, PERSON);
		move(y, x);
		attroff(COLOR_PAIR(PERSON));
		refresh();
		char c = getch();
		switch(c){
			case 'w':
			case 'W':
				if (y > 0){
					y--;
				}
				break;
			case 's':
			case 'S':
				if (y < LINES - 1){
					y++;
				}
				break;
			case 'a':
			case 'A':
				if (x > 0){
					x--;
				}
				break;
			case 'd':
			case 'D':
				if (x < COLS - 1){
					x++;
				}
				break;
			case 'q':
			case 'Q':
				endwin();
				exit(0);
				break;
		}
	}while(1);
}
