#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <curses.h>
#include <unistd.h>
#include <menu.h>

#include "wizard.h"

#include "ww.h"

WINDOW         *topstatw;
WINDOW         *countdownw;

void 		paint_all();

void
fun0()
{
	printf("A curses pgram that creates a kitchen timer type stopwatch and ARED and GREEN button that the ouse can push\n");
}

void
init()
{
	initscr();
	start_color();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	paint_all();

	/* lines, cols, y, x */
	topstatw = newwin(2, 30, 0, 0);
	countdownw = newwin(3, 30, 2, 0);
	box(countdownw, 0, 0);
	curs_set(0);
	wrefresh(countdownw);
	wrefresh(topstatw);
}

/*
 * COLOR_BLACK COLOR_RED COLOR_GREEN COLOR_YELLOW COLOR_BLUE COLOR_MAGENTA
 * COLOR_CYAN COLOR_WHITE
 */
void
paint_all()
{
	int 		max_x    , max_y;
	int 		x        , y;

	getmaxyx(stdscr, max_y, max_x);

	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	attron(COLOR_PAIR(1));

	for (x = 0; x < max_x; x++) {
		for (y = 0; y < max_y; y++) {
			move(y, x);
			addch('e');
		}
	}

	attroff(COLOR_PAIR(1));

	curs_set(0);
	refresh();
}

int
main()
{
	int 		max_x    , max_y;
	int 		i, c;

	getmaxyx(stdscr, max_y, max_x);

	init();


	wprintw(topstatw, "24 frames per second");
	wrefresh(topstatw);

	for (i=0; i<100000; i++) {
		wmove(countdownw, 1, 2);
		wprintw(countdownw, "%d", i);
		wrefresh(countdownw);
	}	

	c = wgetch(topstatw);

	delwin(topstatw);
	delwin(countdownw);
	endwin();
	return EXIT_SUCCESS;
}
