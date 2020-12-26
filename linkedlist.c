#include <stdio.h>
#include <stdlib.h>
#include <linkedlist.h>
#include <ncurses.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

char ch;
short p;


void printList(WINDOW *);
void wpaint(WINDOW *, char, short);
void outlinew(WINDOW *, short);

#define paint(ch, p) wpaint(stdscr, ch, p)
#define outline(p) outlinew(stdscr, p)

int main(int argc, char *argv[]){

	char cmd[30];
	int arg1;
	char arg2[30];

	initscr();
	cbreak();
	noecho();

	WINDOW *win1 = newwin(getmaxy(stdscr)-2,getmaxx(stdscr)/2,1,1);
	WINDOW *info = derwin(win1, getmaxy(win1)-2, getmaxx(win1)-2, 1, 1);

	WINDOW *win2 = newwin(getmaxy(win1)/2,getmaxx(win1),1,getmaxx(stdscr)/2);
	WINDOW *input = derwin(win2, getmaxy(win2)-2, getmaxx(win2)-2, 1, 1);

	WINDOW *win3 = newwin(getmaxy(win2), getmaxx(win2),getmaxy(stdscr)/2,getmaxx(stdscr)/2);
 	WINDOW *output = derwin(win3,getmaxy(win3)-2, getmaxx(win3)-2, 1, 1);

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	paint(32,1);
	wpaint(win1,32,1);
	wpaint(win2,32,1);
	wpaint(win3,32,1);

	outlinew(win1, 1);
	outlinew(win2, 1);
	outlinew(win3, 1);


	int id=0,i=1,j=1;

        head = newNode(1, "head");

	struct node *srch, *temp;

	echo();
	while(1){

		wclear(info);

		wattron(info, COLOR_PAIR(1));

		printList(info);

		wattroff(info, COLOR_PAIR(1));
		wrefresh(info);

		sprintf(cmd, " ");
		sprintf(arg2, " ");
		arg1 = 0;


		wattron(input, COLOR_PAIR(1));
		mvwscanw(input, j, 1,"%s %d %s",cmd, &arg1, arg2);

		wattroff(input, COLOR_PAIR(1));
		wrefresh(input);


		wattron(output, COLOR_PAIR(1));

		if(!strcmp(cmd,"search")){
			srch = searchNode(arg1);
			mvwprintw(output, i, 1, "Found Node %s : %d", srch -> name, srch -> id);
		}
		if(!strcmp(cmd,"remove")){
			srch = searchNode(arg1);
			mvwprintw(output, i, 1, "Removing Node %s : %d", srch -> name, srch -> id);
			removeNode(arg1);
		}
		if(!strcmp(cmd,"add-node")){
			temp = addNode(arg1, arg2);
			mvwprintw(output, i, 1, "Adding new node %s : %d", temp -> name, temp -> id);
		}
		if(!strcmp(cmd,"length")){
			mvwprintw(output, i, 1, "Returning Length of Linkedlist\t%d",length(head));
		}

		if(!strcmp(cmd,"clear")){
			if(!strcmp(arg2, "input")){
				wclear(input);
				i=0;
			}
			if(!strcmp(arg2,"output")){
				wclear(output);
				i=0;
			}
			if(!strcmp(arg2, "both")){
				wclear(input);
				wclear(output);
				i=0;
			}

		}
		if(!strcmp(cmd,"help")){
			mvwprintw(output, i, 1, "search [id] - find node by id\n remove [id] - remove node by id\n add-node [id][name] - create node\n length - find length of list\n clear (both - input - output) - clear window \n exit - exit list\n help - get help\n");
			i+=8;
		}
		if(!strcmp(cmd,"exit")){
			break;
		}

		wattroff(output, COLOR_PAIR(1));
		wrefresh(output);
		i++;
		j++;
	}
	endwin();
        return 0;
}
void printList(WINDOW *win){
	struct node *current = head;

	for(int i=0; current != NULL; i++){
		mvwprintw(win,i,1,"Node %s : %d", current -> name, current -> id);
		current = current -> next;
	}
}
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
