#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

char ch;
short p;
char *s;

extern void wpaint();
extern void outlinew();

#define paint(ch, p) wpaint(stdscr, ch, p)
#define outline(p, s) outlinew(stdscr, p, s);

#endif
