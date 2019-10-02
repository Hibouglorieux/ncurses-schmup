/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan </var/mail/nathan>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:19:03 by nathan            #+#    #+#             */
/*   Updated: 2019/10/02 04:59:13 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <sstream>
#include "keys.hpp" 
#include <unistd.h>

#define REFRESH_RATE 100000

void	loop( WINDOW *win ){
	int	i;
	i = 0;
	while (i != ESC)
	{
		wmove(win, 0, 0); // sets cursor to beginning of window
		i = wgetch(win);
		//while (wgetch(win) != ERR)
		wprintw(win, "i:%d", i); 
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
	loop(main_win);
	delwin(main_win); // destroy windows
	delwin(boxwin);
	delwin(stdscr);
	endwin(); // clear terminal after using initscr()
	return (0);
}
