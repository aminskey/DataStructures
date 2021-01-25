#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

#include <linkedlist.h>
#include <graphics.h>

int main(void){


	initscr();
	cbreak();
	noecho();

	WINDOW *win1 = newwin(getmaxy(stdscr)-2,getmaxx(stdscr)/2,1,1);
	WINDOW *info = derwin(win1, getmaxy(win1)-2, getmaxx(win1)-2, 1, 1);

	WINDOW *win2 = newwin(getmaxy(win1)/2,getmaxx(win1),1,getmaxx(stdscr)/2+1);
	WINDOW *input = derwin(win2, getmaxy(win2)-2, getmaxx(win2)-2, 1, 1);

	WINDOW *win3 = newwin(getmaxy(win2), getmaxx(win2),getmaxy(stdscr)/2,getmaxx(stdscr)/2+1);
 	WINDOW *output = derwin(win3,getmaxy(win3)-2, getmaxx(win3)-2, 1, 1);

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);

	paint(32,1);
	wpaint(win1,32,1);
	wpaint(win2,32,1);
	wpaint(win3,32,1);

	outlinew(win1, 1, "| List |");
	outlinew(win2, 1, "| Commands |");
	outlinew(win3, 1, "| Console |");


	int id=0,i=8, j=0;

        head = newNode(1, "head", "The Head node - basically unremovable");

	for(int i=2;i<9;i++){
		struct node *temp1 = addNode(i, "Temporary Node", "lolnode - no description");
	}

	struct node *srch, *temp;


	wattron(output, COLOR_PAIR(1));


	wattroff(output, COLOR_PAIR(1));
	wrefresh(output);

	echo();
	while(1){

		char cmd[30];
		char arg2[30];
		char arg4[50];

		int arg1;
		int arg3;

		outlinew(win1, 1, "| List |");
		outlinew(win2, 1, "| Commands |");
		outlinew(win3, 1, "| Console |");

		wclear(info);

		wattron(info, COLOR_PAIR(1));

		printList(info);

		wattroff(info, COLOR_PAIR(1));
		wrefresh(info);


		wattron(output, COLOR_PAIR(1));

		mvwprintw(output, 0, 0, "search [id] - find node by id\nremove [id] - remove node by id\nadd-node [name][description] - create node\nlength - find length of list\nclear  (both - input - output) - clear window \nexit - exit list\nreset - reset everything");
		wrefresh(output);

		wattron(input, COLOR_PAIR(1));
		mvwscanw(input, j, 0, "%s",cmd);

		if(!strcmp(cmd,"search")){
			mvwscanw(input, j, strlen("Enter id: ")+1 ,"%d", &arg1);

			srch = searchNode(arg1);
			mvwprintw(output, i, 0, "Found Node \"%s : %d\" with description: \n%s", srch -> name, srch -> id, srch -> des);
			i+=2;
		}
		if(!strcmp(cmd,"remove")){
			mvwscanw(input, j, strlen("Enter id: ")+1 ,"%d", &arg1);


			srch = searchNode(arg1);
			mvwprintw(output, i, 0, "Removing Node \"%s : %d\"", srch -> name, srch -> id);
			removeNode(arg1);
		}
		if(!strcmp(cmd,"add-node")){
			struct node *temp2 = lastNode();

			mvwscanw(input, j, 10, "%s %s", arg2, arg4);

			temp = addNode((temp2 -> id)++, arg2, arg4);
			mvwprintw(output, i, 0, "Adding new node \"%s : %d\"", temp -> name, temp -> id);
		}
		if(!strcmp(cmd,"length")){
			mvwprintw(output, i, 0, "Returning Length of Linkedlist\t%d",length(head));
		}

		if(!strcmp(cmd,"clear")){
			mvwscanw(input, j, 10, "%s", arg2);
			if(!strcmp(arg2, "input")){
				wclear(input);
				i=0;
				j=-1;
			}
			if(!strcmp(arg2,"output")){
				wclear(output);
				i=8;
			}
			if(!strcmp(arg2, "both")){
				wclear(input);
				wclear(output);
				i=8;
				j=-1;
			}

		}
		if(!strcmp(cmd,"exit")){
			break;
		}
		if(!strcmp(cmd,"reset")){
			main();
			break;
		}
/*		if(!strcmp(cmd,"insert-node")){
			struct node *ins = insertNode(arg1, arg2, arg3, arg4);
		}
*/		if(i >= getmaxy(output)-1){
			wclear(output);
			i=8;
		}
		if(j >= getmaxy(input)-1){
			wclear(input);
			j=-1;
		}


		wattroff(input, COLOR_PAIR(1));
		wrefresh(input);

		wattroff(output, COLOR_PAIR(1));
		wrefresh(output);
		i++;
		j++;
	}
	endwin();
        return 0;
}
