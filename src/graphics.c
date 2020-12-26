#include <stdio.h>
#include <ncurses.h>

void wpaint(WINDOW *win, char c, short pair){
        wattron(win, COLOR_PAIR(pair));
        for(int i=0;i<getmaxy(win);i++)
                for(int j=0;j<getmaxx(win);j++)
                        mvwprintw(win,i,j,"%c",c);

        wattron(win, COLOR_PAIR(pair));
        wrefresh(win);
}
void outlinew(WINDOW *win, short pair){
        wattron(win, COLOR_PAIR(pair));
        box(win,0,0);
        wattroff(win, COLOR_PAIR(pair));
        wrefresh(win);
}
