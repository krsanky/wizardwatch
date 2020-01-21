#include <curses.h>

#include "ww.h"

void
ww_display_simple_clock(WINDOW *w)
{
	wprintww(w, "12:12 AM");
}

