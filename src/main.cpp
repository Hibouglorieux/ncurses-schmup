/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:19:03 by nathan            #+#    #+#             */
/*   Updated: 2019/10/02 13:58:18 by aben-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <sstream>
#include "keys.hpp"
#include "cursor.hpp"
#include <unistd.h>
#include <fcntl.h>
#define REFRESH_RATE 100000


/*
	Fonction pour debug pendant l'execution du programme
	dprintf(debug(), "Log\n");
*/
int		debug(void){return open("log", O_RDWR | O_APPEND | O_CREAT, 0666);}

void	handle_input(WINDOW *win, char c){
	if (~c) //if c != -1
		wprintw(win, "Key pressed: %c|%d", c, c);
	else
		wprintw(win, "Press key");
	//wmove()
}

void	loop( WINDOW *win, Cursor cursor){
	char	i;
	i = 'a';
	while (i != ESC)
	{
		//wmove(win, 0, 0); // sets cursor to beginning of window
		cursor.setXY(0, 0);
		i =  wgetch(win);
		handle_input(win, i);
		wrefresh(win);
		werase(win);
		usleep(REFRESH_RATE);
		//napms(REFRESH_RATE / 1000);
	}
	wattron(win, A_STANDOUT); // enable highlight
	wattroff(win, A_STANDOUT); // disable highlight
}

#define WIDTH 60
#define HEIGHT 30
#define MIDW (COLS - WIDTH) * 0.5
#define MIDH (LINES - HEIGHT) * 0.5

int		main( void ){
	WINDOW *boxwin, *main_win;

	initscr(); // initialize terminal
	noecho(); // doesnt show user input
	cbreak(); // allows to catch input per char not waiting for \n
	//	halfdelay(1); // used to discard getch(); after x * 1/10 sec // replaced by nodelay for now
	curs_set(0); // set cursor to invisible
	boxwin = newwin(HEIGHT, WIDTH, MIDH, MIDW);
	box(boxwin, 0, 0); // create a box around the window
	main_win = subwin(boxwin, HEIGHT - 2, WIDTH - 2, MIDH + 1, MIDW + 1); // create smaller window inside boxed window
	keypad(main_win, true);// allow use of arrows
	nodelay(main_win, true); // used to make getch() not bloking
	wrefresh(boxwin); // refresh boxed window
	Cursor cursor(main_win);
	loop(main_win, cursor);
	delwin(main_win); // destroy windows
	delwin(boxwin);
	delwin(stdscr);
	endwin(); // clear terminal after using initscr()
	return (0);
}
