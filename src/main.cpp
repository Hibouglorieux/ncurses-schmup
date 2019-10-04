/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nathan <nathan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:19:03 by nathan            #+#    #+#             */
/*   Updated: 2019/10/04 04:50:32 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
#include "Projectile.hpp"
#include "Weapon.hpp"
#define REFRESH_RATE 50000
#include <iostream>


/*
	Fonction pour debug pendant l'execution du programme
	dprintf(debug(), "Log\n");
*/
int		debug(void){return open("log", O_RDWR | O_APPEND | O_CREAT, 0666);}

void	handle_input(WINDOW *win, Manager & manager, int c){
	(void)win;
	(void)c;
	 // if (~c) //if c != -1
	 // 	wprintw(win, "Key pressed: %c|%d", c, c);
	 // else
	 // 	wprintw(win, "Press key");
	if (c == UP)
		manager.player->moveUp();
	if (c == DOWN)
		manager.player->moveDown();
	if (c == LEFT)
		manager.player->moveLeft();
	if (c == RIGHT)
		manager.player->moveRight();
	if (c == SPACE)
		manager.player->shoot();
	dprintf(debug(), "Touche pressée : %c\n", c);
	manager.player->update();
	//wmove()
}

void	loop( WINDOW *win){
	int	i;
	Manager manager(new Player(26, 24, win, manager));
	manager.player->equip(new Weapon);
	i = 'a';
	//manager.add( new Ennemy1(0, WIDTH / 2, win, manager) );
	//manager.add(player);
	while (i != ESC)
	{
		manager.update();
		i = wgetch(win);
		while (wgetch(win) != ERR);
		wmove(win, 0, 0); // sets cursor to beginning of window
		handle_input(win, manager, i);
		manager.clear();
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
	init_pair(ENEMIES_COLOR, COLOR_YELLOW, COLOR_BLACK);
	init_pair(PLAYER_COLOR, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
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
