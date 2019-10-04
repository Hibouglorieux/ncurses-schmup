/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-azz <aben-azz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:43:09 by aben-azz          #+#    #+#             */
/*   Updated: 2019/10/04 04:58:02 by nathan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"


Player::Player(int y, int x, WINDOW* win, Manager & manager) : ADisplay(y, x, win, manager){
	this->_ammo = 100;
	this->_lives = 3;
	this->_y = y;
	this->_x = x;
	this->_weapon = new Weapon;
}

Player::~Player( void ) {
	delete this->_weapon;
}

void			Player::update( void ){
	//wmove(this->_win, 0, 0);
	//if (this->_y < HEIGHT - 5)
	this->display(this->_y, this->_x);
}

void			Player::draw( void ) const{
	wmove(this->_win, this->_y, this->_x);
	wattron(this->_win, COLOR_PAIR(PLAYER_COLOR));
	//wprintw(this->_win, " _/\\_");
	wmove(this->_win, this->_y + 1, this->_x);
	//wprintw(this->_win, "_/==\\_");
	wmove(this->_win, this->_y + 2, this->_x);
	//wattroff(this->_win, COLOR_PAIR(PLAYER_COLOR));
	dprintf(debug(), "pos: {%d, %d}\n", this->_y, this->_x);

	// draw new ship
	wmove(this->_win, this->_y - 1, this->_x);
	wprintw(this->_win, ".");
	wmove(this->_win, this->_y, this->_x - 1);
	wprintw(this->_win, "/s\\");
	wmove(this->_win, this->_y + 1, this->_x - 2);
	wprintw(this->_win, "<_-_>");
	wattroff(this->_win, COLOR_PAIR(PLAYER_COLOR));
}

void			Player::moveRight( void ){
	dprintf(debug(), "move right\n");

	this->_x++;
}

void			Player::moveLeft( void ){
	this->_x--;
}

void			Player::moveUp( void ){
	this->_y--;
}

void			Player::moveDown( void ){
	this->_y++;
}

void			Player::shoot( void ){
	this->_weapon->shoot(this->_manager, this->_win, this->_y + 1, this->_x);
}

void			Player::equip( Weapon * weapon ){
	delete this->_weapon;
	this->_weapon = weapon;
}

/*	 .
 *  /s\
 * <_-_>
 *
 */
/*
** _ /\_
** _/==\_
*/
