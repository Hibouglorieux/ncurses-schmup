/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:19:03 by nathan            #+#    #+#             */
/*   Updated: 2019/10/03 01:03:45 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
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

void	loop( WINDOW *win){
	char	i;
	Manager manager;
	i = 'a';
	manager.add( new Ennemy1(0, WIDTH / 2, win, manager) );
	while (i != ESC)
	{
		manager.update();
		//cursor.setXY(0, 0);
		i =  wgetch(win);
		while (wgetch(win) != ERR);
		wmove(win, 0, 0); // sets cursor to beginning of window
		handle_input(win, i);
		wrefresh(win);
		werase(win);
		usleep(REFRESH_RATE);
		//napms(REFRESH_RATE / 1000);
	}
	wattron(win, A_STANDOUT); // enable highlight
	wattroff(win, A_STANDOUT); // disable highlight
}

int		main( void ){
	WINDOW *boxwin, *main_win;

	initscr(); // initialize terminal
	noecho(); // doesnt show user input
	cbreak(); // allows to catch input per char not waiting for \n
	//	halfdelay(1); // used to discard getch(); after x * 1/10 sec // replaced by nodelay for now
	curs_set(0); // set cursor to invisible
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	boxwin = newwin(HEIGHT, WIDTH, MIDH, MIDW);
	box(boxwin, 0, 0); // create a box around the window
	main_win = subwin(boxwin, HEIGHT - 2, WIDTH - 2, MIDH + 1, MIDW + 1); // create smaller window inside boxed window
	keypad(main_win, true);// allow use of arrows
	nodelay(main_win, true); // used to make getch() not bloking
	wrefresh(boxwin); // refresh boxed window
	//Cursor cursor(main_win);
	loop(main_win);
	delwin(main_win); // destroy windows
	delwin(boxwin);
	delwin(stdscr);
	endwin(); // clear terminal after using initscr()
	return (0);
}
